#ifndef AI_H
#define AI_H

#include "game.h"
#include <vector>

// Уровень 1: путь к ресурсу
std::vector<Pos> findResourcePath(const GameState &g);

// Уровень 2: выбор врага и путь к нему
int chooseEnemyIndex(const GameState &g);
std::vector<Pos> pathToEnemy(const GameState &g, int enemyIdx);

// Уровень 3: путь к базе
std::vector<Pos> pathToBase(const GameState &g);

#endif // AI_H
