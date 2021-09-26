#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G"

#include "../../base.hpp"
#include "../../combinatorics/BellNumber.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<1000000007>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    cout << bell_number<mint>(n, k) << '\n';
}