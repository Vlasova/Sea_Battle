#include "field.h"
#include "cell.h"
#include "ship.h"

Field::Field(){
    fieldCells=new Cell*[FIELD_SIZE];
    for (int i=0; i<FIELD_SIZE;i++)
        fieldCells[i]=new Cell[FIELD_SIZE];
    for(int i=0; i<FIELD_SIZE;i++)
        for(int j=0;j<FIELD_SIZE;j++){
            fieldCells[i][j].setX(i);
            fieldCells[i][j].setY(j);
            fieldCells[i][j].setStatus(blank);
        }
    fieldShips=new Ship[NUMBER_OF_SHIPS];
    for (int i=0;i<NUMBER_OF_SHIPS;i++)
        Ship();


}

void Field::placeShip(int x, int y, int lenght, shipLine line){

    int number=0;
    fieldShips[number].Ship;
    number++;

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



