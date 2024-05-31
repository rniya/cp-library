#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

std::vector<bool> SubsetSum1(const std::vector<int>& a, int S) {  // O(N * S)
    int n = a.size();
    std::vector<int> dp(S + 1, -1);
    int m = (S >> 6) + 1;
    std::vector<unsigned long long> A(m, 0), B(m, 0);
    A[0] = 1;

    for (int i = 0; i < n; i++) {
        int x = a[i] >> 6, y = a[i] & 63;
        for (int j = 0; j < m; j++) {
            if (j + x < m) B[j + x] |= (A[j] << y);
            if (j + x + 1 < m and y) B[j + x + 1] |= (A[j] >> (64 - y));
        }
        for (int j = 0; j < m; j++) {
            B[j] &= ~A[j];
            A[j] |= B[j];
            while (B[j]) {
                int k = __builtin_ctzll(B[j]);
                if ((j << 6) + k <= S) dp[(j << 6) + k] = i;
                B[j] &= ~(1ULL << k);
            }
        }
    }

    if (S > 0 and dp[S] == -1) return {};
    std::vector<bool> res(n, false);
    while (S > 0) {
        res[dp[S]] = true;
        S -= a[dp[S]];
    }
    return res;
}

std::vector<int> SubsetSum2(const std::vector<int>& a, int S) {  // O(N * max(a))
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
