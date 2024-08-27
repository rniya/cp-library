#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include <iostream>
#include "atcoder/modint"
#include "math/sum_of_multiplicative_function.hpp"

using mint = atcoder::modint998244353;

mint f(long long p, long long c) { return mint(p).pow(c - 1) * (p - 1); }

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    long long N;
    std::cin >> N;

    sum_of_multiplicative_function<mint, f> smf(N);
    auto ans = smf.sum_of_totient_function();

    std::cout << ans.val() << "\n";
    return 0;
}