#ifndef POINT2D_H
#define POINT2D_H

// Класс для работы с координатами
class Point2D {
public:
    int x, y; // Координаты точки, инкапсулированы для защиты данных

public:
    // Конструктор с аргументами по умолчанию
    Point2D(int x = 0, int y = 0);

    // Метод для расчета расстояния между двумя точками
    double distanceTo(const Point2D& other) const;

    // Геттеры для координат
    int getX() const;
    int getY() const;

    // Сеттеры для координат
    void setX(int x);
    void setY(int y);
};

#endif // POINT2D_H
