#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "polynomial/FormalPowerSeries.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    FPS a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    FPS b = a.exp();
    for (int i = 0; i < N; i++) std::cout << b[i] << (i + 1 == N ? '\n' : ' ');
}