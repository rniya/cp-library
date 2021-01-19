#pragma once
#include "../base.hpp"

/**
 * @brief 最小費用流
 * @docs docs/flow/MinCostFlow.md
 */
template <typename T, typename E> struct MinCostFlow {
    const E inf = numeric_limits<E>::max();
    struct edge {
        int to, rev;
        T cap;
        E cost;
        edge(int to, T cap, E cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };
    vector<vector<edge>> G;
    vector<pair<int, int>> pos;
    vector<E> dist;
    vector<int> prevv, preve;
    MinCostFlow(int n) : G(n), dist(n), prevv(n), preve(n) {}
    int add_edge(int from, int to, T cap, E cost) {
        pos.emplace_back(from, G[from].size());
        G[from].emplace_back(to, cap, cost, G[to].size());
        G[to].emplace_back(from, 0, -cost, G[from].size() - 1);
        return pos.size() - 1;
    }
    tuple<int, int, int, int, int> get_edge(int i) {
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost};
    }
    vector<tuple<int, int, int, int, int>> edges() {
        vector<tuple<int, int, int, int, int>> res;
        for (int i = 0; i < pos.size(); i++) {
            res.emplace_back(get_edge(i));
        }
        return res;
    }
    E min_cost_flow(int s, int t, T f) {
        E res = 0;
        while (f > 0) {
            fill(dist.begin(), dist.end(), inf);
            dist[s] = 0;
            bool update = true;
            while (update) {
                update = false;
                for (int v = 0; v < G.size(); v++) {
                    if (dist[v] == inf) continue;
                    for (int i = 0; i < G[v].size(); i++) {
                        edge& e = G[v][i];
                        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }
            if (dist[t] == inf) return -1;
            T d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += dist[t] * d;
            for (int v = t; v != s; v = prevv[v]) {
                edge& e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};