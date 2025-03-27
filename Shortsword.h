#ifndef SHORTSWORD_H
#define SHORTSWORD_H

#include "Weapon.h"

class shortsword : public weapon {
    private:
        char id = '^';
    public:
        char getId();
};

#endif