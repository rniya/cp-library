#pragma once
#include <vector>
#include "../math/binomial.hpp"

/**
 * @brief Lagrange Interpolation of polynomial f of degree n
 *
 * @tparam T F_p
 * @param y f(0), f(1), ... , f(n)
 * @param x you want to calculate f(x)
 * @return T f(x)
 */
template <typename T> T lagrange_interpolation(const std::vector<T>& y, long long x, Binomial<T>& BINOM) {
    int n = y.size() - 1;
    if (x <= n) return y[x];
    std::vector<T> left(n + 1, 1), right(n + 1, 1);
    for (int i = 0; i < n; i++) left[i + 1] = left[i] * (x - i);
    for (int i = n; i > 0; i--) right[i - 1] = right[i] * (x - i);
    T res = 0;
    for (int i = 0; i <= n; i++) {
        T add = y[i] * left[i] * right[i] * BINOM.finv(i) * BINOM.finv(n - i);
        res += ((n - i) & 1) ? -add : add;
    }
    return res;
}
