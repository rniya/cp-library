#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../base.hpp"
#include "../../linearalgebra/Matrix.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<998244353>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    Matrix<mint> a(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    cout << a.determinant() << '\n';
}