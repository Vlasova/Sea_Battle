#ifndef CELL_H
#define CELL_H

#include "enums.h"

/**
 * @brief Клетка игрового поля
 */
class Cell
{
public:
    Cell();
    Cell(int x, int y);
    /**
     * @brief Установить буквенную координату клетки
     * @param x буквенная координата
     */
    void setX(int x);
    /**
     * @brief Установить цифровую координату клетки
     * @param y цифровая координата
     */
    void setY(int y);
    /**
     * @brief Установить статус клетки
     * @param status статус
     */
    void setStatus(cellStatus status);
    /**
     * @brief Получить статус клетки
     * @return статус
     */
    cellStatus getStatus() const;
    /**
     * @brief Получить буквенную координату
     * @return буквенная координата
     */
    int getX() const;
    /**
     * @brief Получить цифровую координату
     * @return цифровая координата
     */
    int getY() const;

private:
    //TODO разделить объявление x и y на 2 строки
    //Это улучшит читаемость. Появится возможность удобно задокументировать данные класса.
    //TODO задокументировать данные класса http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
    int x,y;
    cellStatus status;

};

#endif // CELL_H

