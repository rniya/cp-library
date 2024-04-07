#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include <iostream>
#include "math/elementary_math.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    long long a, b, x, y;
    std::cin >> a >> b;

    elementary_math::extgcd(a, b, x, y);
    std::cout << x << ' ' << y << '\n';
}