#pragma once
#include "../base.hpp"

/**
 * @brief 拡張ユークリッドの互除法
 */
template <typename T> T extgcd(T a, T b, T& x, T& y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else
        x = 1, y = 0;
    return d;
}