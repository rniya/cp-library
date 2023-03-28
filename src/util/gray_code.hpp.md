---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\n#define ALL(x) (x).begin(), (x).end()\n#ifdef LOCAL\n\
    #include <debug.hpp>\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n       \
    \ os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\
    \ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\n\
    template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\nint topbit(signed\
    \ t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(long long t)\
    \ { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(signed a) { return\
    \ a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long long a) { return a == 0 ?\
    \ 64 : __builtin_ctzll(a); }\nint popcount(signed t) { return __builtin_popcount(t);\
    \ }\nint popcount(long long t) { return __builtin_popcountll(t); }\nbool ispow2(int\
    \ i) { return i && (i & -i) == i; }\nlong long MSK(int n) { return (1LL << n)\
    \ - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y >= 1);\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T> T floor(T x, T y)\
    \ {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\n\
    template <class T1, class T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n  \
    \      a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n}\ntemplate <typename T> int lwb(const vector<T>& v, const\
    \ T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }\n\nconst int\
    \ INF = (1 << 30) - 1;\nconst long long IINF = (1LL << 60) - 1;\nconst int dx[4]\
    \ = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};\nconst int MOD = 998244353;\n// const\
    \ int MOD = 1000000007;\n#line 3 \"src/util/gray_code.hpp\"\n\nvector<int> gray_code(int\
    \ n) {\n    vector<int> res(1 << n);\n    for (int i = 0; i < (int)res.size();\
    \ i++) res[i] = i ^ (i >> 1);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nvector<int> gray_code(int n) {\n\
    \    vector<int> res(1 << n);\n    for (int i = 0; i < (int)res.size(); i++) res[i]\
    \ = i ^ (i >> 1);\n    return res;\n}"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/util/gray_code.hpp
  requiredBy: []
  timestamp: '2023-03-28 19:04:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/util/gray_code.hpp
layout: document
title: Gray Code
---

## 概要
Gray Code とは数値の符号化法の一つで, 前後に隣接する符号間のハミング距離が必ず 1 となるという特徴をもつ.

この特徴を生かして, 例えば bit dp や全探索の際に集合の探索順をこの Gray Code になぞらえることで, 更新の際の計算量を改善できることがある.

## 問題例
[Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine) F. Bingo](https://codeforces.com/contest/1530/problem/F)
包除原理により数え上げることを考える.1 が揃うような行集合及び対角線を固定すれば, 各列集合は独立であるから左から走査していくことで数え上げることができる.この際の計算量は決め打ちする集合が $2^{n+2}$ 個で, 各列で 1 が揃うとしたときの確率の計算に $O(n^2)$ かかるから, 結局 $O((n^2+2n)2^{n+2})$ となる.ここで, 集合の探索順を Gray Code にすれば, 集合が変更される際に各列の確率を $O(n)$ で更新することが可能になり, $O(n2^{n+3})$でこの問題が解くことができる.
