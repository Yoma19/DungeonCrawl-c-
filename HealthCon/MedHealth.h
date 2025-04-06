#ifndef MEDHEALTH_H
#define MEDHEALTH_H

#include "HealthCon.h"

class medHealth : public healthCon {
    private:
        char id = '`';
        int heals = 50;
        string name = "Medium Health Potion";
    public:
        char getId();
        int getHeals();
        string getName();
};

#endif