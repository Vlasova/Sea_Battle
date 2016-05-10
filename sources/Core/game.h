#ifndef GAME_H
#define GAME_H

#include <string>
#include "field.h"

//TODO зачем в класса с логиков объявление класса из приложения?
class Application;

//Game - не лучшее название для игрового интерфейса. Это же вроде API.
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
    
    //TODO на мой взгляд, удобнее читать код, когда деструктор идет после конструктора сразу.
    ~Game() ;


private:
    //TODO документировать данные класса
    //Player - это игрок. Им может быть и пользователь и компьютер.
    //На мой взгляд в данном случае уместнее будет не player, а user.
    //TODO подумать над этим
    Field* playerField;
    Field* computerField;


};

#endif // GAME_H

