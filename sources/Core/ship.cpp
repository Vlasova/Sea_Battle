#include "ship.h"

Ship::Ship():firstX(0),firstY(0),lenght(0),status(safe){}

void Ship::createShip(Field& field,int x, int y, int lenght, shipLine line)
{
    this->lenght=lenght;
    this->firstX=x;
    this->firstY=y;
    this->line=line;
    this->status=safe;
    shipCells=new Cell[lenght];
    for (int i=0;i<lenght;i++)
    {
        if (line==horizontal)
        {
            shipCells[i].setX(x+i);
            shipCells[i].setY(y);
            field.getFieldCells()[y][x+i].setStatus(whole);

        }
        else {
            shipCells[i].setX(x);
            shipCells[i].setY(y+i);
            field.getFieldCells()[y+i][x].setStatus(whole);

        }
    }
}


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


Cell* Ship::getShipCells() const
{
    return shipCells;
}

bool Ship::shot(Field &field, int x, int y)
{
    if (field.getFieldCells()[y][x].getStatus()==whole)
    {
        field.getFieldCells()[y][x].setStatus(stricken);
        return true;
    }
    else
    {
        field.getFieldCells()[y][x].setStatus(tried);
        return false;
    }
}


Ship::~Ship()
{
    delete shipCells;
}

