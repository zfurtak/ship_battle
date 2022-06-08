#include "grid.h"
#include <iostream>

Grid::Grid()
{
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            grid[i][j] = Empty;
        }
    }
}

void Grid::placeShip(class Ship * newShip) {
    //wchodząc do tej funkcji mamy pewnosc ze statek sie da polozyc
    int orient = newShip->getOrientation(); // 0 - poziom, 1 - pion
    int x_coord = newShip->getX();
    int y_coord = newShip->getY();
    int size = newShip->getSize();
    for(int i = 0; i < size; i++){
        if(orient == 1){
            grid[x_coord+i][y_coord] = Occupied;
        }else if(orient == 0){
            grid[x_coord][y_coord+i] = Occupied;
        }
    }
}



void Grid::sinkWholeShip(Ship * ship){
    std::cout << "sinking whole" << std::endl;
    int x = ship->getX();
    int y = ship->getY();
    int orient = ship->getOrientation();
    int size = ship->getSize();
    for(int i = 0; i < size; i++){
        int col = y;
        int row = x;
        if(orient == 0){
            col = y + i;
        }else if(orient == 1){
            row = x + i;
        }
        for(int p = -1; p <= 1; p++){
            for(int k = -1; k <=1; k++){
                if(col+p >= 0 && col+p < mapSize && row+k >= 0 && row+k < mapSize
                        && grid[row+k][col+p] == Empty){
                    grid[row+k][col+p] = CheckedFree;
                }
            }
        }
    }
}

void Grid::markShipAsHit(int x, int y){
    grid[x][y] = HitShip;
}

void Grid::markSpotAsChecked(int x, int y){
    grid[x][y] = CheckedFree;
}
