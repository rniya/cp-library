#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

template <typename T> struct Binomial {
    Binomial(int MAX = 0) : n(1), facs(1, T(1)), finvs(1, T(1)), invs(1, T(1)) {
        assert(T::mod() != 0);
        if (MAX > 0) extend(MAX + 1);
    }

    T fac(int i) {
        assert(i >= 0);
        while (n <= i) extend();
        return facs[i];
    }

    T finv(int i) {
        assert(i >= 0);
        while (n <= i) extend();
        return finvs[i];
    }

    T inv(int i) {
        assert(i >= 0);
        while (n <= i) extend();
        return invs[i];
    }

    T P(int n, int r) {
        if (n < r or r < 0) return 0;
        return fac(n) * finv(n - r);
    }

    T C(int n, int r) {
        if (n < r or r < 0) return 0;
        return fac(n) * finv(n - r) * finv(r);
    }

    T H(int n, int r) {
        if (n < 0 or r < 0) return 0;
        return r == 0 ? 1 : C(n + r - 1, r);
    }

    T negative_binom(int n, int k) { return H(k, n); }

    T C_naive(int n, int r) {
        if (n < r or r < 0) return 0;
        T res = 1;
        r = std::min(r, n - r);
        for (int i = 1; i <= r; i++) res *= inv(i) * (n--);
        return res;
    }

    T catalan(int n) {
        if (n < 0) return 0;
        return fac(2 * n) * finv(n + 1) * finv(n);
    }

    T catalan_pow(int n, int k) {
        if (n < 0 or k < 0) return 0;
        if (k == 0) return n == 0 ? 1 : 0;
        return inv(n + k) * k * C(2 * n + k - 1, n);
    }

    T calatan1(int n, int m) { return C(n + m, m) - C(n + m, m - 1); }

    T catalan2(int n, int m, int k) { return n - m <= -k ? 0 : C(n + m, m) - C(n + m, m - k); }

    T narayana(int n, int k) {
        if (n < k or k <= 0) return 0;
        return C(n, k) * C(n, k - 1) * inv(n);
    }

    T grid_sum(int x, int y) {
        if (x < 0 or y < 0) return 0;
        return C(x + y + 2, x + 1) - 1;
    }

    T grid_sum2(int xl, int xr, int yl, int yr) {
        if (xl >= xr or yl >= yr) return 0;
        xl--, xr--, yl--, yr--;
        return grid_sum(xr, yr) - grid_sum(xl, yr) - grid_sum(xr, yl) + grid_sum(xl, yl);
    }

  private:
    int n;
    std::vector<T> facs, finvs, invs;

    inline void extend(int m = -1) {
        if (m == -1) m = n * 2;
        m = std::min(m, T::mod());
        if (n >= m) return;
        facs.resize(m);
        finvs.resize(m);
        invs.resize(m);
        for (int i = n; i < m; i++) facs[i] = facs[i - 1] * i;
        finvs[m - 1] = T(1) / facs[m - 1];
        invs[m - 1] = finvs[m - 1] * facs[m - 2];
        for (int i = m - 2; i >= n; i--) {
            finvs[i] = finvs[i + 1] * (i + 1);
            invs[i] = finvs[i] * facs[i - 1];
        }
        n = m;
    }
};
