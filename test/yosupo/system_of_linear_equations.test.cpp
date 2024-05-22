#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

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
    std::vector<mint> b(N);
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        b[i] = val;
    }

    auto ans = A.system_of_linear_equations(b);
    int R = int(ans.size()) - 1;
    std::cout << R << '\n';
    for (auto& x : ans) {
        for (int i = 0; i < M; i++) {
            std::cout << x[i].val() << (i + 1 == M ? '\n' : ' ');
        }
    }
    return 0;
}
