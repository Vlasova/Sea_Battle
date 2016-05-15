#ifndef FIELD_H
#define FIELD_H

#include <algorithm>
#include <random>
#include <ctime>
#include "ship.h"

/**
 * @brief Игровое поле
 */
class Field
{
public:
    static const int FIELD_SIZE = 10;
    static const int NUMBER_OF_SHIPS = 10;

    Field() noexcept;
    ~Field() noexcept;
    /**
     * @brief Разместить корабль
     * @param x буквенная координата первой палубы корабля
     * @param y цифровая координата первой палубы корабля
     * @param lenght длина корабля
     * @param location расположение
     */
    void placeShip(int x, int y, int lenght, shipLocation location) noexcept;
    /**
     * @brief Узнать, все ли корабли разрушены
     * @return true/false
     */
    bool allShipsDestroyed() noexcept;
    /**
     * @brief Узнать, все ли корабли размещены на поле
     * @return  true/false
     */
    bool allShipsLocate() noexcept;
    /**
     * @brief Узнать, является ли клетка палубой
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true/false
     */
    bool isDeck(int x, int y) noexcept;
    
    /**
     * @brief Выстрелить в клетку игрового поля
     * Изменяет статус клетки
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true при попадании в палубу
     * @return false при промахе
     */
    bool shot(int x, int y) noexcept;
    /**
     * @brief Узнать, можно ли разместить корабль на данные координаты
     * @param x буквенная координата первой палубы
     * @param y цифровая координата первой палубы
     * @param lenght длина
     * @param location расположение
     * @return true/false
     */
    bool canPlaceShip(int x, int y, int lenght, shipLocation location) noexcept;
    /**
     * @brief Получить клетки игрового поля
     * @return указатель на клетки поля
     */
    Cell** getFieldCells() const noexcept;
    /**
     * @brief Получить корабли поля
     * @return указатель на массив кораблей
     */
    Ship* getFieldShips() const noexcept;
    /**
     * @brief Узнать число размещенных кораблей
     * @return количество размещенных кораблей
     */
    int getnumberSetShips() const noexcept;
    /**
     * @brief Рандомно разместить один корабль
     * @param lenght длина корабля
     */
    void locateShipRandomly(int lenght) noexcept;
    /**
     * @brief Рандомно разместить все корабли
     */
    void locateAutomatically() noexcept;
    /**
     * @brief Изменить статус клеток вокруг разрушенного корабля
     * @param ship корабль
     */
    void changeCellsAroundShip(Ship ship) noexcept;
    /**
     * @brief Узнать, разрушен ли данный корабль
     * @param shipNumber номер корабля
     * @return true/false
     */
    bool isShipDestroyed(int shipNumber) noexcept;
    /**
     * @brief Узнать, какому кораблю принадлежит палуба
     * @param x буквенная координата
     * @param y цифровая координата
     * @return номер корабля
     */
    int whoseDeck(int x, int y) noexcept;


private:
    //TODO документировать данные класса.
    Cell** fieldCells;
    Ship* fieldShips;
    int numberSetShips;




};

#endif // FIELD_H

