---
title: Functional Graph
documentation_of: ./FunctionalGraph.hpp
---

## 概要
Functional Graph とは各頂点の出次数が丁度 $1$ であるような有向グラフのことを指す．
グラフはいくつかのループをもち，全体として各ループを根とするような森となる．
`visit[v]` は $v$ が $i$ (0-indexed) 番目のループ上にあるなら $i + 1$，ループ上になく $i$ 番目のループにたどり着く場合には $- (i + 1)$ を格納する．
`G` はループ上の頂点から葉へ向かう逆方向の森である．

## 問題例
- [AtCoder Beginner Contest 296 E - Transition Game](https://atcoder.jp/contests/abc296/tasks/abc296_e)