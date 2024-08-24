---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/binomial.hpp
    title: Binomial Coefficients
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/polynomial/lagrange_interpolation.hpp\"\n#include <vector>\n\
    #line 2 \"src/math/binomial.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #line 5 \"src/math/binomial.hpp\"\n\ntemplate <typename T> struct Binomial {\n\
    \    Binomial(int MAX = 0) : n(1), facs(1, T(1)), finvs(1, T(1)), invs(1, T(1))\
    \ {\n        assert(T::mod() != 0);\n        if (MAX > 0) extend(MAX + 1);\n \
    \   }\n\n    T fac(int i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n\
    \        return facs[i];\n    }\n\n    T finv(int i) {\n        assert(i >= 0);\n\
    \        while (n <= i) extend();\n        return finvs[i];\n    }\n\n    T inv(int\
    \ i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n        return\
    \ invs[i];\n    }\n\n    T P(int n, int r) {\n        if (n < 0 || n < r || r\
    \ < 0) return T(0);\n        return fac(n) * finv(n - r);\n    }\n\n    T C(int\
    \ n, int r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n        return\
    \ fac(n) * finv(n - r) * finv(r);\n    }\n\n    T H(int n, int r) {\n        if\
    \ (n < 0 || r < 0) return T(0);\n        return r == 0 ? 1 : C(n + r - 1, r);\n\
    \    }\n\n    T C_naive(int n, int r) {\n        if (n < 0 || n < r || r < 0)\
    \ return T(0);\n        T res = 1;\n        r = std::min(r, n - r);\n        for\
    \ (int i = 1; i <= r; i++) res *= inv(i) * (n--);\n        return res;\n    }\n\
    \n  private:\n    int n;\n    std::vector<T> facs, finvs, invs;\n\n    inline\
    \ void extend(int m = -1) {\n        if (m == -1) m = n * 2;\n        m = std::min(m,\
    \ T::mod());\n        if (n >= m) return;\n        facs.resize(m);\n        finvs.resize(m);\n\
    \        invs.resize(m);\n        for (int i = n; i < m; i++) facs[i] = facs[i\
    \ - 1] * i;\n        finvs[m - 1] = T(1) / facs[m - 1];\n        invs[m - 1] =\
    \ finvs[m - 1] * facs[m - 2];\n        for (int i = m - 2; i >= n; i--) {\n  \
    \          finvs[i] = finvs[i + 1] * (i + 1);\n            invs[i] = finvs[i]\
    \ * facs[i - 1];\n        }\n        n = m;\n    }\n};\n#line 4 \"src/polynomial/lagrange_interpolation.hpp\"\
    \n\ntemplate <typename T> T lagrange_interpolation(const std::vector<T>& y, long\
    \ long x, Binomial<T>& BINOM) {\n    int n = y.size() - 1;\n    if (0 <= x and\
    \ x <= n) return y[x];\n    std::vector<T> left(n + 1, 1), right(n + 1, 1);\n\
    \    for (int i = 0; i < n; i++) left[i + 1] = left[i] * (x - i);\n    for (int\
    \ i = n; i > 0; i--) right[i - 1] = right[i] * (x - i);\n    T res = 0;\n    for\
    \ (int i = 0; i <= n; i++) {\n        T add = y[i] * left[i] * right[i] * BINOM.finv(i)\
    \ * BINOM.finv(n - i);\n        res += ((n - i) & 1) ? -add : add;\n    }\n  \
    \  return res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../math/binomial.hpp\"\n\ntemplate\
    \ <typename T> T lagrange_interpolation(const std::vector<T>& y, long long x,\
    \ Binomial<T>& BINOM) {\n    int n = y.size() - 1;\n    if (0 <= x and x <= n)\
    \ return y[x];\n    std::vector<T> left(n + 1, 1), right(n + 1, 1);\n    for (int\
    \ i = 0; i < n; i++) left[i + 1] = left[i] * (x - i);\n    for (int i = n; i >\
    \ 0; i--) right[i - 1] = right[i] * (x - i);\n    T res = 0;\n    for (int i =\
    \ 0; i <= n; i++) {\n        T add = y[i] * left[i] * right[i] * BINOM.finv(i)\
    \ * BINOM.finv(n - i);\n        res += ((n - i) & 1) ? -add : add;\n    }\n  \
    \  return res;\n}\n"
  dependsOn:
  - src/math/binomial.hpp
  isVerificationFile: false
  path: src/polynomial/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2024-06-24 16:39:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/665.test.cpp
documentation_of: src/polynomial/lagrange_interpolation.hpp
layout: document
title: Lagrange Interpolation
---

## 入力

$N$ 次多項式 $f$ の評価値 $f(0), f(1), \dots , f(N)$ 及び整数 $T$．

## 出力

$f(T)$．

## 計算量

時間計算量 $\mathrm{O}(N)$

## 概要
$x _ i$ が相異なりかつ $f(x _ i) = y _ i$ を満たすような組 $(x _ 0, y _ 0), (x _ 1, y _ 1), \dots , (x _ N, y _ N)$ が与えられるとき，これを満たす多項式 $f$ は一意に定まる．
具体的には，

$$
f _ i(x) = \prod _ {j \neq i} (x - x _ j) = \frac{\prod _ j (x - x _ j)}{x - x _ i}
$$

として，

$$
f(x) = \sum _ {i = 0} ^ n y _ i \frac{f _ i(x)}{f _ i(x _ i)}
$$

とすることで復元可能である．
一般の場合には $\mathrm{O}(N ^ 2)$ で $f$ の各項の係数を計算可能であるが，特に $\lbrace x _ i \rbrace$ が等差数列を成す場合には，

$$
f _ {i + 1}(x _ {i + 1}) = \prod _ {j \neq i} (x _ {i + 1} - x _ j) = f _ i(x _ i) \frac{x _ {i + 1} - x _ 0}{x _ i - x _ N}
$$

を利用して $f _ i(x _ i)$ から $f _ {i + 1}(x _ {i + 1})$ を適切な前計算の元 $\mathrm{O}(1)$ で計算可能なので，任意の $T$ に対する $f(T)$ を全体 $\mathrm{O}(N)$ で計算することができる．
$x _ i = i$ の場合には階乗前計算のもとでより簡単に計算することもできる．

## 出題例
- [AtCoder Beginner Contest 208 F - Cumulative Sum](https://atcoder.jp/contests/abc208/tasks/abc208_f)
- [Codeforces Round #869 (Div. 1) C. Similar Polynomials](https://codeforces.com/contest/1817/problem/C)