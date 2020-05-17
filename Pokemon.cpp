#include "Pokemon.h"
#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;



Pokemon::Pokemon() : GameObject('P') {
    stamina = 20;
    pokemon_dollars = 0.0;
    current_center = NULL;
    current_gym = NULL;
    stamina_points_to_buy = 0;
    training_units_to_buy = 0;
    speed = 1;
    this->name = "Pokemon";
    is_in_gym = false;
    is_in_center = false;
    experience_points = 0;
    this->speed = 5.0;
    cout << "Pokemon constructed. " << endl;
}


Pokemon::Pokemon(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc):GameObject(in_loc, in_id , 'P')
{
    this->name = in_name;
    this->speed = speed;
    this->health = hp;
    this->physical_damage = phys_dmg;
    this->magical_damage = magic_dmg;
    this->defense = def;
    stamina = 20;
    pokemon_dollars = 0.0;
    current_center = NULL;
    current_gym = NULL;
    current_arena = NULL;
    stamina_points_to_buy = 0;
    training_units_to_buy = 0; 
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false; 
    experience_points = 0;
    cout << "Pokemon constructed. " << endl;
}


Pokemon::Pokemon(char in_code) : GameObject(in_code) {
    stamina = 20;
    pokemon_dollars = 0.0;
    current_center = NULL;
    current_gym = NULL;
    stamina_points_to_buy = 0;
    training_units_to_buy = 0;
    this->name = name;
    this->speed = speed;
    is_in_gym = false;
    is_in_center = false;
    experience_points = 0;
    cout << "Pokemon constructed. " << endl;
}

Pokemon::~Pokemon() {
    cout << "Pokemon destructed. " << endl;
}


bool Pokemon::IsExhausted() {
    return stamina == 0;
}


