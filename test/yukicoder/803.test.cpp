#define PROBLEM "https://yukicoder.me/problems/no/803"

#include "linearalgebra/BitMatrix.hpp"
#include "util/modint.hpp"

const int MAX_LOG = 30, MAX_N = 305;
using mint = atcoder::modint1000000007;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M, X;
    std::cin >> N >> M >> X;
    BitMatrix<MAX_N> A(MAX_LOG + MAX_N, N);
    std::vector<bool> b(MAX_LOG + MAX_N);
    for (int i = 0; i < MAX_LOG; i++, X >>= 1) b[i] = X & 1;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        for (int j = 0; j < MAX_LOG; j++, a >>= 1) A[j][i] = a & 1;
    }
    for (int i = 0; i < M; i++) {
        int t, l, r;
        std::cin >> t >> l >> r;
        for (int j = --l; j < r; j++) A[MAX_LOG + i][j] = 1;
        b[MAX_LOG + i] = t;
    }

    int rank = A.system_of_linear_equations(b).first;
    if (rank == -1) {
        std::cout << 0 << '\n';
        return 0;
    }
    mint ans = mint(2).pow(N - rank);
    std::cout << ans << '\n';
    return 0;
}