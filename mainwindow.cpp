#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "placeshipswindow.h"
#include "player.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton * submit = ui->pushButton;
    connect(submit, SIGNAL(clicked()), this, SLOT(showPlaceShips()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::showPlaceShips() {
    Player player1 = Player(ui->username->text().toStdString());
    Player player2 = Player(ui->username_2->text().toStdString());
    PlaceShipsWindow placeShipsWindow(&player1, &player2);
    placeShipsWindow.setModal(true);
    hide();
    placeShipsWindow.exec();
}
