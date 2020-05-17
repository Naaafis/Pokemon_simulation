#include <iostream>
#include "GameObject.h"
#include "Point2D.h"

//documentation doesn't specify a default constructor
GameObject::GameObject() {
    display_code = ' ';
    state = 0;
    id_num = 1;
    cout << "GameObject constructed. " << endl;
}

GameObject::GameObject(char in_code) {
    display_code = in_code;
    state = 0;
    id_num = 1;
    cout << "GameObject constructed. " << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code) {
    display_code = in_code;
    state = 0;
    id_num = in_id;
    location = in_loc;
    cout << "GameObject constructed. " << endl;
}

GameObject::~GameObject() {
    cout << "GameObject destructed. " << endl;
}

Point2D GameObject::GetLocation() {
    return location;
}

int GameObject::GetId() {
    return id_num;
}

char GameObject::GetState(){
    return state;
}


void GameObject::ShowStatus() {
    //check sample output
    cout << display_code << id_num << " at " << location;
}

void GameObject::DrawSelf(char *ptr) {
    *ptr = display_code;
    *(ptr+1) = '0' + id_num;
}


