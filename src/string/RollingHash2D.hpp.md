---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/Hash.hpp
    title: Hash (reversible)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/RollingHash2D.hpp\"\n#include <string>\n#line\
    \ 2 \"src/string/Hash.hpp\"\n#include <cassert>\n#include <chrono>\n#include <iostream>\n\
    #include <random>\n#include <vector>\n\nnamespace hash_impl {\n\nstatic constexpr\
    \ unsigned long long mod = (1ULL << 61) - 1;\n\nstruct modint {\n    modint()\
    \ : _v(0) {}\n    modint(long long v) {\n        unsigned long long vv = v < 0\
    \ ? v + mod : v;\n        vv = (vv >> 61) + (vv & mod);\n        if (vv >= mod)\
    \ vv -= mod;\n        _v = vv;\n    }\n\n    unsigned long long val() const {\
    \ return _v; }\n\n    modint& operator+=(const modint& rhs) {\n        _v += rhs._v;\n\
    \        if (_v >= mod) _v -= mod;\n        return *this;\n    }\n    modint&\
    \ operator-=(const modint& rhs) {\n        if (_v < rhs._v) _v += mod;\n     \
    \   _v -= rhs._v;\n        return *this;\n    }\n    modint& operator*=(const\
    \ modint& rhs) {\n        __uint128_t t = __uint128_t(_v) * rhs._v;\n        t\
    \ = (t >> 61) + (t & mod);\n        if (t >= mod) t -= mod;\n        _v = t;\n\
    \        return *this;\n    }\n    modint& operator/=(const modint& rhs) { return\
    \ *this = *this * rhs.inv(); }\n\n    modint operator-() const { return modint()\
    \ - *this; }\n\n    modint pow(long long n) const {\n        assert(0 <= n);\n\
    \        modint x = *this, r = 1;\n        while (n) {\n            if (n & 1)\
    \ r *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ r;\n    }\n    modint inv() const { return pow(mod - 2); }\n\n    friend modint\
    \ operator+(const modint& lhs, const modint& rhs) { return modint(lhs) += rhs;\
    \ }\n    friend modint operator-(const modint& lhs, const modint& rhs) { return\
    \ modint(lhs) -= rhs; }\n    friend modint operator*(const modint& lhs, const\
    \ modint& rhs) { return modint(lhs) *= rhs; }\n    friend modint operator/(const\
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
    \ 4 \"src/string/RollingHash2D.hpp\"\n\nstruct RollingHash2D {\n    using mint\
    \ = hash_impl::modint;\n\n    static inline uint64_t generate_base() {\n     \
    \   std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(2, hash_impl::mod - 1);\n\
    \        return rand(mt);\n    }\n\n    RollingHash2D(uint64_t base0 = generate_base(),\
    \ uint64_t base1 = generate_base()) {\n        basis[0] = base0;\n        basis[1]\
    \ = base1;\n        power[0].assign(1, 1);\n        power[1].assign(1, 1);\n \
    \   }\n\n    template <typename T> std::vector<std::vector<mint>> build(const\
    \ T& s) const {\n        int n = s.size(), m = s[0].size();\n        std::vector<std::vector<mint>>\
    \ hash(n + 1, std::vector<mint>(m + 1, 0));\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < m; j++) {\n                hash[i + 1][j\
    \ + 1] =\n                    hash[i][j + 1] * basis[0] + hash[i + 1][j] * basis[1]\
    \ - hash[i][j] * basis[0] * basis[1] + s[i][j];\n            }\n        }\n  \
    \      return hash;\n    }\n\n    template <typename T> mint get(const T& s) const\
    \ {\n        mint res = 0;\n        for (int i = 0; i < int(s.size()); i++) {\n\
    \            mint sum = 0;\n            for (const auto& x : s[i]) sum = sum *\
    \ basis[1] + x;\n            res = res * basis[0] + sum;\n        }\n        return\
    \ res;\n    }\n\n    mint query(const std::vector<std::vector<mint>>& hash, int\
    \ xl, int xr, int yl, int yr) {\n        assert(0 <= xl and xl <= xr and 0 <=\
    \ yl and yl <= yr);\n        extend(0, xr - xl);\n        extend(1, yr - yl);\n\
    \        return hash[xr][yr] - hash[xl][yr] * power[0][xr - xl] - hash[xr][yl]\
    \ * power[1][yr - yl] +\n               hash[xl][yl] * power[0][xr - xl] * power[1][yr\
    \ - yl];\n    }\n\n  private:\n    mint basis[2];\n    std::vector<mint> power[2];\n\
    \n    inline void extend(int x, int len) {\n        if (int(power[x].size()) >\
    \ len) return;\n        int pre = power[x].size();\n        power[x].resize(len\
    \ + 1);\n        for (int i = pre - 1; i < len; i++) power[x][i + 1] = power[x][i]\
    \ * basis[x];\n    }\n};\n"
  code: "#pragma once\n#include <string>\n#include \"Hash.hpp\"\n\nstruct RollingHash2D\
    \ {\n    using mint = hash_impl::modint;\n\n    static inline uint64_t generate_base()\
    \ {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(2, hash_impl::mod - 1);\n\
    \        return rand(mt);\n    }\n\n    RollingHash2D(uint64_t base0 = generate_base(),\
    \ uint64_t base1 = generate_base()) {\n        basis[0] = base0;\n        basis[1]\
    \ = base1;\n        power[0].assign(1, 1);\n        power[1].assign(1, 1);\n \
    \   }\n\n    template <typename T> std::vector<std::vector<mint>> build(const\
    \ T& s) const {\n        int n = s.size(), m = s[0].size();\n        std::vector<std::vector<mint>>\
    \ hash(n + 1, std::vector<mint>(m + 1, 0));\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < m; j++) {\n                hash[i + 1][j\
    \ + 1] =\n                    hash[i][j + 1] * basis[0] + hash[i + 1][j] * basis[1]\
    \ - hash[i][j] * basis[0] * basis[1] + s[i][j];\n            }\n        }\n  \
    \      return hash;\n    }\n\n    template <typename T> mint get(const T& s) const\
    \ {\n        mint res = 0;\n        for (int i = 0; i < int(s.size()); i++) {\n\
    \            mint sum = 0;\n            for (const auto& x : s[i]) sum = sum *\
    \ basis[1] + x;\n            res = res * basis[0] + sum;\n        }\n        return\
    \ res;\n    }\n\n    mint query(const std::vector<std::vector<mint>>& hash, int\
    \ xl, int xr, int yl, int yr) {\n        assert(0 <= xl and xl <= xr and 0 <=\
    \ yl and yl <= yr);\n        extend(0, xr - xl);\n        extend(1, yr - yl);\n\
    \        return hash[xr][yr] - hash[xl][yr] * power[0][xr - xl] - hash[xr][yl]\
    \ * power[1][yr - yl] +\n               hash[xl][yl] * power[0][xr - xl] * power[1][yr\
    \ - yl];\n    }\n\n  private:\n    mint basis[2];\n    std::vector<mint> power[2];\n\
    \n    inline void extend(int x, int len) {\n        if (int(power[x].size()) >\
    \ len) return;\n        int pre = power[x].size();\n        power[x].resize(len\
    \ + 1);\n        for (int i = pre - 1; i < len; i++) power[x][i + 1] = power[x][i]\
    \ * basis[x];\n    }\n};\n"
  dependsOn:
  - src/string/Hash.hpp
  isVerificationFile: false
  path: src/string/RollingHash2D.hpp
  requiredBy: []
  timestamp: '2024-09-28 01:48:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_C.test.cpp
documentation_of: src/string/RollingHash2D.hpp
layout: document
title: Rolling Hash 2D
---

## 概要


## 問題例
- [2023牛客暑期多校训练营3 G - Beautiful Matrix](https://ac.nowcoder.com/acm/contest/57357/G)