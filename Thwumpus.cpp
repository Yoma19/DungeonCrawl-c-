#include <iostream>
#include <vector>

#include "Event.h"
#include "Monster/Zombie.h"
#include "Room.h"
#include "Player.h"
#include "Monster/Skeleton.h"
#include "Weapon/Shortsword.h"
#include "Stairs.h"
#include "HealthCon/SmallHealth.h"
#include "HealthCon/MedHealth.h"
#include "Inventory.h"

#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

template<typename eventType>
void spawnEvent(int num, vector<vector<room>> &rooms) {
    for (int i = 0; i < num; i++) {
        int x = rand() % 6;
        int y = rand() % 7;

        while (rooms[x][y].getEvent() != nullptr) {
            x = rand() % 6;
            y = rand() % 7;
        }

        rooms[x][y].setEvent(new eventType);
    } 
}

int twenty() {
    int twenty = rand() % 5;
    int check;
    if (twenty == 0) {
        check = 1;
    } else {
        check = 0;
    }

    return check;
}

int ten() {
    int ten = rand() % 10;
    int check;
    if (ten == 1) {
        check = 1;
    } else {
        check = 0;
    }

    return check;
}

void move(int &pX, int &pY, int dir) {
    if (dir == 0) {
        pX = pX + 1;
        if (pX > 5) {
            pX--;
        }
    } else if (dir == 1) {
        pX--;
        if (pX < 0) {
            pX++;
        }
    } else if (dir == 2) {
        pY--;
        if (pY < 0) {
            pY++;
        }
    } else if (dir == 3) {
        pY++;
        if (pY > 6) {
            pY--;
        }
    }
    
}

