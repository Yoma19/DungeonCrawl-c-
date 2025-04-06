#ifndef WEAPON_H
#define WEAPON_H

#include "../Item.h"

class weapon : public item {
    private:
        char id;
        int dmg;
        string name;
    public:
        virtual char getId();
        virtual int getDmg();
        virtual void setDmg(int d);
        virtual string getName();

};

#endif