#include "grid.h"

Grid::Grid()
{
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            grid[i][j] = Empty;
        }
    }
}

bool Grid::placeShip(class Ship& newShip) {
    // TODO
    return false;
}
