#include "cell.h"

Cell::Cell() noexcept: x(0), y(0), status(cellStatus::blank){}

Cell::Cell(int x, int y) noexcept: x(x), y(y), status(cellStatus::blank){}

Cell::Cell(int x, int y, cellStatus status) noexcept: x(x), y(y), status(status) {}

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

Cell& Cell::operator =(const Cell& other) noexcept
{
    x=other.getX();
    y=other.getY();
    status=other.getStatus();
    return *this;
}

bool Cell::operator ==(const Cell& other) const noexcept
{
    return (x==other.getX() && y==other.getY() && status==other.getStatus());
}
