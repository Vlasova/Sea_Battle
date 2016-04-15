#ifndef GAME_H
#define GAME_H

#include "field.h"


class Game{
public:
    Game();
    void startNewGame();
    void locateShips();
    void locateShipsRandomly();
    void makeMove();
    Field* getField() const;


private:
    Field* field;


};

#endif // GAME_H

