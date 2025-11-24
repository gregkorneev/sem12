#include "game.h"
#include <climits>

using namespace std;

bool inBounds(const GameState &g, int r, int c) {
    return r >= 0 && r < g.n && c >= 0 && c < g.m;
}

int dist(const Pos &a, const Pos &b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

int minDistToList(int r, int c, const vector<Pos> &lst) {
    int best = INT_MAX;
    for (auto &p : lst) {
        int d = abs(p.r - r) + abs(p.c - c);
        if (d < best) best = d;
    }
    return best;
}

GameState makeGameState(const vector<string> &grid) {
    GameState g;
    g.grid = grid;
    g.n = (int)grid.size();
    g.m = g.n > 0 ? (int)grid[0].size() : 0;

    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.m; ++j) {
            char ch = g.grid[i][j];
            if (ch == 'P') {
                g.player = {i, j};
                g.grid[i][j] = '.'; // чтобы не мешало при поиске
            } else if (ch == 'R') {
                g.resources.push_back({i, j});
            } else if (ch == 'E') {
                g.enemies.push_back({i, j});
            } else if (ch == 'B') {
                g.base = {i, j};
            }
        }
    }

    return g;
}
