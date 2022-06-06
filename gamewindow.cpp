#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QToolButton>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);

    QGridLayout * grid1 = ui->gridLayout_4;
    QGridLayout * grid2 = ui->gridLayout_5;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            QToolButton * button1 = new QToolButton(this);
            button1->setText("");
            button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button1->setMaximumHeight(40);
            button1->setMaximumWidth(40);
            button1->setStyleSheet("background-color: blue");
            grid1->addWidget(button1, i, j);

            QToolButton * button2 = new QToolButton(this);
            button2->setText("");
            button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button2->setMaximumHeight(40);
            button2->setMaximumWidth(40);
            button2->setStyleSheet("background-color: blue");
            grid2->addWidget(button2, i, j);
        }
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}
