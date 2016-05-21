#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap background(":/main_window_background.png");
    QPalette palette;
    palette.setBrush(backgroundRole(),QBrush(background));
    this->setPalette(palette);

    QFont font;
    font.setFamily("Ipact");
    font.setPointSize(25);
    font.setWeight(75);

    ui->buttonStart->setStyleSheet(buttonStyle);
    ui->buttonStart->setFont(font);
    ui->buttonExit->setStyleSheet(buttonStyle);
    ui->buttonExit->setFont(font);


}

MainWindow::~MainWindow()
{
    delete ui;
}
