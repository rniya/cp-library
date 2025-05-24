#pragma once
#include "../math/binomial.hpp"
#include "../polynomial/FormalPowerSeries.hpp"

template <typename T> std::vector<T> bell_number(int n) {
    Binomial<T> binom;
    FormalPowerSeries<T> f(n + 1);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = binom.finv(i);
    }
    f = f.exp();
    for (int i = 0; i <= n; i++) {
        f[i] *= binom.fac(i);
    }
    return f;
}