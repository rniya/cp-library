#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <iostream>
#include "graph/DirectedCycleDetection.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    DirectedCycleDetection G(N);
    for (; M--;) {
        int u, v;
        std::cin >> u >> v;
        G.add_edge(u, v);
    }

    auto [vs, es] = G.build();
    if (es.empty()) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::cout << es.size() << '\n';
    for (auto& e : es) std::cout << e << '\n';
    return 0;
}