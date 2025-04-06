#ifndef ITEM_H
#define ITEM_H

#include "Event.h"
using namespace std;

class item : public event {
    private:
        char id;
        string name;
    public:
        virtual char getId();
        virtual string getName();
};

#endif