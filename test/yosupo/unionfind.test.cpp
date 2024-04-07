#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "datastructure/UnionFind.hpp"
#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;

    UnionFind UF(N);
    for (; Q--;) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (!t)
            UF.merge(u, v);
        else
            std::cout << UF.same(u, v) << '\n';
    }
}