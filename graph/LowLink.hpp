#pragma once
#include <cassert>
#include <utility>
#include <vector>

struct LowLink {
    int n, m = 0, t = 0, b = 0;
    std::vector<std::vector<int>> G;
    std::vector<std::pair<int, int>> es;
    std::vector<int> ord, low, tecc, bcc, tmp;
    std::vector<bool> is_articulation, is_bridge;

    LowLink(int n) : n(n), G(n), ord(n, -1), low(n), tecc(n, -1), is_articulation(n, false) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        G[u].emplace_back(m);
        G[v].emplace_back(m);
        es.emplace_back(u, v);
        is_bridge.emplace_back(false);
        bcc.emplace_back();
        m++;
    }

    void build() {
        for (int i = 0; i < n; i++) {
            if (ord[i] != -1) continue;
            dfs1(i, 0, -1);
            dfs2(i, -1);
        }
    }

    std::pair<int, int> operator[](int k) const { return es[k]; }

private:
    void dfs1(int v, int k, int pre) {
        ord[v] = k++, low[v] = ord[v];
        int cnt = 0;
        for (int& e : G[v]) {
            if (e == pre) continue;
            int u = es[e].first ^ es[e].second ^ v;
            if (ord[u] == -1) {
                cnt++;
                dfs1(u, k, e);
                low[v] = std::min(low[v], low[u]);
                if (pre != -1 and ord[v] <= low[u]) is_articulation[v] = true;
                if (ord[v] < low[u]) is_bridge[e] = true;
            } else
                low[v] = std::min(low[v], ord[u]);
        }
        if (pre == -1 and cnt > 1) is_articulation[v] = true;
    }

    void dfs2(int v, int pre) {
        if (pre == -1) tecc[v] = t++;
        for (int& e : G[v]) {
            if (e == pre) continue;
            int u = es[e].first ^ es[e].second ^ v;
            if (tecc[u] == -1 or ord[u] < ord[v]) tmp.emplace_back(e);
            if (tecc[u] >= 0) continue;
            if (ord[v] >= low[u])
                tecc[u] = tecc[v];
            else
                tecc[u] = t++;
            dfs2(u, e);
            if (ord[v] <= low[u]) {
                while (true) {
                    int ne = tmp.back();
                    tmp.pop_back();
                    bcc[ne] = b;
                    if (ne == e) break;
                }
                b++;
            }
        }
    }
};
