#ifndef GAME_H
#define GAME_H

#include <string>
#include "field.h"
#include "enums.h"

class Appication;

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
    /**
     * @brief Команды пользователя
     * @param str строка с командой
     */
    void commands(std::string str);

    ~Game() ;


private:
    Field* playerField;
    Field* computerField;


};

#endif // GAME_H

