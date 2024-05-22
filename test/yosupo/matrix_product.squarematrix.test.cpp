#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <iostream>
#include "atcoder/modint"
#include "matrix/SquareMatrix.hpp"

using mint = atcoder::modint998244353;
constexpr int MAX = 1 << 10;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M, K;
    std::cin >> N >> M >> K;
    SquareMatrix<mint, MAX> A, B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val;
            std::cin >> val;
            A[i][j] = val;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int val;
            std::cin >> val;
            B[i][j] = val;
        }
    }
    auto C = A * B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            std::cout << C[i][j].val() << (j + 1 == K ? '\n' : ' ');
        }
    }
}