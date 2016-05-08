#include <algorithm>
#include "unistd.h"
#include "game.h"


Game::Game()
{
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

bool Game::makeComputerMove()
{
    int x,y;
    sleep(2);
    x=std::rand()%(FIELD_SIZE-1);
    y=std::rand()%(FIELD_SIZE-1);
    if (playerField->shot(x,y))
        return true;

    else return false;
}

bool Game::makeMove(int x, int y)
{
    if (computerField->shot(x,y)){
        return true;
    }
    else
        return false;
}

Game::~Game()
{
    delete playerField;
    delete computerField;
}



