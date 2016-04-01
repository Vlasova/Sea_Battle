#ifndef SHIP_H
#define SHIP_H
#include "enums.h"
#include "cell.h"


class Ship{
public:
    Ship();
    Ship(int x, int y, int lenght, shipLine line);
    shipStatus getShipStatus();
    void setShipStatus(shipStatus status);



private:
    int lenght;
    shipStatus status;
    Cell* shipCells;



};

#endif // SHIP_H
