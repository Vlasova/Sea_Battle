#ifndef CELL_H
#define CELL_H

#include "enums.h"

/**
 * @brief Клетка игрового поля
 */
class Cell
{
public:
    Cell() noexcept;
    Cell(int x, int y) noexcept;
    
    //TODO задуматься об перегрузке оператора присваивания. &Cell operator=( const Cell& ) noexcept
    //Он был бы отличным дополнением к методам setX(), setY() и setStatus()
    
    //TODO задуматься об перегрузке оператора равенства. bool operator==( const Cell& ) const noexcept
    //Возможно, он не понадобится, тогда и не надо.
    /**
     * @brief Установить буквенную координату клетки
     * @param x буквенная координата
     */
    void setX(int x) noexcept;
    /**
     * @brief Установить цифровую координату клетки
     * @param y цифровая координата
     */
    void setY(int y) noexcept;
    /**
     * @brief Установить статус клетки
     * @param status статус
     */
    void setStatus(cellStatus status) noexcept;
    /**
     * @brief Получить статус клетки
     * @return статус
     */
    cellStatus getStatus() const noexcept;
    /**
     * @brief Получить буквенную координату
     * @return буквенная координата
     */
    int getX() const noexcept;
    /**
     * @brief Получить цифровую координату
     * @return цифровая координата
     */
    int getY() const noexcept;

private:
    //TODO разделить объявление x и y на 2 строки
    //Это улучшит читаемость. Появится возможность удобно задокументировать данные класса.
    //TODO задокументировать данные класса http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
    int x;
    int y;
    cellStatus status;

};

#endif // CELL_H

