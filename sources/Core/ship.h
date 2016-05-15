#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "cell.h"

enum class shipStatus {whole, stricken, destroyed};
enum class shipLocation {vertical, horizontal};

/**
 * @brief Корабль
 */
class Ship
{
public:
    Ship() noexcept;
    ~Ship() noexcept;
    /**
     * @brief Создать корабль
     * @param field игровое поле
     * @param x первая буквенная координата корабля
     * @param y первая цифровая координата корабля
     * @param lenght длина корабля
     * @param location расположение корабля (горизонтальное/вертикальное)
     */
    void createShip(int x, int y, int lenght, shipLocation location) noexcept;
    /**
     * @brief Установить статус корабля
     * @param x первая буквенная координата корабля
     * @param y первая цифровая координата корабля
     */
    void setShipStatus(int x, int y) noexcept;
    /**
     * @brief Проверить, попал ли игрок в клетку корабля
     * При попадании изменяет статус клетки
     * @param field игровое поле
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true/false
     */
    bool shot(int x, int y) noexcept;
    /**
     * @brief Получить статус корабля
     * @return статус
     */
    shipStatus getShipStatus() const noexcept;
    /**
     * @brief Получить клетки корабля
     * @return клетки корабля
     */
    Cell* getShipCells() const noexcept;
    /**
     * @brief Получить длину корабля
     * @return длина
     */
    int getLenght() const noexcept;
    /**
     * @brief Получить расположение корабля
     * @return расположение
     */
    shipLocation getShipLocation() const noexcept;




private:
    //TODO документировать данные
    int firstX;
    int firstY;
    int lenght;
    shipStatus status;
    //TODO подумать о замене массива в стиле си на контейнер из с++ stl. Например, std::valarray или std::vector
    Cell* shipCells;
    shipLocation location;


};

#endif // SHIP_H
