#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include <iostream>
#include "atcoder/modint.hpp"
#include "polynomial/FormalPowerSeries.hpp"

namespace atcoder {

template <int MOD> std::istream& operator>>(std::istream& is, static_modint<MOD>& x) {
    int64_t v;
    x = static_modint<MOD>{(is >> v, v)};
    return is;
}

template <int MOD> std::ostream& operator<<(std::ostream& os, const static_modint<MOD>& x) { return os << x.val(); }

template <int ID> std::ostream& operator<<(std::ostream& os, const dynamic_modint<ID>& x) { return os << x.val(); }

}  // namespace atcoder

using mint = atcoder::modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    FPS a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    FPS b = a.log();
    for (int i = 0; i < N; i++) std::cout << b[i] << (i + 1 == N ? '\n' : ' ');
}