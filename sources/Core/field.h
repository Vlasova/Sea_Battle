#ifndef FIELD_H
#define FIELD_H
#include "enums.h"
#include "cell.h"
#include "ship.h"



class Field{

public:
    Field();
    cellStatus getCellStatus(int x, int y) const;
    shipStatus getShipStatus(int x, int y) const;
    void setCellStatus(int x, int y, cellStatus status);
    bool isDeck(int x, int y);
    void setShipStatus(int x, int y, shipStatus status);
    bool allShipsDestroyed();



private:
    static const int FIELD_SIZE = 10;
    static const int NUMBER_OF_SHIPS = 10;
    static const int NUMBER_OF_SINGLEDECK_SHIPS = 4;
    static const int NUMBER_OF_DOUBLEDECK_SHIPS = 3;
    static const int NUMBER_OF_THREEDECK_SHIPS = 2;
    static const int NUMBER_OF_FOURDECK_SHIPS = 1;
    Cell fieldCells[FIELD_SIZE][FIELD_SIZE];
    Ship fieldShips[];


};

#endif // FIELD_H

