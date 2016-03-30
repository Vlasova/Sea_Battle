#include "ship.h"
#include "cell.h"

Ship::Ship(int x, int y, int lenght, shipLine line){
    firstShipCell.setX(x);
    firstShipCell.setY(y);
    firstShipCell.setStatus(blank);
    shipCells[0]=firstShipCell;
    status=safe;
    this->lenght=lenght;
    if (line==vertical)
        for(int i=1;i<lenght;i++){
            shipCells[i].setX(x+i);
            shipCells[i].setY(y);
            shipCells[i].setStatus(blank);
        }

    else
        for(int i=1;i<lenght;i++){
            shipCells[i].setX(x);
            shipCells[i].setY(y+i);
            shipCells[i].setStatus(blank);
        }
}


