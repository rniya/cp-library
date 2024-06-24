---
title: Subset Sum $\mathrm{O}(NS), \mathrm{O}(N a _ {\max})$
documentation_of: ./SubsetSum.hpp
---

## 概要
$N$ 個の整数 $a _ 0, a _ 1, \dots , a _ {N - 1}$ と整数 $S$ について，$I \subseteq \{0, 1, \dots, N - 1\}$ で $\sum _ {i \in I} a_i = S$ なるものの存在判定及び構成を

- 時間計算量 $O(NS)$ 及び空間計算量 $O(S)$ に 64 倍高速化を施して
- 時間・空間計算量 $O(N a _ {\max})$

で行う．
前者は $S \sim a _ {\max}$、後者は $S \sim N a _ {\max}$ の際に実用的である．

## 出題例
- [Codeforces Round #207 (Div. 1) D. Bags and Coins](https://codeforces.com/contest/356/problem/D)
- [AtCoder Beginner Contest 221 G - Jumping sequence](https://atcoder.jp/contests/abc221/tasks/abc221_g)
