#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

std::vector<int> SubsetSum(const std::vector<int>& a, int S) {
    int n = a.size(), sum = std::accumulate(a.begin(), a.end(), 0);
    if (S < 0 or sum < S) return {};
    bool flip = (S * 2 < sum);
    if (flip) S = sum - S;

    int l = 0;
    while (l < n and S > 0) S -= a[l++];
    int a_max = *std::max_element(a.begin(), a.end()), m = a_max * 2 + 1;
    const int inf = 1 << 30;
    std::vector<std::vector<int>> dp(n + 1);
    for (int i = l; i <= n; i++) dp[i].assign(m, inf);
    dp[l][a_max - S] = 0;

    for (int i = l; i <= n; i++) {
        for (int k = m - 1; k >= 0; k--) {
            if (k > a_max) {
                int r = l;
                if (i > l) r = std::min(r, dp[i - 1][k]);
                for (int j = dp[i][k]; j < r; j++) dp[i][k - a[j]] = std::min(dp[i][k - a[j]], j + 1);
            }
            if (i < n) {
                dp[i + 1][k] = std::min(dp[i + 1][k], dp[i][k]);
                if (k < a_max) dp[i + 1][k + a[i]] = std::min(dp[i + 1][k + a[i]], dp[i][k]);
            }
        }
        if (dp[i][a_max] == inf) continue;
        std::vector<int> res(n);
        std::fill(res.begin(), res.begin() + l, 1);
        for (int k = a_max;;) {
            int j = dp[i][k];
            if (j == 0 and i == l) break;
            if (j != inf and j != 0 and k + a[j - 1] < m and dp[i][k + a[j - 1]] < j) {
                k += a[j - 1];
                res[j - 1] = 0;
                continue;
            }
            i--;
            if (dp[i][k] != j) {
                k -= a[i];
                res[i] = 1;
            }
        }

        if (flip) {
            for (int& x : res) {
                x ^= 1;
            }
        }
        return res;
    }
    return {};
}
