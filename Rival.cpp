#include "Rival.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

Rival::Rival(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc): GameObject(in_loc, id, 'R')
{
    this->name = in_name;
    this->speed = speed; // 5
    this->health = hp; // 20
    this->physical_damage = phys_dmg; // 5
    this->magical_damage = magic_dmg; // 4
    this->defense = def; //15 
    state = ALIVE;
    cout << "Rival Constructed" << endl;
}

Rival::~Rival()
{
    cout << "Rival destructed" << endl;
}

void Rival:: TakeHit(double physical_dmg, double magical_dmg, double dfs)
{
    int typedmg = rand() % 2 + 1;
    double damage = 0.0;

    if(typedmg == 1)
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

string Rival :: GetName()
{
    return this->name;
}

double Rival :: get_phys_dmg()
{
    return this->physical_damage;
}

double Rival :: get_magic_dmg()
{
    return this->magical_damage;
}

double Rival :: get_defense()
{
    return this->defense;
}

double Rival :: get_health()
{
    return this->health;
}

bool Rival :: Update()
{
    if(state == ALIVE)
    {
        return 0;
    }

    else if(state == RFAINTED)
    {
        return 1;
    }
}

bool Rival :: IsAlive()
{
    if(this->health > 0)
    {
        state = ALIVE;
        return 1;
    }

    else 
    {
        state = RFAINTED;
        return 0;
    }
}

void Rival :: ShowStatus()
{
    cout << this->name << " status: " << endl;
    GameObject :: ShowStatus();
    if(this->state == ALIVE)
    {
        cout << "\tAlive" << endl;
        cout << "\tPhysical Damage: " << physical_damage << endl;
        cout << "\tHealth: " << health << endl;
        cout << "\tMagical Damage: " << magical_damage << endl;
        cout << "\tDefense: " << defense << endl;

    }
    else
    {
        cout << "Fainted" << endl;
    }
}

bool Rival :: ShouldBeVisible()
{
    if(state == RFAINTED)
    {
        return 0;
    }
    else if(state == ALIVE)
    {
        return 1;
    }
} 