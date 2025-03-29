#include "Weapon.h"

char weapon :: getId() {
    return this->id;
}

int weapon :: getDmg() {
    return this->dmg;
}

void weapon :: setDmg(int d) {
    this->dmg = d;
}