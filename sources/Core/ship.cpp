#include "ship.h"

//TODO добавить пробелы
//TODO добавить noexcept, т.к функция не генерирует исключений
Ship::Ship():firstX(0),firstY(0),lenght(0),status(safe){}

//TODO добавить noexcept, т.к функция не генерирует исключений
void Ship::createShip(Field& field, int x, int y, int lenght, shipLine line)
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
            shipCells[i].setStatus(whole);
            field.getFieldCells()[y][x+i].setStatus(whole);

        }
        else {
            shipCells[i].setX(x);
            shipCells[i].setY(y+i);
            shipCells[i].setStatus(whole);
            field.getFieldCells()[y+i][x].setStatus(whole);

        }
    }
}

//TODO добавить noexcept, т.к функция не генерирует исключений
shipStatus Ship::getShipStatus() const
{
    return status;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
void Ship::setShipStatus(int x, int y)
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
    for (int i=0; i<lenght; i++)
        if (shipCells[i].getX()==x && shipCells[i].getY()==y)
            shipCells[i].setStatus(stricken);


    int count=0;
    for (int i=0; i<lenght; i++)
        if (shipCells[i].getStatus()==stricken)
            count++;
    if (count==lenght)
        status=destroyed;
    else if (count!=0)
        status=smitten;

}

//TODO добавить noexcept, т.к функция не генерирует исключений
Cell* Ship::getShipCells() const
{
    //здесь без this-> ( см. ниже int Ship::getLenght() const )
    return shipCells;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Ship::shot(Field& field, int x, int y)
{
    for (int i=0; i<lenght; i++)
        if (shipCells[i].getX()==x && shipCells[i].getY()==y)
        {   
            //TODO объединить 2 if'а, т.к их разделение не обосновано и не имеет смысла.
            if (shipCells[i].getStatus()==whole)
            {
                shipCells[i].setStatus(stricken);
                field.getFieldCells()[y][x].setStatus(stricken);
                return true;
            }
        }

    return false;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
int Ship::getLenght() const
{
    //Здесь с this->
    //TODO подумать и выбрать единый вариант для единства кода.
    return this->lenght;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
shipLine Ship::getShipLine() const
{
    //См. выше
    return this->line;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
Ship::~Ship()
{
    delete shipCells;
}

