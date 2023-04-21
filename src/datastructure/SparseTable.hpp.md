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
    \ x) - begin(v); }\n#line 3 \"src/datastructure/SparseTable.hpp\"\n\ntemplate\
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
  timestamp: '2023-04-22 02:23:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: src/datastructure/SparseTable.hpp
layout: document
title: Sparse Table
---

## 概要
