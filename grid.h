#ifndef GRID_H
#define GRID_H

#include "defines.h"
#include "ship.h"

class Grid
{
public:
    Grid();
    GridField getFieldState(int x, int y) {
        return grid[x][y];
    }

    bool placeShip(class Ship&);
private:
    GridField grid[mapSize][mapSize];
};

#endif // GRID_H
