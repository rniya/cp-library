#define PROBLEM "https://yukicoder.me/problems/no/1269"

#include "string/AhoCorasick.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint1000000007;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    long long L, R;
    std::cin >> N >> L >> R;

    std::vector<long long> fib(2);
    fib[0] = fib[1] = 1;
    for (int i = 2; fib[i - 1] + fib[i - 2] <= R; i++) fib.emplace_back(fib[i - 1] + fib[i - 2]);
    AhoCorasick<10, '0'> AHO;
    for (auto f : fib) {
        if (L <= f) {
            AHO.add(std::to_string(f));
        }
    }
    AHO.build(false);

    int n = AHO.size();
    std::vector<std::vector<mint>> dp(N + 1, std::vector<mint>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 10; k++) {
                int nxt = AHO.move(j, '0' + k);
                if (!AHO.count(nxt)) dp[i + 1][nxt] += dp[i][j];
            }
        }
    }

    mint ans = 0;
    for (int j = 0; j < n; j++) ans += dp[N][j];
    std::cout << ans - 1 << '\n';
    return 0;
}