#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include "Position.h"

class event {
    private:
        char id;
        position location;

    public:
        virtual char getId() = 0;
/*         virtual int setLocationX() = 0;
        virtual int setLocationY() = 0; */
        virtual ~event() = default;

};

#endif