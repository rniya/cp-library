---
title: Lagrange Interpolation
documentation_of: ./lagrange_interpolation.hpp
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