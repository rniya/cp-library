#pragma once
#include "../base.hpp"

/**
 * @brief Euler Tour (パスに対する操作)
 * @docs docs/tree/EulerTourforEdge.md
 */
class EulerTourforEdge {
    vector<int> ds, us, dep, btm;
    void dfs(int v, int p, int d) {
        dep[v] = d;
        for (int u : G[v]) {
            if (u == p) continue;
            ds[u] = btm.size();
            btm.emplace_back(u);
            dfs(u, v, d + 1);
            us[u] = btm.size();
            btm.emplace_back(u);
        }
    }

public:
    vector<vector<int>> G;
    EulerTourforEdge(int n) : ds(n), us(n), dep(n), G(n) {}
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(int r = 0) {
        btm.clear();
        ds[r] = btm.size();
        btm.emplace_back(r);
        dfs(r, -1, 0);
        us[r] = btm.size();
        btm.emplace_back(r);
    }
    int child(int u, int v) { return dep[u] < dep[v] ? v : u; }
    int bottom(int e) { return btm[e]; }
    template <typename T, typename F> T query(int v, F f) { return f(0, us[v]); }
    // u or v must be lca(u,v)
    template <typename T, typename F> T query(int u, int v, F f) {
        if (dep[u] < dep[v]) swap(u, v);
        return query<T>(u, f) - query<T>(v, f);
    }
    // v is child of the edge
    template <typename T, typename G> void update(int v, T x, G g) {
        g(ds[v], x);
        g(us[v], -x);
    }
};