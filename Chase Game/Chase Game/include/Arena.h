#ifndef ARENA_H
#define ARENA_H

#include "Character.h"
#include "Prey.h"
#include "Predator.h"

class Arena {
private:
    int width;
    int height;
    int maxSteps;
    int currentStep;
    Prey prey;
    Predator predator;

public:
    Arena(int w, int h, int preyX, int preyY, int maxSteps);

    void display();             // Отображение игрового поля
    void update(int direction, int steps); // Обновление состояния игры
    bool isGameOver();          // Проверка окончания игры

    void startGame();           // Основной игровой цикл

    Prey& getPrey();            // Метод для получения объекта жертвы
    Predator& getPredator();    // Метод для получения объекта хищника
};

#endif // ARENA_H
