#pragma once
#include "atcoder/convolution"

template <typename T> std::vector<T> shift_of_sampling_points_of_polynomial(const std::vector<T>& ys, T c, int m) {
    int n = ys.size();
    int len = std::max(n, m);
    std::vector<T> fac(len), finv(len);
    fac[0] = 1;
    for (int i = 1; i < len; i++) fac[i] = fac[i - 1] * i;
    finv[len - 1] = fac[len - 1].inv();
    for (int i = len - 2; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1);
    std::vector<T> a(n), f(n);
    {
        for (int i = 0; i < n; i++) {
            a[i] = ys[i] * finv[i];
            f[i] = (i & 1 ? -1 : 1) * finv[i];
        }
        a = atcoder::convolution(a, f);
        a.resize(n);
    }
    {
        std::reverse(begin(a), end(a));
        T prod = 1;
        for (int i = 0; i < n; prod *= c - (i++)) {
            a[i] *= fac[n - 1 - i];
            f[i] = prod * finv[i];
        }
        a = atcoder::convolution(a, f);
        a.resize(n);
    }
    {
        std::reverse(begin(a), end(a));
        for (int i = 0; i < n; i++) a[i] *= finv[i];
        f.resize(m);
        for (int i = 0; i < m; i++) f[i] = finv[i];
        auto res = atcoder::convolution(a, f);
        res.resize(m);
        for (int i = 0; i < m; i++) res[i] *= fac[i];
        return res;
    }
}
