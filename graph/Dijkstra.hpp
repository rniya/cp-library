#pragma once
#include "../base.hpp"

/**
 * @brief Dijkstra
 * @docs docs/graph/Dijkstra.md
 */
template <typename T> struct Dijkstra {
    struct edge {
        int to;
        T cost;
        edge(int to, T cost) : to(to), cost(cost) {}
        bool operator<(const edge& e) const { return cost > e.cost; }
    };
    vector<vector<edge>> G;
    vector<T> dp;
    vector<int> pre;
    Dijkstra(int n) : G(n), dp(n), pre(n) {}
    void add_edge(int u, int v, T c) { G[u].emplace_back(v, c); }
    vector<T> build(int s) {
        int n = G.size();
        fill(dp.begin(), dp.end(), numeric_limits<T>::max());
        fill(pre.begin(), pre.end(), -1);
        priority_queue<edge> pq;
        dp[s] = 0;
        pq.emplace(s, dp[s]);
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int v = p.to;
            if (dp[v] < p.cost) continue;
            for (auto e : G[v]) {
                if (dp[v] + e.cost < dp[e.to]) {
                    dp[e.to] = dp[v] + e.cost;
                    pre[e.to] = v;
                    pq.emplace(e.to, dp[e.to]);
                }
            }
        }
        return dp;
    }
    vector<int> restore(int t) {
        vector<int> res;
        if (pre[t] < 0) return res;
        while (~t) {
            res.emplace_back(t);
            t = pre[t];
        }
        reverse(res.begin(), res.end());
        return res;
    }
    T operator[](int to) { return dp[to]; }
};