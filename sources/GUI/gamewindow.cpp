#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
    game=new GameInterface();
    game->getComputerField()->locateAutomatically();
    game->getUserField()->locateAutomatically();


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
    buttonExit->move(770,390);

    connect(buttonExit, SIGNAL(clicked()), this, SLOT(exit()));

}

void GameWindow::exit()
{
    MainWindow* mainwindow=new MainWindow();
    mainwindow->show();
    this->close();
}

void GameWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    drawFrame(painter, QPoint(USER_FIELD_COORD.x()-30, USER_FIELD_COORD.y()-30));
    drawFrame(painter, QPoint(COMPUTER_FIELD_COORD.x()-30, COMPUTER_FIELD_COORD.y()-30));

    drawUserField(painter);
    drawComputerField(painter);
}

void GameWindow::drawComputerField(QPainter &painter)
{
    painter.drawImage(QPoint(COMPUTER_FIELD_COORD.x()-30,COMPUTER_FIELD_COORD.y()-30), QImage(":/field.jpg"));

    for(int i=0; i<Field::FIELD_SIZE; i++)
        for(int j=0; j<Field::FIELD_SIZE; j++)
        {
            if(game->getComputerField()->getFieldCells()[i][j].getStatus()==cellStatus::blank)
                drawFog(painter, QPoint(COMPUTER_FIELD_COORD.x()+30*j, COMPUTER_FIELD_COORD.y()+30*i));
            if(game->getComputerField()->getFieldCells()[i][j].getStatus()==cellStatus::whole)
                drawFog(painter, QPoint(COMPUTER_FIELD_COORD.x()+30*j, COMPUTER_FIELD_COORD.y()+30*i));
            if(game->getComputerField()->getFieldCells()[i][j].getStatus()==cellStatus::stricken){
                drawDeck(painter, QPoint(COMPUTER_FIELD_COORD.x()+30*j, COMPUTER_FIELD_COORD.y()+30*i));
                drawCross(painter, QPoint(COMPUTER_FIELD_COORD.x()+30*j, COMPUTER_FIELD_COORD.y()+30*i));
            }
            if(game->getComputerField()->getFieldCells()[i][j].getStatus()==cellStatus::tried)
                drawPoint(painter, QPoint(COMPUTER_FIELD_COORD.x()+30*j, COMPUTER_FIELD_COORD.y()+30*i));
        }
}

void GameWindow::drawUserField(QPainter &painter)
{
    painter.drawImage(QPoint(USER_FIELD_COORD.x()-30,USER_FIELD_COORD.y()-30), QImage(":/field.jpg"));

    for (int i=0; i<Field::FIELD_SIZE; i++)
        for (int j=0; j<Field::FIELD_SIZE; j++)
        {
            if(game->getUserField()->getFieldCells()[i][j].getStatus()==cellStatus::whole)
                drawDeck(painter, QPoint(USER_FIELD_COORD.x()+30*j, USER_FIELD_COORD.y()+30*i));
            if(game->getUserField()->getFieldCells()[i][j].getStatus()==cellStatus::stricken){
                drawDeck(painter, QPoint(USER_FIELD_COORD.x()+30*j, USER_FIELD_COORD.y()+30*i));
                drawCross(painter, QPoint(USER_FIELD_COORD.x()+30*j, USER_FIELD_COORD.y()+30*i));
            }
            if(game->getUserField()->getFieldCells()[i][j].getStatus()==cellStatus::tried)
                drawPoint(painter, QPoint(USER_FIELD_COORD.x()+30*j, USER_FIELD_COORD.y()+30*i));
        }
}

void GameWindow::drawFrame(QPainter &painter, const QPoint coord)
{
    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);

    painter.drawLine(coord, QPoint(coord.x()+360,coord.y()));
    painter.drawLine(coord, QPoint(coord.x(), coord.y()+360));
    painter.drawLine((QPoint(coord.x(), coord.y()+360)), QPoint(coord.x()+360, coord.y()+360));
    painter.drawLine(QPoint(coord.x()+360, coord.y()), QPoint(coord.x()+360, coord.y()+360));
}

void GameWindow::drawFog(QPainter &painter, QPoint coord)
{
    painter.drawImage(QPoint(coord.x(), coord.y()), QImage(":/fog.jpg"));
}

void GameWindow::drawDeck(QPainter &painter, QPoint coord)
{
    QBrush brush(QColor(49, 58, 91), Qt::SolidPattern);
    painter.fillRect(coord.x(), coord.y(), 29, 29, brush);
}

void GameWindow::drawCross(QPainter &painter, QPoint coord)
{
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(3);

    painter.setPen(pen);
    painter.drawLine(QPoint(coord.x()+3, coord.y()+3), QPoint(coord.x()+27, coord.y()+27));
    painter.drawLine(QPoint(coord.x()+27, coord.y()+3), QPoint(coord.x()+3, coord.y()+27));
}

void GameWindow::drawPoint(QPainter &painter, QPoint coord)
{
    QPen pen;
    pen.setWidth(8);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);

    painter.drawPoint(QPoint(coord.x()+15, coord.y()+15));
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    if(COMPUTER_FIELD.contains(event->pos()))
    {
        if(onComputerFieldClicked(event->pos()) && !game->getComputerField()->allShipsDestroyed())
            update();
        else{
            if(game->getComputerField()->allShipsDestroyed())
                decideWinner();
            else computerMove();
        }

    }
}


void GameWindow::computerMove()
{
    while(game->makeComputerMove() && !game->getUserField()->allShipsDestroyed())
        update();
    if (game->getUserField()->allShipsDestroyed())
        decideWinner();
    else
        update();

}

bool GameWindow::onComputerFieldClicked(QPoint coord)
{
    int shipNumber;
    if(game->makeUserMove(int((coord.x()-COMPUTER_FIELD_COORD.x())/30), int ((coord.y()-COMPUTER_FIELD_COORD.y())/30)))
    {
        shipNumber=game->getComputerField()->whoseDeck(int((coord.x()-COMPUTER_FIELD_COORD.x())/30), int ((coord.y()-COMPUTER_FIELD_COORD.y())/30));
        if (game->getComputerField()->isShipDestroyed(shipNumber))
           game->getComputerField()->changeCellsAroundShip(game->getComputerField()->getFieldShips()[shipNumber]);
        return true;
    }
    else return false;
}

void GameWindow::ifUserHit(int x, int y)
{
    int shipNumber;
    shipNumber=game->getComputerField()->whoseDeck(x, y);
    if (game->getComputerField()->isShipDestroyed(shipNumber))
        game->getComputerField()->changeCellsAroundShip(game->getComputerField()->getFieldShips()[shipNumber]);
    if (game->getComputerField()->allShipsDestroyed())
        decideWinner();
}

void GameWindow::ifComputerHit()
{
    if (game->getUserField()->allShipsDestroyed())
        decideWinner();
}

void GameWindow::decideWinner()
{
    if(game->getComputerField()->allShipsDestroyed())
    {
            ResultWindow* resultWindow=new ResultWindow(this);
            resultWindow->show();

    }
    if(game->getUserField()->allShipsDestroyed())
    {
            ResultWindow* resultWindow=new ResultWindow(this);
            resultWindow->show();

    }
}







