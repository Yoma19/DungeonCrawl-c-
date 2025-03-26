#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Monster.h"
#include <iostream>

class zombie : public monster {
    private:
        int health = 10;
        int dmg = 2;
        char id = 'z';
        position location;
        int hidden = 0;
    public:
        void setLocationX(int num);
        void setLocationY(int num);
        char getId();
        void decHealth(int h);
        int getDmg();
        int getHealth();
};

#endif