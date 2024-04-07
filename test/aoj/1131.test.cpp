#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1131"

#include <iostream>
#include "util/Rational.hpp"

using R = Rational<int>;

int dfs(R r, int dep, int pre, int mul, int a) {
    if (dep == 0) return r == 0;
    if (r == 0) return 1;
    int res = 0;
    for (int i = a / mul; i >= pre; i--) {
        if (r < R(1, i)) break;
        res += dfs(r - R(1, i), dep - 1, i, mul * i, a);
    }
    return res;
}

void solve(int p, int q, int a, int n) {
    R r(p, q);
    int ans = dfs(r, n, 1, 1, a);
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    for (int p, q, a, n; std::cin >> p >> q >> a >> n, n;) solve(p, q, a, n);
    return 0;
}