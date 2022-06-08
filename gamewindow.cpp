#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "defines.h"
#include <QToolButton>
#include <iostream>

GameWindow::GameWindow(Player * player1, Player * player2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow),
    player1(player1),
    player2(player2),
    currentPlayer(player1)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);

    QGridLayout * grid1 = ui->player_1_grid;
    QGridLayout * grid2 = ui->player_2_grid;
    signalMapper1 = new QSignalMapper(this);
    signalMapper2 = new QSignalMapper(this);
    ui->turn_label->setText(QString(" Tura gracza ") + QString::fromStdString(player1->getName()));
    ui->player_1_label->setText(QString("Gracz ") + QString::fromStdString(player1->getName()));
    ui->player_2_label->setText(QString("Gracz ") + QString::fromStdString(player2->getName()));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            QToolButton * button1 = new QToolButton(this);
            QPair<int ,int> gridPair1(i, j);
            buttonHash1.insert(button1, gridPair1);
            button1->setText("");
            button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button1->setMaximumHeight(40);
            button1->setMaximumWidth(40);
            button1->setStyleSheet("");
            grid1->addWidget(button1, i, j);

            connect(button1, SIGNAL(clicked()), signalMapper1, SLOT(map()));
            signalMapper1->setMapping(button1, qobject_cast<QObject*>(button1));

            QToolButton * button2 = new QToolButton(this);
            QPair<int ,int> gridPair2(i, j);
            buttonHash2.insert(button2, gridPair2);
            button2->setText("");
            button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button2->setMaximumHeight(40);
            button2->setMaximumWidth(40);
            button2->setStyleSheet("");
            grid2->addWidget(button2, i, j);

            connect(button2, SIGNAL(clicked()), signalMapper2, SLOT(map()));
            signalMapper2->setMapping(button2, qobject_cast<QObject*>(button2));
        }
    }

    connect(signalMapper1, SIGNAL(mappedObject(QObject*)), this, SLOT(grid1Clicked(QObject*)));
    connect(signalMapper2, SIGNAL(mappedObject(QObject*)), this, SLOT(grid2Clicked(QObject*)));
}

GameWindow::~GameWindow()
{
    delete ui;
    for (auto button : buttonHash1.keys()) {
        delete button;
    }

    for (auto button : buttonHash2.keys()) {
        delete button;
    }

    delete signalMapper1;
    delete signalMapper2;
}

void GameWindow::grid1Clicked(QObject * widget) {
    QPair<int, int> pair = buttonHash1.value(qobject_cast<QToolButton*>(widget));
    if (currentPlayer != player1) {
        return;
    }

    if (player2->makeAShot(pair.first, pair.second)) {
        std::cout << "test1" << std::endl;
        updateGrid1();
        if (player2->getFieldState(pair.first, pair.second) != HitShip) {
            currentPlayer = player2;
            ui->turn_label->setText(QString(" Tura gracza ") + QString::fromStdString(currentPlayer->getName()));
        }
    }
}

void GameWindow::grid2Clicked(QObject * widget) {
    QPair<int, int> pair = buttonHash2.value(qobject_cast<QToolButton*>(widget));
    if (currentPlayer != player2) {
        return;
    }

    if (player1->makeAShot(pair.first, pair.second)) {
        std::cout << "test2" << std::endl;
        updateGrid2();
        if (player1->getFieldState(pair.first, pair.second) != HitShip) {
            currentPlayer = player1;
            ui->turn_label->setText(QString(" Tura gracza ") + QString::fromStdString(currentPlayer->getName()));
        }
    }
}

void GameWindow::updateGrid1() {
    QHashIterator<QToolButton*, QPair<int, int>> i(buttonHash1);
    while (i.hasNext()) {
        i.next();
        int x = i.value().first;
        int y = i.value().second;
        switch(player2->getFieldState(x, y)) {
        case CheckedFree:
            i.key()->setStyleSheet("background-color: #83d7ee");
            break;
        case HitShip:
            i.key()->setStyleSheet("background-color: #7B3F00");
            break;
        default:
            i.key()->setStyleSheet("");
        }
    }
}

void GameWindow::updateGrid2() {
    QHashIterator<QToolButton*, QPair<int, int>> i(buttonHash2);
    while (i.hasNext()) {
        i.next();
        int x = i.value().first;
        int y = i.value().second;
        switch(player1->getFieldState(x, y)) {
        case CheckedFree:
            i.key()->setStyleSheet("background-color: #83d7ee");
            break;
        case HitShip:
            i.key()->setStyleSheet("background-color: #7B3F00");
            break;
        default:
            i.key()->setStyleSheet("");
        }
    }
}
