#pragma once
#include "../base.hpp"

/**
 * @brief 商列挙
 * @docs docs/math/quotient_ranges.md
 */
template <typename T> vector<tuple<T, T, T>> quotient_ranges(T n) {
    vector<tuple<T, T, T>> res;
    T m = 1;
    for (; m * m <= n; m++) res.emplace_back(m, m, n / m);
    for (; m >= 1; m--) {
        T l = n / (i + 1) + 1, r = n / i;
        if (l <= r && get<1>(res.back()) < l) res.emplace_back(l, r, n / l);
    }
    return res;
}