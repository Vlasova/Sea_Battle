#ifndef GAME_H
#define GAME_H

#include "enums.h"
#include "field.h"

class Field;

class Game{
public:
    Game();
    ~Game();
    void startNewGame();
    void locateShips();
    void makeMove();
    void makeComputerMove();
    Field* getPlayerField() const;
    Field* getComputerField() const;
    void printField();
    void decideWinner();


private:
    Field* playerField;
    Field* computerField;


};

#endif // GAME_H

