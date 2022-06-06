#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "placeshipswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton * submit = ui->pushButton;
    connect(submit, SIGNAL(clicked()), this, SLOT(showPlaceShips()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showPlaceShips() {
    PlaceShipsWindow placeShipsWindow;
    placeShipsWindow.setModal(false);
    hide();
    placeShipsWindow.exec();
}
