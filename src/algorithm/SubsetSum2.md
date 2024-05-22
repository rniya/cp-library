---
title: Subset Sum $O(Na_{\max})$
documentation_of: ./SubsetSum2.hpp
---

## 概要
$N$ 個の整数 $a_0, a_1, \dots , a_{N - 1}$ と整数 $S$ について，$I \subseteq \{0, 1, \dots, N - 1\}$ で $\sum_{i \in I} a_i = S$ なるものの存在判定及び構成を時間計算量及び空間計算量 $O(Na_{\max})$ で行う．
$S \sim Na_{\max}$ の際に実用的である．

## 問題例
- [AtCoder Beginner Contest 221 G - Jumping sequence](https://atcoder.jp/contests/abc221/tasks/abc221_g)
