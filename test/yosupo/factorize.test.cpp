#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>
#include "math/fast_factorize.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int Q;
    std::cin >> Q;
    for (; Q--;) {
        long long a;
        std::cin >> a;
        auto res = fast_factorize::factorize(a);
        std::cout << res.size();
        for (auto& x : res) std::cout << ' ' << x;
        std::cout << '\n';
    }
    return 0;
}