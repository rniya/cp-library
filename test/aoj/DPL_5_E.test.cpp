#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E"

#include "math/binomial.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint1000000007;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    Binomial<mint> BINOM;
    int n, k;
    std::cin >> n >> k;

    std::cout << BINOM.C(k, n) << '\n';
}