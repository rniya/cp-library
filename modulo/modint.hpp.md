---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':question:'
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1068.test.cpp
    title: test/yukicoder/1068.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1289.test.cpp
    title: test/yukicoder/1289.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1302.test.cpp
    title: test/yukicoder/1302.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  - icon: ':x:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  - icon: ':x:'
    path: test/yukicoder/931.test.cpp
    title: test/yukicoder/931.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/modulo/modint.md
    document_title: modint
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n      \
    \  os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \" \"\
    );\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate\
    \ <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n\
    \    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"modulo/modint.hpp\"\n\n\
    /**\n * @brief modint\n * @docs docs/modulo/modint.md\n */\ntemplate <uint32_t\
    \ mod> class modint {\n    using i64 = int64_t;\n    using u32 = uint32_t;\n \
    \   using u64 = uint64_t;\n\npublic:\n    u32 v;\n    constexpr modint(const i64\
    \ x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n    constexpr\
    \ u32& value() noexcept { return v; }\n    constexpr const u32& value() const\
    \ noexcept { return v; }\n    constexpr modint operator+(const modint& rhs) const\
    \ noexcept { return modint(*this) += rhs; }\n    constexpr modint operator-(const\
    \ modint& rhs) const noexcept { return modint(*this) -= rhs; }\n    constexpr\
    \ modint operator*(const modint& rhs) const noexcept { return modint(*this) *=\
    \ rhs; }\n    constexpr modint operator/(const modint& rhs) const noexcept { return\
    \ modint(*this) /= rhs; }\n    constexpr modint& operator+=(const modint& rhs)\
    \ noexcept {\n        v += rhs.v;\n        if (v >= mod) v -= mod;\n        return\
    \ *this;\n    }\n    constexpr modint& operator-=(const modint& rhs) noexcept\
    \ {\n        if (v < rhs.v) v += mod;\n        v -= rhs.v;\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint& rhs) noexcept {\n     \
    \   v = (u64)v * rhs.v % mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator/=(const modint& rhs) noexcept { return *this *= rhs.pow(mod - 2); }\n\
    \    constexpr modint pow(u64 exp) const noexcept {\n        modint self(*this),\
    \ res(1);\n        while (exp > 0) {\n            if (exp & 1) res *= self;\n\
    \            self *= self;\n            exp >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint& operator++() noexcept {\n        if (++v\
    \ == mod) v = 0;\n        return *this;\n    }\n    constexpr modint& operator--()\
    \ noexcept {\n        if (v == 0) v = mod;\n        return --v, *this;\n    }\n\
    \    constexpr modint operator++(int) noexcept {\n        modint t = *this;\n\
    \        return ++*this, t;\n    }\n    constexpr modint operator--(int) noexcept\
    \ {\n        modint t = *this;\n        return --*this, t;\n    }\n    constexpr\
    \ modint operator-() const noexcept { return modint(mod - v); }\n    template\
    \ <class T> friend constexpr modint operator+(T x, modint y) noexcept { return\
    \ modint(x) + y; }\n    template <class T> friend constexpr modint operator-(T\
    \ x, modint y) noexcept { return modint(x) - y; }\n    template <class T> friend\
    \ constexpr modint operator*(T x, modint y) noexcept { return modint(x) * y; }\n\
    \    template <class T> friend constexpr modint operator/(T x, modint y) noexcept\
    \ { return modint(x) / y; }\n    constexpr bool operator==(const modint& rhs)\
    \ const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const modint&\
    \ rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!() const\
    \ noexcept { return !v; }\n    friend istream& operator>>(istream& s, modint&\
    \ rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n      \
    \  return s;\n    }\n    friend ostream& operator<<(ostream& s, const modint&\
    \ rhs) noexcept { return s << rhs.v; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief modint\n * @docs\
    \ docs/modulo/modint.md\n */\ntemplate <uint32_t mod> class modint {\n    using\
    \ i64 = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\npublic:\n\
    \    u32 v;\n    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod -\
    \ 1 - (-(x + 1) % mod) : x % mod) {}\n    constexpr u32& value() noexcept { return\
    \ v; }\n    constexpr const u32& value() const noexcept { return v; }\n    constexpr\
    \ modint operator+(const modint& rhs) const noexcept { return modint(*this) +=\
    \ rhs; }\n    constexpr modint operator-(const modint& rhs) const noexcept { return\
    \ modint(*this) -= rhs; }\n    constexpr modint operator*(const modint& rhs) const\
    \ noexcept { return modint(*this) *= rhs; }\n    constexpr modint operator/(const\
    \ modint& rhs) const noexcept { return modint(*this) /= rhs; }\n    constexpr\
    \ modint& operator+=(const modint& rhs) noexcept {\n        v += rhs.v;\n    \
    \    if (v >= mod) v -= mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator-=(const modint& rhs) noexcept {\n        if (v < rhs.v) v += mod;\n\
    \        v -= rhs.v;\n        return *this;\n    }\n    constexpr modint& operator*=(const\
    \ modint& rhs) noexcept {\n        v = (u64)v * rhs.v % mod;\n        return *this;\n\
    \    }\n    constexpr modint& operator/=(const modint& rhs) noexcept { return\
    \ *this *= rhs.pow(mod - 2); }\n    constexpr modint pow(u64 exp) const noexcept\
    \ {\n        modint self(*this), res(1);\n        while (exp > 0) {\n        \
    \    if (exp & 1) res *= self;\n            self *= self;\n            exp >>=\
    \ 1;\n        }\n        return res;\n    }\n    constexpr modint& operator++()\
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
    \ const noexcept { return !v; }\n    friend istream& operator>>(istream& s, modint&\
    \ rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n      \
    \  return s;\n    }\n    friend ostream& operator<<(ostream& s, const modint&\
    \ rhs) noexcept { return s << rhs.v; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: modulo/modint.hpp
  requiredBy:
  - convolution/ArbitaryModConvolution.hpp
  - convolution/NumberTheoreticTransform.hpp
  - test/atcoder/tdpc_fibonacci.cpp
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_G.test.cpp
  - test/aoj/DPL_5_A.test.cpp
  - test/aoj/DPL_5_L.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_C.test.cpp
  - test/aoj/DPL_5_I.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_J.test.cpp
  - test/yukicoder/665.test.cpp
  - test/yukicoder/1302.test.cpp
  - test/yukicoder/3046.test.cpp
  - test/yukicoder/1068.test.cpp
  - test/yukicoder/1269.test.cpp
  - test/yukicoder/1050.test.cpp
  - test/yukicoder/1289.test.cpp
  - test/yukicoder/931.test.cpp
documentation_of: modulo/modint.hpp
layout: document
redirect_from:
- /library/modulo/modint.hpp
- /library/modulo/modint.hpp.html
title: modint
---
## 概要
- 各種演算子(`operator++, operator--, operator-(), operator==, `等)に対応
- `std::cin, std::cout`への対応
- 負数に対応したコンストラクタ
- 内部を32bit符号なし整数で保存

## 参照
[modint 構造体を使ってみませんか？ (C++) - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/03/31/174006)