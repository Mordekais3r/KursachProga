#ifndef PREY_H
#define PREY_H

#include "Character.h"

// Класс жертвы (наследник класса Character)
class Prey : public Character {
public:
    // Конструктор
    Prey(int x = 0, int y = 0);

    // Реализация метода движения жертвы
    void move(int direction, int steps) override;

    // Хаотичное перемещение жертвы (NPC)
    void moveRandom();

    // Методы для задания размеров арены (возможно, потребуется для управления движением)
    void setArenaSize(int w, int h) { width = w; height = h; }

private:
    int width, height; // Размеры арены для ограничения движения
};

#endif // PREY_H
