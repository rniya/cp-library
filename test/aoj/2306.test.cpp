#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2306"

#include "base.hpp"
#include "graph/enumerate_cliques.hpp"

const int inf = 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n, 0));
    vector<vector<bool>> g(n, vector<bool>(n, false));
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v, f;
        cin >> u >> v >> f;
        deg[--u]++;
        deg[--v]++;
        G[u][v] = G[v][u] = f;
        g[u][v] = g[v][u] = true;
    }

    auto calc = [&](const vector<int>& clique) {
        int sum = 0;
        for (const auto& u : clique) {
            int Min = inf;
            for (const auto& v : clique) {
                if (u == v) continue;
                Min = min(Min, G[u][v]);
            }
            if (Min < inf) sum += Min;
        }
        return sum;
    };

    int ans = 0;
    auto cliques = enumerate_cliques(g);
    for (const auto& clique : cliques) ans = max(ans, calc(clique));
    cout << ans << '\n';
    return 0;
}