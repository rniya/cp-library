---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/factorize.test.cpp
    title: test/yosupo/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/base.hpp\"\n#include <bits/stdc++.h>\n#ifdef LOCAL\n\
    #include <debug.hpp>\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate <class\
    \ T> std::istream& operator>>(std::istream& is, std::vector<T>& v) {\n    for\
    \ (auto& x : v) is >> x;\n    return is;\n}\n\ntemplate <class T> std::ostream&\
    \ operator<<(std::ostream& os, const std::vector<T>& v) {\n    auto sep = \"\"\
    ;\n    for (const auto& x : v) os << std::exchange(sep, \" \") << x;\n    return\
    \ os;\n}\n\ntemplate <class T, class U = T> bool chmin(T& x, U&& y) { return y\
    \ < x and (x = std::forward<U>(y), true); }\n\ntemplate <class T, class U = T>\
    \ bool chmax(T& x, U&& y) { return x < y and (x = std::forward<U>(y), true); }\n\
    \ntemplate <class T> void mkuni(std::vector<T>& v) {\n    std::sort(begin(v),\
    \ end(v));\n    v.erase(unique(begin(v), end(v)), end(v));\n}\n\ntemplate <class\
    \ T> int lwb(const std::vector<T>& v, const T& x) {\n    return std::lower_bound(begin(v),\
    \ end(v), x) - begin(v);\n}\n#line 3 \"src/math/fast_factorize.hpp\"\n\nnamespace\
    \ fast_factorize {\nusing u64 = uint64_t;\n\nmt19937_64 mt(random_device{}());\n\
    u64 rng(u64 n) { return uniform_int_distribution<u64>(0, n - 1)(mt); }\n\nstruct\
    \ montgomery64 {\n    using i64 = int64_t;\n    using u64 = uint64_t;\n    using\
    \ u128 = __uint128_t;\n\n    static u64 mod, r, n2;\n\n    static u64 get_r()\
    \ {\n        u64 res = mod;\n        for (int _ = 0; _ < 5; _++) res *= 2 - mod\
    \ * res;\n        return -res;\n    }\n\n    static void set_mod(u64 m) {\n  \
    \      assert(m < (1ULL << 62));\n        assert((m & 1) == 1);\n        mod =\
    \ m;\n        n2 = -u128(m) % m;\n        r = get_r();\n        assert(r * mod\
    \ == -1ULL);\n    }\n    static u64 get_mod() { return mod; }\n\n    static u64\
    \ reduce(const u128& x) noexcept { return (x + u128(u64(x) * r) * mod) >> 64;\
    \ }\n\n    u64 v;\n    montgomery64() : v(0) {}\n    montgomery64(const i64& v)\
    \ : v(reduce((u128(v) + mod) * n2)) {}\n    u64 value() const {\n        u64 res\
    \ = reduce(v);\n        return res >= mod ? res - mod : res;\n    }\n    montgomery64&\
    \ operator+=(const montgomery64& rhs) {\n        if (i64(v += rhs.v - (mod <<\
    \ 1)) < 0) v += mod << 1;\n        return *this;\n    }\n    montgomery64& operator-=(const\
    \ montgomery64& rhs) {\n        if (i64(v -= rhs.v) < 0) v += mod << 1;\n    \
    \    return *this;\n    }\n    montgomery64& operator*=(const montgomery64& rhs)\
    \ {\n        v = reduce(u128(v) * rhs.v);\n        return *this;\n    }\n    montgomery64\
    \ operator+(const montgomery64& rhs) const { return montgomery64(*this) += rhs;\
    \ }\n    montgomery64 operator-(const montgomery64& rhs) const { return montgomery64(*this)\
    \ -= rhs; }\n    montgomery64 operator*(const montgomery64& rhs) const { return\
    \ montgomery64(*this) *= rhs; }\n    bool operator==(const montgomery64& rhs)\
    \ const {\n        return (v >= mod ? v - mod : v) == (rhs.v >= mod ? rhs.v -\
    \ mod : rhs.v);\n    }\n    bool operator!=(const montgomery64& rhs) const {\n\
    \        return (v >= mod ? v - mod : v) != (rhs.v >= mod ? rhs.v - mod : rhs.v);\n\
    \    }\n    montgomery64 pow(u64 n) const {\n        montgomery64 self(*this),\
    \ res(1);\n        while (n > 0) {\n            if (n & 1) res *= self;\n    \
    \        self *= self;\n            n >>= 1;\n        }\n        return res;\n\
    \    }\n    friend istream& operator>>(istream& s, montgomery64& rhs) {\n    \
    \    i64 v;\n        rhs = montgomery64{(s >> v, v)};\n        return s;\n   \
    \ }\n    friend ostream& operator<<(ostream& s, const montgomery64& rhs) { return\
    \ s << rhs.v; }\n};\ntypename montgomery64::u64 montgomery64::mod, montgomery64::r,\
    \ montgomery64::n2;\n\nbool miller_rabin(const u64& n, const vector<u64>& as)\
    \ {\n    if (montgomery64::get_mod() != n) montgomery64::set_mod(n);\n    const\
    \ u64 d = (n - 1) >> __builtin_ctzll(n - 1);\n    const montgomery64 one(1), minus_one(n\
    \ - 1);\n    for (u64 a : as) {\n        if (n <= a) break;\n        u64 t = d;\n\
    \        montgomery64 y = montgomery64(a).pow(t);\n        while (t != n - 1 &&\
    \ y != one && y != minus_one) {\n            y *= y;\n            t <<= 1;\n \
    \       }\n        if (y != minus_one && t % 2 == 0) return false;\n    }\n  \
    \  return true;\n}\nbool is_prime(const u64& n) {\n    if (n == 2 || n == 3 ||\
    \ n == 5 || n == 7) return true;\n    if (n % 2 == 0 || n % 3 == 0 || n % 5 ==\
    \ 0 || n % 7 == 0) return false;\n    if (n < 121) return n > 1;\n    if (n <\
    \ (1ULL << 32)) return miller_rabin(n, {2, 7, 61});\n    return miller_rabin(n,\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\nu64 pollard_rho(const\
    \ u64& n) {\n    if (~n & 1) return 2;\n    if (is_prime(n)) return n;\n    if\
    \ (montgomery64::get_mod() != n) montgomery64::set_mod(n);\n    montgomery64 R,\
    \ one(1);\n    auto f = [&](const montgomery64& x) { return x * x + R; };\n  \
    \  constexpr int m = 128;\n    while (1) {\n        montgomery64 x, y, ys, q =\
    \ one;\n        R = rng(n - 2) + 2, y = rng(n - 2) + 2;\n        u64 g = 1;\n\
    \        for (int r = 1; g == 1; r <<= 1) {\n            x = y;\n            for\
    \ (int i = 0; i < r; i++) y = f(y);\n            for (int k = 0; g == 1 && k <\
    \ r; k += m) {\n                ys = y;\n                for (int i = 0; i < min(m,\
    \ r - k); i++) q *= x - (y = f(y));\n                g = gcd(q.value(), n);\n\
    \            }\n        }\n        if (g == n) {\n            do g = gcd((x -\
    \ (ys = f(ys))).value(), n);\n            while (g == 1);\n        }\n       \
    \ if (g != n) return g;\n    }\n    cerr << \"failed\" << '\\n';\n    assert(false);\n\
    \    return -1;\n}\n\nvector<u64> inner_factorize(u64 n) {\n    if (n <= 1) return\
    \ {};\n    u64 p = pollard_rho(n);\n    if (p == n) return {p};\n    auto l =\
    \ inner_factorize(p);\n    auto r = inner_factorize(n / p);\n    copy(r.begin(),\
    \ r.end(), back_inserter(l));\n    return l;\n}\nvector<u64> factorize(u64 n)\
    \ {\n    auto res = inner_factorize(n);\n    sort(res.begin(), res.end());\n \
    \   return res;\n}\n}  // namespace fast_factorize\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nnamespace fast_factorize {\nusing\
    \ u64 = uint64_t;\n\nmt19937_64 mt(random_device{}());\nu64 rng(u64 n) { return\
    \ uniform_int_distribution<u64>(0, n - 1)(mt); }\n\nstruct montgomery64 {\n  \
    \  using i64 = int64_t;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\
    \n    static u64 mod, r, n2;\n\n    static u64 get_r() {\n        u64 res = mod;\n\
    \        for (int _ = 0; _ < 5; _++) res *= 2 - mod * res;\n        return -res;\n\
    \    }\n\n    static void set_mod(u64 m) {\n        assert(m < (1ULL << 62));\n\
    \        assert((m & 1) == 1);\n        mod = m;\n        n2 = -u128(m) % m;\n\
    \        r = get_r();\n        assert(r * mod == -1ULL);\n    }\n    static u64\
    \ get_mod() { return mod; }\n\n    static u64 reduce(const u128& x) noexcept {\
    \ return (x + u128(u64(x) * r) * mod) >> 64; }\n\n    u64 v;\n    montgomery64()\
    \ : v(0) {}\n    montgomery64(const i64& v) : v(reduce((u128(v) + mod) * n2))\
    \ {}\n    u64 value() const {\n        u64 res = reduce(v);\n        return res\
    \ >= mod ? res - mod : res;\n    }\n    montgomery64& operator+=(const montgomery64&\
    \ rhs) {\n        if (i64(v += rhs.v - (mod << 1)) < 0) v += mod << 1;\n     \
    \   return *this;\n    }\n    montgomery64& operator-=(const montgomery64& rhs)\
    \ {\n        if (i64(v -= rhs.v) < 0) v += mod << 1;\n        return *this;\n\
    \    }\n    montgomery64& operator*=(const montgomery64& rhs) {\n        v = reduce(u128(v)\
    \ * rhs.v);\n        return *this;\n    }\n    montgomery64 operator+(const montgomery64&\
    \ rhs) const { return montgomery64(*this) += rhs; }\n    montgomery64 operator-(const\
    \ montgomery64& rhs) const { return montgomery64(*this) -= rhs; }\n    montgomery64\
    \ operator*(const montgomery64& rhs) const { return montgomery64(*this) *= rhs;\
    \ }\n    bool operator==(const montgomery64& rhs) const {\n        return (v >=\
    \ mod ? v - mod : v) == (rhs.v >= mod ? rhs.v - mod : rhs.v);\n    }\n    bool\
    \ operator!=(const montgomery64& rhs) const {\n        return (v >= mod ? v -\
    \ mod : v) != (rhs.v >= mod ? rhs.v - mod : rhs.v);\n    }\n    montgomery64 pow(u64\
    \ n) const {\n        montgomery64 self(*this), res(1);\n        while (n > 0)\
    \ {\n            if (n & 1) res *= self;\n            self *= self;\n        \
    \    n >>= 1;\n        }\n        return res;\n    }\n    friend istream& operator>>(istream&\
    \ s, montgomery64& rhs) {\n        i64 v;\n        rhs = montgomery64{(s >> v,\
    \ v)};\n        return s;\n    }\n    friend ostream& operator<<(ostream& s, const\
    \ montgomery64& rhs) { return s << rhs.v; }\n};\ntypename montgomery64::u64 montgomery64::mod,\
    \ montgomery64::r, montgomery64::n2;\n\nbool miller_rabin(const u64& n, const\
    \ vector<u64>& as) {\n    if (montgomery64::get_mod() != n) montgomery64::set_mod(n);\n\
    \    const u64 d = (n - 1) >> __builtin_ctzll(n - 1);\n    const montgomery64\
    \ one(1), minus_one(n - 1);\n    for (u64 a : as) {\n        if (n <= a) break;\n\
    \        u64 t = d;\n        montgomery64 y = montgomery64(a).pow(t);\n      \
    \  while (t != n - 1 && y != one && y != minus_one) {\n            y *= y;\n \
    \           t <<= 1;\n        }\n        if (y != minus_one && t % 2 == 0) return\
    \ false;\n    }\n    return true;\n}\nbool is_prime(const u64& n) {\n    if (n\
    \ == 2 || n == 3 || n == 5 || n == 7) return true;\n    if (n % 2 == 0 || n %\
    \ 3 == 0 || n % 5 == 0 || n % 7 == 0) return false;\n    if (n < 121) return n\
    \ > 1;\n    if (n < (1ULL << 32)) return miller_rabin(n, {2, 7, 61});\n    return\
    \ miller_rabin(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\n\
    u64 pollard_rho(const u64& n) {\n    if (~n & 1) return 2;\n    if (is_prime(n))\
    \ return n;\n    if (montgomery64::get_mod() != n) montgomery64::set_mod(n);\n\
    \    montgomery64 R, one(1);\n    auto f = [&](const montgomery64& x) { return\
    \ x * x + R; };\n    constexpr int m = 128;\n    while (1) {\n        montgomery64\
    \ x, y, ys, q = one;\n        R = rng(n - 2) + 2, y = rng(n - 2) + 2;\n      \
    \  u64 g = 1;\n        for (int r = 1; g == 1; r <<= 1) {\n            x = y;\n\
    \            for (int i = 0; i < r; i++) y = f(y);\n            for (int k = 0;\
    \ g == 1 && k < r; k += m) {\n                ys = y;\n                for (int\
    \ i = 0; i < min(m, r - k); i++) q *= x - (y = f(y));\n                g = gcd(q.value(),\
    \ n);\n            }\n        }\n        if (g == n) {\n            do g = gcd((x\
    \ - (ys = f(ys))).value(), n);\n            while (g == 1);\n        }\n     \
    \   if (g != n) return g;\n    }\n    cerr << \"failed\" << '\\n';\n    assert(false);\n\
    \    return -1;\n}\n\nvector<u64> inner_factorize(u64 n) {\n    if (n <= 1) return\
    \ {};\n    u64 p = pollard_rho(n);\n    if (p == n) return {p};\n    auto l =\
    \ inner_factorize(p);\n    auto r = inner_factorize(n / p);\n    copy(r.begin(),\
    \ r.end(), back_inserter(l));\n    return l;\n}\nvector<u64> factorize(u64 n)\
    \ {\n    auto res = inner_factorize(n);\n    sort(res.begin(), res.end());\n \
    \   return res;\n}\n}  // namespace fast_factorize\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/math/fast_factorize.hpp
  requiredBy: []
  timestamp: '2024-04-07 16:52:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/factorize.test.cpp
