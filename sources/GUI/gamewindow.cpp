#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(WINDOW_SIZE);

    QPixmap background(":/game_window_background.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(),QBrush(background));
    this->setPalette(palette);

    QFont font;
    font.setFamily("inpact");
    font.setPointSize(25);
    font.setWeight(75);

    buttonExit=new QPushButton("Exit",this);
    buttonExit->setFont(font);
    buttonExit->setStyleSheet(buttonStyle);
    buttonExit->resize(BUTTON_SIZE);
    buttonExit->move(700,375);

    connect(buttonExit, SIGNAL(clicked()), this, SLOT(exit()));

}

void GameWindow::exit()
{
    MainWindow* mainwindow=new MainWindow();
    mainwindow->show();
    this->close();
}


