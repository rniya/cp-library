#define PROBLEM "https://yukicoder.me/problems/no/803"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../datastructure/BitMatrix.hpp"

const int MAX_LOG = 30, MAX_N = 305;
using BM = BitMatrix<MAX_N>;
using mint = modint<1000000007>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, X;
    cin >> N >> M >> X;
    BM A(MAX_LOG + MAX_N);
    vector<int> b(MAX_LOG + MAX_N);
    for (int i = 0; i < MAX_LOG; i++, X >>= 1) b[i] = X & 1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < MAX_LOG; j++, a >>= 1) A[j][i] = a & 1;
    }
    for (int i = 0; i < M; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        for (int j = --l; j < r; j++) A[MAX_LOG + i][j] = 1;
        b[MAX_LOG + i] = t;
    }

    int rank = A.linear_equation(b).first;
    if (rank == -1) {
        cout << 0 << '\n';
        return 0;
    }
    mint ans = mint(2).pow(N - rank);
    cout << ans << '\n';
    return 0;
}