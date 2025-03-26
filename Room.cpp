#include "Room.h"

event* room :: getEvent() {
    return this->e;
}

void room :: setEvent(event* eve){
    delete e;
    this->e = eve;
}

void room :: setLocationX(int num){
    this->location.x = num;
}

void room :: setLocationY(int num){
    this->location.y = num;
}

void room :: resetEvent() {
    this->e = nullptr;
}