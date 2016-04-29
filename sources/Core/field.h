#ifndef FIELD_H
#define FIELD_H

#include "ship.h"

static const int FIELD_SIZE = 10;
static const int NUMBER_OF_SHIPS = 10;

class Ship;
/**
 * @brief Игровое поле
 */
class Field
{
public:

    Field();
    ~Field();
    /**
     * @brief Разместить корабль
     * @param x буквенная координата первой палубы корабля
     * @param y цифровая координата первой палубы корабля
     * @param lenght длина корабля
     * @param line расположение
     */
    void placeShip(int x, int y, int lenght, shipLine line);
    /**
     * @brief Узнать, все ли корабли разрушены
     * @return true/false
     */
    bool allShipsDestroyed();
    /**
     * @brief Узнать, все ли корабли размещены на поле
     * @return  true/false
     */
    bool allShipsLocate();
    /**
     * @brief Узнать, является ли клетка палубой
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true/false
     */
    bool isDeck(int x, int y);
    /**
     * @brief Выстрелить в клетку игрового поля
     * Изменяет статус клетки
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true/false
     */
    bool shot(int x, int y);
    /**
     * @brief Узнать, можно ли разместить корабль на данные координаты
     * @param x буквенная координата первой палубы
     * @param y цифровая координата первой палубы
     * @param lenght длина
     * @param line расположение
     * @return true/false
     */
    bool canPlaceShip(int x, int y, int lenght, shipLine line);
    /**
     * @brief Проверить корректность ввода при расстановке кораблей
     * @param x буквенная координата первой палубы
     * @param y цифровая координата первой палубы
     * @param lenght длина
     * @param line расположение
     */
    void isInputCorrect(int x, int y, int lenght, shipLine line);
    /**
     * @brief Проверить корректность ввода при совершении хода
     * @param x буквенная координата
     * @param y цифровая координата
     * @return return/false
     */
    bool isCoordinatesCorrect(int x, int y);
    /**
     * @brief Получить клетки игрового поля
     * @return указатель на клетки поля
     */
    Cell** getFieldCells() const;
    /**
     * @brief Получить корабли поля
     * @return указатель на массив кораблей
     */
    Ship* getFieldShips() const;
    /**
     * @brief Узнать число размещенных кораблей
     * @return количество размещенных кораблей
     */
    int getnumberSetShips() const;
    /**
     * @brief Рандомно разместить один корабль
     * @param lenght длина корабля
     */
    void locateShipRandomly(int lenght);
    /**
     * @brief Рандомно разместить все корабли
     */
    void locateAutomatically();
    /**
     * @brief Обрисовать разрушенный корабль
     * @param ship корабль
     */
    void drawAroundShip(Ship ship);


private:
    Cell** fieldCells;
    Ship* fieldShips;
    int numberSetShips;




};

#endif // FIELD_H

