---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_5_B.test.cpp
    title: test/aoj/DSL_5_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/CumulativeSum2D.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <typename T> struct CumulativeSum2D {\n    CumulativeSum2D(const\
    \ std::vector<std::vector<T>>& v) {\n        n = v.size(), m = v[0].size();\n\
    \        dat.assign(n + 1, std::vector<T>(m + 1, T(0)));\n        for (int i =\
    \ 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n              \
    \  dat[i + 1][j + 1] = v[i][j];\n                dat[i + 1][j + 1] += dat[i +\
    \ 1][j] + dat[i][j + 1] - dat[i][j];\n            }\n        }\n    }\n\n    T\
    \ query(int xl, int xr, int yl, int yr) const {  // [xl, xr) * [yl, yr)\n    \
    \    assert(0 <= xl && xl <= xr && xr <= n);\n        assert(0 <= yl && yl <=\
    \ yr && yr <= m);\n        return dat[xr][yr] - dat[xl][yr] - dat[xr][yl] + dat[xl][yl];\n\
    \    }\n\nprivate:\n    int n, m;\n    std::vector<std::vector<T>> dat;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> struct CumulativeSum2D {\n    CumulativeSum2D(const std::vector<std::vector<T>>&\
    \ v) {\n        n = v.size(), m = v[0].size();\n        dat.assign(n + 1, std::vector<T>(m\
    \ + 1, T(0)));\n        for (int i = 0; i < n; i++) {\n            for (int j\
    \ = 0; j < m; j++) {\n                dat[i + 1][j + 1] = v[i][j];\n         \
    \       dat[i + 1][j + 1] += dat[i + 1][j] + dat[i][j + 1] - dat[i][j];\n    \
    \        }\n        }\n    }\n\n    T query(int xl, int xr, int yl, int yr) const\
    \ {  // [xl, xr) * [yl, yr)\n        assert(0 <= xl && xl <= xr && xr <= n);\n\
    \        assert(0 <= yl && yl <= yr && yr <= m);\n        return dat[xr][yr] -\
    \ dat[xl][yr] - dat[xr][yl] + dat[xl][yl];\n    }\n\nprivate:\n    int n, m;\n\
    \    std::vector<std::vector<T>> dat;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_5_B.test.cpp
documentation_of: src/datastructure/CumulativeSum2D.hpp
layout: document
title: "2 \u6B21\u5143\u7D2F\u7A4D\u548C"
---

## 概要
2 次元累積和を用いてオフライン矩形和クエリを処理する．
