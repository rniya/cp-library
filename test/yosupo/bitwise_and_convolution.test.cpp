#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../../base.hpp"
#include "../../convolution/set_function.hpp"
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

    vector<mint> c = set_function::and_convolution(a, b);
    for (int i = 0; i < (1 << N); i++) cout << c[i] << (i + 1 == (1 << N) ? '\n' : ' ');
    return 0;
}