#include "greedy_dfs.h"
#include <algorithm>

using namespace std;

vector<Pos> greedyDFS(
    const GameState &g,
    Pos start,
    function<bool(int,int)> isGoal,
    function<int(int,int)> heuristic
) {
    vector<vector<bool>> visited(g.n, vector<bool>(g.m, false));

    struct Node {
        Pos p;
        vector<Pos> path;
    };

    vector<Node> st;
    st.push_back({start, {start}});
    visited[start.r][start.c] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!st.empty()) {
        Node cur = st.back();
        st.pop_back();

        if (isGoal(cur.p.r, cur.p.c)) {
            return cur.path; // нашли цель
        }

        struct Cand {
            int r, c, h;
        };
        vector<Cand> nbrs;

        for (int k = 0; k < 4; ++k) {
            int nr = cur.p.r + dr[k];
            int nc = cur.p.c + dc[k];
            if (!inBounds(g, nr, nc)) continue;
            if (visited[nr][nc]) continue;
            if (g.grid[nr][nc] == '#') continue;

            int h = heuristic(nr, nc);
            nbrs.push_back({nr, nc, h});
        }

        sort(nbrs.begin(), nbrs.end(), [](const Cand &a, const Cand &b) {
            return a.h < b.h;
        });

        // кладём в стек с конца, чтобы лучшего рассмотреть первым
        for (int i = (int)nbrs.size() - 1; i >= 0; --i) {
            visited[nbrs[i].r][nbrs[i].c] = true;
            vector<Pos> newPath = cur.path;
            newPath.push_back({nbrs[i].r, nbrs[i].c});
            st.push_back({{nbrs[i].r, nbrs[i].c}, newPath});
        }
    }

    return {}; // путь не найден
}
