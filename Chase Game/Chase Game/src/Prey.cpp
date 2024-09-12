#include "../include/Prey.h"
#include <cstdlib>  // Для функции rand

// Конструктор
Prey::Prey(int x, int y) : Character(x, y) {}

// Метод для движения жертвы
void Prey::move(int direction, int steps = 1) {
    for (int i = 0; i < steps; ++i) {
        switch (direction) {
            case 0:  // Вверх
                if (position.y > 1) position.y -= 1;  
                break;
            case 1:  // Вниз
                if (position.y < height - 1) position.y += 1;  
                break;
            case 2:  // Влево
                if (position.x > 1) position.x -= 1;  
                break;
            case 3:  // Вправо
                if (position.x < width - 1) position.x += 1;  
                break;
            case 4:  // Вниз-влево
                if (position.x > 1 && position.y > 1) {
                    position.x -= 1; 
                    position.y -= 1;
                }
                break;
            case 5:  // Вниз-вправо
                if (position.x < width - 1 && position.y > 1) {
                    position.x += 1; 
                    position.y -= 1;
                }
                break;
            case 6:  // Вверх-влево
                if (position.x > 1 && position.y < height - 1) {
                    position.x -= 1;
                    position.y += 1;
                }
                break;
            case 7:  // Вверх-вправо
                if (position.x < width - 1 && position.y < height - 1) {
                    position.x += 1;
                    position.y += 1;
                }
                break;
        }
    }
}

void Prey::moveRandom() {
    int randomDirection = std::rand() % 8;  // Генерация случайного направления от 0 до 7
    move(randomDirection);
}