bool Pokemon::Update() {
    bool arrived = false;
    unsigned int stamina_received = 0;
    unsigned int stamina_cost = 0;
    double dollar_cost = 0;
    unsigned int num_training_units = 0;
    unsigned int experience_gain = 0;
    switch (state) {
        case STOPPED:
            return false;
        case MOVING:
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if (is_in_arena) 
            {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }
            if (stamina == 0) {
                cout << name << " is out of stamina and can't move." << endl;
                state = EXHAUSTED;
                return true;
            } else {
                arrived = UpdateLocation();
                if (arrived) {
                    state = STOPPED;
                    return true;
                } else {
                    pokemon_dollars += GetRandomAmountOfPokemonDollars();
                    stamina -= 1;
                    return false;
                }
            }
        case MOVING_TO_GYM:
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if (is_in_arena) 
            {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }
            if (stamina == 0) {
                cout << name << " is out of stamina and can't move." << endl;
                state = EXHAUSTED;
                return true;
            } else {
                arrived = UpdateLocation();
                if (arrived) {
                    state = IN_GYM;
                    is_in_gym = true;
                    current_gym->AddOnePokemon();
                    return true;
                } else {
                    pokemon_dollars += GetRandomAmountOfPokemonDollars();
                    stamina -= 1;
                    return false;
                }
            }
        case MOVING_TO_CENTER:
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if (is_in_arena) 
            {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }
            if (stamina == 0) {
                cout << name << " is out of stamina and can't move." << endl;
                state = EXHAUSTED;
                return true;
            } else {
                arrived = UpdateLocation();
                if (arrived) {
                    state = IN_CENTER;
                    is_in_center = true;
                    current_center->AddOnePokemon();
                    return true;
                } else {
                    pokemon_dollars += GetRandomAmountOfPokemonDollars();
                    stamina -= 1;
                    return false;
                }
            }
        case MOVING_TO_ARENA: 
            if (is_in_center)
            {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            }
            else if (is_in_gym)
            {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if (is_in_arena)
            {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }
            if (stamina == 0)
            {
                cout << name << " is out of stamina and can't move." << endl;
                state = EXHAUSTED;
                return true;
            }
            else
            {
                arrived = UpdateLocation();
                if (arrived)
                {
                    state = IN_ARENA;
                    is_in_arena = true;
                    current_arena->AddOnePokemon();
                    return true;
                }
                else
                {
                    pokemon_dollars += GetRandomAmountOfPokemonDollars();
                    stamina -= 1;
                    return false;
                }
            }
        case RECOVERING_STAMINA:
            dollar_cost = current_center->GetDollarCost(stamina_points_to_buy);
            pokemon_dollars -= dollar_cost;
            stamina += current_center->DistributeStamina(stamina_points_to_buy);
            cout << "** " << name << " recovered " << stamina_points_to_buy << " stamina point(s)! **" << endl;
            stamina_points_to_buy = 0;
            state = IN_CENTER;
            return true;
        case TRAINING_IN_GYM:
            stamina_cost = current_gym->GetStaminaCost(training_units_to_buy);
            dollar_cost = current_gym->GetDollarCost(training_units_to_buy);
            experience_gain = current_gym->TrainPokemon(training_units_to_buy);
            stamina -= stamina_cost;
            pokemon_dollars -= dollar_cost;
            experience_points += experience_gain;
            cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)! **" << endl;
            cout << "** " << name << " gained " << experience_gain << " experience points! **" << endl;
            training_units_to_buy = 0;
            state = IN_GYM;
            return true;
        case IN_ARENA:

            if(is_in_arena == 0)
            {
                current_arena->AddOnePokemon();
                this->is_in_arena = 1;
                return true;
            }
            else
            {
                return 0;
            }

        case BATTLE:
        {
            stamina -= current_arena->GetStaminaCost();
            pokemon_dollars -= current_arena->GetDollarCost();

            store_health = this->health;

            if(StartBattle())
            {
                state = IN_ARENA;
                this->health = store_health;
                target-> IsAlive();
                current_arena->RemoveOneRival();
            }

            else if(!StartBattle())
            {
                state = FAINTED;
                target->IsAlive();
            }

            return true; 
        }
        case FAINTED:         
        case EXHAUSTED:
        case IN_GYM:
        case IN_CENTER:
        default:
            return false;
        
    }
}

void Pokemon::StartMovingToCenter(PokemonCenter* center) {
    if (!IsExhausted()) {
        if (location == center->GetLocation()) {
            cout << display_code << GetId() << ": I am already at the Pokemon Center!" << endl;
        } else {
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            state = MOVING_TO_CENTER;
            current_center = center;
            SetupDestination(center->GetLocation());
            cout << display_code << GetId() << ": On my way to center " << center->GetId() << endl;
        }
    } else
        cout << display_code << GetId() << ": I am exhausted so I can't move to recover stamina..." << endl;
}

void Pokemon::StartMovingToGym(PokemonGym *gym)
{
    if (!IsExhausted())
    {
        if (location == gym->GetLocation())
        {
            cout << display_code << GetId() << ": I am already at the Pokemon Gym!" << endl;
        }
        else
        {
            if (is_in_gym)
            {
                current_gym->RemoveOnePokemon(); 
                is_in_gym = false;
            }
            else if (is_in_center)
            {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            }
            state = MOVING_TO_GYM;
            current_gym = gym;
            SetupDestination(gym->GetLocation());
            cout << display_code << GetId() << ": On my way to gym " << gym->GetId() << endl;
        }
    }
    else
        cout << display_code << GetId() << ": I am exhausted so I shouldn't be going to the gym.." << endl;
}

void Pokemon::StartMovingToArena(BattleArena* arena) 
{ 
    if (!IsExhausted()) 
    {
        if (location == arena->GetLocation()) 
        {
            cout << display_code << GetId() << ": I am already at the Pokemon Arena!" << endl;
        } else 
        {
            if (is_in_gym) 
            {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            } 
            else if (is_in_center) 
            {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } 
            else if (is_in_arena)
            {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }

            state = MOVING_TO_ARENA;
            current_arena = arena;
            SetupDestination(arena->GetLocation());
            cout << display_code << this->GetId() << ": On my way to arena " << arena->GetId() << endl;
        }
    } else
        cout << display_code << GetId() << ": I am exhausted so I shouldn't be going to the arena.." << endl;
}

