#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"

#include "base.hpp"
#include "math/elementary_math.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << elementary_math::euler_phi(n) << '\n';
    return 0;
}