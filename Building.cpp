#include "Building.h"

Building::Building() : GameObject('B') {
    pokemon_count = 0;
    cout << "Building default constructed" << endl;
}

Building::Building(char code, int id, Point2D loc) : GameObject(loc, id, code) {
    pokemon_count = 0;
    cout << "Building constructed" << endl;
}

Building::~Building() {
    cout << "Building destructed" << endl;
}

void Building::AddOnePokemon() {
    pokemon_count += 1;
}

void Building::RemoveOnePokemon() {
    pokemon_count -= 1;
}

void Building::ShowStatus() {
    cout << display_code << GetId() << " located at " << location << endl;
    cout << "\t" << pokemon_count << " Pokemon " << (pokemon_count == 1 ? "is" : "are")
         <<  " in this building" << endl;
}

bool Building::ShouldBeVisible() {
    return true;
}