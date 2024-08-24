#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

struct UndirectedCycleDetection {
    UndirectedCycleDetection(int n) : n(n), m(0), G(n), used(n, 0), par(n) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        G[u].emplace_back(v, m);
        G[v].emplace_back(u, m);
        m++;
    }

    std::pair<std::vector<int>, std::vector<int>> build() {
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                dfs(i, -1);
            }
        }
        return {vs, es};
    }

  private:
    int n, m;
    std::vector<std::vector<std::pair<int, int>>> G;
    std::vector<int> used, vs, es;
    std::vector<std::pair<int, int>> par;

    void dfs(int v, int pre) {
        used[v] = 1;
        for (auto [u, e] : G[v]) {
            if (not es.empty()) return;
            if (e == pre) continue;
            if (used[u] == 0) {
                par[u] = {v, e};
                dfs(u, e);
            } else {
                vs.emplace_back(v);
                es.emplace_back(e);
                for (int cur = v; cur != u; cur = par[cur].first) {
                    vs.emplace_back(par[cur].first);
                    es.emplace_back(par[cur].second);
                }
                std::reverse(vs.begin(), vs.end());
                std::reverse(es.begin(), es.end());
                return;
            }
        }
    }
};