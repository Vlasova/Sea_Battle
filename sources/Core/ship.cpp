#include "ship.h"

//TODO добавить пробелы
//TODO добавить noexcept, т.к функция не генерирует исключений
Ship::Ship() noexcept:firstX(0), firstY(0), lenght(0), status(shipStatus::whole){}

Ship::~Ship() noexcept
{
    delete shipCells;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
void Ship::createShip(int x, int y, int lenght, shipLocation location) noexcept
{
    this->lenght=lenght;
    this->firstX=x;
    this->firstY=y;
    this->location=location;
    this->status=shipStatus::whole;
    shipCells=new Cell[lenght];
    for (int i=0;i<lenght;i++)
    {
        if (location==shipLocation::horizontal)
        {
            shipCells[i].setX(x+i);
            shipCells[i].setY(y);
            shipCells[i].setStatus(cellStatus::whole);
        }
        else {
            shipCells[i].setX(x);
            shipCells[i].setY(y+i);
            shipCells[i].setStatus(cellStatus::whole);


        }
    }
}

//TODO добавить noexcept, т.к функция не генерирует исключений
shipStatus Ship::getShipStatus() const noexcept
{
    return status;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
void Ship::setShipStatus(int x, int y) noexcept
{
    //TODO Происходит два прохода цикла. Лучше объединить в один цикл.
    //Примерно так
    //int count=0;
    //for (int i=0, i<length; i++)
    //{
    //  if (shipCells[i].getX()==x && shipCells[i].getY()==y)
    //  {
    //      shipCells[i].setStatus(stricken);
    //      count++;
    //  }
    //  if (count==lenght)
    //      status=destroyed;
    //  else if (count!=0)
    //      status=smitten;
    //}
    int count=0;
    for (int i=0; i<lenght; i++){
        if (shipCells[i].getStatus()==cellStatus::stricken)
            count++;
        else if (shipCells[i].getX()==x && shipCells[i].getY()==y)
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

//TODO добавить noexcept, т.к функция не генерирует исключений
Cell* Ship::getShipCells() const noexcept
{
    //здесь без this-> ( см. ниже int Ship::getLenght() const )
    return this->shipCells;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Ship::shot(int x, int y) noexcept
{
    for (int i=0; i<lenght; i++)
        if (shipCells[i].getX()==x && shipCells[i].getY()==y && shipCells[i].getStatus()==cellStatus::whole)
        {
            //TODO объединить 2 if'а, т.к их разделение не обосновано и не имеет смысла.
            {
                shipCells[i].setStatus(cellStatus::stricken);
                return true;
            }
        }

    return false;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
int Ship::getLenght() const noexcept
{
    //Здесь с this->
    //TODO подумать и выбрать единый вариант для единства кода.
    return this->lenght;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
shipLocation Ship::getShipLine() const noexcept
{
    //См. выше
    return this->location;
}


