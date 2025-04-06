#include "Shortsword.h"

char shortsword :: getId() {
    return this->id;
}

string shortsword :: getName() {
    return this->name;
}

int shortsword :: getDmg() {
    return this->dmg;
}

void shortsword :: setDmg(int d) {
    this->dmg = d;
}