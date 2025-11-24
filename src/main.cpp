#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#include "game.h"
#include "ai.h"

using namespace std;

void writeJson(const GameState &g,
               const vector<Pos> &pr,
               const vector<Pos> &pe,
               const vector<Pos> &pb)
{
    std::filesystem::create_directories("output");

    ofstream f("output/map_latest.json");
    f << "{\n";
    f << "  \"n\": " << g.n << ",\n";
    f << "  \"m\": " << g.m << ",\n";

    f << "  \"grid\": [\n";
    for (int i = 0; i < g.n; i++) {
        f << "    \"" << g.grid[i] << "\"";
        if (i + 1 < g.n) f << ",";
        f << "\n";
    }
    f << "  ],\n";

    f << "  \"player\": [" << g.player.r << "," << g.player.c << "],\n";

    auto writeList = [&](const string &name, const vector<Pos> &lst) {
        f << "  \"" << name << "\": [";
        for (int i = 0; i < lst.size(); i++) {
            f << "[" << lst[i].r << "," << lst[i].c << "]";
            if (i + 1 < lst.size()) f << ",";
        }
        f << "],\n";
    };

    writeList("resources", g.resources);
    writeList("enemies", g.enemies);

    f << "  \"base\": [" << g.base.r << "," << g.base.c << "],\n";

    writeList("path_resource", pr);
    writeList("path_enemy",    pe);
    writeList("path_base",     pb);

    f << "  \"ok\": true\n}\n";
}

int main() {
    const int N = 10;
    const int M = 10;

    GameState g = makeRandomGameState(N, M);

    auto pr = findResourcePath(g);
    int ei = chooseEnemyIndex(g);
    auto pe = pathToEnemy(g, ei);
    auto pb = pathToBase(g);

    writeJson(g, pr, pe, pb);

    printGrid(g);
    cout << "JSON записан в output/map_latest.json\n";

    return 0;
}
