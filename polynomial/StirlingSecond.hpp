#pragma once
#include "../base.hpp"
#include "../polynomial/FormalPowerSeries.hpp"

/**
 * @brief 第2種スターリング数
 * @docs docs/polynomial/StirlingSecond.md
 */
template <typename T> FormalPowerSeries<T> StirlingSecond(int n) {
    FormalPowerSeries<T> a(n + 1), b(n + 1);
    T prod = 1;
    for (int i = 0; i <= n; i++) {
        T inv = T(1) / prod;
        a[i] = T(i).pow(n) * inv;
        b[i] = T(1) * inv;
        if (i & 1) b[i] *= -1;
        prod *= i + 1;
    }
    return (a * b).pre(n + 1);
}