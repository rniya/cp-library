#define PROBLEM "https://yukicoder.me/problems/no/1050"

#include "linearalgebra/SquareMatrix.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint1000000007;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int M, K;
    std::cin >> M >> K;

    SquareMatrix<mint, 55> SM;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            SM[i][(i + j) % M]++;
            SM[i][i * j % M]++;
        }
    }

    SM ^= K;
    std::cout << SM[0][0] << '\n';
}