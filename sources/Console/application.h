#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Core/game.h"

/**
 * @brief Консольное приложение
 */
class Application
{
public:
    Application();
    ~Application();
    /**
     * @brief Вывести главное меню
     */
    void mainMenu();
    /**
     * @brief Выбрать способ расстановки кораблей
     */
    void locateShipsMenu();
    /**
     * @brief Начать игру
     */
    void startGameMenu();


private:
    Game* game;

};

#endif // APPLICATION_H

