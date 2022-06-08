#ifndef SHIP_H
#define SHIP_H


class Ship
{
public:
    explicit Ship(int, int, int, int=0);
    int getSize() {
        return size;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getOrientation() {
        return orientation;
    }

    bool isSunk() {
        return hitCounter == size;
    }

    bool hit(int, int);
    void setPosition(int, int);
    void changeOrientation();
private:
    int size;
    int hitCounter = 0;
    int x, y;
    int orientation;  // 0 - poziom, 1 - pion
    bool * parts;
};

#endif // SHIP_H
