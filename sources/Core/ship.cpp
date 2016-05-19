#include "ship.h"

Ship::Ship() noexcept:firstX(0), firstY(0), lenght(0), status(shipStatus::whole){}


Ship::Ship(int x, int y, int lenght, shipLocation location) noexcept
{
    this->lenght=lenght;
    this->firstX=x;
    this->firstY=y;
    this->location=location;
    this->status=shipStatus::whole;
    for (int i=0; i<lenght; i++)
    {
        if (location==shipLocation::horizontal)
        {
            shipCells.push_back(Cell(x+i, y, cellStatus::whole));
        }
        else
        {
            shipCells.push_back(Cell(x, y+i, cellStatus::whole));
        }
    }
}

shipStatus Ship::getShipStatus() const noexcept
{
    return status;
}

void Ship::setShipStatus(int x, int y) noexcept
{
    int count=0;
    for (unsigned int i=0; i<shipCells.size(); i++){
        if (shipCells[i].getStatus()==cellStatus::stricken)
            count++;
        else if (shipCells[i].operator ==(Cell(x, y)))
        {
            shipCells[i].setStatus(cellStatus::stricken);
            count++;
        }
    }
        if (count==lenght)
            status=shipStatus::destroyed;
        else if (count!=0)
            status=shipStatus::stricken;
}

std::vector<Cell> Ship::getShipCells() const noexcept
{
      return this->shipCells;
}

bool Ship::shot(int x, int y) noexcept
{
    for (unsigned int i=0; i<shipCells.size(); i++)
        if (shipCells[i].operator ==(Cell(x, y, cellStatus::whole)))
        {
            {
                shipCells[i].setStatus(cellStatus::stricken);
                return true;
            }
        }

    return false;
}

int Ship::getLenght() const noexcept
{
    return this->lenght;
}

shipLocation Ship::getShipLocation() const noexcept
{
   return this->location;
}



