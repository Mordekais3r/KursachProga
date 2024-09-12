#include "../include/Predator.h"
#include <cmath>
#include <cstdlib> // для функции rand()
#include <algorithm>

// Конструктор
Predator::Predator(int x, int y) : Character(x, y) {}

// Реализация метода move()
void Predator::move(int direction, int steps) {
    // Убедимся, что количество шагов находится в пределах от 1 до 3
    steps = std::max(1, std::min(steps, 3));

    switch (direction) {
        case 0: position.setY(position.getY() - steps); break; // Вверх
        case 1: position.setY(position.getY() + steps); break; // Вниз
        case 2: position.setX(position.getX() - steps); break; // Влево
        case 3: position.setX(position.getX() + steps); break; // Вправо
    }

    // Убедимся, что хищник не выходит за границы арены
    position.x = std::max(0, std::min(position.x, width - 1));
    position.y = std::max(0, std::min(position.y, height - 1));
}

// Метод для движения хищника в сторону жертвы
void Predator::moveTowards(const Prey& prey) {
    Point2D preyPos = prey.getPosition();

    // Вычисляем разницу в координатах
    int deltaX = preyPos.x - position.x;
    int deltaY = preyPos.y - position.y;

    // Выбираем направление и оптимальное количество шагов
    if (std::abs(deltaX) > std::abs(deltaY)) {
        // Движение по оси X
        int stepSize = std::min(3, std::abs(deltaX)); // Оптимальное количество шагов (не больше 3)
        if (deltaX > 0) {
            position.x += stepSize;
        } else {
            position.x -= stepSize;
        }
    } else {
        // Движение по оси Y
        int stepSize = std::min(3, std::abs(deltaY)); // Оптимальное количество шагов (не больше 3)
        if (deltaY > 0) {
            position.y += stepSize;
        } else {
            position.y -= stepSize;
        }
    }

    // Убедимся, что хищник не выходит за границы арены
    position.x = std::max(0, std::min(position.x, width - 1));
    position.y = std::max(0, std::min(position.y, height - 1));
}
