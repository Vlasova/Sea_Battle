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
    /**
     * @brief Вывести поле на экран
     */
    void printField();
    /**
     * @brief Разместить корабли игрока вручную
     * @return  true/false
     */
    bool locateShipsInput();
    /**
     * @brief Проверить корректность ввода при расстановке кораблей
     * @param x буквенная координата первой палубы
     * @param y цифровая координата первой палубы
     * @param lenght длина
     * @param line расположение
     */
    void isInputCorrect(int x, int y, int lenght, shipLine line);
    /**
     * @brief Играть, пока все корабли одного из полей не будут разрушены
     */
    void gameProcess();
    /**
     * @brief Команды пользователя
     * @param str строка с командой
     */
    void commands(std::string str);
    /**
     * @brief Определить победителя
     */
    void decideWinner();
    /**
     * @brief Проверить корректность ввода при совершении хода
     * @param x буквенная координата
     * @param y цифровая координата
     */
    void isCoordinatesCorrect(int x, int y);


private:
    //TODO документировать данные класса
    Game* game;

};

#endif // APPLICATION_H

