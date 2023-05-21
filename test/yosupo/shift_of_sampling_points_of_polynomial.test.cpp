#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include "polynomial/shift_of_sampling_points_of_polynomial.hpp"
#include <iostream>

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, c;
    std::cin >> N >> M >> c;
    std::vector<mint> f(N);
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        f[i] = x;
    }

    auto res = shift_of_sampling_points_of_polynomial<mint>(f, c, M);
    for (int i = 0; i < M; i++) std::cout << res[i].val() << (i + 1 == M ? '\n' : ' ');
    return 0;
}