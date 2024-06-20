#pragma once
#include "../atcoder/convolution"
#include "math/binomial.hpp"

template <typename T> T number_of_increasing_sequences_between_two_sequences(std::vector<int> a, std::vector<int> b) {
    assert(a.size() == b.size());
    int n = a.size();
    for (int i = 0; i < n; i++) b[i]--;
    for (int i = 1; i < n; i++) a[i] = std::max(a[i], a[i - 1]);
    for (int i = n - 2; i >= 0; i--) b[i] = std::min(b[i], b[i + 1]);
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            return T(0);
        }
    }
    int m = b[n - 1] + 1;
    std::vector<int> L(n + m, 0), U(n + m, m - 1);
    U[0] = 0;
    L[n + m - 1] = m - 1;
    for (int i = 0; i < n; i++) {
        L[i + a[i]] = std::max(L[i + a[i]], a[i]);
        U[i + b[i] + 1] = std::min(U[i + b[i] + 1], b[i]);
    }
    n = L.size();
    for (int i = 1; i < n; i++) L[i] = std::max(L[i], L[i - 1]);
    for (int i = n - 2; i >= 0; i--) L[i] = std::max(L[i], L[i + 1] - 1);
    for (int i = n - 2; i >= 0; i--) U[i] = std::min(U[i], U[i + 1]);
    for (int i = 1; i < n; i++) U[i] = std::min(U[i], U[i - 1] + 1);
    Binomial<T> binom;
    auto extract = [](const std::vector<T>& dp, int l, int r = -1) {
        int len = dp.size();
        if (l >= len) return std::vector<T>();
        r = (r == -1 ? len : len < r ? len : r);
        return std::vector<T>(dp.begin() + l, dp.begin() + r);
    };
    auto go = [&](int l, int r, const std::vector<T>& dp) -> std::vector<T> {
        int len = r - l;
        std::vector<T> f(len + 1);
        for (int i = 0; i <= len; i++) f[i] = binom.C(len, i);
        return atcoder::convolution(dp, f);
    };
    auto dfs_only_L = [&](auto self, int l, int r, const std::vector<T>& dp) -> std::vector<T> {
        if (r - l == 1) {
            auto res = go(l, r, dp);
            if (L[l] != L[r]) res = extract(res, L[r] - L[l]);
            return res;
        }

        int m = (l + r) >> 1;
        auto M = go(l, m, extract(dp, L[m] - L[l]));
        auto buf = self(self, l, m, extract(dp, 0, L[m] - L[l]));
        while (M.size() < buf.size()) M.emplace_back(0);
        for (int i = 0; i < int(buf.size()); i++) M[i] += buf[i];

        auto R = go(m, r, extract(M, L[r] - L[m]));
        buf = self(self, m, r, extract(M, 0, L[r] - L[m]));
        while (R.size() < buf.size()) R.emplace_back(0);
        for (int i = 0; i < int(buf.size()); i++) R[i] += buf[i];
        return R;
    };
    auto dfs_only_R = [&](auto self, int l, int r, const std::vector<T>& dp) -> std::vector<T> {
        if (r - l == 1) {
            if (U[l] == U[r]) return std::vector<T>();
            return extract(go(l, r, dp), 1);
        }

        int m = (l + r) >> 1;
        std::vector<T> M((U[m] - U[l]) + (r - m), T(0));
        auto buf = go(l, m, dp);
        for (int i = m - l; i < std::min(int(buf.size()), r - l); i++) M[i - (m - l)] += buf[i];
        buf = self(self, l, m, extract(dp, int(dp.size()) - (m - l)));
        for (int i = 0; i < int(buf.size()); i++) M[i + (r - m)] += buf[i];

        std::vector<T> R(U[r] - U[l], T(0));
        buf = go(m, r, M);
        for (int i = r - m; i < std::min(int(buf.size()), ((U[m] - U[l]) + (r - m))); i++) R[i - (r - m)] += buf[i];
        buf = self(self, m, r, extract(M, int(M.size()) - (r - m)));
        for (int i = 0; i < int(buf.size()); i++) R[i + (U[m] - U[l])] += buf[i];
        return R;
    };
    auto dfs = [&](auto self, int l, int r, const std::vector<T>& dp) -> std::vector<T> {
        if (r - l == 1) {
            auto res = go(l, r, dp);
            return extract(res, L[r] - L[l], U[r] - L[l] + 1);
        }

        if (L[r] + (r - l) <= U[l]) {
            std::vector<T> res(U[r] - L[r] + 1, T(0));
            auto buf = go(l, r, extract(dp, L[r] - L[l]));
            for (int i = 0; i < std::min(int(buf.size()), U[l] - L[r] + 1); i++) res[i] += buf[i];
            buf = dfs_only_L(dfs_only_L, l, r, extract(dp, 0, L[r] - L[l]));
            for (int i = 0; i < int(buf.size()); i++) res[i] += buf[i];
            buf = dfs_only_R(dfs_only_R, l, r, extract(dp, int(dp.size()) - (r - l)));
            for (int i = 0; i < int(buf.size()); i++) res[int(res.size()) - 1 - i] += buf[int(buf.size()) - 1 - i];
            return res;
        }

        int m = (l + r) >> 1;
        return self(self, m, r, self(self, l, m, dp));
    };
    std::vector<T> init(1, T(1));
    auto last = dfs(dfs, 0, n - 1, init);
    return std::accumulate(last.begin(), last.end(), T(0));
}
