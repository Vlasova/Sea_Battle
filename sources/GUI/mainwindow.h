#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QFont>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:

    const QSize WINDOW_SIZE{900,440};
    const QSize BUTTON_SIZE{130,50};

    QPushButton* buttonExit;
    QPushButton* buttonStart;


    QString buttonStyle=
            "QPushButton"

            "{"
                "border: 1px solid rgb(0, 0, 0);"
                "border-radius: 10px;"

                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(128, 128, 128, 120), stop:1 rgba(225, 225, 225, 120));"
                "color: rgb(25, 25, 25);"                

            "}"
            "QPushButton:pressed"
            "{"
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgb(128, 128, 128), stop:1 rgb(225, 225, 225));"
            "}";

private slots:

    void exit();

};

#endif // MAINWINDOW_H
