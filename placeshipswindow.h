#ifndef PLACESHIPSWINDOW_H
#define PLACESHIPSWINDOW_H

#include <QDialog>
#include <QToolButton>
#include <QHash>
#include <QSignalMapper>
#include "player.h"
#include "ship.h"

namespace Ui {
class PlaceShipsWindow;
}

class PlaceShipsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlaceShipsWindow(Player * player1, Player * player2, QWidget *parent = nullptr);
    ~PlaceShipsWindow();

private:
    Ui::PlaceShipsWindow *ui;
    QHash<QToolButton*, QPair<int, int>> buttonHash;
    QSignalMapper * signalMapper;
    Ship shipSize1[4] = {Ship(1, -1, -1, 0), Ship(1, -1, -1, 0), Ship(1, -1, -1, 0), Ship(1, -1, -1, 0)};
    Ship shipSize2[3] = {Ship(2, -1, -1, 0), Ship(2, -1, -1, 0), Ship(2, -1, -1, 0)};
    Ship shipSize3[2] = {Ship(3, -1, -1, 0), Ship(3, -1, -1, 0)};
    Ship shipSize4[1] = {Ship(4, -1, -1, 0)};
    Ship * currentShip = nullptr;
    int ship1ToPlaced = 4;
    int ship2ToPlaced = 3;
    int ship3ToPlaced = 2;
    int ship4ToPlaced = 1;
    Player * player1;
    Player * player2;
    Player * currentPlayer;

    void updateGrid();
    void resetButtonColors();
public slots:
    void showGameWindow();
    void gridClicked(QObject*);
    void changeShipTo1();
    void changeShipTo2();
    void changeShipTo3();
    void changeShipTo4();
    void changeOrientation();
};

#endif // PLACESHIPSWINDOW_H
