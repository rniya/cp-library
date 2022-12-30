#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include "graph/LowLink.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    LowLink G(N);
    for (; M--;) {
        int a, b;
        std::cin >> a >> b;
        G.add_edge(a, b);
    }

    G.build();
    auto& tecc = G.tecc;
    int K = G.t;
    std::vector<std::vector<int>> ans(K);
    for (int i = 0; i < N; i++) ans[tecc[i]].emplace_back(i);
    std::cout << K << '\n';
    for (int i = 0; i < K; i++) {
        std::cout << ans[i].size();
        for (int& v : ans[i]) std::cout << ' ' << v;
        std::cout << '\n';
    }
}