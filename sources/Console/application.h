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
     * @brief Вывести оба поля на экран
     */
    void printFields() noexcept;
    /**
     * @brief Вывести поле пользователя
     */
    void  printUserFieldLine(int lineNumber) noexcept;
    /**
      * @brief Вывести поле компьютера
      */
    void printComputerFieldLine(int lineNumber) noexcept;
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
    bool isInputCorrect(int x, int y, int lenght, int number, shipLocation location);
    int inputX(std::string str);
    int inputY(std::string str);
    int inputLenght(std::string str);
    int inputLocation(std::string str);
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
    GameInterface* game;

};

#endif // APPLICATION_H

