#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "graph/BipartiteMatching.hpp"
#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int L, R, M;
    std::cin >> L >> R >> M;

    BipartiteMatching BM(L, R);
    for (; M--;) {
        int a, b;
        std::cin >> a >> b;
        BM.add_edge(a, b);
    }

    BM.solve();
    auto ans = BM.max_matching();
    std::cout << ans.size() << '\n';
    for (auto p : ans) std::cout << p.first << ' ' << p.second << '\n';
    return 0;
}