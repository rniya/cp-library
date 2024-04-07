#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"

#include <iostream>
#include "math/elementary_math.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;

    std::cout << elementary_math::euler_phi(n) << '\n';
    return 0;
}