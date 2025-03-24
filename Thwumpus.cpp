#include <iostream>
#include <vector>

#include "Event.h"
#include "Zombie.h"
#include "Room.h"
#include "Player.h"

#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int x;
    int y;
    
        while (x != 0) {
            system("cls || clear");
        /* system("cls || clear");
        cout<< "yoma was heir\n";
        cin >> x;  */

        //vector<char> vec(10, 'r');

            zombie z;
            int width;
            int height = 10;
            srand(time(nullptr));

            vector<vector<room>> rooms(6, vector<room>(7));
        //rooms[3][3].setEvent(new zombie);

        player p;
        int pX = rand() % 6;
        int pY = rand() % 7;
        p.setLocationX(pX);
        p.setLocationY(pY);

        rooms[pX][pY].setEvent(&p);

        for (int i = 0; i < 3; i++) {
            int x = rand() % 6;
            int y = rand() % 7;

            while (rooms[x][y].getEvent() != nullptr) {
                x = rand() % 6;
                y = rand() % 7;
            }
            
            //rooms[x][y].setLocationX(x);
            //rooms[x][y].setLocationX(y);
            rooms[x][y].setEvent(new zombie);
        } 

        char q;
        while (q != 'l') {
            system("cls || clear");

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
                
                        //cout<< rand() % 2;
                    cout<< " |";
                
                }
            } 
            cout<< "\n====================================\n";

            cout<< "\nControls:\n'l' Exit\n'w' move up\n's' move down\n'a' move left\n'd' move right\n\n";

            cin >> q;
        }
    

    }
}