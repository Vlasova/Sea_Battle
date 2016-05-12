#include "game.h"

GameInterface::GameInterface() :userField(new Field()), computerField(new Field()){}

GameInterface::~GameInterface() noexcept
{
    delete userField;
    delete computerField;
}

Field* GameInterface::getUserField() const noexcept
{
    return userField;
}

Field* GameInterface::getComputerField() const noexcept
{
    return computerField;
}

bool GameInterface::makeComputerMove() noexcept
{
    int x,y;
    //Это что-то из си?
    sleep(2);
    //TODO заменить std::rand на более удачное решение, см. field
    x=std::rand()%(Field::FIELD_SIZE-1);
    y=std::rand()%(Field::FIELD_SIZE-1);
    return userField->shot(x,y);
}

bool GameInterface::makeUserMove(int x, int y) noexcept
{
    return computerField->shot(x,y);
}






