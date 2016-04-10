#include "ship.h"



Ship::Ship():lenght(0),status(safe),firstX(0),firstY(0){}

Ship::Ship(int x, int y, int lenght, shipLine line){

    status=safe;
    this->lenght=lenght;
    shipCells=new Cell[lenght];
    if (line==vertical)
        for(int i=0;i<lenght;i++){
            shipCells[i].setX(x+1);
            shipCells[i].setY(y);
            shipCells[i].setStatus(blank);

        }

    else
        for(int i=0;i<lenght;i++){
            shipCells[i].setX(x);
            shipCells[i].setY(y+i);
            shipCells[i].setStatus(blank);
        }

}


shipStatus Ship::getShipStatus() const{

    return status;

}

void Ship::setShipStatus(){

    int count=0;
    for (int i=0; i<lenght; i++)
        if (shipCells[i].getStatus()==stricken)
            count++;
    if (count==lenght)
        status=destroyed;
    else if (count!=0)
        status=smitten;

}

void Ship::setShipCells(int x, int y, int lenght, shipLine line){

    shipCells=new Cell[lenght];
    if (line==horizontal)
    for (int i=0;i<lenght;i++){
         shipCells[i].setX(x+i);
         shipCells[i].setY(y);
    }
    else for (int i=0;i<lenght;i++){
        shipCells[i].setY(y+i);
        shipCells[i].setX(x);
    }
    firstX=x;
    firstY=y;

}


