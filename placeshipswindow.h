#ifndef PLACESHIPSWINDOW_H
#define PLACESHIPSWINDOW_H

#include <QDialog>

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
public slots:
    void showGameWindow();
};

#endif // PLACESHIPSWINDOW_H
