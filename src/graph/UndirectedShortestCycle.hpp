#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

template <typename T> struct UndirectedShortestCycle {
    struct edge {
        int from, to;
        T cost;
        edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    };

    std::vector<std::vector<int>> G;
    std::vector<edge> edges;

    UndirectedShortestCycle(int n) : n(n), G(n) {}

    void add_edge(int u, int v, T w) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        assert(w >= 0);
        G[u].emplace_back(edges.size());
        G[v].emplace_back(edges.size());
        edges.emplace_back(u, v, w);
    }

    std::tuple<T, std::vector<int>, std::vector<int>> solve(int r) {
        std::vector<int> label(n, -1), prve(n, -1);
        std::vector<T> dist(n, inf);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> pq;
        dist[r] = 0;
        pq.emplace(dist[r], r);
        label[r] = r;
        while (not pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dist[v] < d) continue;
            for (const int& idx : G[v]) {
                int u = edges[idx].from ^ edges[idx].to ^ v, w = edges[idx].cost;
                if (dist[u] <= dist[v] + w) continue;
                dist[u] = dist[v] + w;
                label[u] = label[v] == r ? u : label[v];
                prve[u] = idx;
                pq.emplace(dist[u], u);
            }
        }

        std::vector<bool> used(edges.size(), false);
        for (int& idx : prve) {
            if (idx != -1) {
                used[idx] = true;
            }
        }
        T mini = inf;
        int argmin = -1;
        for (int i = 0; i < int(edges.size()); i++) {
            if (used[i]) continue;
            auto [u, v, w] = edges[i];
            if (label[u] == -1) continue;
            if (label[u] == label[v]) continue;
            if (dist[u] + dist[v] + w < mini) {
                mini = dist[u] + dist[v] + w;
                argmin = i;
            }
        }
        if (argmin == -1) return {mini, {}, {}};

        std::vector<int> vs, es;
        int a = edges[argmin].from, b = edges[argmin].to;
        while (a != r) {
            int idx = prve[a];
            vs.emplace_back(a);
            es.emplace_back(idx);
            a = edges[idx].from ^ edges[idx].to ^ a;
        }
        vs.emplace_back(a);
        std::reverse(vs.begin(), vs.end());
        std::reverse(es.begin(), es.end());
        es.emplace_back(argmin);
        while (b != r) {
            int idx = prve[b];
            vs.emplace_back(b);
            es.emplace_back(idx);
            b = edges[idx].from ^ edges[idx].to ^ b;
        }
        return {mini, vs, es};
    }

  private:
    constexpr static T inf = std::numeric_limits<T>::max() / 2;
    int n;
};