#pragma once
#include "../base.hpp"

/**
 * @brief 約数列挙
 */
template <typename T> vector<T> divisor(T n) {
    vector<T> res;
    for (T i = 1; i * i <= n; i++)
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    return res;
}