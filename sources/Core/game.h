#ifndef GAME_H
#define GAME_H

#include <string>
#include <algorithm>
#include "unistd.h"
#include "field.h"

//Game - не лучшее название для игрового интерфейса. Это же вроде API.
/**
 * @brief Игровой интерфейс
 */
class Game
{
public:
    Game() noexcept;
    ~Game() noexcept;
    /**
     * @brief Разместить корабли
     * @return true/false
     */
    bool locateShips() noexcept;
    /**
     * @brief Совершить ход компьютера
     * @return true/false
     */
    bool makeComputerMove() noexcept;
    /**
     * @brief Совершить ход игрока
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true/false
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
    
    //TODO на мой взгляд, удобнее читать код, когда деструктор идет после конструктора сразу.



private:
    //TODO документировать данные класса
    //Player - это игрок. Им может быть и пользователь и компьютер.
    //На мой взгляд в данном случае уместнее будет не player, а user.
    //TODO подумать над этим
    Field* userField;
    Field* computerField;


};

#endif // GAME_H

