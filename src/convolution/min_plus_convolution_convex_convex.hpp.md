---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_plus_convolution_convex_convex.test.cpp
    title: test/yosupo/min_plus_convolution_convex_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/convolution/min_plus_convolution_convex_convex.hpp\"\
    \n#include <cassert>\n#include <vector>\n\ntemplate <typename T>\nstd::vector<T>\
    \ min_plus_convolution_convex_convex(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = a.size(), m = b.size();\n    assert(n and m);\n    for (int\
    \ i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);\n   \
    \ for (int i = 0; i + 2 < m; i++) assert(b[i + 1] - b[i] <= b[i + 2] - b[i + 1]);\n\
    \    std::vector<T> c(n + m - 1);\n    c[0] = a[0] + b[0];\n    for (int i = 0,\
    \ j = 0, k = 1; k < n + m - 1; k++) {\n        if (j == m - 1 or (i < n - 1 and\
    \ a[i + 1] + b[j] < a[i] + b[j + 1]))\n            c[k] = a[++i] + b[j];\n   \
    \     else\n            c[k] = a[i] + b[++j];\n    }\n    return c;\n}\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate <typename T>\nstd::vector<T>\
    \ min_plus_convolution_convex_convex(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = a.size(), m = b.size();\n    assert(n and m);\n    for (int\
    \ i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);\n   \
    \ for (int i = 0; i + 2 < m; i++) assert(b[i + 1] - b[i] <= b[i + 2] - b[i + 1]);\n\
    \    std::vector<T> c(n + m - 1);\n    c[0] = a[0] + b[0];\n    for (int i = 0,\
    \ j = 0, k = 1; k < n + m - 1; k++) {\n        if (j == m - 1 or (i < n - 1 and\
    \ a[i + 1] + b[j] < a[i] + b[j + 1]))\n            c[k] = a[++i] + b[j];\n   \
    \     else\n            c[k] = a[i] + b[++j];\n    }\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/min_plus_convolution_convex_convex.hpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/min_plus_convolution_convex_convex.test.cpp
documentation_of: src/convolution/min_plus_convolution_convex_convex.hpp
layout: document
title: Min Plus Convolution (Convex and Convex)
---

## 入力

数列 $a, b$ 

ここで数列 $a, b$ はどちらも下に凸である．
すなわち，任意の $0 \leq i \lt N - 2$ に対して $a _ {i + 1} - a _ i \leq a _ {i + 2} - a _ {i + 1},\ b _ {i + 1} - b _ i \leq b _ {i + 2} - b _ {i + 1}$ が成立する．

2 つの数列の長さをそれぞれ $n, m$ とする．

## 出力

数列 $a$ と $b$ の畳み込み．
すなわち，
$$
c _ k = \min _ {i + j = k} (a _ i + b _ j)
$$
で定義される長さ $n + m - 1$ の数列 $c$．

## 計算量

時間計算量 $\mathrm{O}(n + m)$

## 概要

線分の傾きをマージすることで $\mathrm{O}(n + m)$ 時間で計算可能である．
また，畳み込んでできる数列 $c$ も凸である．
