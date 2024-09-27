#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"

#include "math/sum_of_multiplicative_function.hpp"
#include <iostream>
#include "atcoder/modint"

using mint = atcoder::static_modint<469762049>;

long long a, b;

mint f(long long p, long long e) { return mint(a) * e + mint(b) * p; }

void solve() {
    long long N;
    std::cin >> N >> a >> b;

    sum_of_multiplicative_function<mint, f> smf(N);
    auto S0 = smf.counting_primes();
    auto S1 = smf.summing_primes();
    for (int i = 0; i < int(S1.size()); i++) S1[i] = S1[i] * b + S0[i] * a;
    auto ans = smf.solve(S1);

    std::cout << ans.val() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (; T--;) solve();
    return 0;
}