---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/Hash.hpp
    title: Hash (reversible)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/RollingHash.hpp\"\n#include <algorithm>\n#include\
    \ <string>\n#line 2 \"src/string/Hash.hpp\"\n#include <cassert>\n#include <chrono>\n\
    #include <iostream>\n#include <random>\n#include <vector>\n\nnamespace hash_impl\
    \ {\n\nstatic constexpr unsigned long long mod = (1ULL << 61) - 1;\n\nstruct modint\
    \ {\n    modint() : _v(0) {}\n    modint(long long v) {\n        unsigned long\
    \ long vv = v < 0 ? v + mod : v;\n        vv = (vv >> 61) + (vv & mod);\n    \
    \    if (vv >= mod) vv -= mod;\n        _v = vv;\n    }\n\n    unsigned long long\
    \ val() const { return _v; }\n\n    modint& operator+=(const modint& rhs) {\n\
    \        _v += rhs._v;\n        if (_v >= mod) _v -= mod;\n        return *this;\n\
    \    }\n    modint& operator-=(const modint& rhs) {\n        if (_v < rhs._v)\
    \ _v += mod;\n        _v -= rhs._v;\n        return *this;\n    }\n    modint&\
    \ operator*=(const modint& rhs) {\n        __uint128_t t = __uint128_t(_v) * rhs._v;\n\
    \        t = (t >> 61) + (t & mod);\n        if (t >= mod) t -= mod;\n       \
    \ _v = t;\n        return *this;\n    }\n    modint& operator/=(const modint&\
    \ rhs) { return *this = *this * rhs.inv(); }\n\n    modint operator-() const {\
    \ return modint() - *this; }\n\n    modint pow(long long n) const {\n        assert(0\
    \ <= n);\n        modint x = *this, r = 1;\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n    modint inv() const { return pow(mod - 2); }\n\n   \
    \ friend modint operator+(const modint& lhs, const modint& rhs) { return modint(lhs)\
    \ += rhs; }\n    friend modint operator-(const modint& lhs, const modint& rhs)\
    \ { return modint(lhs) -= rhs; }\n    friend modint operator*(const modint& lhs,\
    \ const modint& rhs) { return modint(lhs) *= rhs; }\n    friend modint operator/(const\
    \ modint& lhs, const modint& rhs) { return modint(lhs) /= rhs; }\n    friend bool\
    \ operator==(const modint& lhs, const modint& rhs) { return lhs._v == rhs._v;\
    \ }\n    friend bool operator!=(const modint& lhs, const modint& rhs) { return\
    \ lhs._v != rhs._v; }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ modint& rhs) {\n        os << rhs._v;\n        return os;\n    }\n\n  private:\n\
    \    unsigned long long _v;\n};\n\nuint64_t generate_base() {\n    std::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n    std::uniform_int_distribution<uint64_t>\
    \ rand(2, mod - 1);\n    return rand(mt);\n}\n\nmodint base(generate_base());\n\
    std::vector<modint> power{1};\n\nmodint get_pow(int n) {\n    if (n < int(power.size()))\
    \ return power[n];\n    int m = power.size();\n    power.resize(n + 1);\n    for\
    \ (int i = m; i <= n; i++) power[i] = power[i - 1] * base;\n    return power[n];\n\
    }\n\n};  // namespace hash_impl\n\nstruct Hash {\n    using mint = hash_impl::modint;\n\
    \    mint x;\n    int len;\n\n    Hash() : x(0), len(0) {}\n    Hash(mint x) :\
    \ x(x), len(1) {}\n    Hash(mint x, int len) : x(x), len(len) {}\n\n    Hash&\
    \ operator+=(const Hash& rhs) {\n        x = x * hash_impl::get_pow(rhs.len) +\
    \ rhs.x;\n        len += rhs.len;\n        return *this;\n    }\n    Hash operator+(const\
    \ Hash& rhs) const { return Hash(*this) += rhs; }\n    bool operator==(const Hash&\
    \ rhs) const { return x == rhs.x and len == rhs.len; }\n};\n\nstruct ReversibleHash\
    \ {\n    using mint = hash_impl::modint;\n    mint x, rx;\n    int len;\n\n  \
    \  ReversibleHash() : x(0), rx(0), len(0) {}\n    ReversibleHash(mint x) : x(x),\
    \ rx(x), len(1) {}\n    ReversibleHash(mint x, mint rx, int len) : x(x), rx(rx),\
    \ len(len) {}\n\n    ReversibleHash rev() const { return ReversibleHash(rx, x,\
    \ len); }\n\n    ReversibleHash operator+=(const ReversibleHash& rhs) {\n    \
    \    x = x * hash_impl::get_pow(rhs.len) + rhs.x;\n        rx = rx + rhs.rx *\
    \ hash_impl::get_pow(len);\n        len += rhs.len;\n        return *this;\n \
    \   }\n    ReversibleHash operator+(const ReversibleHash& rhs) const { return\
    \ ReversibleHash(*this) += rhs; }\n    bool operator==(const ReversibleHash& rhs)\
    \ const { return x == rhs.x and rx == rhs.rx and len == rhs.len; }\n};\n#line\
    \ 5 \"src/string/RollingHash.hpp\"\n\nstruct RollingHash {\n    using mint = hash_impl::modint;\n\
    \n    RollingHash() : power{mint(1)} {}\n\n    template <typename T> std::vector<mint>\
    \ build(const T& s) const {\n        int n = s.size();\n        std::vector<mint>\
    \ hash(n + 1);\n        hash[0] = 0;\n        for (int i = 0; i < n; i++) hash[i\
    \ + 1] = hash[i] * base + s[i];\n        return hash;\n    }\n\n    template <typename\
    \ T> mint get(const T& s) const {\n        mint res = 0;\n        for (const auto&\
    \ x : s) res = res * base + x;\n        return res;\n    }\n\n    mint query(const\
    \ std::vector<mint>& hash, int l, int r) {\n        assert(0 <= l && l <= r);\n\
    \        extend(r - l);\n        return hash[r] - hash[l] * power[r - l];\n  \
    \  }\n\n    mint combine(mint h1, mint h2, int h2_len) {\n        extend(h2_len);\n\
    \        return h1 * power[h2_len] + h2;\n    }\n\n    int lcp(const std::vector<mint>&\
    \ a, int l1, int r1, const std::vector<mint>& b, int l2, int r2) {\n        int\
    \ len = std::min(r1 - l1, r2 - l2);\n        int lb = 0, ub = len + 1;\n     \
    \   while (ub - lb > 1) {\n            int mid = (lb + ub) >> 1;\n           \
    \ (query(a, l1, l1 + mid) == query(b, l2, l2 + mid) ? lb : ub) = mid;\n      \
    \  }\n        return lb;\n    }\n\n  private:\n    const mint base = hash_impl::base;\n\
    \    std::vector<mint> power;\n\n    inline void extend(int len) {\n        if\
    \ (int(power.size()) > len) return;\n        int pre = power.size();\n       \
    \ power.resize(len + 1);\n        for (int i = pre - 1; i < len; i++) power[i\
    \ + 1] = power[i] * base;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <string>\n#include \"Hash.hpp\"\
    \n\nstruct RollingHash {\n    using mint = hash_impl::modint;\n\n    RollingHash()\
    \ : power{mint(1)} {}\n\n    template <typename T> std::vector<mint> build(const\
    \ T& s) const {\n        int n = s.size();\n        std::vector<mint> hash(n +\
    \ 1);\n        hash[0] = 0;\n        for (int i = 0; i < n; i++) hash[i + 1] =\
    \ hash[i] * base + s[i];\n        return hash;\n    }\n\n    template <typename\
    \ T> mint get(const T& s) const {\n        mint res = 0;\n        for (const auto&\
    \ x : s) res = res * base + x;\n        return res;\n    }\n\n    mint query(const\
    \ std::vector<mint>& hash, int l, int r) {\n        assert(0 <= l && l <= r);\n\
    \        extend(r - l);\n        return hash[r] - hash[l] * power[r - l];\n  \
    \  }\n\n    mint combine(mint h1, mint h2, int h2_len) {\n        extend(h2_len);\n\
    \        return h1 * power[h2_len] + h2;\n    }\n\n    int lcp(const std::vector<mint>&\
    \ a, int l1, int r1, const std::vector<mint>& b, int l2, int r2) {\n        int\
    \ len = std::min(r1 - l1, r2 - l2);\n        int lb = 0, ub = len + 1;\n     \
    \   while (ub - lb > 1) {\n            int mid = (lb + ub) >> 1;\n           \
    \ (query(a, l1, l1 + mid) == query(b, l2, l2 + mid) ? lb : ub) = mid;\n      \
    \  }\n        return lb;\n    }\n\n  private:\n    const mint base = hash_impl::base;\n\
    \    std::vector<mint> power;\n\n    inline void extend(int len) {\n        if\
    \ (int(power.size()) > len) return;\n        int pre = power.size();\n       \
    \ power.resize(len + 1);\n        for (int i = pre - 1; i < len; i++) power[i\
    \ + 1] = power[i] * base;\n    }\n};\n"
  dependsOn:
  - src/string/Hash.hpp
  isVerificationFile: false
  path: src/string/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-09-28 01:48:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.test.cpp
