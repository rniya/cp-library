#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <utility>
#include <vector>

struct BipartiteMatching {
    BipartiteMatching(int U, int V) : U(U), V(V), t(0), solved(false), G(U), L(U, -1), R(V, -1), visited(U, -1) {}

    void add_edge(int u, int v) {
        assert(0 <= u && u < U && 0 <= v && v < V);
        G[u].emplace_back(v);
    }

    int solve() {
        for (bool updated = true; std::exchange(updated, false); t++) {
            for (int i = 0; i < U; i++) {
                if (L[i] == -1) {
                    updated |= dfs(i);
                }
            }
        }
        solved = true;
        return U - std::count(L.begin(), L.end(), -1);
    }

    std::vector<std::pair<int, int>> max_matching() const {
        assert(solved);
        std::vector<std::pair<int, int>> res;
        for (int i = 0; i < U; i++) {
            if (~L[i]) {
                res.emplace_back(i, L[i]);
            }
        }
        return res;
    }

private:
    int U, V, t;
    bool solved;
    std::vector<std::vector<int>> G;
    std::vector<int> L, R, visited;

    bool dfs(int u) {
        if (std::exchange(visited[u], t) == t) return false;
        for (int& v : G[u]) {
            if (R[v] == -1) {
                L[u] = v, R[v] = u;
                return true;
            }
        }
        for (int& v : G[u]) {
            if (dfs(R[v])) {
                L[u] = v, R[v] = u;
                return true;
            }
        }
        return false;
    }
};

/**
 * @brief Bipartite Matching
 * @docs docs/flow/BipartiteMathcing.md
 */
