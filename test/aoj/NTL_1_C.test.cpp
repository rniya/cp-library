#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C"

#include <iostream>
#include "math/binary_gcd.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int ans = 1;
    for (; n--;) {
        int a;
        std::cin >> a;
        ans = ans * a / binary_gcd(ans, a);
    }
    std::cout << ans << '\n';
    return 0;
}