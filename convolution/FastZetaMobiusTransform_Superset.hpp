#pragma once
#include "../base.hpp"

/**
 * @brief 高速ゼータ・メビウス変換(上位集合)
 * @docs docs/convolution/FastZetaMobiusTransform.md
 */

template <typename T> void FastZetaTransform(int n, vector<T>& f) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (!((j >> i) & 1)) {
                f[j] += f[j ^ (1 << i)];
            }
        }
    }
}

template <typename T> void FastMobiusTransform(int n, vector<T>& f) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (!((j >> i) & 1)) {
                f[j] -= f[j ^ (1 << i)];
            }
        }
    }
}