---
title: Bostan-Mori Algorithm
documentation_of: ./BostanMori.hpp
---

## 概要
線形漸化式の $N$ 項目を高速に計算するアルゴリズム．アルゴリズムの詳細については Links にあるページがわかりやすい．$d + 1$ 項間漸化式

$$a_n = \sum_{i = 1}^d c_ia_{n - i}$$

について，その数列の母関数を

$$G(x) = \sum_{i = 0}^\infty a_ix^i$$

とし，また

$$Q(x) = 1 - \sum_{i = 1}^d c_ix^i$$

と定めるとき，$G(x)Q(x)$ は漸化式の定義より高々 $d - 1$ 次の多項式 $P(x)$ に一致する．以上より，

$$a_N = [x^N] \frac{P(x)}{Q(x)}$$

となり，これは $O(d \log d \log N)$ で計算することが可能である．

## TODO
高速化

## 問題例
- [競プロ典型 90 問 090 - Tenkei90's Last Problem](https://atcoder.jp/contests/typical90/tasks/typical90_cl)

## Links
- [線形漸化式を満たす数列の N 項目を計算するアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)
