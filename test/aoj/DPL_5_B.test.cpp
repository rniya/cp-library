#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

#include "../../base.hpp"
#include "../../combinatorics/binomial.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<1000000007>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Binomial<mint> BINOM;
    int n, k;
    cin >> n >> k;

    cout << BINOM.P(k, n) << '\n';
}