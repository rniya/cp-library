#define PROBLEM "https://yukicoder.me/problems/no/1068"

#include "../../base.hpp"
#include "../../convolution/NumberTheoreticTransform.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<998244353>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;

    vector<vector<mint>> A(N, vector<mint>(2));
    NumberTheoreticTransform<998244353> NTT;
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        --a;
        A[i][0] = a, A[i][1] = 1;
    }

    auto dfs = [&](auto self, int l, int r) -> vector<mint> {
        if (r - l == 1) return A[l];
        int mid = (l + r) >> 1;
        return NTT.multiply(self(self, l, mid), self(self, mid, r));
    };

    vector<mint> dp = dfs(dfs, 0, N);
    for (; Q--;) {
        int B;
        cin >> B;
        cout << dp[B] << '\n';
    }
}