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

private:
    Game* game;

};

#endif // APPLICATION_H

