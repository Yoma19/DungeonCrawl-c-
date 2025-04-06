#ifndef SMALLHEALTH_H
#define SMALLHEALTH_H

#include "HealthCon.h"

class smallHealth : public healthCon {
    private:
        char id = '"';
        int heals = 20;
        string name = "Small Health Potion";
    public:
        char getId();
        int getHeals();
        string getName();
};

#endif