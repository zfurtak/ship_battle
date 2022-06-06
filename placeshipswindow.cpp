#include "placeshipswindow.h"
#include "ui_placeshipswindow.h"
#include "gamewindow.h"
#include <QToolButton>

PlaceShipsWindow::PlaceShipsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaceShipsWindow)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    QGridLayout * grid = ui->gridLayout_2;


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            QToolButton * button = new QToolButton(this);
            button->setText("");
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setMaximumHeight(40);
            button->setMaximumWidth(40);
            button->setStyleSheet("background-color: blue");
            grid->addWidget(button, i, j);
        }
    }

    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(showGameWindow()));
}

PlaceShipsWindow::~PlaceShipsWindow()
{
    delete ui;
}

void PlaceShipsWindow::showGameWindow() {
    GameWindow gameWindow;
    gameWindow.setModal(false);
    hide();
    gameWindow.exec();
}
