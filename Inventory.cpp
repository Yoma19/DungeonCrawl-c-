#include "Inventory.h"

using namespace std;

void inventory :: viewItems() {
    string inp;
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

        cout << "\n'l' to leave...\n\n";
        cin >> inp;
    }
}

void inventory :: addItems(item* i) {
    this->items.push_back(i);
}

void inventory :: removeItem() {

}