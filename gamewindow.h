#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "player.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(Player & player1, Player & player2, QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    Player & player1;
    Player & player2;
};

#endif // GAMEWINDOW_H
