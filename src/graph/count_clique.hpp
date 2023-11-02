#pragma once
#include <algorithm>
#include "count_independent_set.hpp"

template <typename T> T count_clique(const std::vector<std::vector<int>>& G) {
    int n = G.size();
    T res = 1;
    std::vector<int> deg(n), idx(n, -1);
    for (int i = 0; i < n; i++) deg[i] = G[i].size();
    while (true) {
        int v = -1;
        for (int i = 0; i < n; i++) {
            if (deg[i] != -1 and (v == -1 or deg[i] < deg[v])) {
                v = i;
            }
        }
        if (v == -1) break;
        deg[v] = -1;
        int adj = 0;
        for (const int& u : G[v]) {
            if (deg[u] == -1) continue;
            --deg[u];
            idx[u] = adj++;
        }
        std::vector<unsigned long long> g(adj, (1ULL << adj) - 1);
        for (const int& u : G[v]) {
            if (idx[u] == -1) continue;
            int x = idx[u];
            g[x] &= ~(1ULL << x);
            for (const int& w : G[u]) {
                if (idx[w] == -1) continue;
                int y = idx[w];
                g[x] &= ~(1ULL << y);
                g[y] &= ~(1ULL << x);
            }
        }
        res += count_independent_set(g);
        for (const int& u : G[v]) {
            if (deg[u] == -1) continue;
            idx[u] = -1;
        }
    }
    return res;
}
