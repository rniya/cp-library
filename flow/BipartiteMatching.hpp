#pragma once
#include "../base.hpp"

/**
 * @brief 2部グラフの最大マッチング
 * @docs docs/flow/BipartiteMatching.md
 */
struct BipartiteMatching {
    vector<vector<int>> G;
    vector<int> match, alive, used;
    int time = 0;
    BipartiteMatching(int n) : G(n), match(n, -1), alive(n, 1), used(n, 0) {}
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bool dfs(int v) {
        used[v] = time;
        for (int u : G[v]) {
            int w = match[u];
            if (!alive[u]) continue;
            if (w < 0 || (used[w] != time && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    int build() {
        int res = 0;
        for (int i = 0; i < G.size(); i++) {
            if (!alive[i]) continue;
            if (~match[i]) continue;
            time++;
            res += dfs(i);
        }
        return res;
    }
    int enable(int v) {
        alive[v] = 1;
        time++;
        return dfs(v);
    }
    int disable(int v) {
        alive[v] = 0;
        if (match[v] < 0) return 0;
        match[v] = -1;
        match[match[v]] = -1;
        time++;
        int res = dfs(match[v]);
        return res - 1;
    }
};