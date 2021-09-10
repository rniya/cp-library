#pragma once
#include "../base.hpp"

/**
 * @brief Primal Dual on DAG
 * @docs docs/flow/PrimalDualonDAG.md
 */
template <typename Cap, typename Cost> struct PrimalDualonDAG {
    const Cost inf = numeric_limits<Cost>::max() / 2;
    struct edge {
        int to;
        Cap cap;
        Cost cost;
        int rev;
        edge(int to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };
    vector<vector<edge>> G;
    vector<pair<int, int>> pos;
    vector<Cost> h, dist;
    vector<int> prevv, preve, indeg, ord;
    PrimalDualonDAG(int n) : G(n), h(n), dist(n), prevv(n), preve(n), indeg(n, 0) {}
    int add_edge(int from, int to, Cap cap, Cost cost) {
        pos.emplace_back(from, G[from].size());
        G[from].emplace_back(to, cap, cost, G[to].size());
        G[to].emplace_back(from, 0, -cost, G[from].size() - 1);
        if (cap > 0) indeg[to]++;
        return pos.size() - 1;
    }
    tuple<int, int, Cap, Cap, Cost> get_edge(int i) {
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost};
    }
    vector<tuple<int, int, Cap, Cap, Cost>> edges() {
        vector<tuple<int, int, Cap, Cap, Cost>> res;
        for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));
        return res;
    }
    bool topological_sort() {
        queue<int> que;
        for (size_t i = 0; i < G.size(); i++) {
            if (indeg[i] == 0) {
                que.emplace(i);
            }
        }

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            ord.emplace_back(v);
            for (const auto& e : G[v]) {
                if (e.cap > 0 && --indeg[e.to] == 0) {
                    que.emplace(e.to);
                }
            }
        }

        return (*max_element(indeg.begin(), indeg.end()) == 0);
    }
    void calc_potential(int s) {
        fill(h.begin(), h.end(), inf);
        h[s] = 0;

        for (int& v : ord) {
            if (h[v] == inf) continue;
            for (const auto& e : G[v]) {
                if (e.cap > 0) {
                    h[e.to] = min(h[e.to], h[v] + e.cost);
                }
            }
        }
    }
    void dijkstra(int s) {
        struct P {
            Cost c;
            int v;
            P(Cost c, int v) : c(c), v(v) {}
            bool operator<(const P& rhs) const { return c > rhs.c; }
        };
        priority_queue<P> pq;
        fill(dist.begin(), dist.end(), inf);
        dist[s] = 0;
        pq.emplace(dist[s], s);

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int v = p.v;
            if (dist[v] < p.c) continue;
            for (size_t i = 0; i < G[v].size(); i++) {
                auto& e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }
    }
    vector<pair<Cap, Cost>> slope(int s, int t, Cap lim) {
        assert(topological_sort());
        calc_potential(s);
        Cap f = 0;
        Cost c = 0, pre = -1;
        vector<pair<Cap, Cost>> res;
        res.emplace_back(f, c);

        while (f < lim) {
            dijkstra(s);
            if (dist[t] == inf) break;
            for (size_t v = 0; v < G.size(); v++) h[v] = min(h[v] + dist[v], inf);
            Cap d = lim - f;
            for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
            for (int v = t; v != s; v = prevv[v]) {
                auto& e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
            f += d;
            c += h[t] * d;
            if (pre == h[t]) res.pop_back();
            res.emplace_back(f, c);
            pre = c;
        }

        return res;
    }
    Cost min_cost_flow(int s, int t, Cap f) {
        auto res = slope(s, t, f).back();
        return res.first == f ? res.second : -1;
    }
    pair<Cap, Cost> min_cost_max_flow(int s, int t) { return slope(s, t, numeric_limits<Cap>::max()).back(); }
    vector<pair<Cap, Cost>> min_cost_slope(int s, int t) { return slope(s, t, numeric_limits<Cap>::max()); }
};