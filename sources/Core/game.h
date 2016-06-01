#ifndef GAME_H
#define GAME_H

#include <string>
#include <algorithm>

#include "field.h"



/**
 * @brief Игровой интерфейс
 */
class GameAPI
{
public:
    GameAPI() noexcept;
    ~GameAPI() noexcept;
    /**
     * @brief Совершить ход компьютера
     * @return true при попадании
     * @return false при промахе
     */
    bool makeComputerMove() noexcept;
    /**
     * @brief Совершить ход игрока
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true при попадании
     * @return false при промахе
     */
    bool makeUserMove(int x, int y) noexcept;
    /**
     * @brief Получить поле игрока
     * @return указатель на поле игрока
     */
    Field* getUserField() const noexcept;
    /**
     * @brief Получить поле компьютера
     * @return указатель на поле компьютера
     */
    Field* getComputerField() const noexcept;
    /**
     * @brief Разместить корабль пользователя
     * @param x буквенная координата
     * @param y цифровая координата
     * @param lenght длина
     * @param location расположение
     */
    void placeUserShip(int x, int y, int lenght, shipLocation location) noexcept;
    /**
     * @brief Разместить корабли автоматически
     * @param field указатель на поле
     */
    void placeShipsAutomatically(Field* field) noexcept;
    /**
     * @brief Узнать, все ли корабли разрушены
     * @param field указатель на поле
     * @return true/false
     */
    bool allShipsDestroyed(Field* field) noexcept;


private:

    Field* userField;
    Field* computerField;


};

#endif // GAME_H

