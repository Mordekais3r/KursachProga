#ifndef PREDATOR_H
#define PREDATOR_H

#include "Character.h"
#include "Prey.h"

// Класс хищника (наследник класса Character)
class Predator : public Character {
public:
    // Конструктор
    Predator(int x = 0, int y = 0);

    // Реализация метода движения хищника
    void move(int direction, int steps) override;

    // Метод для движения хищника в сторону жертвы
    void moveTowards(const Prey& prey);

    void setArenaSize(int w, int h) { width = w; height = h; }


private:
    int width, height; // Размеры арены для ограничения движения
};

#endif // PREDATOR_H
