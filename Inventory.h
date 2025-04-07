#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "Player.h"
#include "Weapon/Shortsword.h"
#include "HealthCon/MedHealth.h"
#include "HealthCon/SmallHealth.h"
#include <vector>
#include <memory>

using namespace std;

class inventory {
    private:
        vector<item*> items;
    public:
        void viewItems(player& p);
        void addItems(item* i);
        void removeItem();
        void useItem(int idx, player& p);
};

#endif