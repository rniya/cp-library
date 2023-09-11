#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

struct DirectedCycleDetection {
    DirectedCycleDetection(int n) : n(n), m(0), G(n), used(n, 0), par(n) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        G[u].emplace_back(v, m++);
    }

    std::pair<std::vector<int>, std::vector<int>> build() {
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                dfs(i);
            }
        }
        return {vs, es};
    }

  private:
    int n, m;
    std::vector<std::vector<std::pair<int, int>>> G;
    std::vector<int> used, vs, es;
    std::vector<std::pair<int, int>> par;

    void dfs(int v) {
        used[v] = 1;
        for (auto [u, e] : G[v]) {
            if (not es.empty()) return;
            if (used[u] == 0) {
                par[u] = {v, e};
                dfs(u);
            } else if (used[u] == 1) {
                es.emplace_back(e);
                vs.emplace_back(v);
                for (int cur = v; cur != u; cur = par[cur].first) {
                    vs.emplace_back(par[cur].first);
                    es.emplace_back(par[cur].second);
                }
                std::reverse(begin(es), end(es));
                std::reverse(begin(vs), end(vs));
                return;
            }
        }
        used[v] = 2;
    }
};