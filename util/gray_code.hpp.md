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
    _deprecated_at_docs: docs/util/gray_code.md
    document_title: "\u30B0\u30EC\u30A4\u30B3\u30FC\u30C9"
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
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
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\n\
    template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail)\
    \ {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"util/gray_code.hpp\"\n\n\
    /**\n * @brief \u30B0\u30EC\u30A4\u30B3\u30FC\u30C9\n * @docs docs/util/gray_code.md\n\
    \ */\nvector<int> gray_code(int n) {\n    vector<int> res(1 << n);\n    for (int\
    \ i = 0; i < (int)res.size(); i++) res[i] = i ^ (i >> 1);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u30B0\u30EC\u30A4\
    \u30B3\u30FC\u30C9\n * @docs docs/util/gray_code.md\n */\nvector<int> gray_code(int\
    \ n) {\n    vector<int> res(1 << n);\n    for (int i = 0; i < (int)res.size();\
    \ i++) res[i] = i ^ (i >> 1);\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: util/gray_code.hpp
  requiredBy: []
  timestamp: '2021-07-19 13:04:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/gray_code.hpp
layout: document
redirect_from:
- /library/util/gray_code.hpp
- /library/util/gray_code.hpp.html
title: "\u30B0\u30EC\u30A4\u30B3\u30FC\u30C9"
---
## 概要
Gray Code とは数値の符号化法の一つで, 前後に隣接する符号間のハミング距離が必ず 1 となるという特徴をもつ.

この特徴を生かして, 例えば bit dp や全探索の際に集合の探索順をこの Gray Code になぞらえることで, 更新の際の計算量を改善できることがある.

## 問題例
[Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine) F. Bingo](https://codeforces.com/contest/1530/problem/F)
包除原理により数え上げることを考える.1 が揃うような行集合及び対角線を固定すれば, 各列集合は独立であるから左から走査していくことで数え上げることができる.この際の計算量は決め打ちする集合が $2^{n+2}$ 個で, 各列で 1 が揃うとしたときの確率の計算に $O(n^2)$ かかるから, 結局 $O((n^2+2n)2^{n+2})$ となる.ここで, 集合の探索順を Gray Code にすれば, 集合が変更される際に各列の確率を $O(n)$ で更新することが可能になり, $O(n2^{n+3})$でこの問題が解くことができる.