#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include <iostream>
#include "math/elementary_math.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int m, n;
    std::cin >> m >> n;

    std::cout << elementary_math::modpow(m, n, 1000000007) << '\n';
    return 0;
}