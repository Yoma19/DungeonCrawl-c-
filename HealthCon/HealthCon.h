#ifndef HEALTHCON_H
#define HEALTHCON_H

#include "../Event.h"

class healthCon : public event {
    private:
        char id;
        int heals;
    public:
        virtual char getId();
        virtual int getHeals();
};

#endif