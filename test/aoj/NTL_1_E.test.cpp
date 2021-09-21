#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../../base.hpp"
#include "../../math/elementary_math.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long a, b, x, y;
    cin >> a >> b;
    elementary_math::extgcd(a, b, x, y);
    cout << x << ' ' << y << '\n';
}