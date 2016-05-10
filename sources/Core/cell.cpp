#include "cell.h"
//TODO Пожалуй, не будет лишним добавить пробелы между элементами списка инициализации.
//Не генерирует исключений, значит можно добавить модификатор noexcept. ("современный и эффективный с++ 11/14" С. Мейерс)
//noexcept улучшает читаемость кода, сразу понятно про исключения, и он улучшает оптимизацию кода.
//TODO добавить noexcept, т.к функция не генерирует исключений
Cell::Cell() noexcept:x(0), y(0), status(cellStatus::blank){}

//В конструкторе без параметра инициализация происходит с помощью списка, а здесь нет инициализации.
//Здесь происходит присваивание в теле конструктора. Инициализация происходит перед входом в тело конструктора.
//TODO Неплохо придерживаться одного стиля. А здесь однозначно нужно заменить присваивание инициализацией с помощью списка.
//TODO добавить noexcept, т.к функция не генерирует исключений
Cell::Cell(int x, int y) noexcept: x(x), y(y), status(cellStatus::blank){}


//TODO добавить noexcept, т.к функция не генерирует исключений
void Cell::setX(int x) noexcept
{
    this->x=x;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
void Cell::setY(int y) noexcept
{
    this->y=y;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
void Cell::setStatus(cellStatus status) noexcept
{
    this->status=status;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
cellStatus Cell::getStatus() const noexcept
{
    return status;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
int Cell::getX() const noexcept
{
    return x;
}

//TODO добавить noexcept, т.к функция не генерирует исключений
int Cell::getY() const noexcept
{
    return y;
}
