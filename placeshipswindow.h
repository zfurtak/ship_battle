#ifndef PLACESHIPSWINDOW_H
#define PLACESHIPSWINDOW_H

#include <QDialog>
#include "ship.h"
namespace Ui {
class PlaceShipsWindow;
}

class PlaceShipsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlaceShipsWindow(QWidget *parent = nullptr);
    ~PlaceShipsWindow();

private:
    Ui::PlaceShipsWindow *ui;
    Ship shipSize1[4] = {Ship(1, -1, -1, 0), Ship(1, -1, -1, 0), Ship(1, -1, -1, 0), Ship(1, -1, -1, 0)};
    Ship shipSize2[3] = {Ship(2, -1, -1, 0), Ship(2, -1, -1, 0), Ship(2, -1, -1, 0)};
    Ship shipSize3[2] = {Ship(3, -1, -1, 0), Ship(3, -1, -1, 0)};
    Ship shipSize4[1] = {Ship(4, -1, -1, 0)};
    int ship1ToPlaced = 4;
    int ship2ToPlaced = 3;
    int ship3ToPlaced = 2;
    int ship4ToPlaced = 1;
public slots:
    void showGameWindow();
};

#endif // PLACESHIPSWINDOW_H
