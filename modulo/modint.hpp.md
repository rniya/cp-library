---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/ArbitaryModConvolution.hpp
    title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1068.test.cpp
    title: test/yukicoder/1068.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1289.test.cpp
    title: test/yukicoder/1289.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/886.test.cpp
    title: test/yukicoder/886.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/931.test.cpp
    title: test/yukicoder/931.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/modulo/modint.md
    document_title: modint
    links: []
  bundledCode: "#line 2 \"modulo/modint.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    #include <iostream>\n\ntemplate <uint64_t Modulus> class modint {\n    using i64\
    \ = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static_assert(Modulus\
    \ < static_cast<uint32_t>(1) << 31, \"Modulus must be less than 2**31\");\n  \
    \  static constexpr u32 mod = Modulus;\n    u32 v;\n\npublic:\n    constexpr modint(const\
    \ i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n \
    \   constexpr u32& val() noexcept { return v; }\n    constexpr const u32& val()\
    \ const noexcept { return v; }\n    constexpr modint operator+(const modint& rhs)\
    \ const noexcept { return modint(*this) += rhs; }\n    constexpr modint operator-(const\
    \ modint& rhs) const noexcept { return modint(*this) -= rhs; }\n    constexpr\
    \ modint operator*(const modint& rhs) const noexcept { return modint(*this) *=\
    \ rhs; }\n    constexpr modint operator/(const modint& rhs) const noexcept { return\
    \ modint(*this) /= rhs; }\n    constexpr modint& operator+=(const modint& rhs)\
    \ noexcept {\n        v += rhs.v;\n        if (v >= mod) v -= mod;\n        return\
    \ *this;\n    }\n    constexpr modint& operator-=(const modint& rhs) noexcept\
    \ {\n        if (v < rhs.v) v += mod;\n        v -= rhs.v;\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint& rhs) noexcept {\n     \
    \   v = (u64)v * rhs.v % mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator/=(const modint& rhs) noexcept { return *this *= rhs.inv(); }\n    constexpr\
    \ modint pow(long long n) const noexcept {\n        assert(0 <= n);\n        modint\
    \ self(*this), res(1);\n        while (n > 0) {\n            if (n & 1) res *=\
    \ self;\n            self *= self;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const noexcept {\n        assert(*this\
    \ != 0);\n        return pow(mod - 2);\n    }\n    constexpr modint& operator++()\
    \ noexcept {\n        if (++v == mod) v = 0;\n        return *this;\n    }\n \
    \   constexpr modint& operator--() noexcept {\n        if (v == 0) v = mod;\n\
    \        return --v, *this;\n    }\n    constexpr modint operator++(int) noexcept\
    \ {\n        modint t = *this;\n        return ++*this, t;\n    }\n    constexpr\
    \ modint operator--(int) noexcept {\n        modint t = *this;\n        return\
    \ --*this, t;\n    }\n    constexpr modint operator-() const noexcept { return\
    \ modint(mod - v); }\n    template <class T> friend constexpr modint operator+(T\
    \ x, modint y) noexcept { return modint(x) + y; }\n    template <class T> friend\
    \ constexpr modint operator-(T x, modint y) noexcept { return modint(x) - y; }\n\
    \    template <class T> friend constexpr modint operator*(T x, modint y) noexcept\
    \ { return modint(x) * y; }\n    template <class T> friend constexpr modint operator/(T\
    \ x, modint y) noexcept { return modint(x) / y; }\n    constexpr bool operator==(const\
    \ modint& rhs) const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const\
    \ modint& rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!()\
    \ const noexcept { return !v; }\n    friend std::istream& operator>>(std::istream&\
    \ s, modint& rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n\
    \        return s;\n    }\n    friend std::ostream& operator<<(std::ostream& s,\
    \ const modint& rhs) noexcept { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n\
    \ * @docs docs/modulo/modint.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <iostream>\n\
    \ntemplate <uint64_t Modulus> class modint {\n    using i64 = int64_t;\n    using\
    \ u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static_assert(Modulus < static_cast<uint32_t>(1)\
    \ << 31, \"Modulus must be less than 2**31\");\n    static constexpr u32 mod =\
    \ Modulus;\n    u32 v;\n\npublic:\n    constexpr modint(const i64 x = 0) noexcept\
    \ : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n    constexpr u32& val()\
    \ noexcept { return v; }\n    constexpr const u32& val() const noexcept { return\
    \ v; }\n    constexpr modint operator+(const modint& rhs) const noexcept { return\
    \ modint(*this) += rhs; }\n    constexpr modint operator-(const modint& rhs) const\
    \ noexcept { return modint(*this) -= rhs; }\n    constexpr modint operator*(const\
    \ modint& rhs) const noexcept { return modint(*this) *= rhs; }\n    constexpr\
    \ modint operator/(const modint& rhs) const noexcept { return modint(*this) /=\
    \ rhs; }\n    constexpr modint& operator+=(const modint& rhs) noexcept {\n   \
    \     v += rhs.v;\n        if (v >= mod) v -= mod;\n        return *this;\n  \
    \  }\n    constexpr modint& operator-=(const modint& rhs) noexcept {\n       \
    \ if (v < rhs.v) v += mod;\n        v -= rhs.v;\n        return *this;\n    }\n\
    \    constexpr modint& operator*=(const modint& rhs) noexcept {\n        v = (u64)v\
    \ * rhs.v % mod;\n        return *this;\n    }\n    constexpr modint& operator/=(const\
    \ modint& rhs) noexcept { return *this *= rhs.inv(); }\n    constexpr modint pow(long\
    \ long n) const noexcept {\n        assert(0 <= n);\n        modint self(*this),\
    \ res(1);\n        while (n > 0) {\n            if (n & 1) res *= self;\n    \
    \        self *= self;\n            n >>= 1;\n        }\n        return res;\n\
    \    }\n    constexpr modint inv() const noexcept {\n        assert(*this != 0);\n\
    \        return pow(mod - 2);\n    }\n    constexpr modint& operator++() noexcept\
    \ {\n        if (++v == mod) v = 0;\n        return *this;\n    }\n    constexpr\
    \ modint& operator--() noexcept {\n        if (v == 0) v = mod;\n        return\
    \ --v, *this;\n    }\n    constexpr modint operator++(int) noexcept {\n      \
    \  modint t = *this;\n        return ++*this, t;\n    }\n    constexpr modint\
    \ operator--(int) noexcept {\n        modint t = *this;\n        return --*this,\
    \ t;\n    }\n    constexpr modint operator-() const noexcept { return modint(mod\
    \ - v); }\n    template <class T> friend constexpr modint operator+(T x, modint\
    \ y) noexcept { return modint(x) + y; }\n    template <class T> friend constexpr\
    \ modint operator-(T x, modint y) noexcept { return modint(x) - y; }\n    template\
    \ <class T> friend constexpr modint operator*(T x, modint y) noexcept { return\
    \ modint(x) * y; }\n    template <class T> friend constexpr modint operator/(T\
    \ x, modint y) noexcept { return modint(x) / y; }\n    constexpr bool operator==(const\
    \ modint& rhs) const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const\
    \ modint& rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!()\
    \ const noexcept { return !v; }\n    friend std::istream& operator>>(std::istream&\
    \ s, modint& rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n\
    \        return s;\n    }\n    friend std::ostream& operator<<(std::ostream& s,\
    \ const modint& rhs) noexcept { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n\
    \ * @docs docs/modulo/modint.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: modulo/modint.hpp
  requiredBy:
  - convolution/ArbitaryModConvolution.hpp
  - convolution/NumberTheoreticTransform.hpp
  timestamp: '2021-10-01 20:18:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/characteristic_polynomial.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yukicoder/1289.test.cpp
  - test/yukicoder/803.test.cpp
  - test/yukicoder/1269.test.cpp
  - test/yukicoder/1050.test.cpp
  - test/yukicoder/1068.test.cpp
  - test/yukicoder/886.test.cpp
  - test/yukicoder/931.test.cpp
  - test/yukicoder/665.test.cpp
documentation_of: modulo/modint.hpp
layout: document
redirect_from:
- /library/modulo/modint.hpp
- /library/modulo/modint.hpp.html
title: modint
---
## 概要
自動で $\bmod$ を取る構造体.
- 各種演算子( `operator++, operator--, operator-(), operator==` 等)に対応
- `std::cin, std::cout` への対応
- 負数に対応したコンストラクタ
- 内部を 32 bit 符号なし整数で保存
- 0 除算や `pow` において指数が負の際に例外の送出を行う

## 参照
- [modint 構造体を使ってみませんか？ (C++) - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/03/31/174006)
