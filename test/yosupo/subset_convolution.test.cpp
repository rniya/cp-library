#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "convolution/subset_convolution.hpp"
#include <iostream>
#include "atcoder/modint"

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<mint> a(1 << N), b(1 << N);
    for (int i = 0; i < 1 << N; i++) {
        int x;
        std::cin >> x;
        a[i] = mint::raw(x);
    }
    for (int i = 0; i < 1 << N; i++) {
        int x;
        std::cin >> x;
        b[i] = mint::raw(x);
    }

    auto c = subset_convolution(a, b);
    for (int i = 0; i < 1 << N; i++) std::cout << c[i].val() << (i + 1 == (1 << N) ? '\n' : ' ');
}