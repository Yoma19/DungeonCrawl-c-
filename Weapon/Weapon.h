#ifndef WEAPON_H
#define WEAPON_H

#include "../Event.h"

class weapon : public event {
    private:
        char id;
        int dmg;
    public:
        virtual char getId();
        virtual int getDmg();
        virtual void setDmg(int d);

};

#endif