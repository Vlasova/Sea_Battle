#ifndef FIELD_H
#define FIELD_H

#include <algorithm>
#include "ship.h"

//TODO добавить пробелы между прототипами классов. 
//Так без пробелов сложно читать, часто документация другого метода восприниается как нужная.

//Данные константы тесно связаны с классом Field
//TODO подумать об внесении этих констант в класс

//Данное объявление класса нужно?

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
       //line - переводится не как расположение.
       //TODO поменять имя переменной или изменить перевод
     * @param line расположение
     */
    void placeShip(int x, int y, int lenght, shipLocation line) noexcept;
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
    
    //В данном классе можно поподробней написать про возвращаемое значение.
    //После выстрела разное происзодит. true - это был совершен выстрел? или выстрел попал в цель?
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
       //line - переводится не как расположение.
       //TODO поменять имя переменной или изменить перевод
     * @param line расположение
     * @return true/false
     */
    bool canPlaceShip(int x, int y, int lenght, shipLocation line) noexcept;
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
    
    //По названию становится ясно, что данный метод не относится к бизнес-логике, 
    //а относится к приложению - к взаимодействию с пользователем
    //TODO переместить метод в приложение
    /**
     * @brief Обрисовать разрушенный корабль
     * @param ship корабль
     */
    void drawAroundShip(Ship ship) noexcept;


private:
    //TODO документировать данные класса.
    Cell** fieldCells;
    Ship* fieldShips;
    int numberSetShips;




};

#endif // FIELD_H

