#pragma once
#include <cassert>
#include <utility>
#include <vector>

struct HeavyLightDecomposition {
    HeavyLightDecomposition(int n)
        : n(n), time(0), G(n), par(n, -1), sub(n), dep(n, 0), head(n), tree_id(n, -1), vertex_id(n, -1) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(std::vector<int> roots = {0}) {
        int tree_id_cur = 0;
        for (int& r : roots) {
            assert(0 <= r && r < n);
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r, tree_id_cur++);
        }
    }

    int idx(int v) const { return vertex_id[v]; }

    int lca(int u, int v) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(tree_id[u] == tree_id[v]);
        for (;; v = par[head[v]]) {
            if (vertex_id[u] > vertex_id[v]) std::swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }

    int distance(int u, int v) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(tree_id[u] == tree_id[v]);
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    template <typename F> void query_path(int u, int v, const F& f, bool vertex = false) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(tree_id[u] == tree_id[v]);
        int p = lca(u, v);
        for (auto& e : ascend(u, p)) f(e.second, e.first + 1);
        if (vertex) f(vertex_id[p], vertex_id[p] + 1);
        for (auto& e : descend(p, v)) f(e.first, e.second + 1);
    }

    template <typename F> void query_path_noncommutative(int u, int v, const F& f, bool vertex = false) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(tree_id[u] == tree_id[v]);
        int p = lca(u, v);
        for (auto& e : ascend(u, p)) f(e.first + 1, e.second);
        if (vertex) f(vertex_id[p], vertex_id[p] + 1);
        for (auto& e : descend(p, v)) f(e.first, e.second + 1);
    }

    template <typename F> void query_subtree(int u, const F& f, bool vertex = false) const {
        assert(0 <= u && u < n);
        f(vertex_id[u] + !vertex, vertex_id[u] + sub[u]);
    }

private:
    int n, time;
    std::vector<std::vector<int>> G;  // child of vertex v on heavy edge is G[v].front() is it is not parent of v
    std::vector<int> par              // parent of vertex v
        ,
        sub  // size of subtree whose root is v
        ,
        dep  // distance bitween root and vertex v
        ,
        head  // vertex that is the nearest to root on heavy path of vertex v
        ,
        tree_id  // id of tree vertex v belongs to
        ,
        vertex_id;  // id of vertex v (consecutive on heavy paths)

    void dfs_sz(int v) {
        sub[v] = 1;
        if (!G[v].empty() && G[v].front() == par[v]) std::swap(G[v].front(), G[v].back());
        for (int& u : G[v]) {
            if (u == par[v]) continue;
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub[v] += sub[u];
            if (sub[u] > sub[G[v].front()]) std::swap(u, G[v].front());
        }
    }

    void dfs_hld(int v, int tree_id_cur) {
        vertex_id[v] = time++;
        tree_id[v] = tree_id_cur;
        for (int& u : G[v]) {
            if (u == par[v]) continue;
            head[u] = (u == G[v][0] ? head[v] : u);
            dfs_hld(u, tree_id_cur);
        }
    }

    std::vector<std::pair<int, int>> ascend(int u, int v) const {  // [u, v), v is ancestor of u
        std::vector<std::pair<int, int>> res;
        while (head[u] != head[v]) {
            res.emplace_back(vertex_id[u], vertex_id[head[u]]);
            u = par[head[u]];
        }
        if (u != v) res.emplace_back(vertex_id[u], vertex_id[v] + 1);
        return res;
    }

    std::vector<std::pair<int, int>> descend(int u, int v) const {  // (u, v], u is ancestor of v
        if (u == v) return {};
        if (head[u] == head[v]) return {{vertex_id[u] + 1, vertex_id[v]}};
        auto res = descend(u, par[head[v]]);
        res.emplace_back(vertex_id[head[v]], vertex_id[v]);
        return res;
    }
};

/**
 * @brief Heavy Light Decomposition
 * @docs docs/tree/HeavyLightDecomposition.md
 */