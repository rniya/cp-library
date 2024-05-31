---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/min_plus_convolution_convex_arbitrary.hpp
    title: Min Plus Convolution (Convex and Arbitary)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/optimization/monotone_minima.hpp\"\n#include <vector>\n\
    \ntemplate <class Select> std::vector<int> monotone_minima(int n, int m, const\
    \ Select& select) {\n    std::vector<int> res(n);\n    auto dfs = [&](auto self,\
    \ int u, int d, int l, int r) -> void {\n        if (u == d) return;\n       \
    \ int m = (u + d) >> 1;\n        int argmin = l;\n        for (int col = l + 1;\
    \ col < r; col++) {\n            if (select(m, argmin, col)) {\n             \
    \   argmin = col;\n            }\n        }\n        res[m] = argmin;\n      \
    \  self(self, u, m, l, argmin + 1);\n        self(self, m + 1, d, argmin, r);\n\
    \    };\n    dfs(dfs, 0, n, 0, m);\n    return res;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class Select> std::vector<int>\
    \ monotone_minima(int n, int m, const Select& select) {\n    std::vector<int>\
    \ res(n);\n    auto dfs = [&](auto self, int u, int d, int l, int r) -> void {\n\
    \        if (u == d) return;\n        int m = (u + d) >> 1;\n        int argmin\
    \ = l;\n        for (int col = l + 1; col < r; col++) {\n            if (select(m,\
    \ argmin, col)) {\n                argmin = col;\n            }\n        }\n \
    \       res[m] = argmin;\n        self(self, u, m, l, argmin + 1);\n        self(self,\
    \ m + 1, d, argmin, r);\n    };\n    dfs(dfs, 0, n, 0, m);\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/optimization/monotone_minima.hpp
  requiredBy:
  - src/convolution/min_plus_convolution_convex_arbitrary.hpp
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: src/optimization/monotone_minima.hpp
layout: document
title: Monotone Minima
---

## 概要
totally monotone な $N \times M$ 行列 $A$ を入力として，各 $i$ について $\underset{j}{\operatorname{argmin}}\ A_{i, j}$ を $\mathrm{O}(N + M \log N)$ 時間で求める．
実装中の関数 `select(i, j, k)` は $j < k$ が保証されているもとで，$A_{i, j}$ よりも $A_{i, k}$ が好ましいとされる場合に `true` を，そうでないときは `false` を返す関数である．

計算量は SMAWK algorithm に劣るが，定数倍の関係上実用的には SMAWK algorithm より高速なケースが多い．