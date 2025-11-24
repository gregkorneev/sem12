#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

struct Pos {
    int r, c;
};

struct GameState {
    std::vector<std::string> grid;    // карта: . # R E B
    Pos player;                       // позиция игрока
    std::vector<Pos> enemies;         // враги
    std::vector<Pos> resources;       // ресурсы
    Pos base;                         // база
    int n = 0, m = 0;
};

bool inBounds(const GameState &g, int r, int c);

// Манхэттенское расстояние
int dist(const Pos &a, const Pos &b);

// Минимальное расстояние до любой клетки из списка
int minDistToList(int r, int c, const std::vector<Pos> &lst);

// Инициализация GameState из вектора строк карты
GameState makeGameState(const std::vector<std::string> &grid);

#endif // GAME_H
