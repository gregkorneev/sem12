#include "game.h"
#include <climits>
#include <iostream>
#include <random>
#include <ctime>

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

GameState makeGameState(const vector<string> &raw) {
    GameState g;
    g.n = raw.size();
    g.m = raw[0].size();
    g.grid = raw;

    for (int r = 0; r < g.n; r++) {
        for (int c = 0; c < g.m; c++) {
            char ch = g.grid[r][c];
            if (ch == 'P') {
                g.player = {r, c};
                g.grid[r][c] = '.';
            } else if (ch == 'R') {
                g.resources.push_back({r, c});
            } else if (ch == 'E') {
                g.enemies.push_back({r, c});
            } else if (ch == 'B') {
                g.base = {r, c};
            }
        }
    }
    return g;
}

GameState makeRandomGameState(int n, int m) {
    GameState g;
    g.n = n;
    g.m = m;
    g.grid.assign(n, string(m, '.'));

    static mt19937 rng((unsigned) time(nullptr));
    uniform_real_distribution<> prob(0.0, 1.0);

    // рамка и случайные внутренние стены
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (r==0 || r==n-1 || c==0 || c==m-1)
                g.grid[r][c] = '#';
            else
                g.grid[r][c] = (prob(rng) < 0.15 ? '#' : '.');
        }
    }

    auto randomFree = [&]() {
        uniform_int_distribution<int> R(1, n-2);
        uniform_int_distribution<int> C(1, m-2);
        while (true) {
            int r = R(rng);
            int c = C(rng);
            if (g.grid[r][c] == '.')
                return Pos{r, c};
        }
    };

    g.player = randomFree();
    g.base = randomFree();
    g.grid[g.base.r][g.base.c] = 'B';

    uniform_int_distribution<int> Cnt(2,3);

    int resN = Cnt(rng);
    for (int i = 0; i < resN; i++) {
        Pos p = randomFree();
        g.resources.push_back(p);
        g.grid[p.r][p.c] = 'R';
    }

    int eneN = Cnt(rng);
    for (int i = 0; i < eneN; i++) {
        Pos p = randomFree();
        g.enemies.push_back(p);
        g.grid[p.r][p.c] = 'E';
    }

    return g;
}

void printGrid(const GameState &g) {
    vector<string> vis = g.grid;

    for (auto &r : g.resources) vis[r.r][r.c] = 'R';
    for (auto &e : g.enemies) vis[e.r][e.c] = 'E';
    vis[g.base.r][g.base.c] = 'B';
    vis[g.player.r][g.player.c] = 'P';

    cout << "Карта:\n";
    for (auto &row : vis) cout << row << endl;
    cout << endl;
}
