---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/526.test.cpp
    title: test/yukicoder/526.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/modulo/modint.md
    document_title: "\u5B9F\u884C\u6642 modint"
    links: []
  bundledCode: "#line 2 \"modulo/dynamic_modint.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n\nclass dynamic_modint {\n    using i64 = int64_t;\n    using u32\
    \ = uint32_t;\n    using u64 = uint64_t;\n    static u32& mod() {\n        static\
    \ u32 mod_ = 0;\n        return mod_;\n    }\n\npublic:\n    u32 v;\n    static\
    \ void set_mod(const u32 x) {\n        assert(x < (u32(1) << 31));\n        mod()\
    \ = x;\n    }\n    static u32 get_mod() { return mod(); }\n    dynamic_modint(const\
    \ i64 x = 0) : v(x < 0 ? get_mod() - 1 - (-(x + 1) % get_mod()) : x % get_mod())\
    \ {}\n    u32& val() noexcept { return v; }\n    const u32& val() const noexcept\
    \ { return v; }\n    dynamic_modint operator+(const dynamic_modint& rhs) const\
    \ { return dynamic_modint(*this) += rhs; }\n    dynamic_modint operator-(const\
    \ dynamic_modint& rhs) const { return dynamic_modint(*this) -= rhs; }\n    dynamic_modint\
    \ operator*(const dynamic_modint& rhs) const { return dynamic_modint(*this) *=\
    \ rhs; }\n    dynamic_modint operator/(const dynamic_modint& rhs) const { return\
    \ dynamic_modint(*this) /= rhs; }\n    dynamic_modint& operator+=(const dynamic_modint&\
    \ rhs) {\n        v += rhs.v;\n        if (v >= get_mod()) v -= get_mod();\n \
    \       return *this;\n    }\n    dynamic_modint& operator-=(const dynamic_modint&\
    \ rhs) {\n        if (v < rhs.v) v += get_mod();\n        v -= rhs.v;\n      \
    \  return *this;\n    }\n    dynamic_modint& operator*=(const dynamic_modint&\
    \ rhs) {\n        v = (u64)v * rhs.v % get_mod();\n        return *this;\n   \
    \ }\n    dynamic_modint& operator/=(const dynamic_modint& rhs) { return *this\
    \ *= rhs.pow(get_mod() - 2); }\n    dynamic_modint pow(u64 exp) const {\n    \
    \    dynamic_modint self(*this), res(1);\n        while (exp > 0) {\n        \
    \    if (exp & 1) res *= self;\n            self *= self;\n            exp >>=\
    \ 1;\n        }\n        return res;\n    }\n    dynamic_modint& operator++()\
    \ {\n        if (++v == get_mod()) v = 0;\n        return *this;\n    }\n    dynamic_modint&\
    \ operator--() {\n        if (v == 0) v = get_mod();\n        return --v, *this;\n\
    \    }\n    dynamic_modint operator++(int) {\n        dynamic_modint t = *this;\n\
    \        return ++*this, t;\n    }\n    dynamic_modint operator--(int) {\n   \
    \     dynamic_modint t = *this;\n        return --*this, t;\n    }\n    dynamic_modint\
    \ operator-() { return dynamic_modint(get_mod() - v); }\n    template <class T>\
    \ friend dynamic_modint operator+(T x, dynamic_modint y) { return dynamic_modint(x)\
    \ + y; }\n    template <class T> friend dynamic_modint operator-(T x, dynamic_modint\
    \ y) { return dynamic_modint(x) - y; }\n    template <class T> friend dynamic_modint\
    \ operator*(T x, dynamic_modint y) { return dynamic_modint(x) * y; }\n    template\
    \ <class T> friend dynamic_modint operator/(T x, dynamic_modint y) { return dynamic_modint(x)\
    \ / y; }\n    bool operator==(const dynamic_modint& rhs) { return v == rhs.v;\
    \ }\n    bool operator!=(const dynamic_modint& rhs) { return v != rhs.v; }\n \
    \   bool operator!() { return !v; }\n    friend std::istream& operator>>(std::istream&\
    \ s, dynamic_modint& rhs) {\n        i64 v;\n        rhs = dynamic_modint{(s >>\
    \ v, v)};\n        return s;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ s, const dynamic_modint& rhs) { return s << rhs.v; }\n};\n\n/**\n * @brief \u5B9F\
    \u884C\u6642 modint\n * @docs docs/modulo/modint.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n\nclass dynamic_modint\
    \ {\n    using i64 = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \    static u32& mod() {\n        static u32 mod_ = 0;\n        return mod_;\n\
    \    }\n\npublic:\n    u32 v;\n    static void set_mod(const u32 x) {\n      \
    \  assert(x < (u32(1) << 31));\n        mod() = x;\n    }\n    static u32 get_mod()\
    \ { return mod(); }\n    dynamic_modint(const i64 x = 0) : v(x < 0 ? get_mod()\
    \ - 1 - (-(x + 1) % get_mod()) : x % get_mod()) {}\n    u32& val() noexcept {\
    \ return v; }\n    const u32& val() const noexcept { return v; }\n    dynamic_modint\
    \ operator+(const dynamic_modint& rhs) const { return dynamic_modint(*this) +=\
    \ rhs; }\n    dynamic_modint operator-(const dynamic_modint& rhs) const { return\
    \ dynamic_modint(*this) -= rhs; }\n    dynamic_modint operator*(const dynamic_modint&\
    \ rhs) const { return dynamic_modint(*this) *= rhs; }\n    dynamic_modint operator/(const\
    \ dynamic_modint& rhs) const { return dynamic_modint(*this) /= rhs; }\n    dynamic_modint&\
    \ operator+=(const dynamic_modint& rhs) {\n        v += rhs.v;\n        if (v\
    \ >= get_mod()) v -= get_mod();\n        return *this;\n    }\n    dynamic_modint&\
    \ operator-=(const dynamic_modint& rhs) {\n        if (v < rhs.v) v += get_mod();\n\
    \        v -= rhs.v;\n        return *this;\n    }\n    dynamic_modint& operator*=(const\
    \ dynamic_modint& rhs) {\n        v = (u64)v * rhs.v % get_mod();\n        return\
    \ *this;\n    }\n    dynamic_modint& operator/=(const dynamic_modint& rhs) { return\
    \ *this *= rhs.pow(get_mod() - 2); }\n    dynamic_modint pow(u64 exp) const {\n\
    \        dynamic_modint self(*this), res(1);\n        while (exp > 0) {\n    \
    \        if (exp & 1) res *= self;\n            self *= self;\n            exp\
    \ >>= 1;\n        }\n        return res;\n    }\n    dynamic_modint& operator++()\
    \ {\n        if (++v == get_mod()) v = 0;\n        return *this;\n    }\n    dynamic_modint&\
    \ operator--() {\n        if (v == 0) v = get_mod();\n        return --v, *this;\n\
    \    }\n    dynamic_modint operator++(int) {\n        dynamic_modint t = *this;\n\
    \        return ++*this, t;\n    }\n    dynamic_modint operator--(int) {\n   \
    \     dynamic_modint t = *this;\n        return --*this, t;\n    }\n    dynamic_modint\
    \ operator-() { return dynamic_modint(get_mod() - v); }\n    template <class T>\
    \ friend dynamic_modint operator+(T x, dynamic_modint y) { return dynamic_modint(x)\
    \ + y; }\n    template <class T> friend dynamic_modint operator-(T x, dynamic_modint\
    \ y) { return dynamic_modint(x) - y; }\n    template <class T> friend dynamic_modint\
    \ operator*(T x, dynamic_modint y) { return dynamic_modint(x) * y; }\n    template\
    \ <class T> friend dynamic_modint operator/(T x, dynamic_modint y) { return dynamic_modint(x)\
    \ / y; }\n    bool operator==(const dynamic_modint& rhs) { return v == rhs.v;\
    \ }\n    bool operator!=(const dynamic_modint& rhs) { return v != rhs.v; }\n \
    \   bool operator!() { return !v; }\n    friend std::istream& operator>>(std::istream&\
    \ s, dynamic_modint& rhs) {\n        i64 v;\n        rhs = dynamic_modint{(s >>\
    \ v, v)};\n        return s;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ s, const dynamic_modint& rhs) { return s << rhs.v; }\n};\n\n/**\n * @brief \u5B9F\
    \u884C\u6642 modint\n * @docs docs/modulo/modint.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: modulo/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2021-10-01 20:18:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/526.test.cpp
documentation_of: modulo/dynamic_modint.hpp
layout: document
redirect_from:
- /library/modulo/dynamic_modint.hpp
- /library/modulo/dynamic_modint.hpp.html
title: "\u5B9F\u884C\u6642 modint"
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
