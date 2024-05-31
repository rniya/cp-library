#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include "atcoder/modint"
#include "convolution/RelaxedConvolution.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    for (int i = 0; i < M; i++) std::cin >> b[i];

    RelaxedConvolution<mint> rc;
    for (int i = 0; i <= N + M - 2; i++) {
        mint ans = rc.query(i < N ? a[i] : 0, i < M ? b[i] : 0);
        std::cout << ans.val() << (i == N + M - 2 ? '\n' : ' ');
    }
    return 0;
}