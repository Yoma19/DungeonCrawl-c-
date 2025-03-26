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
        int hidden;

    public:
        int getHealth();
        int getDmg();
        char getId();
        int getHidden();

        void setLocationX(int num);
        void setLocationY(int num);
        void setHealth(int h);
        void setDmg(int d);
        void setHidden();
};

#endif