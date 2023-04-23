#include <cassert>
#include <queue>
#include <vector>
#include "atcoder/scc"
#include "graph/BipartiteMatching.hpp"

struct DulmageMendelsohnDecomposition : BipartiteMatching {
    DulmageMendelsohnDecomposition(int U, int V) : BipartiteMatching(U, V) {}

    std::vector<std::pair<std::vector<int>, std::vector<int>>> decompose() {
        int U = this->U, V = this->V, n = U + V;

        // construct bipartite matching
        this->solve();
        std::vector<int> L = this->L, R = this->R;

        // find V_0 and V_inf
        std::vector<std::vector<std::pair<int, int>>> g(n);
        for (int u = 0; u < U; u++) {
            for (int v : this->G[u]) {
                if (L[u] == v) {
                    g[u].emplace_back(v + U, 3);
                    g[v + U].emplace_back(u, 3);
                } else {
                    g[u].emplace_back(v + U, 1);
                    g[v + U].emplace_back(u, 2);
                }
            }
        }
        std::vector<int> U_unused, V_unused;
        for (int i = 0; i < n; i++) {
            if (i < U and L[i] == -1) U_unused.emplace_back(i);
            if (U <= i and R[i - U] == -1) V_unused.emplace_back(i);
        }
        auto V_inf = bfs(g, U_unused, 0), V_0 = bfs(g, V_unused, 1);

        // calculate strongly connected components among other vertices
        std::vector<bool> erased(n, false);
        for (const int& u : V_0) erased[u] = true;
        for (const int& u : V_inf) erased[u] = true;
        atcoder::scc_graph scc(n);
        for (int u = 0; u < U; u++) {
            for (const auto& e : g[u]) {
                int v = e.first;
                if ((e.second & 1) and !erased[u] and !erased[v]) scc.add_edge(u, v);
            }
        }
        std::vector<std::pair<std::vector<int>, std::vector<int>>> res;
        auto push = [&](const std::vector<int>& V) {
            res.emplace_back();
            for (const int& v : V) {
                if (v < U)
                    res.back().first.emplace_back(v);
                else
                    res.back().second.emplace_back(v - U);
            }
        };
        push(V_0);
        for (const auto& V : scc.scc()) {
            if (erased[V.front()]) continue;
            push(V);
        }
        push(V_inf);
        return res;
    }

  private:
    std::vector<int> bfs(const std::vector<std::vector<std::pair<int, int>>>& g, const std::vector<int>& S, int f) {
        int n = g.size();
        std::vector<bool> seen(n, false);
        std::queue<int> que;
        for (const int& s : S) {
            seen[s] = true;
            que.emplace(s);
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (const auto& e : g[u]) {
                int v = e.first;
                if (!(e.second >> f & 1) or seen[v]) continue;
                seen[v] = true;
                que.emplace(v);
            }
        }
        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            if (seen[i]) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};
