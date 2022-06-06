#include "player.h"

Player::Player(string name) : name(name)
{}

void Player::addShip(Ship * newShip) {
    ships.push_back(newShip);
}
