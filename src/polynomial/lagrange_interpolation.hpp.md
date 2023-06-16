---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/binomial.hpp
    title: binomial
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Lagrange Interpolation of polynomial f of degree n
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/binomial.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <vector>\n#include \"math/binomial.hpp\"\n\n/**\n\
    \ * @brief Lagrange Interpolation of polynomial f of degree n\n *\n * @tparam\
    \ T F_p\n * @param y f(0), f(1), ... , f(n)\n * @param x you want to calculate\
    \ f(x)\n * @return T f(x)\n */\ntemplate <typename T> T lagrange_interpolation(const\
    \ std::vector<T>& y, long long x, Binomial<T>& BINOM) {\n    int n = y.size()\
    \ - 1;\n    if (x <= n) return y[x];\n    std::vector<T> left(n + 1, 1), right(n\
    \ + 1, 1);\n    for (int i = 0; i < n; i++) left[i + 1] = left[i] * (x - i);\n\
    \    for (int i = n; i > 0; i--) right[i - 1] = right[i] * (x - i);\n    T res\
    \ = 0;\n    for (int i = 0; i <= n; i++) {\n        T add = y[i] * left[i] * right[i]\
    \ * BINOM.finv(i) * BINOM.finv(n - i);\n        res += ((n - i) & 1) ? -add :\
    \ add;\n    }\n    return res;\n}\n"
  dependsOn:
  - src/math/binomial.hpp
  isVerificationFile: false
  path: src/polynomial/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2023-05-21 16:36:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/665.test.cpp
documentation_of: src/polynomial/lagrange_interpolation.hpp
layout: document
title: Lagrange Interpolation
---

## 概要
$n$ 次以下の多項式 $f$ について，$x_i$ が相異なりかつ $f(x_i) = y_i$ を満たすような組 $(x_i, y_i)$ が $n + 1$ 個与えられるとき，このような多項式 $f$ は一意に定まる．
このもとで任意の $x$ に対して $f(x)$ を求める．

具体的には，

$$f_i(x) = \prod_{j \neq i} (x - x_j) = \frac{\prod_j (x - x_j)}{x - x_i}$$

として，

$$f(x) = \sum_{i = 0}^n y_i \frac{f_i(x)}{f_i(x_i)}$$

とすることで復元可能である．
一般の場合には $O(n^2)$ で $f$ の各項の係数を計算可能であるが，特に $\{x_i\}$ が等差数列を成す場合には，

$$f_{i + 1}(x_{i + 1}) = \prod_{j \neq i} (x_{i + 1} - x_j) = f_i(x_i) \frac{x_{i + 1} - x_0}{x_i - x_n}$$

を利用して $f_i(x_i)$ から $f_{i + 1}(x_{i + 1})$ を適切な前計算の元 $O(1)$ で計算可能なので，任意の $x$ に対する $f(x)$ を全体 $O(n)$ で計算することができる．
$x_i = i$ の場合には階乗前計算の元より簡単に計算することもできる．

## 問題例
- [AtCoder Beginner Contest 208 F - Cumulative Sum](https://atcoder.jp/contests/abc208/tasks/abc208_f)
- [Codeforces Round #869 (Div. 1) C. Similar Polynomials](https://codeforces.com/contest/1817/problem/C)