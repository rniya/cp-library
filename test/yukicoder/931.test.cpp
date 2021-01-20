#define PROBLEM "https://yukicoder.me/problems/no/931"

#include "../../base.hpp"
#include "../../convolution/NumberTheoreticTransform.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<998244353>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int P;
    cin >> P;
    vector<mint> A(P), B(P);
    for (int i = 1; i < P; i++) cin >> A[i];
    for (int i = 1; i < P; i++) cin >> B[i];

    auto primitive_root = [](int p) -> int {
        for (int x = 1;; x++) {
            long long power = 1;
            for (int i = 0; i < p; i++) {
                (power *= x) %= p;
                if (i == p - 2) return x;
                if (power == 1) break;
            }
        }
    };

    int r = primitive_root(P);
    vector<mint> a(P - 1), b(P - 1);
    vector<long long> power(P, 1);
    for (int i = 0; i < P - 1; i++) {
        a[i] = A[power[i]];
        b[i] = B[power[i]];
        power[i + 1] = power[i] * r % P;
    }

    NumberTheoreticTransform<998244353> NTT;
    vector<mint> c = NTT.multiply(a, b), ans(P);
    for (int i = 0; i < c.size(); i++) {
        ans[power[i % (P - 1)]] += c[i];
    }

    for (int i = 1; i < P; i++) cout << ans[i] << (i + 1 == P ? '\n' : ' ');
}