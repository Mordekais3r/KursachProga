#include "../include/Point2D.h"
#include <cmath> // Для функции sqrt и pow

// Конструктор
Point2D::Point2D(int x, int y) : x(x), y(y) {}

// Метод для расчета расстояния между двумя точками
double Point2D::distanceTo(const Point2D& other) const {
    if (x == other.x && y == other.y) {
        return 0.0;  // Если точки совпадают, возвращаем 0
    }
    int dx = x - other.x;
    int dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Геттер для x
int Point2D::getX() const {
    return x;
}

// Геттер для y
int Point2D::getY() const {
    return y;
}

// Сеттер для x
void Point2D::setX(int x) {
    this->x = x;
}

// Сеттер для y
void Point2D::setY(int y) {
    this->y = y;
}
