#include "ai.h"
#include "greedy_dfs.h"
#include <climits>

using namespace std;

// Уровень 1: поиск ресурса
vector<Pos> findResourcePath(const GameState &g) {
    if (g.resources.empty()) return {};

    auto isGoal = [&](int r, int c) -> bool {
        return g.grid[r][c] == 'R';
    };

    auto heuristic = [&](int r, int c) -> int {
        return minDistToList(r, c, g.resources);
    };

    return greedyDFS(g, g.player, isGoal, heuristic);
}

// Уровень 2: выбор врага (жадно по расстоянию)
int chooseEnemyIndex(const GameState &g) {
    if (g.enemies.empty()) return -1;
    int bestIdx = 0;
    int bestDist = dist(g.player, g.enemies[0]);
    for (int i = 1; i < (int)g.enemies.size(); ++i) {
        int d = dist(g.player, g.enemies[i]);
        if (d < bestDist) {
            bestDist = d;
            bestIdx = i;
        }
    }
    return bestIdx;
}

vector<Pos> pathToEnemy(const GameState &g, int enemyIdx) {
    if (enemyIdx < 0 || enemyIdx >= (int)g.enemies.size()) return {};
    Pos target = g.enemies[enemyIdx];

    auto isGoal = [&](int r, int c) -> bool {
        return (r == target.r && c == target.c);
    };

    auto heuristic = [&](int r, int c) -> int {
        return abs(r - target.r) + abs(c - target.c);
    };

    return greedyDFS(g, g.player, isGoal, heuristic);
}

// Уровень 3: путь к базе
vector<Pos> pathToBase(const GameState &g) {
    Pos target = g.base;

    auto isGoal = [&](int r, int c) -> bool {
        return (r == target.r && c == target.c);
    };

    auto heuristic = [&](int r, int c) -> int {
        return abs(r - target.r) + abs(c - target.c);
    };

    return greedyDFS(g, g.player, isGoal, heuristic);
}
