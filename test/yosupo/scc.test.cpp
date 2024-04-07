#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include "graph/StronglyConnectedComponents.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;

    StronglyConnectedComponents SCC(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        SCC.add_edge(a, b);
    }

    auto res = SCC.build();
    std::cout << res.size() << '\n';
    for (auto& group : res) {
        std::cout << group.size();
        for (int& v : group) std::cout << ' ' << v;
        std::cout << '\n';
    }
}