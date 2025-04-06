#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
#include <memory>

using namespace std;

class inventory {
    private:
        vector<item*> items;
    public:
        void viewItems();
        void addItems(item* i);
        void removeItem();
};

#endif