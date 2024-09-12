#ifndef CHARACTER_H
#define CHARACTER_H

#include "Point2D.h"

// Базовый класс для персонажей игры
class Character {
protected:
    Point2D position; // Координаты персонажа
    bool controlledByPlayer;


public:
    // Конструктор с возможностью задания начальной позиции
    Character(int x = 0, int y = 0);

    // Чисто виртуальный метод для движения персонажа
    virtual void move(int direction, int steps) = 0;

    // Метод для получения текущей позиции персонажа
    Point2D getPosition() const;

    // Установка флага, управляется ли персонаж игроком
    void setControlledByPlayer(bool isPlayerControlled);

    // Проверка, управляется ли персонаж игроком
    bool isControlledByPlayer() const;
};

#endif // CHARACTER_H