int main() {
    char x;
    
    while (x != 'l') {
        system("cls || clear");
        srand(time(nullptr));

        vector<vector<room>> rooms(6, vector<room>(7));

        player p;
        int pX = rand() % 6;
        int pY = rand() % 7;

        inventory inv;

        spawnEvent<zombie>((rand() % 4) + 1, rooms);
        spawnEvent<skeleton>((rand() % 4) + 1, rooms);
        spawnEvent<shortsword>(rand() % 2, rooms);
        spawnEvent<stairs>(1, rooms);

        cout<< "Welcome to gettin cooked";
        cout << "\nWhat do you want to do?\n";
        cout << "\n'p' Play\n'l' Leave\n\n";
        cin >> x;
        if (x == 'l') {
            break;
        }

        int y = 0;
        int hM = 0;
        int floor = 1;
        //rooms[pX][pY].setEvent(&p);

        string q;
        while (q != "r") {

            if (y == 1) {

                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 7; j++) {
                        rooms[i][j].resetEvent();
                    }
                }

                pX = rand() % 6;
                pY = rand() % 7;
                system("cls || clear");
                rooms[pX][pY].setEvent(&p);
                

                spawnEvent<zombie>((rand() % 4) + 1, rooms);
                spawnEvent<skeleton>((rand() % 4) + 1, rooms);
                spawnEvent<shortsword>(twenty(), rooms);
                spawnEvent<smallHealth>(twenty(), rooms);
                spawnEvent<medHealth>(ten(), rooms);
                spawnEvent<stairs>(1, rooms);

                floor++;
                y = 0;
            } else {
                system("cls || clear");
                rooms[pX][pY].setEvent(&p);
            }

            //system("cls || clear");
            //rooms[pX][pY].setEvent(&p);

            cout<< "\n====================================\n";
            for (int i = 0; i < 6; i++){
                if (i != 0){
                    //cout<< "\n____________________________________\n";
                    cout<< "\n------------------------------------\n";
                }
                for (int j = 0; j < 7; j++) {
                    cout<< "| ";

                    

                    if (rooms[i][j].getEvent() != nullptr) {
                        cout<< rooms[i][j].getEvent()->getId();
                    
                    } else {
                        cout<< " ";
                    }
                    cout<< " |";
                
                }
            } 
            cout<< "\n====================================\n";

            cout << "\nHealth: ";
            cout << p.getHealth();
            cout << "\nCurrent Dmg: ";
            cout << p.getDmg();
            cout << "\nFloor: ";
            cout << floor;
            cout<< "\n\nControls:\n'r' Reset\n'w' move up\n's' move down\n'a' move left\n'd' move right\n\n'i' Inventory\n\n";
            if (hM == 1) {
                cout << "You drank a small potion\nYour health has increased!\n\n";
                hM = 0;
            } else if (hM == 2) {
                cout << "You drank a medium potion\nYour health has increased!\n\n";
                hM = 0;
            }

            cin >> q;

            rooms[pX][pY].resetEvent();

            if (q == "i") {
                inv.viewItems();
            }

            if (pX < 6 && pY < 7){
                if (q == "s") {
                    if(pX < 5) {
                        event* nextEvent = rooms[pX+1][pY].getEvent();
                        if (nextEvent != nullptr) {
                            if (monster* m = dynamic_cast<monster*>(nextEvent)) {
                                p.decHealth(m->getDmg());
                                m->decHealth(p.getDmg());
                                if (m->getHealth() > 0) {
                                    // don't move
                                } else if (m->getHealth() <= 0) {
                                    move(pX, pY, 0);
                                }
                            } else if (weapon* w = dynamic_cast<weapon*>(nextEvent)) {
                                item* itemPtr = dynamic_cast<item*>(rooms[pX+1][pY].transferEvent());
                                inv.addItems(itemPtr);
                                p.setDmg(w->getDmg());
                                move(pX, pY, 0);
                                
                            } else if (nextEvent == dynamic_cast<stairs*>(nextEvent)) {
                                y = 1;
                                move(pX, pY, 0);
                            } else if (healthCon* h = dynamic_cast<healthCon*>(nextEvent)) {
                                item* itemPtr = dynamic_cast<item*>(rooms[pX+1][pY].transferEvent());
                                inv.addItems(itemPtr);
                                p.incHealth(h->getHeals());
                                move(pX, pY, 0);
                                
                                if (smallHealth* sHea = dynamic_cast<smallHealth*>(h)) {
                                    hM = 1;
                                } else if (medHealth* mHea = dynamic_cast<medHealth*>(h)) {
                                    hM = 2;
                                }
                            } 
                        } else if (nextEvent == nullptr) {
                            move(pX, pY, 0);
                        }
                    }
                }
                if (q == "w") {
                    if(pX > 0) {
                        event* nextEvent = rooms[pX-1][pY].getEvent();
                        if (nextEvent != nullptr) {
                            if (monster* m = dynamic_cast<monster*>(nextEvent)) {
                                p.decHealth(m->getDmg());
                                m->decHealth(p.getDmg());
                                if (m->getHealth() > 0) {
                                    // don't move
                                } else if (m->getHealth() <= 0) {
                                    move(pX, pY, 1);
                                }
                            } else if (weapon* w = dynamic_cast<weapon*>(nextEvent)) {
                                item* itemPtr = dynamic_cast<item*>(rooms[pX-1][pY].transferEvent());
                                inv.addItems(itemPtr);
                                p.setDmg(w->getDmg());
                                move(pX, pY, 1);
                            } else if (nextEvent == dynamic_cast<stairs*>(nextEvent)) {
                                y = 1;
                                move(pX, pY, 1);
                            } else if (healthCon* h = dynamic_cast<healthCon*>(nextEvent)) {
                                item* itemPtr = dynamic_cast<item*>(rooms[pX-1][pY].transferEvent());
                                inv.addItems(itemPtr);
                                p.incHealth(h->getHeals());
                                move(pX, pY, 1);

                                if (smallHealth* sHea = dynamic_cast<smallHealth*>(h)) {
                                    hM = 1;
                                } else if (medHealth* mHea = dynamic_cast<medHealth*>(h)) {
                                    hM = 2;
                                }
                            }
                        } else if (nextEvent == nullptr) {
                            move(pX, pY, 1);
                        }
                    }
                }
                if (q == "a") {
                    if(pY > 0) {
                        event* nextEvent = rooms[pX][pY-1].getEvent();
                        if (nextEvent != nullptr) {
                            if (monster* m = dynamic_cast<monster*>(nextEvent)) {
                                p.decHealth(m->getDmg());
                                m->decHealth(p.getDmg());
                                if (m->getHealth() > 0) {
                                    // don't move
                                } else if (m->getHealth() <= 0) {
                                    move(pX, pY, 2);
                                }
                            } else if (weapon* w = dynamic_cast<weapon*>(nextEvent)) {
                                item* itemPtr = dynamic_cast<item*>(rooms[pX][pY-1].transferEvent());
                                inv.addItems(itemPtr);
                                p.setDmg(w->getDmg());
                                move(pX, pY, 2);
                            } else if (nextEvent == dynamic_cast<stairs*>(nextEvent)) {
                                y = 1;
                                move(pX, pY, 2);
                            } else if (healthCon* h = dynamic_cast<healthCon*>(nextEvent)) {
                                item* itemPtr = dynamic_cast<item*>(rooms[pX][pY-1].transferEvent());
                                inv.addItems(itemPtr);
                                p.incHealth(h->getHeals());
                                move(pX, pY, 2);

                                if (smallHealth* sHea = dynamic_cast<smallHealth*>(h)) {
                                    hM = 1;
                                } else if (medHealth* mHea = dynamic_cast<medHealth*>(h)) {
                                    hM = 2;
                                }
                            }
                        } else if (nextEvent == nullptr) {
                            move(pX, pY, 2);
                        }
                    }
                }
                if (q == "d") {
                    if(pY < 6) {
                        event* nextEvent = rooms[pX][pY+1].getEvent();
                        if (nextEvent != nullptr) {
                            if (monster* m = dynamic_cast<monster*>(nextEvent)) {
                                p.decHealth(m->getDmg());
                                m->decHealth(p.getDmg());
                                if (m->getHealth() > 0) {
                                    // don't move
                                } else if (m->getHealth() <= 0) {
                                    move(pX, pY, 3);
                                }
                            } else if (weapon* w = dynamic_cast<weapon*>(nextEvent)) {
                                item* itemPtr = dynamic_cast<item*>(rooms[pX][pY+1].transferEvent());
                                inv.addItems(itemPtr);
                                p.setDmg(w->getDmg());
                                move(pX, pY, 3);
                            } else if (nextEvent == dynamic_cast<stairs*>(nextEvent)) {
                                y = 1;
                                move(pX, pY, 3);
                            } else if (healthCon* h = dynamic_cast<healthCon*>(nextEvent)) {
                                item* itemPtr = dynamic_cast<item*>(rooms[pX][pY+1].transferEvent());
                                inv.addItems(itemPtr);
                                p.incHealth(h->getHeals());
                                move(pX, pY, 3);

                                if (smallHealth* sHea = dynamic_cast<smallHealth*>(h)) {
                                    hM = 1;
                                } else if (medHealth* mHea = dynamic_cast<medHealth*>(h)) {
                                    hM = 2;
                                }
                            }
                        } else if (nextEvent == nullptr) {
                            move(pX, pY, 3);
                        }
                    }
                }
            } 
        }


    

    }
}