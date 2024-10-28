#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

#include <iostream>
#include "matrix/F2Matrix.hpp"

const int MAX_M = (1 << 12) + 1;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    F2Matrix<MAX_M> A(N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char val;
            std::cin >> val;
            A[i][j] = val - '0';
        }
    }
    std::vector<bool> b(N);
    for (int i = 0; i < N; i++) {
        char val;
        std::cin >> val;
        b[i] = val - '0';
    }

    auto ans = A.system_of_linear_equations(b);
    int R = int(ans.size()) - 1;
    std::cout << R << '\n';
    for (auto& x : ans) {
        for (int i = 0; i < M; i++) {
            std::cout << x[i] << (i + 1 == M ? "\n" : "");
        }
    }
    return 0;
}
