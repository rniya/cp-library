---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convolution/ArbitaryModConvolution.hpp
    title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':question:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':warning:'
    path: test/atcoder/tdpc_fibonacci.cpp
    title: test/atcoder/tdpc_fibonacci.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_C.test.cpp
    title: test/aoj/DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G.test.cpp
    title: test/aoj/DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_I.test.cpp
    title: test/aoj/DPL_5_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_J.test.cpp
    title: test/aoj/DPL_5_J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_L.test.cpp
    title: test/aoj/DPL_5_L.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
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
    path: test/yukicoder/1302.test.cpp
    title: test/yukicoder/1302.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  - icon: ':x:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/931.test.cpp
    title: test/yukicoder/931.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \   constexpr u32& value() noexcept { return v; }\n    constexpr const u32& value()\
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
    \ modint pow(u64 exp) const noexcept {\n        assert(0 <= exp);\n        modint\
    \ self(*this), res(1);\n        while (exp > 0) {\n            if (exp & 1) res\
    \ *= self;\n            self *= self;\n            exp >>= 1;\n        }\n   \
    \     return res;\n    }\n    constexpr modint inv() const noexcept {\n      \
    \  assert(*this != 0);\n        return pow(mod - 2);\n    }\n    constexpr modint&\
    \ operator++() noexcept {\n        if (++v == mod) v = 0;\n        return *this;\n\
    \    }\n    constexpr modint& operator--() noexcept {\n        if (v == 0) v =\
    \ mod;\n        return --v, *this;\n    }\n    constexpr modint operator++(int)\
    \ noexcept {\n        modint t = *this;\n        return ++*this, t;\n    }\n \
    \   constexpr modint operator--(int) noexcept {\n        modint t = *this;\n \
    \       return --*this, t;\n    }\n    constexpr modint operator-() const noexcept\
    \ { return modint(mod - v); }\n    template <class T> friend constexpr modint\
    \ operator+(T x, modint y) noexcept { return modint(x) + y; }\n    template <class\
    \ T> friend constexpr modint operator-(T x, modint y) noexcept { return modint(x)\
    \ - y; }\n    template <class T> friend constexpr modint operator*(T x, modint\
    \ y) noexcept { return modint(x) * y; }\n    template <class T> friend constexpr\
    \ modint operator/(T x, modint y) noexcept { return modint(x) / y; }\n    constexpr\
    \ bool operator==(const modint& rhs) const noexcept { return v == rhs.v; }\n \
    \   constexpr bool operator!=(const modint& rhs) const noexcept { return v !=\
    \ rhs.v; }\n    constexpr bool operator!() const noexcept { return !v; }\n   \
    \ friend std::istream& operator>>(std::istream& s, modint& rhs) noexcept {\n \
    \       i64 v;\n        rhs = modint{(s >> v, v)};\n        return s;\n    }\n\
    \    friend std::ostream& operator<<(std::ostream& s, const modint& rhs) noexcept\
    \ { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n * @docs docs/modulo/modint.md\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <iostream>\n\
    \ntemplate <uint64_t Modulus> class modint {\n    using i64 = int64_t;\n    using\
    \ u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static_assert(Modulus < static_cast<uint32_t>(1)\
    \ << 31, \"Modulus must be less than 2**31\");\n    static constexpr u32 mod =\
    \ Modulus;\n    u32 v;\n\npublic:\n    constexpr modint(const i64 x = 0) noexcept\
    \ : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n    constexpr u32& value()\
    \ noexcept { return v; }\n    constexpr const u32& value() const noexcept { return\
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
    \ modint& rhs) noexcept { return *this *= rhs.inv(); }\n    constexpr modint pow(u64\
    \ exp) const noexcept {\n        assert(0 <= exp);\n        modint self(*this),\
    \ res(1);\n        while (exp > 0) {\n            if (exp & 1) res *= self;\n\
    \            self *= self;\n            exp >>= 1;\n        }\n        return\
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
    \ * @docs docs/modulo/modint.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: modulo/modint.hpp
  requiredBy:
  - convolution/NumberTheoreticTransform.hpp
  - convolution/ArbitaryModConvolution.hpp
  - test/atcoder/tdpc_fibonacci.cpp
  timestamp: '2021-09-21 14:56:05+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DPL_5_J.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_I.test.cpp
  - test/aoj/DPL_5_L.test.cpp
  - test/aoj/DPL_5_A.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_C.test.cpp
  - test/aoj/DPL_5_G.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yukicoder/803.test.cpp
  - test/yukicoder/931.test.cpp
  - test/yukicoder/3046.test.cpp
  - test/yukicoder/1050.test.cpp
  - test/yukicoder/1289.test.cpp
  - test/yukicoder/1302.test.cpp
  - test/yukicoder/1068.test.cpp
  - test/yukicoder/1269.test.cpp
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