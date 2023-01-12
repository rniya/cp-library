---
title: Subset Sum（部分和問題）$O(NS)$
documentation_of: ./SubsetSum.hpp
---

## 概要
$N$ 個の整数 $a_0, a_1, \dots , a_{N - 1}$ と整数 $S$ について，$I \subseteq \{0, 1, \dots, N - 1\}$ で $\sum_{i \in I} a_i = S$ なるものの存在判定及び構成を時間計算量 $O(NS)$ 及び空間計算量 $O(S)$ に 64 倍高速化を施して行う．
$S \sim a_{\max}$ の際に実用的である．

## 問題例
- [Codeforces Round #207 (Div. 1) D. Bags and Coins](https://codeforces.com/contest/356/problem/D)
