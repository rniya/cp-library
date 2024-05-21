#pragma once
#include "../atcoder/convolution"

template <class mint>
std::vector<mint> convolution_arbitary_mod(const std::vector<mint>& a, const std::vector<mint>& b) {
    int n = a.size(), m = b.size();
    if (n == 0 or m == 0) return {};
    static constexpr unsigned long long MOD1 = 754974721;  // 2^24
    static constexpr unsigned long long MOD2 = 167772161;  // 2^25
    static constexpr unsigned long long MOD3 = 469762049;  // 2^26
    using mint1 = atcoder::static_modint<MOD1>;
    using mint2 = atcoder::static_modint<MOD2>;
    using mint3 = atcoder::static_modint<MOD3>;

    const mint2 i1 = mint2(MOD1).inv();
    const mint3 i2 = mint3(MOD2).inv();
    const mint3 i1i2 = mint3(MOD1).inv() * i2;
    const mint m1 = MOD1, m1m2 = m1 * MOD2;

    std::vector<mint1> a1(n), b1(m);
    std::vector<mint2> a2(n), b2(m);
    std::vector<mint3> a3(n), b3(m);
    for (int i = 0; i < n; i++) {
        a1[i] = a[i].val();
        a2[i] = a[i].val();
        a3[i] = a[i].val();
    }
    for (int i = 0; i < m; i++) {
        b1[i] = b[i].val();
        b2[i] = b[i].val();
        b3[i] = b[i].val();
    }
    auto c1 = convolution(a1, b1);
    auto c2 = convolution(a2, b2);
    auto c3 = convolution(a3, b3);

    std::vector<mint> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        int v1 = c1[i].val();
        int v2 = (i1 * (c2[i] - v1)).val();
        int v3 = (i1i2 * (c3[i] - v1) - i2 * v2).val();
        c[i] = v1 + m1 * v2 + m1m2 * v3;
    }

    return c;
}
