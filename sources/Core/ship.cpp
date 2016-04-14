#include "ship.h"

Ship::Ship():lenght(0),status(safe),firstX(0),firstY(0){}


shipStatus Ship::getShipStatus() const
{

    return status;

}

void Ship::setShipStatus()
{

    int count=0;
    for (int i=0; i<lenght; i++)
        if (shipCells[i].getStatus()==stricken)
            count++;
    if (count==lenght)
        status=destroyed;
    else if (count!=0)
        status=smitten;

}

void Ship::setShipCells(int firstX, int firstY, int lenght, shipLine line)
{
    shipCells=new Cell[lenght];
    this->firstX=firstX;
    this->firstY=firstY;
    this->lenght=lenght;
    this->line=line;
    if (line==horizontal)
    for (int i=0;i<lenght;i++){
         shipCells[i].setX(firstX+i);
         shipCells[i].setY(firstY);
         shipCells[i].setStatus(whole);
    }
    else for (int i=0;i<lenght;i++){
        shipCells[i].setY(firstY+i);
        shipCells[i].setX(firstX);
        shipCells[i].setStatus(whole);
    }
}

Cell* Ship::getShipCells() const
{
    return shipCells;
}

Ship::~Ship()
{
    delete shipCells;
}

