#ifndef SKELETON_H
#define SKELETON_H

#include "Monster.h"

class skeleton : public monster {
    private:
        int health = 6;
        int dmg = 5;
        char id = 's';
        position location;
        int hidden = 0;
        int type = 1;

    public:
        char getId();
        void decHealth(int h);
        int getDmg();
        int getHealth();
        int getType();
};

#endif