---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ int MOD = 1000000007;\n#line 3 \"src/datastructure/SparseTable.hpp\"\n\ntemplate\
    \ <typename T> struct SparseTable {\n    typedef function<T(T, T)> F;\n    vector<vector<T>>\
    \ dat;\n    vector<int> lookup;\n    const F f;\n    SparseTable(F f) : f(f) {}\n\
    \    void build(const vector<T>& v) {\n        int n = v.size(), h = 1;\n    \
    \    while ((1 << h) <= n) h++;\n        dat.assign(h, vector<T>(n));\n      \
    \  lookup.assign(n + 1, 0);\n        for (int i = 2; i <= n; i++) lookup[i] =\
    \ lookup[i >> 1] + 1;\n        for (int j = 0; j < n; j++) dat[0][j] = v[j];\n\
    \        for (int i = 1, mask = 1; i < h; i++, mask <<= 1) {\n            for\
    \ (int j = 0; j < n; j++) {\n                dat[i][j] = f(dat[i - 1][j], dat[i\
    \ - 1][min(j + mask, n - 1)]);\n            }\n        }\n    }\n    T query(int\
    \ a, int b) {\n        int d = lookup[b - a];\n        return f(dat[d][a], dat[d][b\
    \ - (1 << d)]);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate <typename T> struct SparseTable\
    \ {\n    typedef function<T(T, T)> F;\n    vector<vector<T>> dat;\n    vector<int>\
    \ lookup;\n    const F f;\n    SparseTable(F f) : f(f) {}\n    void build(const\
    \ vector<T>& v) {\n        int n = v.size(), h = 1;\n        while ((1 << h) <=\
    \ n) h++;\n        dat.assign(h, vector<T>(n));\n        lookup.assign(n + 1,\
    \ 0);\n        for (int i = 2; i <= n; i++) lookup[i] = lookup[i >> 1] + 1;\n\
    \        for (int j = 0; j < n; j++) dat[0][j] = v[j];\n        for (int i = 1,\
    \ mask = 1; i < h; i++, mask <<= 1) {\n            for (int j = 0; j < n; j++)\
    \ {\n                dat[i][j] = f(dat[i - 1][j], dat[i - 1][min(j + mask, n -\
    \ 1)]);\n            }\n        }\n    }\n    T query(int a, int b) {\n      \
    \  int d = lookup[b - a];\n        return f(dat[d][a], dat[d][b - (1 << d)]);\n\
    \    }\n};"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2023-03-28 19:04:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: src/datastructure/SparseTable.hpp
layout: document
title: Sparse Table
---

## 概要
