#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include "base.hpp"
#include "math/elementary_math.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    auto ans = elementary_math::prime_factor(n);
    cout << n << ':';
    for (auto p : ans) {
        for (int i = 0; i < p.second; i++) {
            cout << ' ' << p.first;
        }
    }
    cout << '\n';
    return 0;
}