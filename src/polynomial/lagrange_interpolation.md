---
title: Lagrange Interpolation
documentation_of: ./lagrange_interpolation.hpp
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