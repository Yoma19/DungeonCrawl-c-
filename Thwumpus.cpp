#include <iostream>
#include <vector>

#include "Event.h"
#include "Monster/Zombie.h"
#include "Room.h"
#include "Player.h"
#include "Monster/Skeleton.h"
#include "Weapon/Shortsword.h"

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

int main() {
    int x;
    int y;
    
    while (x != 0) {
        system("cls || clear");
        srand(time(nullptr));

        vector<vector<room>> rooms(6, vector<room>(7));

        player p;
        int pX = rand() % 6;
        int pY = rand() % 7;

        spawnEvent<zombie>((rand() % 4) + 1, rooms);
        spawnEvent<skeleton>((rand() % 4) + 1, rooms);
        spawnEvent<shortsword>(1, rooms);

        //cout<< "Welcome to gettin cooked";

        string q;
        while (q != "l") {
            system("cls || clear");
            rooms[pX][pY].setEvent(&p);

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
            cout<< "\n\nControls:\n'l' Reset\n'w' move up\n's' move down\n'a' move left\n'd' move right\n\n";

            cin >> q;

            rooms[pX][pY].resetEvent();

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
                                    pX = pX + 1;
                                    if (pX > 5) {
                                        pX--;
                                    }
                                }
                            } else if (weapon* w = dynamic_cast<weapon*>(nextEvent)) {
                                p.setDmg(w->getDmg());
                                pX = pX + 1;
                                if (pX > 5) {
                                    pX--;
                                }
                            }
                        } else if (nextEvent == nullptr) {
                            pX = pX + 1;
                            if (pX > 5) {
                                pX--;
                            }
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
                                    pX--;
                                    if (pX < 0) {
                                        pX++;
                                    }
                                }
                            } else if (weapon* w = dynamic_cast<weapon*>(nextEvent)) {
                                p.setDmg(w->getDmg());
                                pX--;
                                if (pX < 0) {
                                    pX++;
                                }
                            }
                        } else if (nextEvent == nullptr) {
                            pX--;
                            if (pX < 0) {
                                pX++;
                            }
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
                                    pY--;
                                    if (pY < 0) {
                                        pY++;
                                    }
                                }
                            } else if (weapon* w = dynamic_cast<weapon*>(nextEvent)) {
                                p.setDmg(w->getDmg());
                                pY--;
                                if (pY < 0) {
                                    pY++;
                                }
                            }
                        } else if (nextEvent == nullptr) {
                            pY--;
                            if (pY < 0) {
                                pY++;
                            }
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
                                    pY++;
                                    if (pY > 6) {
                                        pY--;
                                    }
                                }
                            } else if (weapon* w = dynamic_cast<weapon*>(nextEvent)) {
                                p.setDmg(w->getDmg());
                                pY++;
                                if (pY > 6) {
                                    pY--;
                                }
                            }
                        } else if (nextEvent == nullptr) {
                            pY++;
                            if (pY > 6) {
                                pY--;
                            }
                        }
                    }
                }
            } 
        }


    

    }
}