#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#include "math/discrete_logarithm.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    for (; T--;) {
        int X, Y, M;
        std::cin >> X >> Y >> M;
        std::cout << discrete_logarithm(X, Y, M) << '\n';
    }
    return 0;
}