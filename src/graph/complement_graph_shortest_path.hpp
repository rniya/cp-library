#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

std::vector<int> complement_graph_shortest_path(const std::vector<std::vector<int>>& G, int s) {
    int n = G.size();
    std::vector<int> dist(n, (1 << 30) - 1);
    dist[s] = 0;
    std::vector<int> L;
    std::vector<bool> mark(n, false);
    for (int i = 0; i < n; i++) {
        if (i != s) {
            L.emplace_back(i);
        }
    }
    std::queue<int> Q;
    Q.emplace(s);
    while (not Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (const int& u : G[v]) mark[u] = true;
        std::partition(begin(L), end(L), [&](const int u) { return mark[u]; });
        while (not L.empty()) {
            int u = L.back();
            if (mark[u]) break;
            L.pop_back();
            dist[u] = dist[v] + 1;
            Q.emplace(u);
        }
        for (const int& u : G[v]) mark[u] = false;
    }
    return dist;
}