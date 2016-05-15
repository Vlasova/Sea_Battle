#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Core/game.h"

/**
 * @brief Консольное приложение
 */
class Application
{
public:
    Application() noexcept;
    ~Application() noexcept;
    /**
     * @brief Вывести главное меню
     */
    void mainMenu() noexcept;
    /**
     * @brief Выбрать способ расстановки кораблей
     */
    void locateShipsMenu() noexcept;
    /**
     * @brief Начать игру
     */
    void startGameMenu() noexcept;
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
    bool locateShipsInput() noexcept;
    /**
     * @brief Проверить корректность ввода при расстановке кораблей
     * @param x буквенная координата первой палубы
     * @param y цифровая координата первой палубы
     * @param lenght длина
     * @param line расположение
     */
    bool canPlaceShip(int x, int y, int lenght, int number, shipLocation location) noexcept;
    int inputX(std::string str) noexcept;
    int inputY(std::string str) noexcept;
    int inputLenght(std::string str) noexcept;
    int inputLocation(std::string str) noexcept;
    /**
     * @brief Играть, пока все корабли одного из полей не будут разрушены
     */
    void gameProcess() noexcept;
    /**
     * @brief Команды пользователя
     * @param str строка с командой
     */
    void commands(std::string str) noexcept;
    /**
     * @brief Определить победителя
     */
    void decideWinner() noexcept;
    /**
     * @brief Проверить корректность ввода при совершении хода
     * @param x буквенная координата
     * @param y цифровая координата
     */
    bool isCoordinatesCorrect(int x, int y) noexcept;
    bool isLenghtCorrect(int lenght) noexcept;
    bool isLocationCorrect(int number) noexcept;
    void ifUserHit(int x, int y) noexcept;
    void ifComputerHit() noexcept;
    void locateShipsAutomatically() noexcept;
    void locateShipsOnOnesOwn() noexcept;
    void exit() noexcept;
    void startGame() noexcept;
    void locateShipsAgain() noexcept;

private:
    //TODO документировать данные класса
    GameInterface* game;

};

#endif // APPLICATION_H

