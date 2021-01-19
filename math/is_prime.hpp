#pragma once
#include "../base.hpp"

/**
 * @brief 素数判定
 */
template <typename T> bool is_prime(T n) {
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return 1 < n;
}