#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)

{
    this->setFixedSize(WINDOW_SIZE);
    QPixmap background(":/main_window_background.png");
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
    buttonExit->move(370,250);

    connect(buttonExit, SIGNAL(clicked()), this, SLOT(exit()));

}

 void MainWindow::exit()
{
    this->close();
}


