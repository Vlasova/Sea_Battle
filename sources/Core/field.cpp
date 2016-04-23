#include <algorithm>
#include "field.h"


Field::Field(){
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

void Field::placeShip(int x, int y, int lenght, shipLine line)
{
    if (line==horizontal)
        for(int i=0;i<lenght;++i)
            fieldCells[y][x+i].setStatus(whole);
    else for(int i=0;i<lenght;++i)
        fieldCells[y+i][x].setStatus(whole);
    fieldShips[numberSetShips].createShip(*this,x,y,lenght,line);
    numberSetShips++;
}

bool Field::allShipsDestroyed()
{

    int count=0;
    for(int i=0; i<NUMBER_OF_SHIPS; i++)
        if (fieldShips[i].getShipStatus()==destroyed)
            count++;
    if(count==NUMBER_OF_SHIPS-1)
        return true;
    else return false;

}

bool Field::allShipsLocate()
{
    if (numberSetShips==NUMBER_OF_SHIPS)
        return true;
    else return false;

}

bool Field::isDeck(int x, int y)
{

    if (fieldCells[y][x].getStatus()==whole || fieldCells[y][x].getStatus()==stricken)
        return true;
    else return false;
}


bool Field::shot(int x, int y)
{

    for (int i=0; i<NUMBER_OF_SHIPS; i++)
    {
       if (getFieldShips()[i].shot(*this, x, y)){
           getFieldShips()[i].setShipStatus();
           return true;
       }
    }

    return false;


}

Cell** Field::getFieldCells() const
{
    return fieldCells;
}

Ship* Field::getFieldShips() const
{
    return fieldShips;
}

void Field::canPlacePlayerShip(int x, int y, int lenght, shipLine line)
{
    static int count1Deck=0;
    static int count2Deck=0;
    static int count3Deck=0;
    static int count4Deck=0;

    if(x>FIELD_SIZE || x<0)
        throw 5;
    if(y>FIELD_SIZE || y<0)
        throw 6;
    if((line==horizontal && x+lenght>FIELD_SIZE) || (line==vertical && y+lenght>FIELD_SIZE))
        throw 7;
    if(!canPlaceShip(x,y,lenght,line))
        throw 0;
    if (lenght==1){
        count1Deck++;
        if (count1Deck>4){
            count1Deck--;
            throw 1;
        }
    }
    if (lenght==2){
        count2Deck++;
        if (count2Deck>3){
            count2Deck--;
            throw 2;
        }
    }
    if (lenght==3){
        count3Deck++;
        if (count3Deck>2){
            count3Deck--;
            throw 3;
        }
    }
    if (lenght==4){
        count4Deck++;
        if (count4Deck>1){
            count4Deck--;
            throw 4;
        }
    }
}

bool Field::canPlaceShip(int x, int y, int lenght, shipLine line)
{   
    if (line==horizontal)
    {
        for (int i=std::max(0,y-1);i<=std::min(FIELD_SIZE-1,y+1);i++)
            for (int j=std::max(0,x-1);j<=std::min(FIELD_SIZE-1,x+lenght);j++)
                if(fieldCells[i][j].getStatus()!=blank){
                    return false;

                }
        return true;
    }
    else
    {
        for (int i=std::max(0,y-1);i<=std::min(FIELD_SIZE-1,y+lenght);i++)
            for(int j=std::max(0,x-1);j<=std::min(FIELD_SIZE-1,x+1);j++)
                if(fieldCells[i][j].getStatus()!=blank){
                    return false;
                }
        return true;
    }

}

void Field::locateShipsRandomly(int lenght)
{
    int x,y;
    shipLine line=shipLine(std::rand()%2);
    do
    {
        do
        {
            y=std::rand()%FIELD_SIZE;
        }while(line==vertical && y>FIELD_SIZE-lenght);
        do
        {
            x=std::rand()%FIELD_SIZE;
        }while(line==horizontal && x>FIELD_SIZE-lenght);

    }while(!canPlaceShip(x,y,lenght,line));
    placeShip(x,y,lenght,line);

}

void Field::locateComputerShips()
{
    for (int i=0;i<1;i++)
    {
        locateShipsRandomly(4);
    }
    for (int i=0;i<2;i++)
    {
        locateShipsRandomly(3);
    }
    for (int i=0;i<3;i++)
    {
        locateShipsRandomly(2);
    }
    for (int i=0;i<4;i++)
    {
        locateShipsRandomly(1);
    }
}






