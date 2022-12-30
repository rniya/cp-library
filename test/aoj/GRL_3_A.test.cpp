#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include <iostream>
#include "graph/LowLink.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int V, E;
    std::cin >> V >> E;
    LowLink G(V);
    for (; E--;) {
        int s, t;
        std::cin >> s >> t;
        G.add_edge(s, t);
    }

    G.build();
    for (int i = 0; i < V; i++) {
        if (G.is_articulation[i]) {
            std::cout << i << '\n';
        }
    }
    return 0;
}