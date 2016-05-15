#ifndef CELL_H
#define CELL_H

enum class cellStatus {whole, stricken, blank, tried};

/**
 * @brief Клетка игрового поля
 */
class Cell
{
public:
    Cell() noexcept;
    Cell(int x, int y) noexcept;
    Cell(int x, int y, cellStatus status) noexcept;

    Cell& operator=(const Cell& other) noexcept;
    bool operator==(const Cell& other) const noexcept;

    /**
     * @brief Установить буквенную координату клетки
     * @param x буквенная координата
     */
    void setX(int x) noexcept;
    /**
     * @brief Установить цифровую координату клетки
     * @param y цифровая координата
     */
    void setY(int y) noexcept;
    /**
     * @brief Установить статус клетки
     * @param status статус
     */
    void setStatus(cellStatus status) noexcept;
    /**
     * @brief Получить статус клетки
     * @return статус
     */
    cellStatus getStatus() const noexcept;
    /**
     * @brief Получить буквенную координату
     * @return буквенная координата
     */
    int getX() const noexcept;
    /**
     * @brief Получить цифровую координату
     * @return цифровая координата
     */
    int getY() const noexcept;

private:
    //TODO задокументировать данные класса http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
    int x;
    int y;
    cellStatus status;

};


#endif // CELL_H

