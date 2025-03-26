#include <iostream>
#include <vector>

#include "Event.h"
#include "Zombie.h"
#include "Room.h"
#include "Player.h"
#include "Skeleton.h"

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
            cout<< "\n\nControls:\n'l' Reset\n'w' move up\n's' move down\n'a' move left\n'd' move right\n\n";

            cin >> q;

            rooms[pX][pY].resetEvent();

            if (pX < 6 && pY < 7){
                if (q == "s") {
                    if(pX < 5) {
                        if (rooms[pX+1][pY].getEvent() != nullptr) {
                            p.decHealth(rooms[pX+1][pY].getEvent()->getDmg());
                        }
                    }

                    pX = pX + 1;
                    if (pX > 5) {
                        pX--;
                    }
                }
                if (q == "w") {
                    if(pX > 0) {
                        if (rooms[pX-1][pY].getEvent() != nullptr) {
                            p.decHealth(rooms[pX-1][pY].getEvent()->getDmg());
                        }
                    }


                    pX--;
                    if (pX < 0) {
                        pX++;
                    }
                }
                if (q == "a") {
                    if(pY > 0) {
                        if (rooms[pX][pY-1].getEvent() != nullptr) {
                            p.decHealth(rooms[pX][pY-1].getEvent()->getDmg());
                        }
                    }

                    pY--;
                    if (pY < 0) {
                        pY++;
                    }
                }
                if (q == "d") {
                    if(pY < 6) {
                        if (rooms[pX][pY+1].getEvent() != nullptr) {
                            p.decHealth(rooms[pX][pY+1].getEvent()->getDmg());
                        }
                    }

                    pY++;
                    if (pY > 6) {
                        pY--;
                    }
                }
            } 
        }


    

    }
}