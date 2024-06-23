#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "convolution/gcd_convolution.hpp"
#include <iostream>
#include "atcoder/modint"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<mint> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    for (int i = 1; i <= N; i++) {
        int val;
        std::cin >> val;
        b[i] = val;
    }

    auto c = gcd_convolution(a, b);
    for (int i = 1; i <= N; i++) std::cout << c[i].val() << (i == N ? '\n' : ' ');
    return 0;
}