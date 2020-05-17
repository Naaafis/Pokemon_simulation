#ifndef RIVAL_H
#define RIVAL_H

#include <iostream>
#include <string>
#include "GameObject.h"
#include "BattleArena.h"
#include "Point2D.h"
#include "Vector2D.h"


enum RivalStates
{
    ALIVE = 0,
    RFAINTED = 1
};

class Rival : public GameObject
{
    protected:
        
        string name;
        double speed;
        double health;
        double physical_damage;
        double magical_damage;
        double defense;
        bool is_in_arena;

    public:
        ~Rival();
        Rival(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc); // :GameObject('R', id, in_loc)
        void TakeHit(double physical_damage, double magical_damage, double defense);
        double get_phys_dmg();
        double get_magic_dmg();
        double get_defense();
        double get_health();
        bool Update();
        void ShowStatus();
        bool IsAlive();
        string GetName();
        bool ShouldBeVisible();
};

#endif