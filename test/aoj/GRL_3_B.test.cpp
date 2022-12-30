#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B"

#include <algorithm>
#include <iostream>
#include "graph/LowLink.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int V, E;
    std::cin >> V >> E;
    LowLink G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        std::cin >> s >> t;
        if (s > t) std::swap(s, t);
        G.add_edge(s, t);
    }

    G.build();
    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < E; i++) {
        if (G.is_bridge[i]) {
            ans.emplace_back(G[i]);
        }
    }
    std::sort(ans.begin(), ans.end());
    for (auto& e : ans) std::cout << e.first << ' ' << e.second << '\n';
    return 0;
}