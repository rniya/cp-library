#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <iostream>
#include "tree/HeavyLightDecomposition.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    HeavyLightDecomposition HLD(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        HLD.add_edge(a, b);
    }

    HLD.build();
    for (; Q--;) {
        int s, t, i;
        std::cin >> s >> t >> i;
        std::cout << HLD.jump(s, t, i) << '\n';
    }
    return 0;
}