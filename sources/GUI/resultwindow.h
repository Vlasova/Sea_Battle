#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QtWidgets>
#include "mainwindow.h"
#include "gamewindow.h"

class ResultWindow : public QDialog
{
    Q_OBJECT
public:
    ResultWindow(QWidget* parent);

private:
    const QSize WINDOW_SIZE{500, 300};
    const QSize BUTTON_SIZE{120, 45};

    QPushButton* buttonYes;
    QPushButton* buttonNo;

    QWidget* parent;

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
private slots:
    void again();
    void exit();
};

#endif // RESULTWINDOW_H

