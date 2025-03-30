#ifndef MEDHEALTH_H
#define MEDHEALTH_H

#include "HealthCon.h"

class medHealth : public healthCon {
    private:
        char id = '`';
        int heals = 50;
    public:
        char getId();
        int getHeals();
};

#endif