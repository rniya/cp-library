#pragma once
#include "../base.hpp"

/**
 * @brief Bellman Ford
 * @docs docs/graph/BellmanFord.md
 */
template <typename T> struct BellmanFord {
    const T inf = numeric_limits<T>::max();
    struct edge {
        int u, v;
        T w;
        edge(int u, int v, T w) : u(u), v(v), w(w) {}
    };
    int n;
    vector<vector<int>> G;
    vector<int> check, reach;
    vector<edge> es;
    BellmanFord(int n) : n(n), G(n), check(n), reach(n, 1) {}
    void add_edge(int u, int v, T w) {
        es.emplace_back(u, v, w);
        G[u].emplace_back(v);
    }
    vector<T> build(int s, int& neg_loop) {
        vector<T> d(n, inf);
        d[s] = 0;
        for (int i = 0; i < n; i++) {
            bool update = false;
            for (auto e : es) {
                if (!reach[e.u] || !reach[e.v] || d[e.u] == inf) continue;
                if (d[e.u] + e.w < d[e.v]) {
                    d[e.v] = d[e.u] + e.w;
                    update = true;
                }
            }
            if (!update) break;
            if (i == n - 1) {
                neg_loop = 1;
                return d;
            }
        }
        neg_loop = 0;
        return d;
    }
    void dfs(int v) {
        if (check[v]) return;
        check[v] = 1;
        for (int u : G[v]) dfs(u);
    }
    T shortest_path(int s, int t, int& neg_loop) {
        for (int i = 0; i < n; i++) {
            fill(check.begin(), check.end(), 0);
            dfs(i);
            reach[i] = check[t];
        }
        return build(s, neg_loop)[t];
    }
};