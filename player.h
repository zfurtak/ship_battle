#ifndef PLAYER_H
#define PLAYER_H

#include "ship.h"
#include "grid.h"

#include <string>
#include <vector>

class Player
{
public:
    Player(std::string);
    bool isAlive() {
        return remainingShips == 0;
    }
    bool place(class Ship*);
    bool beenCheckedBefore(int, int);
    bool makeAShot(int, int);
private:
    std::string name;
    int remainingShips = 10;
    std::vector<class Ship*> ships;
    Grid playerGrid;
};

#endif // PLAYER_H
