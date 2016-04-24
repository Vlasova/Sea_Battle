#ifndef FIELD_H
#define FIELD_H
#include "ship.h"
#include "enums.h"
#include "cell.h"


static const int FIELD_SIZE = 10;
static const int NUMBER_OF_SHIPS = 10;

class Ship;

class Field{

public:

    Field();
    void placeShip(int x, int y, int lenght, shipLine line);
    bool allShipsDestroyed();
    bool allShipsLocate();
    bool isDeck(int x, int y);
    bool shot(int x, int y);
    bool canPlaceShip(int x, int y, int lenght, shipLine line);
    void canPlacePlayerShip(int x, int y, int lenght, shipLine line);
    Cell** getFieldCells() const;
    Ship* getFieldShips() const;
    int getnumberSetShips() const;
    void locateShipsRandomly(int lenght);
    void locateComputerShips();


private:
    Cell** fieldCells;
    Ship* fieldShips;
    int numberSetShips;




};

#endif // FIELD_H

