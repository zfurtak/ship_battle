#include "placeshipswindow.h"
#include "ui_placeshipswindow.h"
#include "gamewindow.h"
#include <QToolButton>
#include <iostream>
#include <QPair>
#include <QSignalMapper>

PlaceShipsWindow::PlaceShipsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaceShipsWindow)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    QGridLayout * grid = ui->gridLayout_2;
    QSignalMapper * signalMapper = new QSignalMapper();


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            QToolButton * button = new QToolButton(this);
            QPair<int ,int> gridPair(i, j);
            buttonHash.insert(button, gridPair);
            button->setText("");
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setMaximumHeight(40);
            button->setMaximumWidth(40);
            button->setStyleSheet("background-color: blue");
            grid->addWidget(button, i, j);

            connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(button, qobject_cast<QObject*>(button));
        }
    }

    connect(signalMapper, SIGNAL(mappedObject(QObject*)), this, SLOT(buttonClicked(QObject*)));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(showGameWindow()));
}

PlaceShipsWindow::~PlaceShipsWindow()
{
    delete ui;
    for (auto button : buttonHash.keys()) {
        delete button;
    }
    delete signalMapper;
}

void PlaceShipsWindow::showGameWindow() {
    GameWindow gameWindow;
    gameWindow.setModal(true);
    hide();
    gameWindow.exec();
}

void PlaceShipsWindow::buttonClicked(QObject * widget) {
    QPair<int, int> pair = buttonHash.value(qobject_cast<QToolButton*>(widget));
    std::cout << pair.first << " and " << pair.second << std::endl;
}
