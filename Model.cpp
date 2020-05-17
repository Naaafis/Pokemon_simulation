#include "Point2D.h"
#include "Model.h"
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Building.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
#include "Input_Handling.h"
#include <cstdlib>
#include <iostream>
#include <string>



using namespace std;

Model::Model() {
    time = 0;
    //Pikachu 1
    Pokemon* p1 = new Pokemon("Pikachu", 2.0, 20, 5, 4, 15, 1, 'P', Point2D(5, 1)); // Update this
    pokemon_ptrs.push_back(p1);
    object_ptrs.push_back(p1);
    activeobjects.push_back(p1); 

    //Bulbasaur 2
    Pokemon* p2 = new Pokemon("Bulbasaur", 1.0, 20, 5, 4, 15, 2, 'P', Point2D(10, 1)); // Update this
    pokemon_ptrs.push_back(p2);
    object_ptrs.push_back(p2);
    activeobjects.push_back(p2);

    //PokemonCenter 1
    PokemonCenter* c1 = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    center_ptrs.push_back(c1);
    object_ptrs.push_back(c1);
    activeobjects.push_back(c1);

    //PokemonCenter 2
    PokemonCenter* c2 = new PokemonCenter(2, 2, 200,  Point2D(10, 20));
    center_ptrs.push_back(c2);
    object_ptrs.push_back(c2);
    activeobjects.push_back(c2);

    //PokemonGym 
    PokemonGym* g1 = new PokemonGym(10, 1.0,2.0, 3, 1, Point2D(0, 0));
    gym_ptrs.push_back(g1);
    object_ptrs.push_back(g1);
    activeobjects.push_back(g1);

    PokemonGym* g2 = new PokemonGym(20, 5,7.5, 8, 2, Point2D(5, 5));
    gym_ptrs.push_back(g2);
    object_ptrs.push_back(g2);
    activeobjects.push_back(g2);

    Point2D ArenaLocation;
    ArenaLocation.x = 15;
    ArenaLocation.y = 5;

    //Rival 1
    Rival* r1 = new Rival("Cooties", 3.0, 20, 5, 6, 15, 1, ArenaLocation);
    rival_ptrs.push_back(r1);
    object_ptrs.push_back(r1);
    activeobjects.push_back(r1);
    //rival_ptrs[0] = new Rival();
    //object_ptrs[6] = rival_ptrs[0];

    //Rival 2
    Rival* r2 = new Rival("Hooters", 2.0, 25, 4, 3, 15, 2, ArenaLocation);
    rival_ptrs.push_back(r2);
    object_ptrs.push_back(r2);
    activeobjects.push_back(r2);
    //rival_ptrs[1] = new Rival();
    //object_ptrs[7] = rival_ptrs[1]; 

    //Rival 3
    Rival* r3 = new Rival("Riker", 2.0, 15, 4, 3, 20, 3, ArenaLocation);
    rival_ptrs.push_back(r3);
    object_ptrs.push_back(r3);
    activeobjects.push_back(r3);

    //BattleArena
    BattleArena* a1 = new BattleArena(3, 3, 2.5, 1, ArenaLocation);
    arena_ptrs.push_back(a1);
    object_ptrs.push_back(a1);
    activeobjects.push_back(a1);

    cout << "Model default constructed. " << endl;
}

Model::~Model() 
{
    for (auto index = object_ptrs.begin(); index != object_ptrs.end(); ++index)
    {
        GameObject *alive = *index;
        object_ptrs.erase(index);
    }
    cout << "Model destructed. " << endl;
}

Pokemon *Model::GetPokemonPtr(int id) 
{
    for (auto &poke : pokemon_ptrs) 
    {
        if (id == poke->GetId()) 
        {
            return poke;
        }
    }
    return 0;
}

PokemonCenter *Model::GetPokemonCenterPtr(int id) 
{
    for (auto &centers : center_ptrs) 
    {
        if (id == centers->GetId()) 
        {
            return centers;
        }
    }
    return 0;
}

PokemonGym *Model::GetPokemonGymPtr(int id) 
{
    for (auto &gyms : gym_ptrs) 
    {
        if (id == gyms->GetId()) 
        {
            return gyms;
        }
    }
    return 0;
}

Rival *Model::GetRivalPtr(int id) 
{
    for (auto &rivals : rival_ptrs) 
    {
        if (id == rivals->GetId()) 
        {
            return rivals;
        }
    }
    return 0;
}

BattleArena* Model::GetBattleArenaPtr(int id)
{
    for (auto &arena : arena_ptrs) 
    {
        if (id == arena->GetId()) 
        {
            return arena;
        }
    }
    return 0;
}

