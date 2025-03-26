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
    public:
        char getId();
        void decHealth(int h);
        int getDmg();
};

#endif