#include <iostream>
#include <vector>
#include "game.h"
#include "ai.h"

using namespace std;

void printPath(const vector<Pos> &path, const string &label) {
    cout << label << " (длина " << path.size() << "):\n";
    for (auto &p : path) {
        cout << "(" << p.r << "," << p.c << ") ";
    }
    cout << "\n\n";
}

int main() {
    vector<string> grid = {
        "##########",
        "#P...R...#",
        "#..##....#",
        "#..E....B#",
        "#....R...#",
        "##########"
    };

    GameState g = makeGameState(grid);

    // Уровень 1: поиск ресурса
    auto resourcePath = findResourcePath(g);
    printPath(resourcePath, "Путь к ресурсу");

    // Уровень 2: атака врага
    int enemyIdx = chooseEnemyIndex(g);
    cout << "Выбран враг с индексом " << enemyIdx << "\n";
    auto enemyPath = pathToEnemy(g, enemyIdx);
    printPath(enemyPath, "Путь к врагу");

    // Уровень 3: захват базы
    auto basePath = pathToBase(g);
    printPath(basePath, "Путь к базе");

    return 0;
}
