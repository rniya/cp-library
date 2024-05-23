#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"

#include <iostream>
#include "matrix/F2Matrix.hpp"

const int MAX = 1 << 12;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    F2Matrix<MAX> A(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char val;
            std::cin >> val;
            A[i][j] = val - '0';
        }
    }

    int det = A.det();
    std::cout << det << '\n';
    return 0;
}
