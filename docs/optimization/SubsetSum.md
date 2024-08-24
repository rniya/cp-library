---
title: Subset Sum $\mathrm{O}(NS), \mathrm{O}(N a _ {\max})$
documentation_of: //src/optimization/SubsetSum.hpp
---

## 入力

$N$ 個の非負整数 $a _ 0, a _ 1, \dots , a _ {N - 1}$ 及び整数 $S$．

## 出力

$\sum _ {i \in I} a _ i = S$ となる $I \subseteq \lbrace 0, 1, \dots , N - 1 \rbrace$ のうち 1 つ（存在しない場合は空配列を返す）．

## 計算量

- `SubsetSum1`: ワードサイズを $w$ として時間計算量 $\mathrm{O}\left( \frac{N S}{w} \right)$
- `SubsetSum2`: 時間計算量 $\mathrm{O}(N a _ {\max})$

## 出題例
- [Codeforces Round #207 (Div. 1) D. Bags and Coins](https://codeforces.com/contest/356/problem/D)
- [AtCoder Beginner Contest 221 G - Jumping sequence](https://atcoder.jp/contests/abc221/tasks/abc221_g)
