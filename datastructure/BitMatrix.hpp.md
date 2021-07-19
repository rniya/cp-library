---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/BitMatrix.md
    document_title: BitMatrix
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/BitMatrix.hpp\"\
    \n\n/**\n * @brief BitMatrix\n * @docs docs/datastructure/BitMatrix.md\n */\n\
    template <size_t MAX_COL> struct BitMatrix {\n    int n, m;\n    vector<bitset<MAX_COL>>\
    \ A;\n    BitMatrix(int n) : n(n), m(MAX_COL), A(n) {}\n    const bitset<MAX_COL>&\
    \ operator[](int k) const { return A[k]; }\n    bitset<MAX_COL>& operator[](int\
    \ k) { return A[k]; }\n    int gauss_jordan(int extended = 0) {\n        int rank\
    \ = 0;\n        for (int j = 0; j < m - extended; j++) {\n            int pivot\
    \ = -1;\n            for (int i = rank; i < n; i++) {\n                if (A[i][j])\
    \ {\n                    pivot = i;\n                    break;\n            \
    \    }\n            }\n            if (pivot == -1) continue;\n            swap(A[pivot],\
    \ A[rank]);\n            for (int i = 0; i < n; i++) {\n                if (i\
    \ != rank && A[i][j]) {\n                    A[i] ^= A[rank];\n              \
    \  }\n            }\n            rank++;\n        }\n        return rank;\n  \
    \  }\n    pair<int, vector<int>> linear_equation(const vector<int>& b) {\n   \
    \     assert(n == (int)b.size());\n        for (int i = 0; i < n; i++) A[i][m\
    \ - 1] = b[i];\n        int rank = gauss_jordan(1);\n        for (int i = rank;\
    \ i < n; i++) {\n            if (A[i][m - 1]) {\n                return {-1, vector<int>{}};\n\
    \            }\n        }\n        vector<int> res(m, 0);\n        for (int i\
    \ = 0; i < rank; i++) res[i] = A[i][m - 1];\n        return {rank, res};\n   \
    \ }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief BitMatrix\n * @docs\
    \ docs/datastructure/BitMatrix.md\n */\ntemplate <size_t MAX_COL> struct BitMatrix\
    \ {\n    int n, m;\n    vector<bitset<MAX_COL>> A;\n    BitMatrix(int n) : n(n),\
    \ m(MAX_COL), A(n) {}\n    const bitset<MAX_COL>& operator[](int k) const { return\
    \ A[k]; }\n    bitset<MAX_COL>& operator[](int k) { return A[k]; }\n    int gauss_jordan(int\
    \ extended = 0) {\n        int rank = 0;\n        for (int j = 0; j < m - extended;\
    \ j++) {\n            int pivot = -1;\n            for (int i = rank; i < n; i++)\
    \ {\n                if (A[i][j]) {\n                    pivot = i;\n        \
    \            break;\n                }\n            }\n            if (pivot ==\
    \ -1) continue;\n            swap(A[pivot], A[rank]);\n            for (int i\
    \ = 0; i < n; i++) {\n                if (i != rank && A[i][j]) {\n          \
    \          A[i] ^= A[rank];\n                }\n            }\n            rank++;\n\
    \        }\n        return rank;\n    }\n    pair<int, vector<int>> linear_equation(const\
    \ vector<int>& b) {\n        assert(n == (int)b.size());\n        for (int i =\
    \ 0; i < n; i++) A[i][m - 1] = b[i];\n        int rank = gauss_jordan(1);\n  \
    \      for (int i = rank; i < n; i++) {\n            if (A[i][m - 1]) {\n    \
    \            return {-1, vector<int>{}};\n            }\n        }\n        vector<int>\
    \ res(m, 0);\n        for (int i = 0; i < rank; i++) res[i] = A[i][m - 1];\n \
    \       return {rank, res};\n    }\n};\n"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/BitMatrix.hpp
  requiredBy: []
  timestamp: '2021-07-19 13:04:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/803.test.cpp
documentation_of: datastructure/BitMatrix.hpp
layout: document
redirect_from:
- /library/datastructure/BitMatrix.hpp
- /library/datastructure/BitMatrix.hpp.html
title: BitMatrix
---
## 概要
$\mathbb{F}_2$ 上での掃き出し法を行うためのライブラリ. $\mathbb{F}_2$ に特化させるために内部では `bitset` でデータを保持している.
- `gauss_jordan(extended)` : 掃き出し法を行い, その結果得られた $\operatorname{rank}$ を返す. `extended` は `linear_equtation(b)` などで最後の行を除外して掃き出す機会があるのでそのための変数.
- `linear_equation(b)` : $\forall i,\ \otimes_{j=1}^m a_{ij}x_j = b_i$ を満たすような数列 $\{x_j\}_{j=1}^m$ を求める. 解を構成することが不可能な場合には -1 を返す. 行列 $A$ の列方向のサイズには 1 だけ余分をもたせておく必要があることに注意.

## 計算量
$O\left(\dfrac{n^2m}{64}\right)$

## 問題例
[yukicoder No.803 Very Limited Xor Subset](https://yukicoder.me/problems/no/803)