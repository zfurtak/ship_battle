#include "placeshipswindow.h"
#include "ui_placeshipswindow.h"
#include "gamewindow.h"
#include "defines.h"
#include <QToolButton>
#include <iostream>
#include <QPair>
#include <QSignalMapper>

PlaceShipsWindow::PlaceShipsWindow(Player & player1, Player & player2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaceShipsWindow),
    player1(player1),
    player2(player2),
    currentPlayer(player1)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    QGridLayout * grid = ui->gridLayout_2;
    QSignalMapper * signalMapper = new QSignalMapper(this);
    ui->label->setText(QString(" Układa gracz ") + QString::fromStdString(currentPlayer.getName()));

    ui->ship_1_label->setText(QString::number(ship1ToPlaced));
    ui->ship_2_label->setText(QString::number(ship2ToPlaced));
    ui->ship_3_label->setText(QString::number(ship3ToPlaced));
    ui->ship_4_label->setText(QString::number(ship4ToPlaced));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            QToolButton * button = new QToolButton(this);
            QPair<int ,int> gridPair(i, j);
            buttonHash.insert(button, gridPair);
            button->setText("");
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setMaximumHeight(40);
            button->setMaximumWidth(40);
            button->setStyleSheet("background-color: gray");
            grid->addWidget(button, i, j);

            connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(button, qobject_cast<QObject*>(button));
        }
    }

    connect(signalMapper, SIGNAL(mappedObject(QObject*)), this, SLOT(gridClicked(QObject*)));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(showGameWindow()));
    connect(ui->ship_1_button, SIGNAL(clicked()), this, SLOT(changeShipTo1()));
    connect(ui->ship_2_button, SIGNAL(clicked()), this, SLOT(changeShipTo2()));
    connect(ui->ship_3_button, SIGNAL(clicked()), this, SLOT(changeShipTo3()));
    connect(ui->ship_4_button, SIGNAL(clicked()), this, SLOT(changeShipTo4()));
    connect(ui->change_orientation, SIGNAL(clicked()), this, SLOT(changeOrientation()));
}

PlaceShipsWindow::~PlaceShipsWindow()
{
//    delete signalMapper;
    delete ui;
    for (auto button : buttonHash.keys()) {
        delete button;
    }
}

void PlaceShipsWindow::showGameWindow() {
    if (&currentPlayer != &player2) {
        currentPlayer = player2;
        ui->label->setText(QString(" Układa gracz ") + QString::fromStdString(currentPlayer.getName()));
        updateGrid();
        shipSize1[0] = Ship(1, -1, -1, 0);
        shipSize1[1] = Ship(1, -1, -1, 0);
        shipSize1[2] = Ship(1, -1, -1, 0);
        shipSize1[3] = Ship(1, -1, -1, 0);

        shipSize2[0] = Ship(2, -1, -1, 0);
        shipSize2[1] = Ship(2, -1, -1, 0);
        shipSize2[2] = Ship(2, -1, -1, 0);

        shipSize3[0] = Ship(3, -1, -1, 0);
        shipSize3[1] = Ship(3, -1, -1, 0);

        shipSize4[0] = Ship(4, -1, -1, 0);

        ship1ToPlaced = 4;
        ship2ToPlaced = 3;
        ship3ToPlaced = 2;
        ship3ToPlaced = 1;
        ui->ship_1_label->setText(QString::number(ship1ToPlaced));
        ui->ship_2_label->setText(QString::number(ship2ToPlaced));
        ui->ship_3_label->setText(QString::number(ship3ToPlaced));
        ui->ship_4_label->setText(QString::number(ship4ToPlaced));
        return;
    }
    GameWindow gameWindow = GameWindow(player1, player2);
    gameWindow.setModal(true);
    hide();
    gameWindow.exec();
}

void PlaceShipsWindow::gridClicked(QObject * widget) {
    QPair<int, int> pair = buttonHash.value(qobject_cast<QToolButton*>(widget));
    if (currentShip == nullptr) {
        return;
    }

    currentShip->setPosition(pair.first, pair.second);

    if (currentPlayer.place(currentShip)) {
        resetButtonColors();
        switch(currentShip->getSize()) {
        case 1:
            ship1ToPlaced--;
            ui->ship_1_label->setText(QString::number(ship1ToPlaced));
            currentShip = nullptr;
            break;
        case 2:
            ship2ToPlaced--;
            ui->ship_2_label->setText(QString::number(ship2ToPlaced));
            currentShip = nullptr;
            break;
        case 3:
            ship3ToPlaced--;
            ui->ship_3_label->setText(QString::number(ship3ToPlaced));
            currentShip = nullptr;
            break;
        case 4:
            ship4ToPlaced--;
            ui->ship_4_label->setText(QString::number(ship4ToPlaced));
            currentShip = nullptr;
            break;
        default:
            return;
        }

        updateGrid();
    }
}

void PlaceShipsWindow::updateGrid() {
    QHashIterator<QToolButton*, QPair<int, int>> i(buttonHash);
    while (i.hasNext()) {
        i.next();
        int x = i.value().first;
        int y = i.value().second;
        switch(currentPlayer.getFieldState(x, y)) {
        case Empty:
            i.key()->setStyleSheet("background-color: gray");
            break;
        case Occupied:
            i.key()->setStyleSheet("background-color: yellow");
            break;
        default:
            return;
        }
    }
}

void PlaceShipsWindow::changeShipTo1(){
    if (ship1ToPlaced > 0) {
        resetButtonColors();
        ui->ship_1_button->setStyleSheet("background-color: blue");
        currentShip = &shipSize1[ship1ToPlaced - 1];
    }
}

void PlaceShipsWindow::changeShipTo2(){
    if (ship2ToPlaced > 0) {
        resetButtonColors();
        ui->ship_2_button->setStyleSheet("background-color: blue");
        currentShip = &shipSize2[ship2ToPlaced - 1];
    }
}

void PlaceShipsWindow::changeShipTo3(){
    if (ship3ToPlaced > 0) {
        resetButtonColors();
        ui->ship_3_button->setStyleSheet("background-color: blue");
        currentShip = &shipSize3[ship3ToPlaced - 1];
    }
}

void PlaceShipsWindow::changeShipTo4(){
    if (ship4ToPlaced > 0) {
        resetButtonColors();
        ui->ship_4_button->setStyleSheet("background-color: blue");
        currentShip = &shipSize4[ship4ToPlaced - 1];
    }
}

void PlaceShipsWindow::changeOrientation() {
    std::cout << currentShip << std::endl;
    if (currentShip != nullptr) {
        currentShip->changeOrientation();
        if (currentShip->getOrientation() == 0) {
            ui->change_orientation->setText("Poziom");
        }
        else {
            ui->change_orientation->setText("Pion");
        }
    }
}

void PlaceShipsWindow::resetButtonColors() {
    ui->ship_1_button->setStyleSheet("");
    ui->ship_2_button->setStyleSheet("");
    ui->ship_3_button->setStyleSheet("");
    ui->ship_4_button->setStyleSheet("");
}
