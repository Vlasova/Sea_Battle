#ifndef SHIP_H
#define SHIP_H

#include "cell.h"
#include "enums.h"
#include "field.h"

//Данное объявление класса нужно?
class Field;

/**
 * @brief Корабль
 */
class Ship
{
public:
    Ship();
    /**
     * @brief Создать корабль
     * @param field игровое поле
     * @param x первая буквенная координата корабля
     * @param y первая цифровая координата корабля
     * @param lenght длина корабля
     * @param line расположение корабля (горизонтальное/вертикальное)
     */
    void createShip(Field& field,int x, int y, int lenght, shipLine line);
    /**
     * @brief Установить статус корабля
     * @param x первая буквенная координата корабля
     * @param y первая цифровая координата корабля
     */
    void setShipStatus(int x, int y);
    /**
     * @brief Проверить, попал ли игрок в клетку корабля
     * @param field игровое поле
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true/false
     */
    bool shot(Field& field, int x, int y);
    /**
     * @brief Получить статус корабля
     * @return статус
     */
    shipStatus getShipStatus() const;
    /**
     * @brief Получить клетки корабля
     * @return клетки корабля
     */
    Cell* getShipCells() const;
    /**
     * @brief Получить длину корабля
     * @return длина
     */
    int getLenght() const;
    /**
     * @brief Получить расположение корабля
     * @return расположение
     */
    shipLine getShipLine() const;
    ~Ship();


private:
    //TODO документировать данные
    //TODO разделить объявление переменных на несколько строк. Улучшится читаемость
    int firstX, firstY, lenght;
    shipStatus status;
    //TODO подумать о замене массива в стиле си на контейнер из с++ stl. Например, std::valarray или std::vector
    Cell* shipCells;
    shipLine line;


};

#endif // SHIP_H
