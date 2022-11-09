#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include "polynomial/FormalPowerSeries.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, K;
    long long M;
    std::cin >> N >> K >> M;
    std::vector<std::pair<int, mint>> f;
    for (; K--;) {
        int i, a;
        std::cin >> i >> a;
        f.emplace_back(i, a);
    }

    auto b = FPS::pow_sparse(f, M, N);
    for (int i = 0; i < N; i++) std::cout << b[i] << (i + 1 == N ? '\n' : ' ');
}