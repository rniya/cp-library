#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
#include "atcoder/modint"
#include "matrix/SquareMatrix.hpp"

using mint = atcoder::modint998244353;
constexpr int MAX = 1 << 9;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    SquareMatrix<mint, MAX> A;
    for (int i = 0; i < MAX; i++) A[i][i] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            std::cin >> val;
            A[i][j] = val;
        }
    }

    auto det = A.det();
    std::cout << det.val() << '\n';
    return 0;
}
