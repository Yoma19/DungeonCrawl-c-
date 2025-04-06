#ifndef SHORTSWORD_H
#define SHORTSWORD_H

#include "Weapon.h"

class shortsword : public weapon {
    private:
        char id = '^';
        int dmg = 7;
        string name = "Shortsword";
    public:
        char getId();
        int getDmg();
        void setDmg(int d);
        string getName();
};

#endif