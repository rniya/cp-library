#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "math/gcd_convolution.hpp"
#include <iostream>
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<mint> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) std::cin >> a[i];
    for (int i = 1; i <= N; i++) std::cin >> b[i];

    auto c = gcd_convolution::gcd_convolution(a, b);
    for (int i = 1; i <= N; i++) std::cout << c[i] << (i == N ? '\n' : ' ');
    return 0;
}