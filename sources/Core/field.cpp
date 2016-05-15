#include "field.h"

Field::Field() noexcept
{

    for(int i=0; i<FIELD_SIZE;i++){
        std::vector<Cell> mas;
        for(int j=0;j<FIELD_SIZE;j++){
            mas.push_back(Cell(j, i));
        }
        fieldCells.push_back(mas);
    }
    numberSetShips=0;
}



void Field::placeShip(int x, int y, int lenght, shipLocation location) noexcept
{
    if (location==shipLocation::horizontal)
        for(int i=0;i<lenght;++i)
            fieldCells[y][x+i].setStatus(cellStatus::whole);
    else for(int i=0;i<lenght;++i)
        fieldCells[y+i][x].setStatus(cellStatus::whole);
    fieldShips.push_back(Ship(x,y,lenght,location));
    numberSetShips++;
}

bool Field::allShipsDestroyed() noexcept
{

    int count=0;
    for(int i=0; i<numberSetShips; i++)
        if (fieldShips[i].getShipStatus()==shipStatus::destroyed)
            count++;
    return count==numberSetShips;

}

bool Field::allShipsLocate() noexcept
{
    return numberSetShips==NUMBER_OF_SHIPS;

}

bool Field::isDeck(int x, int y) noexcept
{
    return (fieldCells[y][x].getStatus()==cellStatus::whole || fieldCells[y][x].getStatus()==cellStatus::stricken);
}

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

std::vector<std::vector<Cell>> Field::getFieldCells() const noexcept
{
    return this->fieldCells;
}

std::vector<Ship> Field::getFieldShips() const noexcept
{
    return this->fieldShips;
}

bool Field::canPlaceShip(int x, int y, int lenght, shipLocation line) noexcept
{
    if (line==shipLocation::horizontal)
    {
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

int Field::getnumberSetShips() const noexcept
{
    return this->numberSetShips;
}

void Field::changeCellsAroundShip(Ship ship) noexcept
{
    if (ship.getShipLocation()==shipLocation::horizontal)
    {
        for (int i=std::max(0, ship.getShipCells()[0].getY()-1);
             i<=std::min(ship.getShipCells()[0].getY()+1, FIELD_SIZE-1);
             i++)
            for (int j=std::max(0, ship.getShipCells()[0].getX()-1);
                 j<=std::min(ship.getShipCells()[ship.getLenght()-1].getX()+1, FIELD_SIZE-1);
                 j++)
                if (fieldCells[i][j].getStatus()!=cellStatus::stricken)
                    fieldCells[i][j].setStatus(cellStatus::tried);

    }
    else
    {
        for (int i=std::max(0, ship.getShipCells()[0].getY()-1);
             i<=std::min(ship.getShipCells()[ship.getLenght()-1].getY()+1, FIELD_SIZE-1);
             i++)
            for (int j=std::max(0, ship.getShipCells()[0].getX()-1);
                 j<=std::min(ship.getShipCells()[0].getX()+1, FIELD_SIZE-1);
                 j++)
                if (fieldCells[i][j].getStatus()!=cellStatus::stricken)
                    fieldCells[i][j].setStatus(cellStatus::tried);
    }
}

bool Field::isShipDestroyed(int shipNumber) noexcept
{
    return fieldShips[shipNumber].getShipStatus()==shipStatus::destroyed;

}

int Field::whoseDeck(int x, int y) noexcept
{
    bool flag=false;
    int i;
    for (i=0; i<NUMBER_OF_SHIPS; i++){
        for (int j=0; j<fieldShips[i].getLenght(); j++)
            if (fieldShips[i].getShipCells()[j].getX()==x &&
                    fieldShips[i].getShipCells()[j].getY()==y){
                flag=true;
                break;
             }
        if (flag==true)
            break;
    }
    return i;
}







