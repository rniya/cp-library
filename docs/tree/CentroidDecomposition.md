---
title: Centroid Decomposition
documentation_of: //src/tree/CentroidDecomposition.hpp
---

## 概要

木の重心分解を扱う．

| メンバ関数                 | 効果                              | 時間計算量             |
| -------------------------- | --------------------------------- | ---------------------- |
| `CentroidDecomposition(n)` | 頂点数 $n$ の木として初期化する． | $\mathrm{O}(n)$        |
| `add_edge(u, v)`           | 辺 $(u, v)$ を追加する．          | $\mathrm{O}(1)$        |
| `build()`                  | 重心分解を構築する（後述）        | $\mathrm{O}(n \log n)$ |

木の重心とは，その頂点を取り除いて残るすべての部分木のうち最大のものの頂点数が最小になる頂点である．
特に嬉しいのは，重心を取り除いて残るすべての部分木の頂点数がもとの木の頂点数の半分以下になっているという性質で，これにより再帰の深さは $\mathrm{O}(\log n)$ で抑えられる．
各深さ帯においての処理に $\mathrm{O}(n)$ かけてもよく，現在の部分木の頂点を全探索するといったことも行える．
このためパスの数え上げ等の問題によく用いられる手法である．

メンバ関数 `build()` はもとの木を重心分解していく過程における重心を dfs-order に列挙する．
これをもとにまた別に重心を潰しながら探索していくのが良い．

## 出題例
- [COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred) E. Eye-Pleasing City Park Tour](https://codeforces.com/contest/1575/problem/E)
  - 頂点に重みがついた，距離 $k$ 以下のパスの重みの総和の数え上げ．
- [AtCoder Regular Contest 087 F - Squirrel Migration](https://atcoder.jp/contests/arc087/tasks/arc087_d)
  - 直接重心分解を用いる訳ではないが重心の性質を利用する．
- [Starters 83 Beauty Sum](https://www.codechef.com/problems/BEAUTY_SUM?tab=statement)
