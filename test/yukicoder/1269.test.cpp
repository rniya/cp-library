#define PROBLEM "https://yukicoder.me/problems/no/1269"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../string/AhoCorasick.hpp"

using mint = modint<1000000007>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    ll L, R;
    cin >> N >> L >> R;

    vector<ll> fib(2);
    fib[0] = fib[1] = 1;
    for (int i = 2; fib[i - 1] + fib[i - 2] <= R; i++) {
        fib.emplace_back(fib[i - 1] + fib[i - 2]);
    }
    AhoCorasick<10> AHO([](char c) { return c - '0'; });
    for (ll f : fib) {
        if (L <= f) {
            AHO.add(to_string(f));
        }
    }
    AHO.build(false);

    int n = AHO.size();
    vector<vector<mint>> dp(N + 1, vector<mint>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 10; k++) {
                int nxt = AHO.move('0' + k, j);
                if (!AHO.count(nxt)) dp[i + 1][nxt] += dp[i][j];
            }
        }
    }

    mint ans = 0;
    for (int j = 0; j < n; j++) ans += dp[N][j];
    cout << ans - 1 << '\n';
}