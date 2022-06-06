#include "player.h"
#include "defines.h"

Player::Player(std::string name) : name(name)
{
    playerGrid = Grid();
}

bool Player::place(class Ship * ship_){
    int orient = ship_->getOrientation(); // 0 - poziom, 1 - pion
    int x_coord = ship_->getX();
    int y_coord = ship_->getY();
    int size = ship_->getSize();
    for(int i = 0; i < size; i++){
        if(orient == 0 && y_coord >= 0 && y_coord < mapSize && x_coord >=0 && x_coord+i<mapSize){
            for(int k = -1; k <= 1; k++){
                for(int g = -1; g <= 1; g++){
                    if(x_coord+i+k >= 0 && x_coord+i+k < mapSize && y_coord+g >= 0 && y_coord+g < mapSize
                            && this->playerGrid.getFieldState(x_coord+i+k, y_coord+g) == Occupied){
                        return false;
                    }
                }
            }
        }else if(orient == 1 && y_coord >= 0 && y_coord+i < mapSize && x_coord >=0 && x_coord<mapSize){
            for(int k = -1; k <= 1; k++){
                for(int g = -1; g <= 1; g++){
                    if(x_coord+k >= 0 && x_coord+k < mapSize && y_coord+i+g >= 0 && y_coord+i+g < mapSize
                            && this->playerGrid.getFieldState(x_coord+k, y_coord+i+g) == Occupied){
                        return false;
                    }
                }
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
