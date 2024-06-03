#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_directed"

#include <iostream>
#include "atcoder/modint"
#include "tree/counting_spanning_trees.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, r;
    std::cin >> N >> M >> r;
    std::vector G(N, std::vector<mint>(N, 0));
    for (; M--;) {
        int u, v;
        std::cin >> u >> v;
        G[v][u]++;
    }

    auto ans = counting_spanning_trees_directed(G, r);
    std::cout << ans.val() << '\n';
    return 0;
}