#include "resultwindow.h"

ResultWindow::ResultWindow(QWidget* parent): QDialog(parent), parent(parent)
{
    this->setFixedSize(WINDOW_SIZE);

    QPixmap background(":/game_window_background.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(),QBrush(background));
    this->setPalette(palette);

    QFont font1;
    font1.setFamily("inpact");
    font1.setPointSize(25);
    font1.setWeight(75);

    QFont font2;
    font2.setFamily("inpact");
    font2.setPointSize(40);
    font2.setWeight(75);

    QLabel* labelWinner=new QLabel(this);
    labelWinner->setFont(font2);
    labelWinner->setText("You win!");
    labelWinner->move(120, 50);
    labelWinner->show();

    QLabel* labelAgain=new QLabel(this);
    labelAgain->setFont(font1);
    labelAgain->setText("Do you want to play again?");
    labelAgain->move(30, 120);
    labelWinner->show();

    buttonYes=new QPushButton("Yes", this);
    buttonYes->setFont(font1);
    buttonYes->setStyleSheet(buttonStyle);
    buttonYes->resize(BUTTON_SIZE);
    buttonYes->move(100, 200);

    buttonNo=new QPushButton("No", this);
    buttonNo->setFont(font1);
    buttonNo->setStyleSheet(buttonStyle);
    buttonNo->resize(BUTTON_SIZE);
    buttonNo->move(250, 200);

    connect(buttonNo, SIGNAL(clicked()), this, SLOT(exit()));
    connect(buttonYes, SIGNAL(clicked()), this, SLOT(again()));

}

void ResultWindow::exit()
{
    MainWindow* mainwindow=new MainWindow();
    mainwindow->show();
    this->close();
    this->parent->close();
}

void ResultWindow::again()
{
    GameWindow* gameWindow=new GameWindow(0);
    gameWindow->show();
    this->close();
    this->parent->close();
}

