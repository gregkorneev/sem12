#ifndef GREEDY_DFS_H
#define GREEDY_DFS_H

#include "game.h"
#include <vector>
#include <functional>

// Универсальный Greedy DFS: путь от start до клетки, удовлетворяющей isGoal
// heuristic(r,c) — меньшая эвристика = лучше
std::vector<Pos> greedyDFS(
    const GameState &g,
    Pos start,
    std::function<bool(int,int)> isGoal,
    std::function<int(int,int)> heuristic
);

#endif // GREEDY_DFS_H
