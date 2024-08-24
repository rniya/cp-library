#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"

#include <iostream>
#include "graph/UndirectedCycleDetection.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    UndirectedCycleDetection G(N);
    for (; M--;) {
        int u, v;
        std::cin >> u >> v;
        G.add_edge(u, v);
    }

    auto [vs, es] = G.build();
    if (vs.empty()) {
        std::cout << -1 << '\n';
        return 0;
    }
    int L = vs.size();
    assert(int(es.size()) == L);
    std::cout << L << "\n";
    for (int i = 0; i < L; i++) std::cout << vs[i] << (i + 1 == L ? "\n" : " ");
    for (int i = 0; i < L; i++) std::cout << es[i] << (i + 1 == L ? "\n" : " ");
    return 0;
}