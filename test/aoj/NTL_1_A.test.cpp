#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include <iostream>
#include "math/elementary_math.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;

    auto ans = elementary_math::prime_factor(n);
    std::cout << n << ':';
    for (auto p : ans) {
        for (int i = 0; i < p.second; i++) {
            std::cout << ' ' << p.first;
        }
    }
    std::cout << '\n';
    return 0;
}