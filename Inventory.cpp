#include "Inventory.h"

using namespace std;

void inventory :: viewItems(player& p) {
    string inp;
    int idx;
    int flg = 0;
    while (inp != "l") {
        system("cls || clear");
        cout << "Your inventory\n\n";
        for (int j = 0; j < items.size(); j++) {
            cout << j + 1;
            cout << ". ";
            cout << this->items[j]->getName();
            cout << "\n";
        }

        if (items.size() == 0) {
            cout << "You have no items broke boi";
        }

        if (flg == 1) {
            cout << "\nYour attack has increased!\n\n";
        } else if (flg == 2) {
            cout << "\nYour health has increased!\n\n";
        }

        cout << "\n'u' to use\n'l' to leave...\n\n";
        cin >> inp;

        if (inp == "u") {
            while (idx < 0 || idx > items.size()) {
                cout << "\nEnter the number of the item you want to use\n\n";
                cin >> idx;
            }
            int ix = idx - 1;
            if (weapon* w = dynamic_cast<weapon*>(this->items[ix])) {
                p.setDmg(w->getDmg());
                items.erase(items.begin() + ix);
                flg = 1;
                idx = -1;
            } else if (healthCon* h = dynamic_cast<healthCon*>(this->items[ix])) {
                p.incHealth(h->getHeals());
                items.erase(items.begin() + ix);
                flg = 2;
                idx = -1;
            }
        }
    }
}

void inventory :: addItems(item* i) {
    this->items.push_back(i);
}

/* void inventory :: useItem(int idx, player& p) {
    int ix = idx--;

    item* ite = this->items[ix];

    if (weapon* w = dynamic_cast<weapon*>(ite)) {
        p.setDmg(w->getDmg());
    } else if (healthCon* h = dynamic_cast<healthCon*>(ite)) {
        p.incHealth(h->getHeals());
    }
} */

void inventory :: removeItem() {

}