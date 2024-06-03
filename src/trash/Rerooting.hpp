#include <cassert>
#include <functional>
#include <vector>

template <class key_t, class sum_t = key_t> struct Rerooting {
    struct edge {
        int from, to;
        key_t cost;
        sum_t dp, ndp;
        edge(int from, int to, key_t cost, sum_t dp, sum_t ndp) : from(from), to(to), cost(cost), dp(dp), ndp(ndp) {}
    };
    using F = std::function<sum_t(sum_t, sum_t)>;
    using G = std::function<sum_t(sum_t, edge)>;

    int n;
    std::vector<std::vector<edge>> g;
    const F op;
    const G mapping;
    const sum_t id;

    Rerooting(int n, const F& op, const G& mapping, const sum_t& id)
        : n(n), g(n), op(op), mapping(mapping), id(id), sub(n, id), dp(n, id) {}

    void add_edge(int u, int v, key_t w) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        g[u].emplace_back(u, v, w, id, id);
        g[v].emplace_back(v, u, w, id, id);
    }

    std::vector<sum_t> solve() {
        dfs_sub(0, -1);
        dfs_all(0, -1, id);
        return dp;
    }

  private:
    std::vector<sum_t> sub, dp;

    void dfs_sub(int v, int p) {
        for (auto& e : g[v]) {
            if (e.to == p) continue;
            dfs_sub(e.to, v);
            sub[v] = op(sub[v], e.dp);
        }
    }

    void dfs_all(int v, int p, sum_t top) {
        sum_t cur = id;
        for (int i = 0; i < (int)g[v].size(); i++) {
            auto& e = g[v][i];
            e.ndp = cur;
            if (e.to == p) e.dp = mapping(top, e);
            cur = op(cur, e.dp);
        }
        dp[v] = cur;
        cur = id;
        for (int i = (int)g[v].size() - 1; i >= 0; i--) {
            auto& e = g[v][i];
            if (e.to != p) dfs_all(e.to, v, op(e.ndp, cur));
            cur = op(cur, e.dp);
        }
    }
};
