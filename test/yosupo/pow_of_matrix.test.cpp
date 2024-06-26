#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include <iostream>
#include "atcoder/modint"
#include "matrix/Matrix.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    long long K;
    std::cin >> N >> K;
    Matrix<mint> A(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            std::cin >> val;
            A[i][j] = val;
        }
    }

    auto B = A.pow(K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << B[i][j].val() << (j + 1 == N ? '\n' : ' ');
        }
    }
    return 0;
}
