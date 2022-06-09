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
        return remainingShips != 0;
    }
    bool allPlaced(){
        return this->ships.size() == 10;
    }
    bool place(class Ship*);
    bool beenCheckedBefore(int, int);
    bool makeAShot(int, int);
    Ship* getShipFromPosition(int, int);
    const std::string getName() const {
        return name;
    }
    GridField getFieldState(int x, int y) {
        return playerGrid.getFieldState(x, y);
    }
private:
    std::string name;
    int remainingShips = 10;
    std::vector<class Ship*> ships;
    Grid playerGrid;
};

#endif // PLAYER_H
