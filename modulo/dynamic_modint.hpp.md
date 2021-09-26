---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
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
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"modulo/dynamic_modint.hpp\"\
    \n\n/**\n * @brief \u5B9F\u884C\u6642 modint\n * @docs docs/modulo/modint.md\n\
    \ */\nclass dynamic_modint {\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n    static u32& mod() {\n        static u32 mod_ =\
    \ 0;\n        return mod_;\n    }\n\npublic:\n    u32 v;\n    static void set_mod(const\
    \ u32 x) {\n        assert(x < (u32(1) << 31));\n        mod() = x;\n    }\n \
    \   static u32 get_mod() { return mod(); }\n    dynamic_modint(const i64 x = 0)\
    \ : v(x < 0 ? get_mod() - 1 - (-(x + 1) % get_mod()) : x % get_mod()) {}\n   \
    \ u32& value() noexcept { return v; }\n    const u32& value() const noexcept {\
    \ return v; }\n    dynamic_modint operator+(const dynamic_modint& rhs) const {\
    \ return dynamic_modint(*this) += rhs; }\n    dynamic_modint operator-(const dynamic_modint&\
    \ rhs) const { return dynamic_modint(*this) -= rhs; }\n    dynamic_modint operator*(const\
    \ dynamic_modint& rhs) const { return dynamic_modint(*this) *= rhs; }\n    dynamic_modint\
    \ operator/(const dynamic_modint& rhs) const { return dynamic_modint(*this) /=\
    \ rhs; }\n    dynamic_modint& operator+=(const dynamic_modint& rhs) {\n      \
    \  v += rhs.v;\n        if (v >= get_mod()) v -= get_mod();\n        return *this;\n\
    \    }\n    dynamic_modint& operator-=(const dynamic_modint& rhs) {\n        if\
    \ (v < rhs.v) v += get_mod();\n        v -= rhs.v;\n        return *this;\n  \
    \  }\n    dynamic_modint& operator*=(const dynamic_modint& rhs) {\n        v =\
    \ (u64)v * rhs.v % get_mod();\n        return *this;\n    }\n    dynamic_modint&\
    \ operator/=(const dynamic_modint& rhs) { return *this *= rhs.pow(get_mod() -\
    \ 2); }\n    dynamic_modint pow(u64 exp) const {\n        dynamic_modint self(*this),\
    \ res(1);\n        while (exp > 0) {\n            if (exp & 1) res *= self;\n\
    \            self *= self;\n            exp >>= 1;\n        }\n        return\
    \ res;\n    }\n    dynamic_modint& operator++() {\n        if (++v == get_mod())\
    \ v = 0;\n        return *this;\n    }\n    dynamic_modint& operator--() {\n \
    \       if (v == 0) v = get_mod();\n        return --v, *this;\n    }\n    dynamic_modint\
    \ operator++(int) {\n        dynamic_modint t = *this;\n        return ++*this,\
    \ t;\n    }\n    dynamic_modint operator--(int) {\n        dynamic_modint t =\
    \ *this;\n        return --*this, t;\n    }\n    dynamic_modint operator-() {\
    \ return dynamic_modint(get_mod() - v); }\n    template <class T> friend dynamic_modint\
    \ operator+(T x, dynamic_modint y) { return dynamic_modint(x) + y; }\n    template\
    \ <class T> friend dynamic_modint operator-(T x, dynamic_modint y) { return dynamic_modint(x)\
    \ - y; }\n    template <class T> friend dynamic_modint operator*(T x, dynamic_modint\
    \ y) { return dynamic_modint(x) * y; }\n    template <class T> friend dynamic_modint\
    \ operator/(T x, dynamic_modint y) { return dynamic_modint(x) / y; }\n    bool\
    \ operator==(const dynamic_modint& rhs) { return v == rhs.v; }\n    bool operator!=(const\
    \ dynamic_modint& rhs) { return v != rhs.v; }\n    bool operator!() { return !v;\
    \ }\n    friend istream& operator>>(istream& s, dynamic_modint& rhs) {\n     \
    \   i64 v;\n        rhs = dynamic_modint{(s >> v, v)};\n        return s;\n  \
    \  }\n    friend ostream& operator<<(ostream& s, const dynamic_modint& rhs) {\
    \ return s << rhs.v; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u5B9F\u884C\u6642\
    \ modint\n * @docs docs/modulo/modint.md\n */\nclass dynamic_modint {\n    using\
    \ i64 = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n    static\
    \ u32& mod() {\n        static u32 mod_ = 0;\n        return mod_;\n    }\n\n\
    public:\n    u32 v;\n    static void set_mod(const u32 x) {\n        assert(x\
    \ < (u32(1) << 31));\n        mod() = x;\n    }\n    static u32 get_mod() { return\
    \ mod(); }\n    dynamic_modint(const i64 x = 0) : v(x < 0 ? get_mod() - 1 - (-(x\
    \ + 1) % get_mod()) : x % get_mod()) {}\n    u32& value() noexcept { return v;\
    \ }\n    const u32& value() const noexcept { return v; }\n    dynamic_modint operator+(const\
    \ dynamic_modint& rhs) const { return dynamic_modint(*this) += rhs; }\n    dynamic_modint\
    \ operator-(const dynamic_modint& rhs) const { return dynamic_modint(*this) -=\
    \ rhs; }\n    dynamic_modint operator*(const dynamic_modint& rhs) const { return\
    \ dynamic_modint(*this) *= rhs; }\n    dynamic_modint operator/(const dynamic_modint&\
    \ rhs) const { return dynamic_modint(*this) /= rhs; }\n    dynamic_modint& operator+=(const\
    \ dynamic_modint& rhs) {\n        v += rhs.v;\n        if (v >= get_mod()) v -=\
    \ get_mod();\n        return *this;\n    }\n    dynamic_modint& operator-=(const\
    \ dynamic_modint& rhs) {\n        if (v < rhs.v) v += get_mod();\n        v -=\
    \ rhs.v;\n        return *this;\n    }\n    dynamic_modint& operator*=(const dynamic_modint&\
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
    \   bool operator!() { return !v; }\n    friend istream& operator>>(istream& s,\
    \ dynamic_modint& rhs) {\n        i64 v;\n        rhs = dynamic_modint{(s >> v,\
    \ v)};\n        return s;\n    }\n    friend ostream& operator<<(ostream& s, const\
    \ dynamic_modint& rhs) { return s << rhs.v; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: modulo/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
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