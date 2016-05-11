#include "field.h"

//TODO добавить noexcept, т.к функция не генерирует исключений
Field::Field() noexcept
{
    fieldCells=new Cell*[FIELD_SIZE];
    for (int i=0; i<FIELD_SIZE;i++)
        fieldCells[i]=new Cell[FIELD_SIZE];
    for(int i=0; i<FIELD_SIZE;i++)
        for(int j=0;j<FIELD_SIZE;j++){
            fieldCells[i][j].setX(j);
            fieldCells[i][j].setY(i);
        }
    fieldShips=new Ship[NUMBER_OF_SHIPS];
    numberSetShips=0;


}

Field::~Field() noexcept
{
    delete fieldCells;
    delete fieldShips;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
void Field::placeShip(int x, int y, int lenght, shipLocation line) noexcept
{
    if (line==shipLocation::horizontal)
        for(int i=0;i<lenght;++i)
            fieldCells[y][x+i].setStatus(cellStatus::whole);
    else for(int i=0;i<lenght;++i)
        fieldCells[y+i][x].setStatus(cellStatus::whole);
    fieldShips[numberSetShips].createShip(x,y,lenght,line);
    numberSetShips++;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Field::allShipsDestroyed() noexcept
{

    int count=0;
    for(int i=0; i<numberSetShips; i++)
        if (fieldShips[i].getShipStatus()==shipStatus::destroyed)
            count++;
            
    //TODO заменить на более читаемый вид.
    //return count==numberSetShips;
    //И понятнее и короче.
    return count==numberSetShips;

}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Field::allShipsLocate() noexcept
{
    //TODO заменить на более читаемый вид.
    //return numberSetShips==NUMBER_OF_SHIPS;
    return numberSetShips==NUMBER_OF_SHIPS;

}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Field::isDeck(int x, int y) noexcept
{
    //TODO заменить на более читаемый вид.
    //см. выше
    return (fieldCells[y][x].getStatus()==cellStatus::whole || fieldCells[y][x].getStatus()==cellStatus::stricken);
}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Field::shot(int x, int y) noexcept
{
    if (isDeck(x,y))
    {
        for (int i=0; i<NUMBER_OF_SHIPS; i++)
        {
            if (fieldShips[i].shot(x, y))
            {
                fieldShips[i].setShipStatus(x, y);
                fieldCells[y][x].setStatus(cellStatus::stricken);
                return true;
            }
        }
    }
    else fieldCells[y][x].setStatus(cellStatus::tried);
    return false;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
Cell** Field::getFieldCells() const noexcept
{
    return this->fieldCells;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
Ship* Field::getFieldShips() const noexcept
{
    return this->fieldShips;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Field::canPlaceShip(int x, int y, int lenght, shipLocation line) noexcept
{
    if (line==shipLocation::horizontal)
    {   
        //TODO длинное условие!
        for (int i=std::max(0,y-1);
             i<=std::min(FIELD_SIZE-1,y+1);
             i++)
            for (int j=std::max(0,x-1);
                 j<=std::min(FIELD_SIZE-1,x+lenght);
                 j++)
                if(fieldCells[i][j].getStatus()!=cellStatus::blank){
                    return false;

                }
        return true;
    }
    else
    {
        //TODO длинное условие!
        for (int i=std::max(0,y-1);
             i<=std::min(FIELD_SIZE-1,y+lenght);
             i++)
            for(int j=std::max(0,x-1);
                j<=std::min(FIELD_SIZE-1,x+1);
                j++)
                if(fieldCells[i][j].getStatus()!=cellStatus::blank){
                    return false;
                }
        return true;
    }

}

//В с++ принятно использовать не std::rand()
//https://www.securecoding.cert.org/confluence/display/cplusplus/MSC50-CPP.+Do+not+use+std%3A%3Arand%28%29+for+generating+pseudorandom+numbers
//https://www.securecoding.cert.org/confluence/display/cplusplus/MSC51-CPP.+Ensure+your+random+number+generator+is+properly+seeded
//TODO заменить rand() на более удачное решение.
//TODO добавить noexcept, т.к функция не генерирует исключений
void Field::locateShipRandomly(int lenght) noexcept
{
    int x,y;
    shipLocation line=shipLocation(std::rand()%2);
    do
    {
        do
        {
            y=std::rand()%FIELD_SIZE;
        }while(line==shipLocation::vertical && y>FIELD_SIZE-lenght);
        do
        {
            x=std::rand()%FIELD_SIZE;
        }while(line==shipLocation::horizontal && x>FIELD_SIZE-lenght);

    }while(!canPlaceShip(x,y,lenght,line));
    placeShip(x,y,lenght,line);

}

//TODO добавить noexcept, т.к функция не генерирует исключений
void Field::locateAutomatically() noexcept
{
    for (int i=0;i<1;i++)
    {
        locateShipRandomly(4);
    }
    for (int i=0;i<2;i++)
    {
        locateShipRandomly(3);
    }
    for (int i=0;i<3;i++)
    {
        locateShipRandomly(2);
    }
    for (int i=0;i<4;i++)
    {
        locateShipRandomly(1);
    }
}

//TODO добавить noexcept, т.к функция не генерирует исключений
int Field::getnumberSetShips() const noexcept
{
    return this->numberSetShips;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
//Название метода некорректно. Сбивает с толку. Возникает мысль, что он - часть приложения, а не логики.
//TODO подумать над другим названием метода.
void Field::drawAroundShip(Ship ship) noexcept
{
    if (ship.getShipLine()==shipLocation::horizontal)
    {
        //Слишком длинные условия в for.
        //TODO вынести за пределы условия цикла min и max, улучшив читаемость. Либо есть вариант аккуратненько разбить на строки.
        //for (int i=std::max(0, ship.getShipCells()[0].getY()-1); 
        //     i<=std::min(ship.getShipCells()[0].getY()+1, FIELD_SIZE-1); 
        //     i++)
        //Как больше понравится
        for (int i=std::max(0, ship.getShipCells()[0].getY()-1);
             i<=std::min(ship.getShipCells()[0].getY()+1, FIELD_SIZE-1);
             i++)
            for (int j=std::max(0, ship.getShipCells()[0].getX()-1);
                 j<=std::min(ship.getShipCells()[ship.getLenght()-1].getX()+1, FIELD_SIZE-1);
                 j++)
                if (getFieldCells()[i][j].getStatus()!=cellStatus::stricken)
                    getFieldCells()[i][j].setStatus(cellStatus::tried);

    }
    else
    {
        //TODO вынести за пределы условия цикла min и max, улучшив читаемость. Либо есть вариант аккуратненько разбить на строки.
        for (int i=std::max(0, ship.getShipCells()[0].getY()-1);
             i<=std::min(ship.getShipCells()[ship.getLenght()-1].getY()+1, FIELD_SIZE-1);
             i++)
            for (int j=std::max(0, ship.getShipCells()[0].getX()-1);
                 j<=std::min(ship.getShipCells()[0].getX()+1, FIELD_SIZE-1);
                 j++)
                if (getFieldCells()[i][j].getStatus()!=cellStatus::stricken)
                    getFieldCells()[i][j].setStatus(cellStatus::tried);
    }
}








