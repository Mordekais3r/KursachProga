#include "../include/Arena.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

// Конструктор арены
Arena::Arena(int w, int h, int preyX, int preyY, int maxSteps)
    : width(w), height(h), maxSteps(maxSteps), currentStep(0), prey(preyX, preyY), predator(w / 2, h / 2) {
    // Инициализация генератора случайных чисел для хаотичного движения жертвы
    std::srand(std::time(0));
}

// Метод отображения игрового поля
void Arena::display() {
    #ifdef _WIN32
        system("cls");  // Очистка экрана в Windows
    #endif
    
    std::cout << "Оставшиеся шаги: " << (maxSteps - currentStep) << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    for (int y = height; y > 0; --y) {
        std::cout << (y < 10 ? " " : "") << y << " ";  // Отображение координаты Y

        for (int x = 1; x <= width; ++x) {
            if (x == prey.getPosition().getX() && y == prey.getPosition().getY()) {
                std::cout << "()  ";  // Обозначение жертвы
                x++;  // Пропускаем одну клетку, так как жертва занимает 2 символа
            } else if (x == predator.getPosition().getX() && y == predator.getPosition().getY()) {
                std::cout << "**  ";  // Обозначение хищника
                x++;  // Пропускаем одну клетку, так как хищник занимает 2 символа
            } else {
                std::cout << "  ";  // Пустое пространство
            }
        }
        std::cout << " |" << std::endl;  // Вертикальная линия по правому краю
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // Отображение координаты X
    std::cout << "  ";
    for (int x = 1; x <= width; ++x) {
        std::cout << (x < 10 ? " " : "") << x;
    }
    std::cout << std::endl;
}

// Метод обновления состояния игры
void Arena::update(int direction, int steps) {
    if (prey.isControlledByPlayer()) {
        prey.move(direction, 1);  // Перемещаем жертву согласно введенному направлению
    } else {
        prey.moveRandom();  // Жертва, управляемая NPC, двигается хаотично
    }

    if (predator.isControlledByPlayer()) {
        predator.move(direction, steps);  // Перемещаем хищника, если он под контролем игрока
    } else {
        predator.moveTowards(prey);  // Хищник, управляемый NPC, перемещается в направлении жертвы
    }

    currentStep++;
}

// Метод проверки окончания игры
// Метод проверки окончания игры
bool Arena::isGameOver() {
    // Хищник догнал жертву, если находится в непосредственной близости по горизонтали или вертикали.
    bool predatorCaughtPrey = std::abs(predator.getPosition().getX() - prey.getPosition().getX()) <= 1 &&
                              std::abs(predator.getPosition().getY() - prey.getPosition().getY()) <= 0;

    // Игра заканчивается, если хищник догнал жертву или если шаги закончились
    return predatorCaughtPrey || currentStep >= maxSteps;
}


// Основной игровой цикл
void Arena::startGame() {
    std::cout << "Добро пожаловать в игру 'Chase Game'!" << std::endl;
    std::cout << "Выберите персонажа: P (Жертва) или H (Хищник)." << std::endl;
    std::cout << "Перемещение осуществляется с помощью клавиш 0-7." << std::endl;
    std::cout << "0 - Вниз, 1 - Вверх, 2 - Влево, 3 - Вправо," << std::endl;
    std::cout << "4 - Вниз-влево, 5 - Вниз-вправо, 6 - Вверх-влево, 7 - Вверх-вправо." << std::endl;

    char choice;
    std::cout << "Выберите персонажа (P - жертва, H - хищник): ";
    std::cin >> choice;

    bool playerIsPrey = (choice == 'P' || choice == 'p');
    prey.setControlledByPlayer(playerIsPrey);
    predator.setControlledByPlayer(!playerIsPrey);

    while (!isGameOver()) {
        display();

        int direction;
        if (!playerIsPrey) {  // Если игрок управляет хищником
            std::cout << "0 - Вниз, 1 - Вверх, 2 - Влево, 3 - Вправо," << std::endl;
        }
        else {
            std::cout << "0 - Вниз, 1 - Вверх, 2 - Влево, 3 - Вправо," << std::endl;
            std::cout << "4 - Вниз-влево, 5 - Вниз-вправо, 6 - Вверх-влево, 7 - Вверх-вправо." << std::endl;
        }

        std::cout << "Куда двигаемся? (0-7): ";
        std::cin >> direction;

        // Проверка корректности ввода направления
        if (direction < 0 || direction > 7) {
            std::cout << "Неверное направление. Попробуйте снова." << std::endl;
            continue;
        }

        int steps = 1;
        if (!playerIsPrey) {  // Если игрок управляет хищником
            std::cout << "Сколько шагов? (1-3): ";
            std::cin >> steps;

            // Проверка корректности ввода количества шагов
            if (steps < 1 || steps > 3) {
                std::cout << "Неверное количество шагов. Попробуйте снова." << std::endl;
                continue;
            }
        }

        update(direction, steps);  // Обновляем положение персонажей

        std::this_thread::sleep_for(std::chrono::seconds(1));  // Задержка для удобства наблюдения
    }

    std::cout << "Игра завершена!" << std::endl;
}

// Реализация метода для получения объекта жертвы
Prey& Arena::getPrey() {
    return prey;
}

// Реализация метода для получения объекта хищника
Predator& Arena::getPredator() {
    return predator;
}
