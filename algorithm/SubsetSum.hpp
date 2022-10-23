#pragma once
#include <vector>

std::vector<bool> SubsetSum(const std::vector<int>& a, int S) {
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
