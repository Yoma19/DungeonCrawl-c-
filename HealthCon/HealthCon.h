#ifndef HEALTHCON_H
#define HEALTHCON_H

#include "../Item.h"

class healthCon : public item {
    private:
        char id;
        int heals;
        string name;
    public:
        virtual char getId();
        virtual int getHeals();
        virtual string getName();
};

#endif