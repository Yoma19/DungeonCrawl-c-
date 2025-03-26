#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include "Position.h"

class event {
    private:
        char id;
        int dmg;
        int health;
        position location;

    public:
        virtual char getId() = 0;
        virtual ~event() = default;
        virtual int getDmg() = 0;
        virtual void decHealth(int h) = 0;
        virtual int getHealth() = 0;

};

#endif