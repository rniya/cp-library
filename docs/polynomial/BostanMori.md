---
title: Bostan-Mori Algorithm
documentation_of: //src/polynomial/BostanMori.hpp
---

## `BontanMori(Q, P, N)`

### 入力

$d$ 次多項式 $Q$ 及び高々 $d - 1$ 次の多項式 $P$，整数 $N$．

### 出力

$$
\lbrack x^N \rbrack \frac{P(x)}{Q(x)}.
$$

### 計算量

時間計算量 $\mathrm{O}(d \log d \log N)$

## `LinearRecurrence(a, c, N)`

### 入力

線型漸化式

$$
a _ i = \sum _ {j = 1} ^ d c _ j a _{i - j}
$$

を満たす数列 $a$ の初めの $d$ 項 $a _ 0, \dots , a _ {d - 1}$ 及び係数列 $c _ 1, \dots , c _ d$，整数 $N$．

### 出力

数列 $a$ の第 $N$ 項 $a _ N$ の値．

### 計算量

時間計算量 $\mathrm{O}(d \log d \log N)$

## 概要
アルゴリズムの詳細については Links にあるページがわかりやすい．
ここでは `LinearRecurrence(a, c, N)` から `BostanMori(Q, P, N)` への帰着について説明する．

$d + 1$ 項間漸化式

$$
a _ i = \sum _ {j = 1} ^ d c _ j a _ {i - j}
$$

について，その数列の母関数を

$$
G(x) = \sum _ {i = 0} ^ \infty a _ i x ^ i
$$

とし，また

$$
Q(x) = 1 - \sum _ {i = 1}^d c _ i x ^ i
$$

と定めるとき，$G(x) Q(x)$ は漸化式の定義より高々 $d - 1$ 次の多項式 $P(x)$ に一致する．
以上より，

$$
a _ N = \lbrack x ^ N \rbrack \frac{P(x)}{Q(x)}
$$

となり，これは $\mathrm{O}(d \log d \log N)$ で計算することが可能である．

## 出題例
- [競プロ典型 90 問 090 - Tenkei90's Last Problem](https://atcoder.jp/contests/typical90/tasks/typical90_cl)
- [AtCoder Beginner Contest 241 Ex - Card Deck Score](https://atcoder.jp/contests/abc241/tasks/abc241_h)
- [AtCoder Beginner Contest 300 Ex - Fibonacci: Revisited](https://atcoder.jp/contests/abc300/tasks/abc300_h)

## Links
- [線形漸化式を満たす数列の N 項目を計算するアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)
