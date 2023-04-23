#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "matrix/Matrix.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    Matrix<mint> a(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
        }
    }

    std::cout << a.determinant() << '\n';
}