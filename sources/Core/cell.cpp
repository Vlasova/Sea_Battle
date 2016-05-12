#include "cell.h"

Cell::Cell() noexcept:x(0), y(0), status(cellStatus::blank){}

Cell::Cell(int x, int y) noexcept: x(x), y(y), status(cellStatus::blank){}

void Cell::setX(int x) noexcept
{
    this->x=x;
}

void Cell::setY(int y) noexcept
{
    this->y=y;
}

void Cell::setStatus(cellStatus status) noexcept
{
    this->status=status;
}

cellStatus Cell::getStatus() const noexcept
{
    return status;
}

int Cell::getX() const noexcept
{
    return x;
}

int Cell::getY() const noexcept
{
    return y;
}
