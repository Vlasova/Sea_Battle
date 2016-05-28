#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>

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

    const QPoint USER_FIELD_COORD{60,50};
    const QRect USER_FIELD{USER_FIELD_COORD, QPoint(USER_FIELD_COORD.x()+FIELD_SIZE.width(), USER_FIELD_COORD.y()+FIELD_SIZE.height())};
    const QSize FIELD_SIZE{350, 350};
    const QPoint COMPUTER_FIELD_COORD{480,50};
    const QRect COMPUTER_FIELD{COMPUTER_FIELD_COORD, QPoint(COMPUTER_FIELD_COORD.x()+FIELD_SIZE.width(), COMPUTER_FIELD_COORD.y()+FIELD_SIZE.height())};


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

    void drawUserField(QPainter& painter);
    void drawComputerField(QPainter& painter);
    void drawFrame(QPainter& painter, const QPoint coord);
    void drawDeck(QPainter& painter, QPoint coord);
    void drawPoint(QPainter& painter, QPoint coord);
    void drawCross(QPainter&painter, QPoint coord);
    void drawFog(QPainter& painter, QPoint coord);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent* event);
    void onComputerFieldClicked(QPoint coord);




private slots:

    void exit();



};

#endif // GAMEWINDOW_H

