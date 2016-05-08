#ifndef GAME_H
#define GAME_H

#include <string>
#include "field.h"
#include "enums.h"

class Application;

/**
 * @brief Игровой интерфейс
 */
class Game
{
public:
    Game();
    /**
     * @brief Разместить корабли
     * @return true/false
     */
    bool locateShips();
    /**
     * @brief Совершить ход компьютера
     * @return true/false
     */
    bool makeComputerMove();
    /**
     * @brief Совершить ход игрока
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true/false
     */
    bool makeMove(int x, int y);
    /**
     * @brief Получить поле игрока
     * @return указатель на поле игрока
     */
    Field* getPlayerField() const;
    /**
     * @brief Получить поле компьютера
     * @return указатель на поле компьютера
     */
    Field* getComputerField() const;
    ~Game() ;


private:
    Field* playerField;
    Field* computerField;


};

#endif // GAME_H