void Pokemon::StartTraining(unsigned int num_training_units) {
    unsigned int training_units_in_gym = 0;
    if (!IsExhausted()) {
        if (state == IN_GYM || state == TRAINING_IN_GYM) {
            if (current_gym->IsAbleToTrain(num_training_units,
                                           pokemon_dollars, stamina)) {
                if (!current_gym->IsBeaten()) {
                    training_units_in_gym = current_gym->GetNumTrainingUnitsRemaining();
                    training_units_to_buy = min(num_training_units, training_units_in_gym);
                    state = TRAINING_IN_GYM;
                    cout << display_code << GetId() << ": Started " << training_units_to_buy
                         << " training unit(s) at Pokemon Gym " << current_gym->GetId() << endl;
                } else
                    cout << display_code << GetId() << ": Cannot train! This Pokemon Gym is already beaten!"
                         << current_gym->GetId() << endl;
            } else
                cout << display_code << GetId() << ": Not enough stamina and/or money for training" << endl;
        } else
            cout << display_code << GetId() << ": I can only train in a Pokemon Gym!" << endl;
    } else
        cout << display_code << GetId() << ": I am exhausted so no more training for me.." << endl;
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points) {
    unsigned int stamina_count_in_center = 0;
    if (state == IN_CENTER || state == RECOVERING_STAMINA) {
        if (IsExhausted())
            cout << display_code << GetId() << ": I barely made it to the Pokemon center!" << endl;
        if (current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars)) {
            if (current_center->HasStaminaPoints()) {
                stamina_count_in_center = current_center->GetNumStaminaPointsRemaining();
                state = RECOVERING_STAMINA;
                stamina_points_to_buy = min(num_stamina_points, stamina_count_in_center);
                cout << display_code << GetId() << ": Started recovering " << stamina_points_to_buy
                     << " stamina point(s) at Pokemon Center " << current_center->GetId() << endl;
            } else
                cout << display_code << GetId()
                    << ": Cannot recover! No stamina points available in this Pokemon Center "
                     << current_center->GetId() << endl;
        } else
            cout << display_code << GetId() << ": Not enough money to recover stamina." << endl;
    } else
        cout << display_code << GetId() << ": I can only recover stamina at a Pokemon Center!" << endl;
}

void Pokemon::StartMoving(Point2D dest) {
    if (!IsExhausted()) {
        if (dest == this->GetLocation()) {
            cout << display_code << GetId() << ": I'm already there. see?" << endl;
        } else {
            state = MOVING;
            SetupDestination(dest);
            cout << display_code << GetId() << ": On my way." << endl;
        }
    } else {
        cout << display_code << GetId() << ": I am exhausted. I may move but you just cannot see me. " << endl;
    }
}

void Pokemon::SetupDestination(Point2D dest) {
    destination = dest;
    delta = (destination - location)*(speed / GetDistanceBetween(destination, location));
}

void Pokemon::Stop() {
    state = STOPPED;
    cout << display_code << GetId() << ": Stopping.." << endl;
}

bool Pokemon::UpdateLocation() {
    //check if within one step
    if (fabs((destination - location).x) <= fabs(delta.x) &&
        fabs((destination - location).y) <= fabs(delta.y)) {
        location = destination;
        cout << display_code << GetId() << ": I’m there!" << endl;
        return true;
    }
    else {
        location = location + delta;
        cout << display_code << GetId() << ": step..." << endl;
        return false;
    }
}

string Pokemon::GetName() {
    return name;
}

double GetRandomAmountOfPokemonDollars() {
    double f_min = 0.0;
    double f_max = 2.0;
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}

