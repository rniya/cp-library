#pragma once
#include <queue>
#include <vector>

std::vector<std::vector<int>> enumerate_cliques(std::vector<std::vector<bool>> G) {
    int n = G.size(), m = 0;
    std::vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) deg[i] += G[i][j];
        m += deg[i];
    }
    std::vector<std::vector<int>> cliques;

    auto add_clique = [&](const std::vector<int>& cand, bool last) {
        int size = cand.size() - last;
        std::vector<int> not_adj(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j && !G[cand[i]][cand[j]]) {
                    not_adj[i] |= 1 << j;
                }
            }
        }
        for (int mask = 1 - last; mask < (1 << (size)); mask++) {
            bool ok = true;
            for (int i = 0; i < size; i++) {
                if ((mask >> i & 1) && (mask & not_adj[i])) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            std::vector<int> clique;
            if (last) clique.emplace_back(cand.back());
            for (int i = 0; i < size; i++) {
                if (mask >> i & 1) {
                    clique.emplace_back(cand[i]);
                }
            }
            cliques.emplace_back(clique);
        }
    };

    std::vector<bool> used(n, false);
    std::queue<int> que;
    for (int i = 0; i < n; i++) {
        if (deg[i] * (deg[i] + 1) <= m) {
            used[i] = true;
            que.emplace(i);
        }
    }
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        std::vector<int> cand;
        for (int u = 0; u < n; u++) {
            if (G[v][u]) {
                cand.emplace_back(u);
            }
        }
        cand.emplace_back(v);
        add_clique(cand, true);
        for (int u = 0; u < n; u++) {
            if (!G[v][u]) continue;
            G[v][u] = G[u][v] = false;
            deg[u]--;
            if (!used[u] && deg[u] * (deg[u] + 1) <= m) {
                used[u] = true;
                que.emplace(u);
            }
        }
    }
    std::vector<int> rest;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            rest.emplace_back(i);
        }
    }
    add_clique(rest, false);
    return cliques;
}
