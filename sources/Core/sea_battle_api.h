#ifndef SEA_BATTLE_API_H
#define SEA_BATTLE_API_H
#include "field.h"

class SeaBattleAPI{

public:

    /**
     * @brief Начать новую игру
     */
    virtual void startNewGame()=0;
    /**
     * @brief Продолжить сохраненную игру
     */
    virtual void continueSavedGame()=0;
    /**
     * @brief Сохранить игру
     */
    virtual void saveGame()=0;
    /**
     * @brief Разместить корабли
     */
    virtual void locateShips()=0;
    /**
     * @brief Сделать ход на указанные игроком координаты
     */
    virtual void makeMove()=0;
    /**
     * @brief Получить указатель на игровое поле
     */
    virtual Field &getField()=0;


};

#endif // SEA_BATTLE_API_H