void Pokemon::ShowStatus() {
    cout << name << " status: ";
    GameObject::ShowStatus();
    switch (state) {
        case STOPPED:
            cout << " stopped" << endl;
            break;
        case MOVING:
            cout << " moving at a speed of " << speed
                 << " to " << destination << " at each step of " << delta << endl;
            break;
        case MOVING_TO_CENTER:
            cout << " heading to Pokemon Center " << current_center->GetId()
                 << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case MOVING_TO_GYM:
            cout << " heading to Pokemon Gym " << current_gym->GetId()
                 << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case IN_GYM:
            cout << " inside Pokemon Gym " << current_gym->GetId() << endl;
            break;
        case IN_CENTER:
            cout << " inside Pokemon Center " << current_center->GetId() << endl;
            break;
        case TRAINING_IN_GYM:
            cout << " training in Pokemon Gym " << current_gym->GetId() << endl;
        case RECOVERING_STAMINA:
            cout << " recovering stamina in Pokemon Center " << current_gym->GetId() << endl;
            break;
        case IN_ARENA:
            cout << " inside Battle Arena " << current_arena->GetId() << endl;
        case BATTLE:
            cout << " in a battle" << current_arena->GetId() << endl;
        case MOVING_TO_ARENA:
            cout << " heading to Battle Arena " << current_arena->GetId() << " at a speed of " << this->speed << " at each step of " << this->delta << endl;
        case FAINTED:
            cout << this->GetName() << " has fainted " << endl;
        case EXHAUSTED:
            cout << endl;
        default:
            break;
    }
    //  Print stats here
    cout << "\tStamina: " << stamina << endl;
    cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
    cout << "\tExperience Points: " << experience_points << endl;
    cout << "\tPhysical Damage: " << physical_damage << endl;
    cout << "\tHealth: " << health << endl;
    cout << "\tMagical Damage: " << magical_damage << endl;
    cout << "\tDefense: " << defense << endl;
}

bool Pokemon::ShouldBeVisible() {
    return !IsExhausted();
}


void Pokemon:: ReadyBattle(Rival* in_target)
{
    if(this->state == IN_ARENA && current_arena->IsAbleToFight(pokemon_dollars, stamina) && !(current_arena->IsBeaten()) && in_target->IsAlive())
    {
        target = in_target;
        state = BATTLE;
    }
    else 
    {
        state = IN_ARENA;
    }
}

void Pokemon:: TakeHit(double physical_dmg, double magical_dmg, double dfs)
{
    int dmg = rand() % 2 + 1;
    double damage = 0.0;

    if(dmg == 1)
    {
        cout << "***" << endl;
        damage = (100.0 - defense) / 100 * magical_dmg;
        cout << this->GetName() << "was hit for " << damage << " points of magical damage!" << endl;
    }

    else
    {
        cout << "***" << endl;
        damage = (100.0 - defense) / 100 * physical_dmg;
        cout << this->GetName() << "was hit for " << damage << " points of physical damage!" << endl;
    }

    this->health -= damage;
    cout << "Health reduced to " << this->health << endl;
}


bool Pokemon:: StartBattle() 
{
    double r_def = target->get_defense();
    double r_magic = target->get_magic_dmg();
    double r_physical = target->get_phys_dmg();

    while (target->get_health() > 0 && this->health > 0)
    {
        this->TakeHit(r_physical, r_magic, defense);
        target->TakeHit(physical_damage, magical_damage, r_def);

        if(this->health == 0)
        {
            this->state = FAINTED;
            return false;
        }

        else if(target->get_health() == 0)
        {
            state = IN_ARENA;
        
            return true;
        }

        else
        { 
            continue;
        }
    }
}

bool Pokemon:: IsAlive()
{
    if(health >0 && this->state != FAINTED)
    {
        return 1;
    }
    else if (health <= 0)
    {
        state = FAINTED;
        health = 0;
        return 0;
    }
}
