#ifndef SEA_BATTLE_API_H
#define SEA_BATTLE_API_H

class Sea_Battle_API{

public:

    /// Начать новую игру
    void start_new_game();
    /// Продолжить сохраненную игру
    void continue_saved_game();
    /// Сохранить игру
    void save_game();
    /// Разместить корабли
    void locate_ships();
    /// Сделать ход на указанные игроком координаты
    void make_move();
    /// Пометить клетку крестиком, если игрок попал в корабль противника
    void place_cross();
    /// Пометить клетку точкой, если игрок не попал
    void place_point();
    /// Получить текущий статус игры
    void get_status();
};

#endif // SEA_BATTLE_API_H
