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


