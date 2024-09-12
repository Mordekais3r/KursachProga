#include <iostream>
#include <thread>
#include <chrono>
#include "../include/Arena.h"
#include <locale>
#include <codecvt> 
#include <windows.h>


int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Инициализация игрового поля: ширина, высота, начальная позиция жертвы, максимальное количество шагов
    Arena arena(30, 30, 1, 2, 10);

    // Передача размеров арены для ограничения движения
    arena.getPrey().setArenaSize(30, 30);
    arena.getPredator().setArenaSize(30, 30);

    arena.startGame();
    return 0;
}
