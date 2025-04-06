#include "Room.h"

event* room :: getEvent() {
    return this->e;
}

void room :: setEvent(event* eve){
    delete e;
    this->e = eve;
}

void room :: resetEvent() {
    this->e = nullptr;
}

event* room :: transferEvent() {
    event* t = this->e;
    e = nullptr;
    return t;
}