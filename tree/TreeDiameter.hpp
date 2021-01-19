#pragma once
#include "../base.hpp"

/**
 * @brief Tree Diameter
 * @docs docs/tree/TreeDiameter.md
 */
template <typename T> struct TreeDiameter {
    vector<T> dp, par;
    vector<vector<pair<int, T>>> G;
    TreeDiameter(int n) : dp(n), par(n), G(n) {}
    void add_edge(int u, int v, T c) {
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }
    void dfs(int v, int p, int& s) {
        par[v] = p;
        if (p < 0) dp[v] = T(0);
        if (dp[s] < dp[v]) s = v;
        for (auto e : G[v]) {
            int u = e.first;
            if (u == p) continue;
            dp[u] = dp[v] + e.second;
            dfs(u, v, s);
        }
    }
    pair<int, int> endPoints() {
        int s = 0;
        dfs(s, -1, s);
        int t = s;
        dfs(t, -1, t);
        return make_pair(s, t);
    }
    T build() {
        int t = endPoints().second;
        return dp[t];
    }
    vector<int> restore() {
        int t = endPoints().second;
        vector<int> res;
        while (~t) {
            res.emplace_back(t);
            t = par[t];
        }
        return res;
    }
    vector<T> distance(int v) {
        dfs(v, -1, v);
        return dp;
    }
    vector<T> farthest() {
        int t = endPoints().second;
        auto ds = dp;
        auto dt = distance(t);
        for (int i = 0; i < ds.size(); i++) ds[i] = max(ds[i], dt[i]);
        return ds;
    }
};