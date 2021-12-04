#define PROBLEM "https://judge.yosupo.jp/problem/characteristic_polynomial"

#include "linearalgebra/characteristic_polynomial.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<std::vector<mint>> a(N, std::vector<mint>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
        }
    }

    auto p = characteristic_polynomial(a);
    for (int i = 0; i <= N; i++) std::cout << p[i] << (i == N ? '\n' : ' ');
    return 0;
}