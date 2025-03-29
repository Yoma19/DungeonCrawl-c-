#include "Shortsword.h"

char shortsword :: getId() {
    return this->id;
}

int shortsword :: getDmg() {
    return this->dmg;
}

void shortsword :: setDmg(int d) {
    this->dmg = d;
}