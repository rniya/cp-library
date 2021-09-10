#pragma once
#include "../base.hpp"

/**
 * @brief Ford Fulkerson
 * @docs docs/flow/FordFulkerson.md
 */
template <typename T, bool directed> struct FordFulkerson {
    struct edge {
        int to, rev;
        T cap;
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };
    vector<vector<edge>> G;
    vector<pair<int, int>> pos;
    vector<int> used;
    FordFulkerson(int n) : G(n), used(n) {}
    int add_edge(int from, int to, T cap) {
        pos.emplace_back(from, G[from].size());
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, directed ? 0 : cap, G[from].size() - 1);
        return pos.size() - 1;
    }
    tuple<int, int, T, T> get_edge(int i) {
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap};
    }
    vector<tuple<int, int, T, T>> edges() {
        vector<tuple<int, int, T, T>> res;
        for (int i = 0; i < (int)pos.size(); i++) {
            res.emplace_back(get_edge(i));
        }
        return res;
    }
    T dfs(int v, int t, T f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d <= 0) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    T max_flow(int s, int t, T lim) {
        T flow = 0;
        while (lim > 0) {
            fill(used.begin(), used.end(), 0);
            T f = dfs(s, t, lim);
            if (f == 0) break;
            flow += f;
            lim -= f;
        }
        return flow;
    }
    T max_flow(int s, int t) { return max_flow(s, t, numeric_limits<T>::max()); }
};