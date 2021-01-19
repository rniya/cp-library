#pragma once
#include "../base.hpp"

/**
 * @brief Two Edge Connected Components
 * @docs docs/graph/StronglyConnectedComponents.md
 */
struct TwoEdgeConnectedComponents {
    int time, k;
    vector<int> ord, low, cmp;
    vector<vector<int>> G, C, T;
    vector<pair<int, int>> bridge;
    TwoEdgeConnectedComponents(int n) : time(0), k(0), ord(n, -1), low(n), cmp(n, -1), G(n) {}
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bool is_bridge(int u, int v) {
        if (ord[u] > ord[v]) swap(u, v);
        return ord[u] < low[v];
    }
    void dfs(int v, int p) {
        ord[v] = low[v] = time++;
        int bic = 0;
        for (int u : G[v]) {
            if (u == p && !bic) {
                bic = 1;
                continue;
            }
            if (~ord[u]) {
                low[v] = min(low[v], ord[u]);
                continue;
            }
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (is_bridge(v, u)) bridge.emplace_back(v, u);
        }
    }
    void fill_component(int v) {
        C[cmp[v]].emplace_back(v);
        for (int u : G[v]) {
            if (~cmp[u] || is_bridge(u, v)) continue;
            cmp[u] = cmp[v];
            fill_component(u);
        }
    }
    void add_component(int v) {
        if (~cmp[v]) return;
        cmp[v] = k++;
        C.emplace_back();
        fill_component(v);
    }
    int build() {
        int n = G.size();
        for (int v = 0; v < n; v++) {
            if (ord[v] < 0) dfs(v, -1);
        }
        for (int v = 0; v < n; v++) add_component(v);
        T.resize(k);
        for (auto e : bridge) {
            int u = cmp[e.first], v = cmp[e.second];
            T[u].emplace_back(v);
            T[v].emplace_back(u);
        }
        return k;
    }
    int operator[](int i) const { return cmp[i]; }
};