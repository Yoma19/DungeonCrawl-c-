#ifndef MONSTER_H
#define MONSTER_H

#include "../Event.h"
#include <iostream>

class monster : public event {
    private:
        int health;
        int dmg;
        char id;
        position location;
        int hidden;
        int type = 1;

    public:
        virtual ~monster() = default;
        virtual int getHealth();
        virtual int getDmg();
        virtual char getId();
        virtual int getHidden();

        void setLocationX(int num);
        void setLocationY(int num);
        virtual void decHealth(int h);
        virtual void setDmg(int d);
        virtual void setHidden();
        //int getType();
};

#endif