#ifndef CELL_H
#define CELL_H
#include "enums.h"


class Cell{

public:
    Cell();
    Cell(int x, int y);
    void setX(int x);
    void setY(int y);
    void setStatus(cellStatus status);
    cellStatus getStatus() const;
    int getX() const;
    int getY() const;

private:
    int x, y;
    cellStatus status;

};

#endif // CELL_H

