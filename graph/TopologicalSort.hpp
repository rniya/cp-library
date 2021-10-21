#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

struct TopologicalSort {
    std::vector<std::vector<int>> G;

    TopologicalSort(int n) : G(n), n(n), indeg(n, 0) {}

    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v);
        indeg[v]++;
    }

    std::vector<int> build() {
        std::queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                que.emplace(i);
            }
        }
        std::vector<int> order;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            order.emplace_back(v);
            for (int& u : G[v]) {
                if (--indeg[u] == 0) {
                    que.emplace(u);
                }
            }
        }
        if (*std::max_element(indeg.begin(), indeg.end()) != 0) return {};
        return order;
    }

private:
    int n;
    std::vector<int> indeg;
};

/**
 * @brief Topological Sort
 * @docs docs/graph/TopologicalSort.md
 */
