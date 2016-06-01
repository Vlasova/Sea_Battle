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
     * @return true если все корабли расставлены
     * @return false
     */
    bool locateShipsInput() noexcept;
    /**
     * @brief Узнать, можно ли разместить корабль на данные координаты
     * @param x буквенная координата первой палубы
     * @param y цифровая координата первой палубы
     * @param lenght длина
     * @param location расположение
     * @return true/false
     */
    bool canPlaceShip(int x, int y, int lenght, int number, shipLocation location) noexcept;
    /**
     * @brief Ввод пользователем буквенной координаты
     * @param str строка ввода
     * @return буквенная координата
     */
    int inputX(std::string str) noexcept;
    /**
     * @brief Ввод пользователем цифровой координаты
     * @param str строка ввода
     * @return цифровая кооридната
     */
    int inputY(std::string str) noexcept;
    /**
     * @brief Ввод длины корабля
     * @param str строка ввода
     * @return длина
     */
    int inputLenght(std::string str) noexcept;
    /**
     * @brief Ввод расположения
     * @param str строка ввода
     * @return расположение
     */
    int inputLocation(std::string str) noexcept;
    /**
     * @brief Играть, пока все корабли одного из полей не будут разрушены
     */
    void gameProcess() noexcept;
    /**
     * @brief Команды пользователя
     * @param str строка ввода
     */
    void commands(std::string str) noexcept;
    /**
     * @brief Определить победителя
     */
    void decideWinner() noexcept;
    /**
     * @brief Проверить корректность введенных координат
     * @param x буквенная координата
     * @param y цифровая координата
     * @return true/false
     */
    bool isCoordinatesCorrect(int x, int y) noexcept;
    /**
     * @brief Проверить корректность введенной длины
     * @param lenght длина
     * @return true/false
     */
    bool isLenghtCorrect(int lenght) noexcept;
    /**
     * @brief Проверить корректность расположения
     * @param location расположение
     * @return true/false
     */
    bool isLocationCorrect(int location) noexcept;
    /**
     * @brief Функция, вызываемая при попадании пользователя
     * Проверяет, разрушен ли корабль, в который попали
     * @param x буквенная координата
     * @param y цифровая координата
     */
    void ifUserHit(int x, int y) noexcept;
    /**
     * @brief Функция, вывзваемая при попадании компьютера
     */
    void ifComputerHit() noexcept;
    /**
     * @brief Разместить корабли пользователя автоматически
     */
    void locateShipsAutomatically() noexcept;
    /**
     * @brief Разместить корабли пользователя вручную
     */
    void locateShipsOnOnesOwn() noexcept;
    /**
     * @brief Выйти в главное меню
     */
    void exit() noexcept;
    /**
     * @brief Начать игровой процесс
     */
    void startGame() noexcept;
    /**
     * @brief Разместить корабли заново
     */
    void locateShipsAgain() noexcept;

private:
    //TODO документировать данные класса
    GameAPI* game;

};

#endif // APPLICATION_H

