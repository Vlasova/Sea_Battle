#ifndef SEA_BATTLE_API_H
#define SEA_BATTLE_API_H

class Sea_Battle_API{

public:

    /**
     * @brief Начать новую игру
     */
    virtual void start_new_game()=0;
    /**
     * @brief Продолжить сохраненную игру
     */
    virtual void continue_saved_game()=0;
    /**
     * @brief Сохранить игру
     */
    virtual void save_game()=0;
    /**
     * @brief Разместить корабли
     */
    virtual void locate_ships()=0;
    /**
     * @brief Сделать ход на указанные игроком координаты
     */
    virtual void make_move()=0;
    /**
     * @brief Пометить клетку крестиком, если игрок попал в корабль противника
     */
    virtual void place_cross()=0;
    /**
     * @brief Пометить клетку точкой, если игрок не попал
     */
    virtual void place_point()=0;

};

#endif // SEA_BATTLE_API_H
