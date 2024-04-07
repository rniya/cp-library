#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

template <typename Cap, typename Cost> struct PrimalDualonDAG {
    PrimalDualonDAG(int n) : n(n), G(n), h(n), dist(n), prevv(n), preve(n), indeg(n, 0) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        // assert(0 <= cost);
        int m = pos.size(), from_id = G[from].size(), to_id = G[to].size();
        pos.emplace_back(from, G[from].size());
        G[from].emplace_back(to, cap, cost, to_id);
        G[to].emplace_back(from, 0, -cost, from_id);
        if (cap > 0) indeg[to]++;
        return m;
    }

    std::tuple<int, int, Cap, Cap, Cost> get_edge(int i) {
        assert(0 <= i && i < (int)pos.size());
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost};
    }

    std::vector<std::tuple<int, int, Cap, Cap, Cost>> edges() {
        std::vector<std::tuple<int, int, Cap, Cap, Cost>> res;
        for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));
        return res;
    }

    Cost min_cost_flow(int s, int t, Cap flow) {
        auto res = slope(s, t, flow).back();
        return res.first == flow ? res.second : -1;
    }

    std::pair<Cap, Cost> min_cost_max_flow(int s, int t) { return slope(s, t, std::numeric_limits<Cap>::max()).back(); }

    std::vector<std::pair<Cap, Cost>> slope(int s, int t) { return slope(s, t, std::numeric_limits<Cap>::max()); }

  private:
    struct edge {
        int to;
        Cap cap;
        Cost cost;
        int rev;
        edge(int to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };

    const Cost inf = std::numeric_limits<Cost>::max();
    int n;
    std::vector<std::vector<edge>> G;
    std::vector<std::pair<int, int>> pos;
    std::vector<Cost> h, dist;
    std::vector<int> prevv, preve, indeg, order;

    bool topological_sort() {
        std::queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                que.emplace(i);
            }
        }
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            order.emplace_back(v);
            for (const auto& e : G[v]) {
                if (e.cap > 0 && --indeg[e.to] == 0) {
                    que.emplace(e.to);
                }
            }
        }

        return *std::max_element(indeg.begin(), indeg.end()) == 0;
    }

    void calc_potential(int s) {
        fill(h.begin(), h.end(), inf);
        h[s] = 0;
        for (int& v : order) {
            if (h[v] == inf) continue;
            for (const auto& e : G[v]) {
                if (e.cap > 0) {
                    h[e.to] = std::min(h[e.to], h[v] + e.cost);
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
        std::priority_queue<P> pq;
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

    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);
        assert(topological_sort());
        calc_potential(s);
        Cap flow = 0;
        Cost cost = 0, prev_cost_pre_flow = -1;
        std::vector<std::pair<Cap, Cost>> res;
        res.emplace_back(flow, cost);
        while (flow < flow_limit) {
            dijkstra(s);
            if (dist[t] == inf) break;
            for (int v = 0; v < n; v++) h[v] += dist[v];
            Cap d = flow_limit - flow;
            for (int v = t; v != s; v = prevv[v]) d = std::min(d, G[prevv[v]][preve[v]].cap);
            for (int v = t; v != s; v = prevv[v]) {
                auto& e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
            flow += d;
            cost += d * h[t];
            if (prev_cost_pre_flow == d) res.pop_back();
            res.emplace_back(flow, cost);
            prev_cost_pre_flow = d;
        }
        return res;
    }
};
