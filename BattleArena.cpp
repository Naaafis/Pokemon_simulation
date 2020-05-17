#include "BattleArena.h"
#include "Pokemon.h"

#include <ctime>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

BattleArena::BattleArena():Building('A', 0, Point2D(0.0, 0.0))
{
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    this->state = RIVALS_AVAILABLE;
    cout << "BattleArena default constructed" << endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc):Building('A', in_id, in_loc)
{
    max_num_rivals = max_rivals;
    stamina_cost_per_fight = stamina_cost; 
    dollar_cost_per_fight = dollar_cost;
    num_rivals_remaining = max_num_rivals;
    pokemon_count = 0;
    this->state = RIVALS_AVAILABLE;
    cout << "BattleArena constructed" << endl;
}

BattleArena::~BattleArena()
{
    cout << "Battle Arena destructed" << endl;
}

unsigned int BattleArena:: GetNumRivalsRemaining()
{
    return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals()
{
    if(state == NO_RIVALS_AVAILABLE)
    {
        return 0;
    }
    else if(num_rivals_remaining == 0)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

double BattleArena::GetDollarCost()
{
    return this->dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost()
{
    return this->stamina_cost_per_fight; 
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
    if(budget >= this->dollar_cost_per_fight && stamina >= this->stamina_cost_per_fight)
    {
        return true;
    }

    else if (budget < this->dollar_cost_per_fight && stamina < this->stamina_cost_per_fight)
    {
        cout << "Not enough stamina to fight and Not enough pokemon dollars to fight" << endl;
        return false;
    }

    else if(stamina < this->stamina_cost_per_fight)
    {
        cout << "Not enough stamina to fight" << endl;
        return false;
    }

    else if(budget < this->dollar_cost_per_fight)
    {
        cout << "Not enough pokemon dollars to fight" << endl;
        return false;
    }

    else 
    {
        return false;
    }
}

bool BattleArena::Update()
{
    if(num_rivals_remaining > 0)
    {
        return 0;
    }

    else if(state ==  RIVALS_AVAILABLE && num_rivals_remaining == 0)
    {
        state = NO_RIVALS_AVAILABLE;
        cout << this->GetId() << " has no rivals left." << endl;
        return true;
    }

    else if(state == NO_RIVALS_AVAILABLE && num_rivals_remaining == 0)
    {
        return 0;
    }

    else 
    {
        return 0;
    }
}

bool BattleArena::IsBeaten()
{
    if(num_rivals_remaining > 0)
    {
        return false;
    }

    else
    {
        return true;
    }
}

void BattleArena::ShowStatus()
{
    cout << "Battle Arena Status: " << endl;
    Building::ShowStatus();
    cout << "\t Max number of rivals: " << this->max_num_rivals << endl;
    cout << "\t num_rivals_remaining: " << this->GetNumRivalsRemaining() << endl;
    cout << "\t dollar_cost_per_fight: " << this->GetDollarCost() << endl;
    cout << "\t Stamina_cost_per_fight: " << this->GetStaminaCost() << endl;
    // cout << "\t State: " << GameObject:: GetState() << endl;
}

void BattleArena::RemoveOneRival()
{
    num_rivals_remaining -= 1;
}
