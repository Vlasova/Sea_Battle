#ifndef SHIP_H
#define SHIP_H
#include "enums.h"
#include "cell.h"


class Ship{
public:
    Ship(int x, int y, int lenght, shipLine line);
    Cell getShipCells() const;


private:
    int lenght;
    shipStatus status;
    Cell firstShipCell;
    Cell shipCells[];



};

#endif // SHIP_H

