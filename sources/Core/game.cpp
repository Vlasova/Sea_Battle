#include <algorithm>
#include "unistd.h"
#include "game.h"

//TODO добавить noexcept, т.к функция не генерирует исключений
//TODO заменить присваивание в теле конструктора списком инициализации.
Game::Game()
{
    playerField=new Field();
    computerField=new Field();
}

//TODO добавить noexcept, т.к функция не генерирует исключений
Field* Game::getPlayerField() const
{
    return playerField;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
Field* Game::getComputerField() const
{
    return computerField;
}

//В методах Game::makeComputerMove() и Game::makeMove(int x, int y) много общего кода, т.е происходит дублирование.
//Рекомендую в метод makeMove вызывать из метода makeComputerMove. И можно создать для однородности метод makeUserMove() (Player)
//TODO устранить дублирование путем выделения метода ("Рефакторинг. Улучшение существующего кода" М. Фаулер)

//TODO добавить noexcept, т.к функция не генерирует исключений

bool Game::makeComputerMove()
{
    int x,y;
    //Это что-то из си?
    sleep(2);
    //TODO заменить std::rand на более удачное решение, см. field
    x=std::rand()%(FIELD_SIZE-1);
    y=std::rand()%(FIELD_SIZE-1);
    //TODO заменить на return playerField->shot(x,y);
    if (playerField->shot(x,y))
        return true;

    else return false;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Game::makeMove(int x, int y)
{
    //TODO заменить на более читаемую и простую форму. см выше.
    if (computerField->shot(x,y)){
        return true;
    }
    else
        return false;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
Game::~Game()
{
    delete playerField;
    delete computerField;
}



