#ifndef WEAPON_H
#define WEAPON_H

#include "Event.h"

class weapon : public event {
    private:
        char id;
    public:
        virtual char getId();

};

#endif