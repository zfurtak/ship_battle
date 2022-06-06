#include "player.h"

Player::Player(std::string name) : name(name)
{
    playerGrid = Grid();
}

void Player::addShip(class Ship * newShip) {
    ships.push_back(newShip);
}
