#ifndef SHIP_H
#define SHIP_H
#include "enums.h"
#include "cell.h"

class Ship{
public:
    Ship();
    void setShipStatus();
    shipStatus getShipStatus() const;
    void setShipCells(int firstX, int firstY, int lenght, shipLine line);
    Cell* getShipCells() const;
    ~Ship();


private:
    int lenght;
    shipStatus status;
    int firstX;
    int firstY;
    Cell* shipCells;
    shipLine line;

};

#endif // SHIP_H
