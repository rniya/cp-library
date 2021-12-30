#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "polynomial/BostanMori.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int d;
    long long k;
    std::cin >> d >> k;
    std::vector<mint> a(d), c(d);
    for (auto& x : a) std::cin >> x;
    for (auto& x : c) std::cin >> x;

    auto ans = LinearRecurrence(a, c, k);
    std::cout << ans << '\n';
    return 0;
}