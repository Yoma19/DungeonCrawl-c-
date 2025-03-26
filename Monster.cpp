#include "Monster.h"

int monster :: getHealth() {
    return this->health;
}

int monster :: getDmg(){
    return this->dmg;
}

char monster :: getId(){
    return this->id;
}

int monster :: getHidden() { 
    return this->hidden;
}

void monster :: setHealth(int h) {
    this->health = health - h;
}

void monster :: setDmg(int d) {
    this->dmg = d;
}

void monster :: setLocationX(int num){
    this->location.x = num;
}

void monster :: setLocationY(int num){
    this->location.y = num;
}

void monster :: setHidden() {
    this->hidden = 1;
}