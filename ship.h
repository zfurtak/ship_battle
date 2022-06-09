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
    int getHitCounter(){
        return this->hitCounter;
    }

    bool isSunk() {
        return hitCounter == size;
    }
    void increaseHitCounter(){
        this->hitCounter ++;
    }
    void setPosition(int, int);
    void changeOrientation();
    bool isIncluded(int, int);

private:
    int size;
    int hitCounter = 0;
    int x, y;
    int orientation;  // 0 - poziom, 1 - pion
};

#endif // SHIP_H
