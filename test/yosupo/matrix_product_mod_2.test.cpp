#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"

#include <iostream>
#include "matrix/F2Matrix.hpp"

const int MAX = 1 << 12;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M, K;
    std::cin >> N >> M >> K;
    F2Matrix<MAX> A(N, M), B(M, K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char val;
            std::cin >> val;
            A[i][j] = val - '0';
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            char val;
            std::cin >> val;
            B[i][j] = val - '0';
        }
    }

    auto C = A * B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) std::cout << C[i][j];
        std::cout << '\n';
    }
    return 0;
}
