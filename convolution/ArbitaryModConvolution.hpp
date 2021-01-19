#pragma once
#include "../base.hpp"
#include "../convolution/NumberTheoreticTransform.hpp"
#include "../modulo/modint.hpp"

/**
 * @brief Arbirary Mod Convolution (任意mod畳み込み)
 * @docs docs/convolution/ArbitaryModConvolution.md
 */
template <typename M> vector<M> ArbitaryModConvolution(const vector<M>& a, const vector<M>& b) {
    int n = a.size(), m = b.size();
    static constexpr int mod0 = 167772161, mod1 = 469762049, mod2 = 754974721;
    using mint0 = modint<mod0>;
    using mint1 = modint<mod1>;
    using mint2 = modint<mod2>;
    NumberTheoreticTransform<mod0> ntt0;
    NumberTheoreticTransform<mod1> ntt1;
    NumberTheoreticTransform<mod2> ntt2;
    vector<mint0> a0(n), b0(m);
    vector<mint1> a1(n), b1(m);
    vector<mint2> a2(n), b2(m);
    for (int i = 0; i < n; i++) a0[i] = a[i].v, a1[i] = a[i].v, a2[i] = a[i].v;
    for (int i = 0; i < m; i++) b0[i] = b[i].v, b1[i] = b[i].v, b2[i] = b[i].v;
    auto c0 = ntt0.multiply(a0, b0);
    auto c1 = ntt1.multiply(a1, b1);
    auto c2 = ntt2.multiply(a2, b2);
    static const mint1 inv0 = (mint1)1 / mod0;
    static const mint2 inv1 = (mint2)1 / mod1, inv0inv1 = inv1 / mod0;
    static const M m0 = mod0, m0m1 = m0 * mod1;
    vector<M> res(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        int v0 = c0[i].v;
        int v1 = (inv0 * (c1[i] - v0)).v;
        int v2 = (inv0inv1 * (c2[i] - v0) - inv1 * v1).v;
        res[i] = v0 + m0 * v1 + m0m1 * v2;
    }
    return res;
}