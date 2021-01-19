#pragma once
#include "../base.hpp"

/**
 * @brief Prim
 * @docs docs/graph/Prim.md
 */
template <typename T> struct Prim {
    using P = pair<T, int>;
    int n;
    vector<vector<pair<int, T>>> G;
    vector<bool> used;
    Prim(int n) : n(n), G(n), used(n, false) {}
    void add_edge(int u, int v, T c) {
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }
    T build() {
        T res = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            if (used[p.second]) continue;
            used[p.second] = true;
            res += p.first;
            for (auto e : G[p.second]) {
                pq.emplace(e.second, e.first);
            }
        }
        return res;
    }
};