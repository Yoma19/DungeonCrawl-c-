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
    public:
        void setLocationX(int num);
        void setLocationY(int num);
        char getId();
};

#endif