#include <cassert>
#include <queue>
#include <vector>

template <class S, S (*op)(S, S)> struct ForestScheduling {
    S tot;
    std::vector<int> ord;

    ForestScheduling(const std::vector<int>& par, std::vector<S> x) : tot() {
        int n = par.size();
        assert(int(x.size()) == n);
        dsu.assign(n + 1, -1);
        std::priority_queue<T> pq;
        std::vector<int> tails(n + 1), nxt(n + 1, -1);
        for (int i = 0; i < n; i++) {
            tails[i] = i;
            pq.push({x[i], i, i});
        }
        tails[n] = n;
        while (not pq.empty()) {
            auto [tmp, v, tail] = pq.top();
            pq.pop();
            if (tails[v] == tail) {
                int u = leader(par[v] >= 0 ? par[v] : n);
                merge(u, v);
                nxt[tails[u]] = v;
                tails[u] = tail;
                if (u == n)
                    tot = op(tot, x[v]);
                else {
                    x[u] = op(x[u], x[v]);
                    pq.push({x[u], u, tail});
                }
            }
        }
        for (int i = 0, cur = n; i < n; i++) {
            cur = nxt[cur];
            ord.emplace_back(cur);
        }
    }

    int operator[](int i) const { return ord[i]; }

  private:
    struct T {
        S s;
        int head, tail;
        bool operator<(const T& rhs) const { return rhs.s < s; }
    };
    std::vector<int> dsu;

    int leader(int u) { return dsu[u] < 0 ? u : (dsu[u] = leader(dsu[u])); }

    bool merge(int u, int v) {
        u = leader(u), v = leader(v);
        if (u == v) return false;
        dsu[u] += dsu[v];
        dsu[v] = u;
        return true;
    }
};