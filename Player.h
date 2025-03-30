#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Event.h"
#include <iostream>

class player : public event {

    private:
        int health = 100;
        int dmg = 1;
        char id = '*';
        int type = 0;
        position location;

    public:
        player() = default;
        
        void decHealth(int h);
        void incHealth(int h);
        void setDmg(int d);
        void setLocationX(int x);
        void setLocationY(int y);
        

        char getId();
        int getHealth();
        int getDmg();
        int getLocationX();
        int getLocationY();
        //int getType();

};

#endif