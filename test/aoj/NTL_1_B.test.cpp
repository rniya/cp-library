#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include "base.hpp"
#include "math/elementary_math.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    cout << elementary_math::modpow(m, n, 1000000007) << '\n';
    return 0;
}