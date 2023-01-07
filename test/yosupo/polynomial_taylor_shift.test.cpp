#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "polynomial/FormalPowerSeries.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, c;
    std::cin >> N >> c;
    FPS a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];

    auto b = a.taylor_shift(c);
    for (int i = 0; i < N; i++) std::cout << b[i] << (i + 1 == N ? '\n' : ' ');
}