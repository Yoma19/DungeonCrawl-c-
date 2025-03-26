#include "Event.h"

char event :: getId(){
    return this->id;
}

int event :: getDmg() {
    return this->dmg;
}

void event :: decHealth(int h) {
    this->health = health - h;
}

int event :: getHealth() {
    return this->health;
}