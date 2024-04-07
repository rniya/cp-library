#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include <iostream>
#include "graph/BellmanFord.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int V, E, r;
    std::cin >> V >> E >> r;

    BellmanFord<int> BF(V);

    for (int i = 0; i < E; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        BF.add_edge(s, t, d);
    }

    auto ans = BF.solve(r);
    if (ans.empty()) {
        std::cout << "NEGATIVE CYCLE" << '\n';
        return 0;
    }
    for (int i = 0; i < V; i++) {
        if (ans[i] > 1e9)
            std::cout << "INF" << '\n';
        else
            std::cout << ans[i] << '\n';
    }
    return 0;
}