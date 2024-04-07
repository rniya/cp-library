#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

template <typename T> struct DirectedShortestCycle {
    struct edge {
        int from, to;
        T cost;
        edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    };

    std::vector<std::vector<int>> G;
    std::vector<edge> edges;

    DirectedShortestCycle(int n) : n(n), G(n) {}

    void add_edge(int u, int v, T w) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        assert(w >= 0);
        G[u].emplace_back(edges.size());
        edges.emplace_back(u, v, w);
    }

    std::tuple<T, std::vector<int>, std::vector<int>> solve(int r) {
        std::vector<int> prve(n, -1);
        std::vector<T> dist(n, inf);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> pq;
        for (const int& idx : G[r]) {
            int u = edges[idx].to, w = edges[idx].cost;
            if (w < dist[u]) {
                dist[u] = w;
                prve[u] = idx;
                pq.emplace(dist[u], u);
            }
        }
        while (not pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dist[v] < d) continue;
            for (const int& idx : G[v]) {
                int u = edges[idx].to, w = edges[idx].cost;
                if (dist[u] <= dist[v] + w) continue;
                dist[u] = dist[v] + w;
                prve[u] = idx;
                pq.emplace(dist[u], u);
            }
        }

        if (dist[r] == inf) return {inf, {}, {}};
        std::vector<int> vs, es;
        vs.emplace_back(r);
        while (true) {
            int idx = prve[vs.back()];
            es.emplace_back(idx);
            vs.emplace_back(edges[idx].from);
            if (vs.back() == r) break;
        }
        std::reverse(vs.begin(), vs.end());
        std::reverse(es.begin(), es.end());
        vs.pop_back();
        return {dist[r], vs, es};
    }

  private:
    constexpr static T inf = std::numeric_limits<T>::max() / 2;
    int n;
};