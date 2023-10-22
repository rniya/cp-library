#pragma once
#include "FormalPowerSeries.hpp"

template <typename T> T difference_product(const std::vector<int>& x) {
    int n = x.size(), k = 1;
    while (k < n) k <<= 1;
    std::vector<FormalPowerSeries<T>> prod(k << 1, {1});
    for (int i = 0; i < n; i++) prod[k + i] = {-x[i], 1};
    for (int i = k - 1; i > 0; i--) prod[i] = prod[i << 1] * prod[i << 1 | 1];
    std::vector<FormalPowerSeries<T>> rem(k << 1);
    rem[0] = {1};
    for (int i = 1; i < k + n; i++) {
        rem[i] = rem[i >> 1];
        if (~i & 1) rem[i] *= prod[i | 1];
        rem[i] %= prod[i];
    }
    T res = 1;
    for (int i = 0; i < n; i++) res *= (rem[k + i].empty() ? 0 : rem[k + i][0]);
    return res;
}