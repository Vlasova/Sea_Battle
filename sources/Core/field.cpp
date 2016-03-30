#include "field.h"
#include "cell.h"

Field::Field(){
    for(int i=1; i<=FIELD_SIZE;i++)
        for(int j=1;j<=FIELD_SIZE;j++){
            fieldCells[i][j].setX(i);
            fieldCells[i][j].setY(j);
            fieldCells[i][j].setStatus(blank);
        }

}

cellStatus Field::getCellStatus(int x, int y) const{

    return fieldCells[x][y].getStatus();


}

