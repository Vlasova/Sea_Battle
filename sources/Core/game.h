#ifndef GAME_H
#define GAME_H

#include <string>
#include <algorithm>
#include "unistd.h"
#include "field.h"



/**
 * @brief Игровой интерфейс
 */
class GameInterface
{
public:
    GameInterface() noexcept;
    ~GameInterface() noexcept;
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

private:
    //TODO документировать данные класса
    Field* userField;
    Field* computerField;


};

#endif // GAME_H

