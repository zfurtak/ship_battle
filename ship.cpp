#include "ship.h"

Ship::Ship(int size, int x, int y, int orientation)
{
    this->size = size;
    parts = new bool[size];
    for (int i = 0; i < size; i++) {
        parts[i] = 0;
    }

    this->orientation = orientation;
    this->x = x;
    this->y = y;
}

bool Ship::isIncluded(int x, int y) {
    if (orientation == 1 && x - this->x >= 0 && x - this->x < size && y == this->y) {
        return true;
    }
    if (orientation == 0 && y - this->y >= 0 && y - this->y < size && x == this->x) {
        return true;
    }
    return false;
}



void Ship::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Ship::changeOrientation() {
    if (orientation == 0) {
        orientation = 1;
    }
    else {
        orientation = 0;
    }
}

