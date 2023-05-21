#pragma once
#include <cassert>
#include <vector>

template <typename T> struct Binomial {
    Binomial(int MAX = 0) : n(1), facs(1, T(1)), finvs(1, T(1)), invs(1, T(1)) {
        while (n <= MAX) extend();
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
        if (n < 0 || n < r || r < 0) return T(0);
        return fac(n) * finv(n - r);
    }

    T C(int n, int r) {
        if (n < 0 || n < r || r < 0) return T(0);
        return fac(n) * finv(n - r) * finv(r);
    }

    T H(int n, int r) {
        if (n < 0 || r < 0) return T(0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }

    T C_naive(int n, int r) {
        if (n < 0 || n < r || r < 0) return T(0);
        T res = 1;
        r = std::min(r, n - r);
        for (int i = 1; i <= r; i++) res *= inv(i) * (n--);
        return res;
    }

  private:
    int n;
    std::vector<T> facs, finvs, invs;

    inline void extend() {
        int m = n << 1;
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
