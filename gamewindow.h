#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QToolButton>
#include <QHash>
#include <QSignalMapper>
#include "player.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(Player * player1, Player * player2, QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    Player * player1;
    Player * player2;
    Player * currentPlayer;
    QHash<QToolButton*, QPair<int, int>> buttonHash1;
    QHash<QToolButton*, QPair<int, int>> buttonHash2;
    QSignalMapper * signalMapper1;
    QSignalMapper * signalMapper2;
    void updateGrid1();
    void updateGrid2();
public slots:
    void grid1Clicked(QObject*);
    void grid2Clicked(QObject*);
};

#endif // GAMEWINDOW_H
