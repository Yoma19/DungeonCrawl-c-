#ifndef SHORTSWORD_H
#define SHORTSWORD_H

#include "Weapon.h"

class shortsword : public weapon {
    private:
        char id = '^';
        int dmg = 7;
    public:
        char getId();
        int getDmg();
        void setDmg(int d);
};

#endif