#pragma once
#include <stack>
#include <vector>

template <bool directed> struct CycleDetection {
    std::vector<std::vector<int>> G;
    int n, pos;

    CycleDetection(int n) : G(n), n(n), pos(-1), seen(n, 0), finished(n, 0) {}

    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        if (!directed) G[v].emplace_back(u);
    }

    std::vector<int> build() {
        for (int v = 0; v < n; v++) {
            if (!seen[v]) dfs(v, -1);
            if (~pos) break;
        }
        std::vector<int> res;
        while (!hist.empty()) {
            int t = hist.top();
            hist.pop();
            res.emplace_back(t);
            if (t == pos) break;
        }
        return res;
    }

private:
    std::vector<int> seen, finished;
    std::stack<int> hist;

    void dfs(int v, int p) {
        seen[v] = 1;
        hist.emplace(v);
        for (int u : G[v]) {
            if (!directed and u == p) continue;
            if (finished[u]) continue;
            if (seen[u] and !finished[u]) {
                pos = u;
                return;
            }
            dfs(u, v);
            if (~pos) return;
        }
        finished[v] = 1;
        hist.pop();
    }
};
