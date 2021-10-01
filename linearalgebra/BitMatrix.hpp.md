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
    _deprecated_at_docs: docs/datastructure/BitMatrix.md
    document_title: BitMatrix
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"linearalgebra/BitMatrix.hpp\"\
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
  path: linearalgebra/BitMatrix.hpp
  requiredBy: []
  timestamp: '2021-10-01 16:25:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linearalgebra/BitMatrix.hpp
layout: document
redirect_from:
- /library/linearalgebra/BitMatrix.hpp
- /library/linearalgebra/BitMatrix.hpp.html
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