bool Model::Update() {
    time++;
    int gyms_beaten = 0;
    int pokemon_exhausted = 0;
    //Calculating number of gyms beaten
    if (gyms_beaten != gym_ptrs.size()) 
    {
        for (auto &gym : gym_ptrs) 
        {
            if (gym->GetState() == BEATEN)
                gyms_beaten++;
        }
    }
    // Calculating number of pokemon that are tired
    if (pokemon_exhausted != pokemon_ptrs.size()) 
    {
        for (auto &pokemon: pokemon_ptrs) 
        {
            if (pokemon->IsExhausted())
                pokemon_exhausted++;
        }
    }
    bool event = false;

    for (auto alive = activeobjects.begin(); alive != activeobjects.end(); ++alive)
    {
        GameObject* index = *alive;
        if(index->ShouldBeVisible()==0)
        {
            alive = activeobjects.erase(alive);
            cout << "Fainted object deleted" << endl;
        }
    }

    // continue to update all
    if (gyms_beaten == gym_ptrs.size()) 
    {
        cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
        exit(EXIT_SUCCESS);
    }
    if (pokemon_exhausted == pokemon_ptrs.size()) 
    {
        cout << "GAME OVER: You lose! All of your Pokemon are exhausted!" << endl;
        exit(EXIT_SUCCESS);
    }
    // update if winning condition is not met
    for (auto &object : object_ptrs) 
    {
        bool temp = object->Update();
        if (temp) 
        {
            event = temp;
        }
    }
    return event;
}

void Model::Display(View &view) 
{
    view.Clear();
    for (auto &active : activeobjects) {
        if (active->ShouldBeVisible()) {
            view.Plot(active);
        }
    }
    view.Draw();
}

void Model::ShowStatus() 
{
    cout << "Time: " << time << endl;
    for (auto &object : object_ptrs) 
    {
        object->ShowStatus();
    }
}

void Model:: NewCommand(Model& model, char type, int id, Point2D location)
{
    if (type == 'p')
    {
        try
        {
            for (auto &poke : pokemon_ptrs)
            {
                if (id == poke->GetId())
                {
                    throw Invalid_Input("ID number already exists");
                }

                else 
                {
                    continue;
                }
            }
            
            Pokemon *P3 = new Pokemon("NewPokemon", 1.0, 20, 5, 4, 15, id, 'P', location);

            model.pokemon_ptrs.push_back(P3);
            model.object_ptrs.push_back(P3);
            model.activeobjects.push_back(P3);
        }
        catch (Invalid_Input &except)
        {
            cout << "Input error-> " << except.msg_ptr << endl;
        }
        
    }

    else if(type == 'g')
    {
        try
        {
            for (auto &gyms : gym_ptrs) 
            {
                if (id == gyms->GetId()) 
                {
                    throw Invalid_Input("ID number already exists");
                }

                else
                {
                    continue;
                }
            }
            
            PokemonGym* G3 = new PokemonGym(10, 1.0,2.0, 3, id, location);

            model.gym_ptrs.push_back(G3);
            model.object_ptrs.push_back(G3);
            model.activeobjects.push_back(G3);
        }

        catch (Invalid_Input &except)
        {
            cout << "Input error-> " << except.msg_ptr << endl;
        }
        
    }

    else if(type == 'c')
    {
        try
        {
            for (auto &centers : center_ptrs) 
            {
                if (id == centers->GetId()) 
                {
                    throw Invalid_Input("ID number already exists");
                }

                else 
                {
                    continue;
                }
            }

            PokemonCenter* C3 = new PokemonCenter(id, 1, 100, location);

            model.center_ptrs.push_back(C3);
            model.object_ptrs.push_back(C3);
            model.activeobjects.push_back(C3);
        }
        catch (Invalid_Input &except)
        {
            cout << "Input error-> " << except.msg_ptr << endl;
        }

    }

    else if(type == 'r')
    {
        try
        {
            for (auto &rivals : rival_ptrs) 
            {
                if (id == rivals->GetId()) 
                {
                    throw Invalid_Input("ID number already exists");
                }

                else
                {
                    continue;
                }
            }

            Rival* R4 = new Rival("New Rival", 3.0, 20, 5, 6, 15, id, location);
            model.rival_ptrs.push_back(R4);
            model.object_ptrs.push_back(R4);
            model.activeobjects.push_back(R4);
        }

        catch (Invalid_Input &except)
        {
            cout << "Input error-> " << except.msg_ptr << endl;
        }

    }
}