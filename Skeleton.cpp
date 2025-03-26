#include "Skeleton.h"

char skeleton :: getId() {
    return this->id;
}

void skeleton :: decHealth(int h) {
    this->health = health - h;
}

int skeleton :: getDmg() {
    return this->dmg;
}

int skeleton :: getHealth() {
    return this->health;
}