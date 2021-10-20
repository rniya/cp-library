#pragma once
#include <cassert>
#include <limits>
#include <utility>
#include <vector>

template <typename T> struct BellmanFord {
    BellmanFord(int n) : n(n), d(n) {}

    void add_edge(int from, int to, T cost) {
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        es.emplace_back(from, to, cost);
    }

    bool find_negative_loop() {
        fill(d.begin(), d.end(), 0);
        for (int i = 0, updated = 1; i < n and std::exchange(updated, 0); i++) {
            for (auto& e : es) {
                if (d[e.from] + e.cost < d[e.to]) {
                    d[e.to] = d[e.from] + e.cost;
                    updated = 1;
                }
            }
            if (!updated) return true;
            if (i == n - 1) return false;
        }
    }

    std::vector<T> solve(int s) {
        assert(0 <= s and s < n);
        fill(d.begin(), d.end(), inf);
        d[s] = 0;
        for (int i = 0, updated = 1; i < n and std::exchange(updated, 0); i++) {
            for (auto& e : es) {
                if (d[e.from] != inf and d[e.from] + e.cost < d[e.to]) {
                    d[e.to] = d[e.from] + e.cost;
                    updated = 1;
                }
            }
            if (!updated) break;
            if (i == n - 1) return {};
        }
        return d;
    }

    std::vector<T> shortest_path(int s, int t) {
        assert(0 <= s and s < n);
        assert(0 <= t and t < n);
        fill(d.begin(), d.end(), inf);
        d[s] = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            for (auto& e : es) {
                if (d[e.from] != inf and d[e.from] + e.cost < d[e.to]) {
                    d[e.to] = d[e.from] + e.cost;
                    if (i >= n - 1) {
                        if (e.to == t) return {};
                        d[e.to] = -inf;
                    }
                }
            }
        }
        return d;
    }

private:
    struct edge {
        int from, to;
        T cost;
        edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    };
    int n;
    const T inf = std::numeric_limits<T>::max() / 2;
    std::vector<T> d;
    std::vector<edge> es;
};

/**
 * @brief Bellman-Ford
 * @docs docs/graph/BellmanFord.md
 */
