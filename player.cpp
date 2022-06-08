#include "player.h"
#include "defines.h"

Player::Player(std::string name) : name(name)
{
    playerGrid = Grid();
}

bool Player::place(class Ship * ship_){
    int orient = ship_->getOrientation(); // 0 - poziom, 1 - pion
    int row = ship_->getX();
    int col = ship_->getY();
    int size = ship_->getSize();
    for(int i = 0; i < size; i++){
        if(orient == 1){
            if(col >= 0 && col < mapSize && row+i >=0 && row+i < mapSize){
                for(int k = -1; k <= 1; k++){
                    for(int g = -1; g <= 1; g++){
                        if(row+i+k >= 0 && row+i+k < mapSize && col+g >= 0 && col+g < mapSize
                                && this->playerGrid.getFieldState(row+i+k, col+g) == Occupied){
                            return false;
                        }
                    }
                }
            }else{
                return false;
            }
        }else if(orient == 0){
            if(col + i >= 0 && col+i < mapSize && row >=0 && row<mapSize){
                for(int k = -1; k <= 1; k++){
                    for(int g = -1; g <= 1; g++){
                        if(row+k >= 0 && row+k < mapSize && col+i+g >= 0 && col+i+g < mapSize
                                && this->playerGrid.getFieldState(row+k, col+i+g) == Occupied){
                            return false;
                        }
                    }
                }
            }else{
                return false;
            }
        }
    }
    // umieszczanie statku w wektorze i na gridzie
    this->ships.push_back(ship_);
    this->playerGrid.placeShip(ship_);

    if(orient == 0 || orient == 1){
        return true;
    }
    return false;
}

bool Player::beenCheckedBefore(int x, int y){
    return this->playerGrid.getFieldState(x, y) == CheckedFree ||
            this->playerGrid.getFieldState(x, y) == HitShip;
}

bool Player::makeAShot(int x, int y){
    if(!this->beenCheckedBefore(x, y)){
        if(this->playerGrid.getFieldState(x, y) == Occupied){
            this->playerGrid.markShipAsHit(x, y);
        }else if(this->playerGrid.getFieldState(x, y) == Empty){
            this->playerGrid.markSpotAsChecked(x, y);
        }
        return true;
    }
    return false;
}
