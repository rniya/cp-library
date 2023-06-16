#pragma once
#include <cassert>
#include <utility>
#include <vector>

struct EdgeMatching {
    EdgeMatching(int n) : n(n), G(n), seen(n), dep(n) {}
    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        int idx = es.size();
        G[u].emplace_back(idx);
        G[v].emplace_back(idx);
        es.emplace_back(u, v);
    }

    std::vector<std::pair<int, int>> build() {
        std::vector<std::pair<int, int>> res;
        for (int i = 0; i < n; i++) {
            if (not seen[i]) {
                dfs(i, -1, 0, res);
            }
        }
        return res;
    }

    std::pair<int, int> operator[](int k) const { return es[k]; }

  private:
    int n;
    std::vector<std::pair<int, int>> es;
    std::vector<std::vector<int>> G;
    std::vector<bool> seen;
    std::vector<int> dep;

    int dfs(int v, int p, int d, std::vector<std::pair<int, int>>& res) {
        seen[v] = true;
        dep[v] = d;
        int r = -1;
        for (const int& e : G[v]) {
            int u = es[e].first ^ es[e].second ^ v;
            if (e == p) continue;
            if (seen[u]) {
                if (dep[u] < dep[v]) {
                    if (r == -1)
                        r = e;
                    else {
                        res.emplace_back(r, e);
                        r = -1;
                    }
                }
            } else {
                int ch = dfs(u, e, d + 1, res);
                if (r == -1)
                    r = ch;
                else if (ch != -1) {
                    res.emplace_back(r, ch);
                    r = -1;
                }
            }
        }
        if (r != -1 and p != -1) {
            res.emplace_back(r, p);
            return -1;
        }
        return p;
    }
};
