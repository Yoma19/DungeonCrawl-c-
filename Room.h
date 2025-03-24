#ifndef ROOM_H
#define ROOM_H

#include "Event.h"
#include <iostream>

class room {
    private:
        event* e = nullptr;
        position location;
    public:
        room() : e(nullptr) {}
        event* getEvent();
        void setEvent(event* eve);
        void setLocationX(int num);
        void setLocationY(int num);
        ~room() {delete e;}
};

#endif