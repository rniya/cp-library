#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"

#include "math/exp_of_set_power_series.hpp"
#include <iostream>
#include "atcoder/modint"

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<mint> b(1 << N);
    for (int i = 0; i < 1 << N; i++) {
        int x;
        std::cin >> x;
        b[i] = mint::raw(x);
    }

    auto c = exp_of_set_power_series(b);
    for (int i = 0; i < 1 << N; i++) std::cout << c[i].val() << (i + 1 == (1 << N) ? '\n' : ' ');
}