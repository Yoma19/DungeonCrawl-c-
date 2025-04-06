#include "Weapon.h"

char weapon :: getId() {
    return this->id;
}

string weapon :: getName() {
    return this->name;
}

int weapon :: getDmg() {
    return this->dmg;
}

void weapon :: setDmg(int d) {
    this->dmg = d;
}