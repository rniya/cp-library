#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <iostream>
#include "atcoder/modint"
#include "graph/count_graphs.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> x(N);
    for (int i = 0; i < N; i++) std::cin >> x[i];
    std::vector<std::vector<int>> G(N);
    for (; M--;) {
        int u, v;
        std::cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    mint ans = 0;
    for (auto [a, b, c] : count_graphs::enumerate_C4(G)) ans += mint(1) * x[a] * x[b] * x[c];
    std::cout << ans.val() << '\n';
    return 0;
}