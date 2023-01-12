#pragma once
#include <vector>
#include "FormalPowerSeries.hpp"

template <typename T> std::vector<T> subset_sum(const std::vector<int>& s, int m) {
    std::vector<int> cnt(m + 1, 0);
    for (const int& x : s) {
        assert(x >= 0);
        if (x <= m) cnt[x]++;
    }
    FormalPowerSeries<T> res(m + 1);
    std::vector<T> inv(m + 1);
    inv[0] = T(0);
    if (m > 0) inv[1] = T(1);
    auto mod = T::mod();
    for (int i = 2; i <= m; i++) inv[i] = -inv[mod % i] * (mod / i);
    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) continue;
        for (int j = 1; i * j <= m; j++) {
            if (j & 1)
                res[i * j] += inv[j] * cnt[i];
            else
                res[i * j] -= inv[j] * cnt[i];
        }
    }
    res = res.exp(m + 1);
    T p = T(2).pow(cnt[0]);
    for (auto& val : res) val *= p;
    return res;
}
