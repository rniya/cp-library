#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include "convolution/convolution_arbitary_mod.hpp"

using mint = atcoder::modint1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<mint> a(N), b(M);
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        a[i] = x;
    }
    for (int i = 0; i < M; i++) {
        int x;
        std::cin >> x;
        b[i] = x;
    }

    auto c = convolution_arbitary_mod(a, b);
    for (int i = 0; i < N + M - 1; i++) std::cout << c[i].val() << (i + 1 == N + M - 1 ? '\n' : ' ');
}