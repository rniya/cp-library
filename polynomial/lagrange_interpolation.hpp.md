---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/binomial.hpp
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
  bundledCode: "#line 2 \"polynomial/lagrange_interpolation.hpp\"\n#include <vector>\n\
    #line 2 \"combinatorics/binomial.hpp\"\n#include <cassert>\n#line 4 \"combinatorics/binomial.hpp\"\
    \n\ntemplate <typename T> struct Binomial {\n    Binomial(int MAX = 0) : n(1),\
    \ facs(1, T(1)), finvs(1, T(1)), invs(1, T(1)) {\n        while (n <= MAX) extend();\n\
    \    }\n\n    T fac(int i) {\n        assert(i >= 0);\n        while (n <= i)\
    \ extend();\n        return facs[i];\n    }\n\n    T finv(int i) {\n        assert(i\
    \ >= 0);\n        while (n <= i) extend();\n        return finvs[i];\n    }\n\n\
    \    T inv(int i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n\
    \        return invs[i];\n    }\n\n    T P(int n, int r) {\n        if (n < 0\
    \ || n < r || r < 0) return T(0);\n        return fac(n) * finv(n - r);\n    }\n\
    \n    T C(int n, int r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n\
    \        return fac(n) * finv(n - r) * finv(r);\n    }\n\n    T H(int n, int r)\
    \ {\n        if (n < 0 || r < 0) return T(0);\n        return r == 0 ? 1 : C(n\
    \ + r - 1, r);\n    }\n\n    T C_naive(int n, int r) {\n        if (n < 0 || n\
    \ < r || r < 0) return T(0);\n        T res = 1;\n        r = std::min(r, n -\
    \ r);\n        for (int i = 1; i <= r; i++) res *= inv(i) * (n--);\n        return\
    \ res;\n    }\n\nprivate:\n    int n;\n    std::vector<T> facs, finvs, invs;\n\
    \n    inline void extend() {\n        int m = n << 1;\n        facs.resize(m);\n\
    \        finvs.resize(m);\n        invs.resize(m);\n        for (int i = n; i\
    \ < m; i++) facs[i] = facs[i - 1] * i;\n        finvs[m - 1] = T(1) / facs[m -\
    \ 1];\n        invs[m - 1] = finvs[m - 1] * facs[m - 2];\n        for (int i =\
    \ m - 2; i >= n; i--) {\n            finvs[i] = finvs[i + 1] * (i + 1);\n    \
    \        invs[i] = finvs[i] * facs[i - 1];\n        }\n        n = m;\n    }\n\
    };\n#line 4 \"polynomial/lagrange_interpolation.hpp\"\n\n/**\n * @brief Lagrange\
    \ Interpolation of polynomial f of degree n\n *\n * @tparam T F_p\n * @param y\
    \ f(0), f(1), ... , f(n)\n * @param x you want to calculate f(x)\n * @return T\
    \ f(x)\n */\ntemplate <typename T> T lagrange_interpolation(const std::vector<T>&\
    \ y, long long x, Binomial<T>& BINOM) {\n    int n = y.size() - 1;\n    if (x\
    \ <= n) return y[x];\n    std::vector<T> left(n + 1, 1), right(n + 1, 1);\n  \
    \  for (int i = 0; i < n; i++) left[i + 1] = left[i] * (x - i);\n    for (int\
    \ i = n; i > 0; i--) right[i - 1] = right[i] * (x - i);\n    T res = 0;\n    for\
    \ (int i = 0; i <= n; i++) {\n        T add = y[i] * left[i] * right[i] * BINOM.finv(i)\
    \ * BINOM.finv(n - i);\n        res += ((n - i) & 1) ? -add : add;\n    }\n  \
    \  return res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"combinatorics/binomial.hpp\"\n\
    \n/**\n * @brief Lagrange Interpolation of polynomial f of degree n\n *\n * @tparam\
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
  - combinatorics/binomial.hpp
  isVerificationFile: false
  path: polynomial/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2022-10-23 23:11:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/665.test.cpp
documentation_of: polynomial/lagrange_interpolation.hpp
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
