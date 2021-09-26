#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_C"

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

    mint ans = 0;
    for (int i = 0; i < k; i++) {
        mint add = BINOM.C(k, i) * mint(k - i).pow(n);
        if (i & 1)
            ans -= add;
        else
            ans += add;
    }

    cout << ans << '\n';
}