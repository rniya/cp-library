#pragma once
#include <cassert>
#include <vector>

template <typename T = int> struct TreeDiameter {
    std::vector<std::vector<std::pair<int, T>>> G;

    TreeDiameter(int n) : G(n), n(n), dist(n), par(n) {}

    void add_edge(int u, int v, T c = 1) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }

    std::pair<T, std::vector<int>> get_diameter_path() {
        argmax = 0;
        dfs(argmax, -1);
        dfs(argmax, -1);
        T diam = dist[argmax];
        std::vector<int> path;
        while (argmax >= 0) {
            path.emplace_back(argmax);
            argmax = par[argmax];
        }
        return {diam, path};
    }

    std::vector<T> farthest_distance() {
        auto path = get_diameter_path().second;
        int s = path.front(), t = path.back();
        dfs(s, -1);
        auto dist_s = dist;
        dfs(t, -1);
        auto dist_t = dist;
        for (int i = 0; i < n; i++) dist_s[i] = std::max(dist_s[i], dist_t[i]);
        return dist_s;
    }

private:
    int n, argmax;
    std::vector<T> dist;
    std::vector<int> par;

    void dfs(int v, int p) {
        par[v] = p;
        if (p < 0) dist[v] = T(0);
        if (dist[argmax] < dist[v]) argmax = v;
        for (auto& e : G[v]) {
            int u = e.first;
            if (u == p) continue;
            dist[u] = dist[v] + e.second;
            dfs(u, v);
        }
    }
};

/**
 * @brief Tree Diameter
 * @docs docs/tree/TreeDiameter.md
 */