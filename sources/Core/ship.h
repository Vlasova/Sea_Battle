#ifndef SHIP_H
#define SHIP_H
#include "enums.h"
#include "cell.h"


class Ship{
public:
    Ship();
    Ship(int x, int y, int lenght, shipLine line);
    void setShipStatus();
    shipStatus getShipStatus() const;
    void setShipCells(int x, int y, int lenght, shipLine line);



private:
    int lenght;
    shipStatus status;
    int firstX;
    int firstY;
    Cell* shipCells;



};

#endif // SHIP_H
