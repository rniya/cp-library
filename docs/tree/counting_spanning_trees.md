---
title: Counting Spanning Trees
documentation_of: //src/tree/counting_spanning_trees.hpp
---

## `counting_spanning_trees_undirected`

### 入力

$n$ 頂点の無向グラフ $G$ に対する隣接行列（すなわち，第 $(i, j)$ 成分が頂点 $i, j$ を結ぶ辺の本数に等しいような行列）．

### 出力

グラフの全域木の個数．

### 計算量

$\mathrm{O}(n ^ 3)$

## `counting_spanning_trees_directed`

### 入力

$n$ 頂点の有向グラフ $G$ に対する隣接行列（すなわち，第 $(i, j)$ 成分が頂点 $i$ から $j$ に向かう辺の本数に等しいような行列）及び頂点 $r$．

### 出力

根を $r$ とする（全ての頂点から根に到達できる）有向全域木の個数．

### 計算量

$\mathrm{O}(n ^ 3)$

## 概要

行列木定理より，ラプラシアン行列の行列式計算に帰着される．

## Links
- [行列木定理の証明 - blogoid](https://mizuwater0.hatenablog.com/entry/2018/11/25/233547)

## 出題例
- [AtCoder Beginner Contest 323 G - Inversion of Tree](https://atcoder.jp/contests/abc323/tasks/abc323_g)
- [AtCoder Beginner Contest 336 G - 16 Integers](https://atcoder.jp/contests/abc336/tasks/abc336_g)
  - BEST Theorem の中で有向全域木の個数を求める必要が生じる．