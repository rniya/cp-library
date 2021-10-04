#pragma once
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

template <typename T> struct Prim {
    Prim(int n) : n(n), G(n), dist(n, std::numeric_limits<T>::max()), used(n, false) {}

    void add_edge(int u, int v, T cost) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v, cost);
        G[v].emplace_back(u, cost);
    }

    T build() {
        T res = 0;
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;
        dist[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int v = p.second;
            if (used[v]) continue;
            used[v] = true;
            res += p.first;
            for (auto& e : G[v]) {
                int u = e.first;
                if (!used[u] && e.second < dist[u]) {
                    dist[u] = e.second;
                    pq.emplace(e.second, u);
                }
            }
        }
        return res;
    }

private:
    int n;
    std::vector<std::vector<std::pair<int, T>>> G;
    std::vector<T> dist;
    std::vector<bool> used;
};

/**
 * @brief Prim
 * @docs docs/graph/Prim.md
 */
