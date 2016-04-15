#include "game.h"

Game::Game(){
    field = new Field();
}

Field* Game::getField() const
{
    return field;
}
