#ifndef PLACESHIPSWINDOW_H
#define PLACESHIPSWINDOW_H

#include <QDialog>
#include <QToolButton>
#include <QHash>
#include <QSignalMapper>

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
    QHash<QToolButton*, QPair<int, int>> buttonHash;
    QSignalMapper * signalMapper;
public slots:
    void showGameWindow();
    void buttonClicked(QObject*);
};

#endif // PLACESHIPSWINDOW_H
