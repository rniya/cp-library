---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_J.test.cpp
    title: test/aoj/DPL_5_J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_L.test.cpp
    title: test/aoj/DPL_5_L.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/combinatorics/PartitionTable.md
    document_title: "\u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"combinatorics/PartitionTable.hpp\"\
    \n\n/**\n * @brief \u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB\n * @docs docs/combinatorics/PartitionTable.md\n\
    \ */\ntemplate <typename T> vector<vector<T>> partition_table(int n, int k) {\n\
    \    vector<vector<T>> dp(n + 1, vector<T>(k + 1));\n    dp[0][0] = 1;\n    for\
    \ (int i = 0; i <= n; i++) {\n        for (int j = 1; j <= k; j++) {\n       \
    \     dp[i][j] = dp[i][j - 1] + (i - j >= 0 ? dp[i - j][j] : 0);\n        }\n\
    \    }\n    return dp;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u5206\u5272\u6570\
    \u30C6\u30FC\u30D6\u30EB\n * @docs docs/combinatorics/PartitionTable.md\n */\n\
    template <typename T> vector<vector<T>> partition_table(int n, int k) {\n    vector<vector<T>>\
    \ dp(n + 1, vector<T>(k + 1));\n    dp[0][0] = 1;\n    for (int i = 0; i <= n;\
    \ i++) {\n        for (int j = 1; j <= k; j++) {\n            dp[i][j] = dp[i][j\
    \ - 1] + (i - j >= 0 ? dp[i - j][j] : 0);\n        }\n    }\n    return dp;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: combinatorics/PartitionTable.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_L.test.cpp
  - test/aoj/DPL_5_J.test.cpp
documentation_of: combinatorics/PartitionTable.hpp
layout: document
redirect_from:
- /library/combinatorics/PartitionTable.hpp
- /library/combinatorics/PartitionTable.hpp.html
title: "\u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB"
---
## 概要
分割数$P\left(n,k\right)$は$n$の個の区別できない玉を$k$個の区別できない箱に入れる組合せ数, すなわち整数$n$をちょうど$k$個の非負整数の和で表す場合の数を与える. これは,
1. 分割が$0$を含むとき, 組合せ数は$P\left(n,k-1\right)$に帰着される.
2. 分割が$0$を含まないとき, $k$個の整数が全て$0$以上なので, それらから$1$ずつ除けば組合せ数は$P\left(n-k,k\right)$に帰着される.

から,
$$P\left(n,k\right)=P\left(n,k-1\right)+P\left(n-k,k\right)$$
によって計算できる.

## 計算量
$O\left(nk\right)$

## 参照
[「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)