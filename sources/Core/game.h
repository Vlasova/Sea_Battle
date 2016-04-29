#ifndef GAME_H
#define GAME_H

#include "field.h"
#include "enums.h"

/**
 * @brief Игровой интерфейс
 */
class Game
{
public:
    Game();
    /**
     * @brief Начать новую игру
     */
    void startNewGame();
    /**
     * @brief Разместить корабли
     */
    void locateShips();
    /**
     * @brief Играть, пока все корабли одного из полей не будут разрушены
     */
    void gameProcess();
    /**
     * @brief Совершить ход компьютера
     */
    void makeComputerMove();
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
    /**
     * @brief Вывести поле на экран
     */
    void printField();
    /**
     * @brief Определить победителя
     */
    void decideWinner();
    ~Game() ;


private:
    Field* playerField;
    Field* computerField;


};

#endif // GAME_H

