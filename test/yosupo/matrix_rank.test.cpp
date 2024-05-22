#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include <iostream>
#include "atcoder/modint"
#include "matrix/Matrix.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    Matrix<mint> A(N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val;
            std::cin >> val;
            A[i][j] = val;
        }
    }

    int rank = A.rank();
    std::cout << rank << '\n';
    return 0;
}
