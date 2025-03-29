#ifndef STAIRS_H
#define STAIRS_H

#include "Event.h"

class stairs : public event {
    private:
        char id = '~';
    public:
        char getId();
};

#endif