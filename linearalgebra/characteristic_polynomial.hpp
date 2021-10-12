#pragma once
#include <cassert>
#include <vector>

template <typename T> std::vector<T> characteristic_polynomial(std::vector<std::vector<T>> M) {
    assert(M.empty() or M.size() == M[0].size());
    int n = M.size();
    // reduce M to upper Hessenberg form
    for (int j = 0; j < n - 2; j++) {
        for (int i = j + 2; i < n; i++) {
            if (M[i][j] != 0) {
                std::swap(M[j + 1], M[i]);
                for (int k = 0; k < n; k++) std::swap(M[k][j + 1], M[k][i]);
                break;
            }
        }
        if (M[j + 1][j] == 0) continue;
        auto inv = T(1) / M[j + 1][j];
        for (int i = j + 2; i < n; i++) {
            auto coef = M[i][j] * inv;
            for (int k = j; k < n; k++) M[i][k] -= coef * M[j + 1][k];
            for (int k = 0; k < n; k++) M[k][j + 1] += coef * M[k][i];
        }
    }

    // compute the characteristic polynomial of upper Hessenberg matrix M
    std::vector<std::vector<T>> p(n + 1);
    p[0] = {T(1)};
    for (int i = 0; i < n; i++) {
        p[i + 1].resize(i + 2);
        for (int j = 0; j <= i; j++) {
            p[i + 1][j + 1] += p[i][j];
            p[i + 1][j] -= p[i][j] * M[i][i];
        }
        T betas = 1;
        for (int j = i - 1; j >= 0; j--) {
            betas *= M[j + 1][j];
            T coef = -betas * M[j][i];
            for (int k = 0; k <= j; k++) p[i + 1][k] += coef * p[j][k];
        }
    }
    return p[n];
}

/**
 * @brief Characteristic Polynomial
 * @docs docs/linearalgebra/characteristic_polynomial.md
 * @see https://arxiv.org/abs/1104.3769
 */
