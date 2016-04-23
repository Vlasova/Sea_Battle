#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Core/game.h"


class Application
{
public:
    Application();
    void mainMenu();
    void startGame();
    void loadGame();
private:
    Game* game;

};

#endif // APPLICATION_H

