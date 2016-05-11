#include "game.h"

//TODO добавить noexcept, т.к функция не генерирует исключений
//TODO заменить присваивание в теле конструктора списком инициализации.
Game::Game() noexcept:userField(new Field()), computerField(new Field()){}

//TODO добавить noexcept, т.к функция не генерирует исключений
Field* Game::getUserField() const noexcept
{
    return userField;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
Field* Game::getComputerField() const noexcept
{
    return computerField;
}

//В методах Game::makeComputerMove() и Game::makeMove(int x, int y) много общего кода, т.е происходит дублирование.
//Рекомендую в метод makeMove вызывать из метода makeComputerMove. И можно создать для однородности метод makeUserMove() (Player)
//TODO устранить дублирование путем выделения метода ("Рефакторинг. Улучшение существующего кода" М. Фаулер)

//TODO добавить noexcept, т.к функция не генерирует исключений

bool Game::makeComputerMove() noexcept
{
    int x,y;
    //Это что-то из си?
    sleep(2);
    //TODO заменить std::rand на более удачное решение, см. field
    x=std::rand()%(Field::FIELD_SIZE-1);
    y=std::rand()%(Field::FIELD_SIZE-1);
    //TODO заменить на return playerField->shot(x,y);
    return userField->shot(x,y);
}

//TODO добавить noexcept, т.к функция не генерирует исключений
bool Game::makeUserMove(int x, int y) noexcept
{
    //TODO заменить на более читаемую и простую форму. см выше.
    return computerField->shot(x,y);
}

//TODO добавить noexcept, т.к функция не генерирует исключений
Game::~Game() noexcept
{
    delete userField;
    delete computerField;
}



