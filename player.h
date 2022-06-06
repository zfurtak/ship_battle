#ifndef PLAYER_H
#define PLAYER_H

#include "ship.h"

#include <string>
#include <vector>
using namespace std;

class Player
{
public:
    Player(string);
    void addShip(Ship*);
    bool isAlive() {
        return remainingShips == 0;
    }
private:
    string name;
    int remainingShips = 10;
    vector<Ship*> ships;
};

#endif // PLAYER_H
