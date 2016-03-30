#include "cell.h"

Cell::Cell():x(0),y(0),status(blank){}

Cell::Cell(int x, int y, cellStatus status):x(x),y(y),status(status){}

void Cell::setX(int x){
    this->x=x;
}

void Cell::setY(int y){
    this->y=y;
}

void Cell::setStatus(cellStatus status){
    this->status=status;
}


cellStatus Cell::getStatus() const{
    return status;
}

int Cell::getX() const{
    return x;
}

int Cell::getY() const{
    return y;
}