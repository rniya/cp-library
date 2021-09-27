#define PROBLEM "https://yukicoder.me/problems/no/1289"

#include "../../base.hpp"
#include "../../convolution/set_function.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<998244353>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(1 << N);
    int sum = 0;
    for (int i = 0; i < (1 << N); i++) {
        cin >> A[i];
        sum += A[i];
    }

    set_function::subset_zeta_transform(A);
    mint ans = 0, inv = mint(1) / sum;

    for (int mask = 0; mask < (1 << N) - 1; mask++) {
        mint add = mint(1) / (1 - inv * A[mask]);
        if (__builtin_popcount((1 << N) - 1 - mask) & 1)
            ans += add;
        else
            ans -= add;
    }

    cout << ans << '\n';
    return 0;
}