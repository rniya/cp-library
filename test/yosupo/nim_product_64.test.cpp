#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include <iostream>
#include "math/Nimber.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    for (; T--;) {
        unsigned long long A, B;
        std::cin >> A >> B;
        auto ans = (Nimber64::nim(A) * Nimber64::nim(B)).v;
        std::cout << ans << '\n';
    }
    return 0;
}