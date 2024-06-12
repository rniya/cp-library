#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"

#include <iostream>
#include "matrix/F2Matrix.hpp"

const int MAX_N = 1 << 12;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    F2Matrix<MAX_N> a(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char val;
            std::cin >> val;
            a[i][j] = (val == '1');
        }
    }

    if (a.det() == 0) {
        std::cout << -1 << "\n";
        return 0;
    }
    auto b = a.inv();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) std::cout << b[i][j];
        std::cout << "\n";
    }
}