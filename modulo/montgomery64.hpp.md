---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/modulo/montgomery64.md
    document_title: montgomery modint (64 bit)
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#pragma region Macros\ntypedef long long ll;\ntypedef __int128_t\
    \ i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n#define\
    \ ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (size_t i = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size()\
    \ ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
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
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (size_t i\
    \ = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" :\
    \ \" \");\n    }\n    return os;\n}\ntemplate <typename T, size_t N> ostream&\
    \ operator<<(ostream& os, const array<T, N>& v) {\n    for (size_t i = 0; i <\
    \ N; i++) {\n        os << v[i] << (i + 1 == N ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&, const T&)\
    \ {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
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
    \ void(0)\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\nlong long MSK(int n) {\
    \ return (1LL << n) - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y\
    \ >= 1);\n    return (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T>\
    \ T floor(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y\
    \ + 1) / y);\n}\n\ntemplate <class T1, class T2> inline bool chmin(T1& a, T2 b)\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n\
    \    if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <typename T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n\
    \    v.erase(unique(v.begin(), v.end()), v.end());\n}\ntemplate <typename T> int\
    \ lwb(const vector<T>& v, const T& x) { return lower_bound(v.begin(), v.end(),\
    \ x) - v.begin(); }\n#pragma endregion\n#line 3 \"modulo/montgomery64.hpp\"\n\n\
    /**\n * @brief montgomery modint (64 bit)\n * @docs docs/modulo/montgomery64.md\n\
    \ */\nstruct montgomery64 {\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \    using u128 = __uint128_t;\n\n    static u64 mod, r, n2;\n\n    static u64\
    \ get_r() {\n        u64 res = mod;\n        for (int _ = 0; _ < 5; _++) res *=\
    \ 2 - mod * res;\n        return -res;\n    }\n\n    static void set_mod(u64 m)\
    \ {\n        assert(m < (1ULL << 62));\n        assert((m & 1) == 1);\n      \
    \  mod = m;\n        n2 = -u128(m) % m;\n        r = get_r();\n        assert(r\
    \ * mod == -1ULL);\n    }\n    static u64 get_mod() { return mod; }\n\n    static\
    \ u64 reduce(const u128& x) noexcept { return (x + u128(u64(x) * r) * mod) >>\
    \ 64; }\n\n    u64 v;\n    montgomery64() : v(0) {}\n    montgomery64(const i64&\
    \ v) : v(reduce((u128(v) + mod) * n2)) {}\n    u64 value() const {\n        u64\
    \ res = reduce(v);\n        return res >= mod ? res - mod : res;\n    }\n    montgomery64&\
    \ operator+=(const montgomery64& rhs) {\n        if (i64(v += rhs.v - (mod <<\
    \ 1)) < 0) v += mod << 1;\n        return *this;\n    }\n    montgomery64& operator-=(const\
    \ montgomery64& rhs) {\n        if (i64(v -= rhs.v) < 0) v += mod << 1;\n    \
    \    return *this;\n    }\n    montgomery64& operator*=(const montgomery64& rhs)\
    \ {\n        v = reduce(u128(v) * rhs.v);\n        return *this;\n    }\n    montgomery64&\
    \ operator/=(const montgomery64& rhs) { return *this *= rhs.inverse(); }\n   \
    \ montgomery64 operator+(const montgomery64& rhs) const { return montgomery64(*this)\
    \ += rhs; }\n    montgomery64 operator-(const montgomery64& rhs) const { return\
    \ montgomery64(*this) -= rhs; }\n    montgomery64 operator*(const montgomery64&\
    \ rhs) const { return montgomery64(*this) *= rhs; }\n    montgomery64 operator/(const\
    \ montgomery64& rhs) const { return montgomery64(*this) /= rhs; }\n    bool operator==(const\
    \ montgomery64& rhs) const {\n        return (v >= mod ? v - mod : v) == (rhs.v\
    \ >= mod ? rhs.v - mod : rhs.v);\n    }\n    bool operator!=(const montgomery64&\
    \ rhs) const {\n        return (v >= mod ? v - mod : v) != (rhs.v >= mod ? rhs.v\
    \ - mod : rhs.v);\n    }\n    montgomery64 operator-() const { return montgomery64()\
    \ - montgomery64(*this); }\n    montgomery64 pow(u64 n) const {\n        montgomery64\
    \ self(*this), res(1);\n        while (n > 0) {\n            if (n & 1) res *=\
    \ self;\n            self *= self;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n    montgomery64 inverse() const { return pow(mod - 2); }\n   \
    \ friend istream& operator>>(istream& s, montgomery64& rhs) {\n        i64 v;\n\
    \        rhs = montgomery64{(s >> v, v)};\n        return s;\n    }\n    friend\
    \ ostream& operator<<(ostream& s, const montgomery64& rhs) { return s << rhs.v;\
    \ }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief montgomery modint\
    \ (64 bit)\n * @docs docs/modulo/montgomery64.md\n */\nstruct montgomery64 {\n\
    \    using i64 = int64_t;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\
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
    \ * rhs.v);\n        return *this;\n    }\n    montgomery64& operator/=(const\
    \ montgomery64& rhs) { return *this *= rhs.inverse(); }\n    montgomery64 operator+(const\
    \ montgomery64& rhs) const { return montgomery64(*this) += rhs; }\n    montgomery64\
    \ operator-(const montgomery64& rhs) const { return montgomery64(*this) -= rhs;\
    \ }\n    montgomery64 operator*(const montgomery64& rhs) const { return montgomery64(*this)\
    \ *= rhs; }\n    montgomery64 operator/(const montgomery64& rhs) const { return\
    \ montgomery64(*this) /= rhs; }\n    bool operator==(const montgomery64& rhs)\
    \ const {\n        return (v >= mod ? v - mod : v) == (rhs.v >= mod ? rhs.v -\
    \ mod : rhs.v);\n    }\n    bool operator!=(const montgomery64& rhs) const {\n\
    \        return (v >= mod ? v - mod : v) != (rhs.v >= mod ? rhs.v - mod : rhs.v);\n\
    \    }\n    montgomery64 operator-() const { return montgomery64() - montgomery64(*this);\
    \ }\n    montgomery64 pow(u64 n) const {\n        montgomery64 self(*this), res(1);\n\
    \        while (n > 0) {\n            if (n & 1) res *= self;\n            self\
    \ *= self;\n            n >>= 1;\n        }\n        return res;\n    }\n    montgomery64\
    \ inverse() const { return pow(mod - 2); }\n    friend istream& operator>>(istream&\
    \ s, montgomery64& rhs) {\n        i64 v;\n        rhs = montgomery64{(s >> v,\
    \ v)};\n        return s;\n    }\n    friend ostream& operator<<(ostream& s, const\
    \ montgomery64& rhs) { return s << rhs.v; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: modulo/montgomery64.hpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulo/montgomery64.hpp
layout: document
redirect_from:
- /library/modulo/montgomery64.hpp
- /library/modulo/montgomery64.hpp.html
title: montgomery modint (64 bit)
---
## 概要


## 参照
- [高速なMOD演算 Barrett Reduction, Montgomery 乗算 - でも今日はSRMあるから](https://natsugiri.hatenablog.com/entry/2020/04/06/030559)