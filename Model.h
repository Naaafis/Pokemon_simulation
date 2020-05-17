#ifndef MODEL_H
#define MODEL_H
#include "Point2D.h"
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
#include <list>

class Model {
    
private:
    //simulation time
    int time;
    /*GameObject * object_ptrs[10];
    int num_objects;
    Pokemon * pokemon_ptrs[10];
    int num_pokemon;
    PokemonCenter * center_ptrs[10];
    int num_centers;
    PokemonGym * gym_ptrs[10];
    int num_gyms;
    Rival * rival_ptrs[0];
    int num_rivals;*/
    list <GameObject*> object_ptrs;
    list <Pokemon*> pokemon_ptrs;
    list <PokemonCenter*> center_ptrs;
    list <PokemonGym*> gym_ptrs;
    list <Rival*> rival_ptrs;
    list <BattleArena*> arena_ptrs;
    list <GameObject*> activeobjects;  

    
public:
    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    BattleArena* GetBattleArenaPtr(int id);
    Rival* GetRivalPtr(int id);
    bool Update();
    void Display(View &view);
    void ShowStatus();
    void NewCommand(Model&, char, int, Point2D);
};


#endif
