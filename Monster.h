#ifndef MONSTER_H
#define MONSTER_H

#include "Event.h"
#include <iostream>

class monster : public event {
    private:
        int health;
        int dmg;
        char id;
        position location;

    public:
        int getHealth();
        int getDmg();
        char getId();

        void setLocationX(int num);
        void setLocationY(int num);
        void setHealth(int h);
        void setDmg(int d);
};

#endif