---
title: 補グラフ上の最短路
documentation_of: ./complement_graph_shortest_path.hpp
---


## 概要
補グラフ上の頂点 $s$ から各点までの最短経路長を $\mathrm{O}(n + m)$ 時間で求める（ここで、$m$ は元のグラフの辺数）．

補グラフは特に以下のような性質をもつ．
- 各点までの最短路の距離は $\mathrm{O}(\sqrt{m})$ である．
  - ある点までの距離が $d$ とすると、最短経路においてその直前の点を除いた $d - 1$ 点と隣接している必要があることからわかる．
- 各点までの最短路の距離の合計は $\mathrm{O}(n + m)$ である．
  - BFS 木で親の親以上の点に対しては元のグラフで辺が貼られている必要がある．
- もとのグラフが非連結ならばその補グラフは連結．

## Links
- https://twitter.com/noshi91/status/1383110660796518401?s=20&t=6NELIs3eDe0fVQxuwfwvow

## 問題例
- [BPC 1 S5 - Temple](https://dmoj.ca/problem/bpc1s5)
- [Educational Codeforces Round 142 (Rated for Div. 2) F2. Graph Coloring (hard version)](https://codeforces.com/contest/1792/problem/F2)
- [AtCoder Beginner Contest 319 G - Counting Shortest Paths](https://atcoder.jp/contests/abc319/tasks/abc319_g)
