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

void Field::placeShip(int x,int y, int lenght, shipLine line){

    if (line==horizontal)
        for(int i=0;i<lenght;i++)
            fieldCells[y-1][x-1+i].setStatus(whole);
    else for(int i=0;i<lenght;i++)
        fieldCells[y-1+i][x-1].setStatus(whole);
    fieldShips[numberSetShips].setShipCells(x,y,lenght,line);
    numberSetShips++;

}

bool Field::allShipsDestroyed(){

    int count=0;
    for(int i=0; i<NUMBER_OF_SHIPS;i++)
        if (fieldShips[i].getShipStatus()==destroyed)
            count++;
    if(count==NUMBER_OF_SHIPS)
        return true;
    else return false;

}

bool Field::isDeck(int x, int y){

    if (fieldCells[y][x].getStatus()==whole || fieldCells[y][x].getStatus()==stricken)
        return true;
    else return false;
}

bool Field::shot(int x, int y){

    if (fieldCells[y][x].getStatus()==whole){
        fieldCells[y][x].setStatus(stricken);
        return true;
    }
    else return false;

}

Cell** Field::getFieldCells() const
{
    return fieldCells;
}

Ship* Field::getFieldShips() const
{
    return fieldShips;
}



