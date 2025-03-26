#include "Zombie.h"

char zombie :: getId() {
    return id;
}

void zombie :: setLocationX(int num){
    this->location.x = num;
}

void zombie :: setLocationY(int num){
    this->location.y = num;
}

void zombie :: decHealth(int h) {
    this->health = health - h;
}

int zombie :: getDmg() {
    return this->dmg;
}

int zombie :: getHealth() {
    return this->health;
}