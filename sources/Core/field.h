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
    bool isDeck(int x, int y);
    bool shot(int x, int y);
    Cell** getFieldCells() const;
    Ship* getFieldShips() const;



private:
    static const int FIELD_SIZE = 10;
    static const int NUMBER_OF_SHIPS = 10;
    Cell** fieldCells;
    Ship* fieldShips;
    int numberSetShips;



};

#endif // FIELD_H

