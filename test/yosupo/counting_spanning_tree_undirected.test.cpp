#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"

#include <iostream>
#include "atcoder/modint"
#include "tree/counting_spanning_trees.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector G(N, std::vector<mint>(N, 0));
    for (; M--;) {
        int u, v;
        std::cin >> u >> v;
        G[u][v]++;
        G[v][u]++;
    }

    auto ans = counting_spanning_trees_undirected(G);
    std::cout << ans.val() << '\n';
    return 0;
}