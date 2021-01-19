#pragma once
#include "../base.hpp"

/**
 * @brief 添字XOR畳み込み
 * @docs docs/convolution/XORconvolution.md
 */

template <typename T> void fwt(vector<T>& f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if (!(j & i)) {
                T x = f[j], y = f[j | i];
                f[j] = x + y;
                f[j | i] = x - y;
            }
        }
    }
}

template <typename T> void ifwt(vector<T>& f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if (!(j & i)) {
                T x = f[j], y = f[j | i];
                f[j] = (x + y) / 2;
                f[j | i] = (x - y) / 2;
            }
        }
    }
}

template <typename T> vector<T> XOR_convolution(vector<T> A, vector<T> B) {
    int n = A.size();
    assert(__builtin_popcount(n) == 1);
    assert(A.size() == B.size());
    fwt(A);
    fwt(B);
    for (int i = 0; i < n; i++) A[i] *= B[i];
    ifwt(A);
    return A;
}