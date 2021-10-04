#pragma once
#include <cassert>
#include <vector>
#include "../datastructure/UnionFind.hpp"

template <typename T> struct Kruskal {
    Kruskal(int n) : n(n), called_build(false) {}

    void add_edge(int u, int v, T cost, int idx = 0) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        es.emplace_back(u, v, cost, idx);
    }

    T build() {
        called_build = true;
        std::sort(es.begin(), es.end());
        UnionFind uf(n);
        T res = 0;
        for (auto& e : es) {
            if (uf.merge(e.u, e.v)) {
                res += e.cost;
                e.used = true;
            }
        }
        return res;
    }

    std::vector<int> used_edges() {
        assert(called_build);
        int m = es.size();
        std::vector<int> res(m);
        for (int i = 0; i < m; i++) res[es[i].idx] = es[i].used;
        return res;
    }

private:
    struct edge {
        int u, v;
        T cost;
        int idx, used;
        edge(int u, int v, T cost, int idx) : u(u), v(v), cost(cost), idx(idx), used(false) {}
        bool operator<(const edge& e) const { return cost < e.cost; }
    };
    int n;
    bool called_build;
    std::vector<edge> es;
};

/**
 * @brief Kruskal
 * @docs docs/graph/Kruskal.md
 */
