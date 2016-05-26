#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QFont>
#include <QPainter>


#include "mainwindow.h"
#include "game.h"

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent);


private:
    const QSize WINDOW_SIZE{900,440};
    const QSize BUTTON_SIZE{120,45};
    const QSize FIELD_SIZE{350, 350};
    const QSize CELL_SIZE{23,23};
    const QPoint USER_FIELD_COORD{30,20};
    const QPoint COMPUTER_FIELD_COORD{450,20};

    QPushButton* buttonExit;

    GameInterface* game;

    QString buttonStyle=
            "QPushButton"

            "{"
                "border: 1.5px solid rgb(0, 0, 0);"
                "border-radius: 10px;"

                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(128, 128, 128, 160), stop:1 rgba(225, 225, 225, 160));"
                "color: rgb(25, 25, 25);"

            "}"
            "QPushButton:pressed"
            "{"
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(128, 128, 128), stop:1 rgb(225, 225, 225));"
            "}";

private:
    void drawGameFields(QPainter& painter, const QPoint coord);
    void drawUserField(QPainter& painter);
    void drawComputerGield(QPainter& painter);
    void paintEvent(QPaintEvent*);
    void drawFrame(QPainter& painter, const QPoint coord);
    void drawDeck(QPainter& painter, QPoint coord);
    void drawFog(QPainter& painter, QPoint coord);
    void drawPoint(QPainter& painter, QPoint coord);
    void drawCross(QPainter&painter, QPoint coord);

private slots:

    void exit();



};

#endif // GAMEWINDOW_H

