#pragma once
#include <cassert>
#include "../optimization/monotone_minima.hpp"

template <typename T>
std::vector<T> min_plus_convolution_convex_arbitrary(const std::vector<T>& a, const std::vector<T>& b) {
    int n = a.size(), m = b.size();
    assert(n and m);
    for (int i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);
    auto f = [&](int i, int j) { return a[i - j] + b[j]; };
    auto select = [&](int i, int j, int k) {
        if (i < k) return false;
        if (n <= i - j) return true;
        return f(i, j) >= f(i, k);
    };
    auto argmin = monotone_minima(n + m - 1, m, select);
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) c[i] = f(i, argmin[i]);
    return c;
}