documentation_of: src/math/fast_factorize.hpp
layout: document
title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3 (Miller-Rabin primality test +\
  \ Pollard's rho algorithm)"
---

## 概要
#### Miller-Rabin の素数判定法
与えられた $n$ の素数判定を高速に行う乱択（ただし $2^64$ 未満の数については決定的に行うことが可能）アルゴリズム。

偶数については自明だから以下では $n$ は奇数とする。
また、合同式は全て $p$ を法とする。

#### 補題
任意の奇素数 $p$ について、
$$
x^2 \equiv 1 \iff  \equiv \pm 1.
$$

###### 証明

$\blacksquare$

自然数 $s$ 及び奇数 $d$ を用いて $p - 1 = 2^s d$ とすると、Fermat の小定理から自然数 $a$ が $p$ と互いに素であるならば、
$$
a^{2^s d} \equiv 1.
$$
このとき、上の補題より、
$$
a^d \equiv 1 \lor (\exists r \in \Z \cap [0, s - 1],\ a^{2^r d} \equiv - 1)
$$
が成立する。
この対偶を取ることで
$p \not| a$ かつ $a^d \not\equiv 1$ かつ $\forall r \in \Z \cap [0, s - 1],\ a^{2^r d} \not\equiv - 1$ ならば $a$ は $p$ と互いに素ではなく、$p$ は合成数であることがわかる。
この $a$ をランダムに選び合成数であるかを判定していき最後まで決まらなかった場合に $p$ は素数であるとするのがアルゴリズムの概要である。

ここで、$a < 2^{64}$ 未満の $n$ については決まった高々 7 個の $a$ を用いることで決定的に判定可能であることがわかっている。

#### Pollard の $\rho$ 法

## 計算量
$O(n^{1/4})$

## 問題例
- [2019-2020 Winter Petrozavodsk Camp, Day 8: Almost Algorithmic Contest D. FFT Algorithm](https://codeforces.com/gym/103261/problem/D)

## 参照
- [素因数分解の高速なアルゴリズム（ロー法） \| 高校数学の美しい物語](https://manabitimes.jp/math/1192)
- [素因数分解を $O(n^{1/4})$ でする - Qiita](https://qiita.com/Kiri8128/items/eca965fe86ea5f4cbb98)
