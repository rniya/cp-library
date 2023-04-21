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
  bundledCode: "#line 2 \"src/base.hpp\"\n#include <bits/stdc++.h>\n#ifdef LOCAL\n\
    #include <debug.hpp>\n#else\n#define debug(...) void(0)\n#endif\n\nusing namespace\
    \ std;\n\ntypedef long long ll;\n#define all(x) begin(x), end(x)\nconstexpr int\
    \ INF = (1 << 30) - 1;\nconstexpr long long IINF = (1LL << 60) - 1;\nconstexpr\
    \ int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};\n\ntemplate <class T> istream&\
    \ operator>>(istream& is, vector<T>& v) {\n    for (auto& x : v) is >> x;\n  \
    \  return is;\n}\n\ntemplate <class T> ostream& operator<<(ostream& os, const\
    \ vector<T>& v) {\n    auto sep = \"\";\n    for (const auto& x : v) os << exchange(sep,\
    \ \" \") << x;\n    return os;\n}\n\ntemplate <class T, class U = T> bool chmin(T&\
    \ x, U&& y) { return y < x and (x = forward<U>(y), true); }\n\ntemplate <class\
    \ T, class U = T> bool chmax(T& x, U&& y) { return x < y and (x = forward<U>(y),\
    \ true); }\n\ntemplate <class T> void mkuni(vector<T>& v) {\n    sort(begin(v),\
    \ end(v));\n    v.erase(unique(begin(v), end(v)), end(v));\n}\n\ntemplate <class\
    \ T> int lwb(const vector<T>& v, const T& x) { return lower_bound(begin(v), end(v),\
    \ x) - begin(v); }\n#line 3 \"src/util/gray_code.hpp\"\n\nvector<int> gray_code(int\
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
  timestamp: '2023-04-22 02:23:28+09:00'
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
