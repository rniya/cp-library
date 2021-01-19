#pragma once
#include "../base.hpp"

/**
 * @brief combination
 * @docs @docs/combinatorics/combination.md
 */
template <class M> struct Combination {
    vector<M> _fac, _inv, _finv;
    Combination(int n) : _fac(n + 1), _inv(n + 1), _finv(n + 1) {
        _fac[0] = _finv[n] = _inv[0] = 1;
        for (int i = 1; i <= n; i++) _fac[i] = _fac[i - 1] * i;
        _finv[n] /= _fac[n];
        for (int i = n - 1; i >= 0; i--) _finv[i] = _finv[i + 1] * (i + 1);
        for (int i = 1; i <= n; i++) _inv[i] = _finv[i] * _fac[i - 1];
    }
    M fac(int k) const { return _fac[k]; }
    M finv(int k) const { return _finv[k]; }
    M inv(int k) const { return _inv[k]; }
    M P(int n, int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        return _fac[n] * _finv[n - r];
    }
    M C(int n, int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        return _fac[n] * _finv[r] * _finv[n - r];
    }
};