documentation_of: src/string/RollingHash.hpp
layout: document
title: Rolling Hash
---

## 概要
$\bmod\ 2^{61}-1$ で基数は $\left[2, 2^{61}-1\right)$ の乱数によるRolling Hash．

| メンバ関数                  | 効果                                                                                                                                | 時間計算量                          |
| --------------------------- | ----------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------- |
| `build(s)`                  | 文字列もしくは数列 $s$ に対する hash table を返す．                                                                                 | $O(\|S\|)$                          |
| `get(s)`                    | 文字列もしくは数列 $s$ 全体の hash 値をを返す．                                                                                     | $O(\|S\|)$                          |
| `query(hash, l, r)`         | `build` で生成された hash table である `hash` をもとにこの列の区間 $[l, r)$ に対応する hash 値を返す．                              | $O(1)$                              |
| `combine(h1, h2, h2_len)`   | 前半の hash 値が $h_1$，後半のそれが $h_2$ で後半の長さが `h2_len` のときに列全体の hash 値を返す．                                 | $O(1)$                              |
| `lcp(a, l1, r1, b, l2, r2)` | hash table $a$ からなる列の $[l_1, r_1)$ の部分文字列と，hash table $b$ からなる列の $[l_2, r_2)$ の部分文字列の LCP の長さを返す． | $O(\log\max(r_1 - l_1, r_2 - l_2))$ |

## 問題例
- [Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1) C. Morse Code](https://codeforces.com/contest/1129/problem/C)
  - $\bmod$ の値が小さいとかなりの確率で衝突し，hash 値を 2 つもとうとすると TLE にハマるので，この Rolling Hash が特に有効．

## 参照
- [安全で爆速なRollingHashの話 - Qiita](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)
