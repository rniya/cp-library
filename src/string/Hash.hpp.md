---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/string/RollingHash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: src/string/RollingHash2D.hpp
    title: Rolling Hash 2D
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/Hash.hpp\"\n#include <cassert>\n#include <chrono>\n\
    #include <iostream>\n#include <random>\n#include <vector>\n\nnamespace hash_impl\
    \ {\n\nstatic constexpr unsigned long long mod = (1ULL << 61) - 1;\n\nstruct modint\
    \ {\n    modint() : _v(0) {}\n    modint(unsigned long long v) {\n        v =\
    \ (v >> 61) + (v & mod);\n        if (v >= mod) v -= mod;\n        _v = v;\n \
    \   }\n\n    unsigned long long val() const { return _v; }\n\n    modint& operator+=(const\
    \ modint& rhs) {\n        _v += rhs._v;\n        if (_v >= mod) _v -= mod;\n \
    \       return *this;\n    }\n    modint& operator-=(const modint& rhs) {\n  \
    \      if (_v < rhs._v) _v += mod;\n        _v -= rhs._v;\n        return *this;\n\
    \    }\n    modint& operator*=(const modint& rhs) {\n        __uint128_t t = __uint128_t(_v)\
    \ * rhs._v;\n        t = (t >> 61) + (t & mod);\n        if (t >= mod) t -= mod;\n\
    \        _v = t;\n        return *this;\n    }\n    modint& operator/=(const modint&\
    \ rhs) { return *this = *this * rhs.inv(); }\n\n    modint operator-() const {\
    \ return modint() - *this; }\n\n    modint pow(long long n) const {\n        assert(0\
    \ <= n);\n        modint x = *this, r = 1;\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n    modint inv() const { return pow(mod - 2); }\n\n   \
    \ friend modint operator+(const modint& lhs, const modint& rhs) { return modint(lhs)\
    \ += rhs; }\n    friend modint operator-(const modint& lhs, const modint& rhs)\
    \ { return modint(lhs) -= rhs; }\n    friend modint operator*(const modint& lhs,\
    \ const modint& rhs) { return modint(lhs) *= rhs; }\n    friend bool operator==(const\
    \ modint& lhs, const modint& rhs) { return lhs._v == rhs._v; }\n    friend bool\
    \ operator!=(const modint& lhs, const modint& rhs) { return lhs._v != rhs._v;\
    \ }\n    friend std::ostream& operator<<(std::ostream& os, const modint& rhs)\
    \ { os << rhs._v; }\n\n  private:\n    unsigned long long _v;\n};\n\nuint64_t\
    \ generate_base() {\n    std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \    std::uniform_int_distribution<uint64_t> rand(2, mod - 1);\n    return rand(mt);\n\
    }\n\nmodint base(generate_base());\nstd::vector<modint> power{1};\n\nmodint get_pow(int\
    \ n) {\n    if (n < int(power.size())) return power[n];\n    int m = power.size();\n\
    \    power.resize(n + 1);\n    for (int i = m; i <= n; i++) power[i] = power[i\
    \ - 1] * base;\n    return power[n];\n}\n\n};  // namespace hash_impl\n\nstruct\
    \ Hash {\n    using mint = hash_impl::modint;\n    mint x;\n    int len;\n\n \
    \   Hash() : x(0), len(0) {}\n    Hash(mint x, int len) : x(x), len(len) {}\n\n\
    \    Hash& operator+=(const Hash& rhs) {\n        x = x * hash_impl::get_pow(rhs.len)\
    \ + rhs.x;\n        len += rhs.len;\n        return *this;\n    }\n    Hash operator+(const\
    \ Hash& rhs) { return *this += rhs; }\n    bool operator==(const Hash& rhs) {\
    \ return x == rhs.x and len == rhs.len; }\n};\n\nstruct ReversibleHash {\n   \
    \ using mint = hash_impl::modint;\n    mint x, rx;\n    int len;\n\n    ReversibleHash()\
    \ : x(0), rx(0), len(0) {}\n    ReversibleHash(mint x) : x(x), rx(x), len(1) {}\n\
    \    ReversibleHash(mint x, mint rx, int len) : x(x), rx(rx), len(len) {}\n\n\
    \    ReversibleHash rev() const { return ReversibleHash(rx, x, len); }\n\n   \
    \ ReversibleHash operator+=(const ReversibleHash& rhs) {\n        x = x * hash_impl::get_pow(rhs.len)\
    \ + rhs.x;\n        rx = rx + rhs.rx * hash_impl::get_pow(len);\n        len +=\
    \ rhs.len;\n        return *this;\n    }\n    ReversibleHash operator+(const ReversibleHash&\
    \ rhs) { return *this += rhs; }\n    bool operator==(const ReversibleHash& rhs)\
    \ { return x == rhs.x and rx == rhs.rx and len == rhs.len; }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <chrono>\n#include <iostream>\n\
    #include <random>\n#include <vector>\n\nnamespace hash_impl {\n\nstatic constexpr\
    \ unsigned long long mod = (1ULL << 61) - 1;\n\nstruct modint {\n    modint()\
    \ : _v(0) {}\n    modint(unsigned long long v) {\n        v = (v >> 61) + (v &\
    \ mod);\n        if (v >= mod) v -= mod;\n        _v = v;\n    }\n\n    unsigned\
    \ long long val() const { return _v; }\n\n    modint& operator+=(const modint&\
    \ rhs) {\n        _v += rhs._v;\n        if (_v >= mod) _v -= mod;\n        return\
    \ *this;\n    }\n    modint& operator-=(const modint& rhs) {\n        if (_v <\
    \ rhs._v) _v += mod;\n        _v -= rhs._v;\n        return *this;\n    }\n  \
    \  modint& operator*=(const modint& rhs) {\n        __uint128_t t = __uint128_t(_v)\
    \ * rhs._v;\n        t = (t >> 61) + (t & mod);\n        if (t >= mod) t -= mod;\n\
    \        _v = t;\n        return *this;\n    }\n    modint& operator/=(const modint&\
    \ rhs) { return *this = *this * rhs.inv(); }\n\n    modint operator-() const {\
    \ return modint() - *this; }\n\n    modint pow(long long n) const {\n        assert(0\
    \ <= n);\n        modint x = *this, r = 1;\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n    modint inv() const { return pow(mod - 2); }\n\n   \
    \ friend modint operator+(const modint& lhs, const modint& rhs) { return modint(lhs)\
    \ += rhs; }\n    friend modint operator-(const modint& lhs, const modint& rhs)\
    \ { return modint(lhs) -= rhs; }\n    friend modint operator*(const modint& lhs,\
    \ const modint& rhs) { return modint(lhs) *= rhs; }\n    friend bool operator==(const\
    \ modint& lhs, const modint& rhs) { return lhs._v == rhs._v; }\n    friend bool\
    \ operator!=(const modint& lhs, const modint& rhs) { return lhs._v != rhs._v;\
    \ }\n    friend std::ostream& operator<<(std::ostream& os, const modint& rhs)\
    \ { os << rhs._v; }\n\n  private:\n    unsigned long long _v;\n};\n\nuint64_t\
    \ generate_base() {\n    std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \    std::uniform_int_distribution<uint64_t> rand(2, mod - 1);\n    return rand(mt);\n\
    }\n\nmodint base(generate_base());\nstd::vector<modint> power{1};\n\nmodint get_pow(int\
    \ n) {\n    if (n < int(power.size())) return power[n];\n    int m = power.size();\n\
    \    power.resize(n + 1);\n    for (int i = m; i <= n; i++) power[i] = power[i\
    \ - 1] * base;\n    return power[n];\n}\n\n};  // namespace hash_impl\n\nstruct\
    \ Hash {\n    using mint = hash_impl::modint;\n    mint x;\n    int len;\n\n \
    \   Hash() : x(0), len(0) {}\n    Hash(mint x, int len) : x(x), len(len) {}\n\n\
    \    Hash& operator+=(const Hash& rhs) {\n        x = x * hash_impl::get_pow(rhs.len)\
    \ + rhs.x;\n        len += rhs.len;\n        return *this;\n    }\n    Hash operator+(const\
    \ Hash& rhs) { return *this += rhs; }\n    bool operator==(const Hash& rhs) {\
    \ return x == rhs.x and len == rhs.len; }\n};\n\nstruct ReversibleHash {\n   \
    \ using mint = hash_impl::modint;\n    mint x, rx;\n    int len;\n\n    ReversibleHash()\
    \ : x(0), rx(0), len(0) {}\n    ReversibleHash(mint x) : x(x), rx(x), len(1) {}\n\
    \    ReversibleHash(mint x, mint rx, int len) : x(x), rx(rx), len(len) {}\n\n\
    \    ReversibleHash rev() const { return ReversibleHash(rx, x, len); }\n\n   \
    \ ReversibleHash operator+=(const ReversibleHash& rhs) {\n        x = x * hash_impl::get_pow(rhs.len)\
    \ + rhs.x;\n        rx = rx + rhs.rx * hash_impl::get_pow(len);\n        len +=\
    \ rhs.len;\n        return *this;\n    }\n    ReversibleHash operator+(const ReversibleHash&\
    \ rhs) { return *this += rhs; }\n    bool operator==(const ReversibleHash& rhs)\
    \ { return x == rhs.x and rx == rhs.rx and len == rhs.len; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Hash.hpp
  requiredBy:
  - src/string/RollingHash2D.hpp
  - src/string/RollingHash.hpp
  timestamp: '2023-10-01 16:26:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_C.test.cpp
  - test/aoj/ALDS1_14_B.test.cpp
documentation_of: src/string/Hash.hpp
layout: document
title: "Hash \u69CB\u9020\u4F53 (reversible)"
---

## 問題例
- [Codeforces Round 857 (Div. 1) E. Gasoline prices](https://codeforces.com/contest/1801/problem/E)