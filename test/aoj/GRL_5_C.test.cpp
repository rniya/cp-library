#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"

#include <iostream>
#include "tree/HeavyLightDecomposition.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    HeavyLightDecomposition HLD(n);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        for (; k--;) {
            int c;
            std::cin >> c;
            HLD.add_edge(i, c);
        }
    }
    HLD.build();

    int q;
    std::cin >> q;
    for (; q--;) {
        int u, v;
        std::cin >> u >> v;
        std::cout << HLD.lca(u, v) << '\n';
    }
}