#include <algorithm>
#include "game.h"


Game::Game(){
    playerField=new Field();
    computerField=new Field();
}

Field* Game::getPlayerField() const
{
    return playerField;
}

Field* Game::getComputerField() const
{
    return computerField;
}

void Game::makeComputerMove()
{
    int x,y;
    x=std::rand()%FIELD_SIZE-1;
    y=std::rand()%FIELD_SIZE-1;
    playerField->shot(x,y);


}

