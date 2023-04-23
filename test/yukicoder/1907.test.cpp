#define PROBLEM "https://yukicoder.me/problems/no/1907"

#include <iostream>
#include "matrix/characteristic_polynomial.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<std::vector<mint>> M0(N, std::vector<mint>(N)), M1(N, std::vector<mint>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> M0[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> M1[i][j];
        }
    }

    auto ans = determinant_polynomial(M0, M1);
    for (auto& x : ans) std::cout << x << '\n';
    return 0;
}