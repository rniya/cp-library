#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../../base.hpp"
#include "../../convolution/ArbitaryModConvolution.hpp"

using mint = modint<1000000007>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<mint> a(N), b(M);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];

    vector<mint> c = ArbitaryModConvolution(a, b);
    for (int i = 0; i < N + M - 1; i++) cout << c[i] << (i == N + M - 2 ? '\n' : ' ');
}