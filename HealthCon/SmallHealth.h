#ifndef SMALLHEALTH_H
#define SMALLHEALTH_H

#include "HealthCon.h"

class smallHealth : public healthCon {
    private:
        char id = '"';
        int heals = 20;
    public:
        char getId();
        int getHeals();
};

#endif