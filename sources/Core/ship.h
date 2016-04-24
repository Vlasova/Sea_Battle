#ifndef SHIP_H
#define SHIP_H
#include "enums.h"
#include "cell.h"
#include "game.h"

class Field;

class Ship
{
public:
    Ship();
    void createShip(Field& field,int x, int y, int lenght, shipLine line);
    void setShipStatus(int x, int y);
    bool shot(Field& field, int x, int y);
    shipStatus getShipStatus() const;
    Cell* getShipCells() const;
    bool shipDestroyed();
    int getLenght() const;
    ~Ship();


private:
    int firstX, firstY, lenght;
    shipStatus status;
    Cell* shipCells;
    shipLine line;


};

#endif // SHIP_H
