#ifndef GAME_H
#define GAME_H

#include "field.h"

class Field;

class Game{
public:
    Game();
    void startNewGame();
    void locateShips();
    void makeMove();
    void makeComputerMove();
    Field* getPlayerField() const;
    Field* getComputerField() const;
    void printField();


private:
    Field* playerField;
    Field* computerField;


};

#endif // GAME_H

