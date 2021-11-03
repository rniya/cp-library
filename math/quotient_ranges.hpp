#pragma once
#include <tuple>
#include <vector>

template <typename T> std::vector<std::tuple<T, T, T>> quotient_ranges(T n) {
    std::vector<std::tuple<T, T, T>> res;
    T m = 1;
    for (; m * m <= n; m++) res.emplace_back(m, m, n / m);
    for (; m >= 1; m--) {
        T l = n / (m + 1) + 1, r = n / m;
        if (l <= r and std::get<1>(res.back()) < l) res.emplace_back(l, r, n / l);
    }
}

/**
 * @brief 商列挙
 * @docs docs/math/quotient_ranges.md
 */
