#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

struct Pos {
    int r, c;
};

struct GameState {
    int n = 0;
    int m = 0;

    std::vector<std::string> grid; // '.', '#', 'R', 'E', 'B'
    Pos player;
    std::vector<Pos> enemies;
    std::vector<Pos> resources;
    Pos base;
};

bool inBounds(const GameState &g, int r, int c);
int dist(const Pos &a, const Pos &b);
int minDistToList(int r, int c, const std::vector<Pos> &lst);

// старая функция, остается на всякий случай
GameState makeGameState(const std::vector<std::string> &grid);

// новая функция генерации карты
GameState makeRandomGameState(int n, int m);

// печать карты в консоль
void printGrid(const GameState &g);

#endif
