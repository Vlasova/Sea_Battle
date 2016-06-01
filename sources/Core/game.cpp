#include "game.h"

GameAPI::GameAPI() noexcept :userField(new Field()), computerField(new Field()){}

GameAPI::~GameAPI() noexcept
{
    delete userField;
    delete computerField;
}


Field* GameAPI::getUserField() const noexcept
{
    return userField;
}

Field* GameAPI::getComputerField() const noexcept
{
    return computerField;
}

bool GameAPI::makeComputerMove() noexcept
{
    int x,y;
    x=std::rand()%(Field::FIELD_SIZE-1);
    y=std::rand()%(Field::FIELD_SIZE-1);
    if(userField->getFieldCells()[y][x].getStatus()==cellStatus::stricken
            || userField->getFieldCells()[y][x].getStatus()==cellStatus::tried)
                makeComputerMove();
    return userField->shot(x, y);

}

bool GameAPI::makeUserMove(int x, int y) noexcept
{
    return computerField->shot(x,y);
}

void GameAPI::placeUserShip(int x, int y, int lenght, shipLocation location) noexcept
{
    userField->placeShip(x, y, lenght, location);
}

bool GameAPI::allShipsDestroyed(Field* field) noexcept
{
    int count=0;
    for(int i=0; i<field->getnumberSetShips(); i++)
        if (field->getFieldShips()[i].getShipStatus()==shipStatus::destroyed)
            count++;
    return count==field->getnumberSetShips();
}

void GameAPI::placeShipsAutomatically(Field *field) noexcept
{
    field->locateAutomatically();
}





