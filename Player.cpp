#include "Player.h"

void player :: decHealth(int h) {
    health = health - h;
}

void player :: setDmg(int d) {
    dmg = d;
}

void player :: setLocationX(int x) {
    location.x = x;
}

void player :: setLocationY(int y) {
    location.y = y;
}

char player :: getId() {
    return id;
}

int player :: getHealth() {
    return health;
}

int player :: getDmg() {
    return dmg;
}

int player :: getLocationX() {
    return location.x;
}

int player :: getLocationY() {
    return location.y;
}

