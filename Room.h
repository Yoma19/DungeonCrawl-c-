#ifndef ROOM_H
#define ROOM_H

#include "Event.h"
#include <iostream>
#include <memory>

using namespace std;

class room {
    private:
        event* e = nullptr;
        position location;
    public:
        room() : e(nullptr) {}
        event* getEvent();
        void setEvent(event* eve);
        void resetEvent();
        event* transferEvent ();
};

#endif