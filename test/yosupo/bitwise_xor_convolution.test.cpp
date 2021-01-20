#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "../../base.hpp"
#include "../../convolution/XORconvolution.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<998244353>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<mint> a(1 << N), b(1 << N);
    for (int i = 0; i < (1 << N); i++) cin >> a[i];
    for (int i = 0; i < (1 << N); i++) cin >> b[i];

    vector<mint> c = XOR_convolution(a, b);
    for (int i = 0; i < (1 << N); i++) cout << c[i] << (i + 1 == (1 << N) ? '\n' : ' ');
}