#define PROBLEM "https://judge.yosupo.jp/problem/characteristic_polynomial"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../linearalgebra/characteristic_polynomial.hpp"

using mint = modint<998244353>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<mint>> a(N, vector<mint>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    auto p = characteristic_polynomial(a);
    for (int i = 0; i <= N; i++) cout << p[i] << (i == N ? '\n' : ' ');
    return 0;
}