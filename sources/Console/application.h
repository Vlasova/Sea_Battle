#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Core/game.h"


class Application
{
public:
    Application();
    ~Application();
    void mainMenu();
    void locateShipsMenu();
    void startGameMenu();
    void startGame();
    void loadGame();
private:
    Game* game;

};

#endif // APPLICATION_H

