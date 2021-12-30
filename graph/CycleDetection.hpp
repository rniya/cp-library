#pragma once
#include "../base.hpp"

template <bool directed> struct CycleDetection {
    vector<vector<int>> G;
    vector<int> seen, finished;
    stack<int> hist;
    int pos;
    CycleDetection(int n) : G(n), seen(n, 0), finished(n, 0), pos(-1) {}
    void add_edge(int u, int v) { G[u].emplace_back(v); }
    void dfs(int v, int p) {
        seen[v] = 1;
        hist.emplace(v);
        for (int u : G[v]) {
            if (!directed && u == p) continue;
            if (finished[u]) continue;
            if (seen[u] && !finished[u]) {
                pos = u;
                return;
            }
            dfs(u, v);
            if (~pos) return;
        }
        finished[v] = 1;
        hist.pop();
    }
    vector<int> build() {
        for (int v = 0; v < (int)G.size(); v++) {
            if (!seen[v]) dfs(v, -1);
            if (~pos) break;
        }
        vector<int> res;
        while (!hist.empty()) {
            int t = hist.top();
            hist.pop();
            res.emplace_back(t);
            if (t == pos) break;
        }
        return res;
    }
};
