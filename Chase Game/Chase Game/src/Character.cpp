#include "../include/Character.h"

// Конструктор
Character::Character(int x, int y) : position(x, y) {}

// Метод для получения текущей позиции персонажа
Point2D Character::getPosition() const {
    return position;
}
void Character::setControlledByPlayer(bool isPlayerControlled) {
    controlledByPlayer = isPlayerControlled;
}

bool Character::isControlledByPlayer() const {
    return controlledByPlayer;
}
