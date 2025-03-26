#ifndef SKELETON_H
#define SKELETON_H

#include "Monster.h"

class skeleton : public monster {
    private:
        int health = 10;
        int dmg = 2;
        char id = 's';
        position location;
        int hidden = 0;
    public:
        char getId();
};

#endif