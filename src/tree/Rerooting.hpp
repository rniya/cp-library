#pragma once
#include <cassert>
#include <vector>

template <class TreeDP> struct Rerooting {
    using T = TreeDP::T;

    struct edge {
        int to, e;
        T dp, ndp;
        edge(int to, int e, T dp, T ndp) : to(to), e(e), dp(dp), ndp(ndp) {}
    };

    std::vector<std::vector<edge>> G;

    Rerooting(int n, const TreeDP& treedp) : n(n), m(0), G(n), treedp(treedp), sub(n), dp(n) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        G[u].emplace_back(v, m, treedp.e(), treedp.e());
        G[v].emplace_back(u, m, treedp.e(), treedp.e());
        m++;
    }

    std::vector<T> solve() {
        dfs_sub(0, -1);
        dfs_all(0, -1, treedp.e());
        return dp;
    }

  private:
    int n, m;
    TreeDP treedp;
    std::vector<T> sub, dp;

    void dfs_sub(int v, int p) {
        sub[v] = treedp.e();
        for (auto& e : G[v]) {
            if (e.to == p) continue;
            dfs_sub(e.to, v);
            sub[v] = treedp.op(sub[v], treedp.add_edge(sub[e.to], e.e));
        }
        sub[v] = treedp.add_vertex(sub[v], v);
    }

    void dfs_all(int v, int p, const T& top) {
        T cur = treedp.e();
        for (int i = 0; i < int(G[v].size()); i++) {
            auto& e = G[v][i];
            e.ndp = cur;
            e.dp = treedp.add_edge(e.to == p ? top : sub[e.to], e.e);
            cur = treedp.op(cur, e.dp);
        }
        dp[v] = treedp.add_vertex(cur, v);
        cur = treedp.e();
        for (int i = int(G[v].size()) - 1; i >= 0; i--) {
            auto& e = G[v][i];
            e.ndp = treedp.add_vertex(treedp.op(e.ndp, cur), v);
            if (e.to != p) dfs_all(e.to, v, e.ndp);
            cur = treedp.op(cur, e.dp);
        }
    }
};
