#ifndef FIELD_H
#define FIELD_H
#include "enums.h"
#include "cell.h"
#include "ship.h"



class Field{

public:
    Field();
    void placeShip(int x, int y, int lenght, shipLine line);
    bool allShipsDestroyed();
    char printField();



private:
    static const int FIELD_SIZE = 10;
    static const int NUMBER_OF_SHIPS = 10;
    static const int NUMBER_OF_SINGLEDECK_SHIPS = 4;
    static const int NUMBER_OF_DOUBLEDECK_SHIPS = 3;
    static const int NUMBER_OF_THREEDECK_SHIPS = 2;
    static const int NUMBER_OF_FOURDECK_SHIPS = 1;
    Cell** fieldCells;
    Ship* fieldShips;


};

#endif // FIELD_H

