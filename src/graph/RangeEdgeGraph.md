---
title: Range Edge Graph
documentation_of: ./RangeEdgeGraph.hpp
---

## 概要
区間から区間に辺が伸びるようなグラフ上での最短路を計算する. Segment Treeの構造を利用して頂点数$3n+q$, 辺数$4n+q\log n$のグラフを構成している.

- 'add_edge(l1, r1, l2, r2, cost)'：$[l1,r1)$から$[l2,r2)$に対して伸びる重み$cost$の辺を追加する.
- 'build(s)'：$s$を始点にしたときの各点までの最短距離を計算する.

## 計算量
- 'add_edge(l1, r1, l2, r2, cost)'：$O(\log n)$
- 'build(s)'：$O(n+q\log n)\log(n+q)$

## 参照
[区間に辺を張るテクの実装例（Dijkstra法セット）と使用例 - Lorent’s diary](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)

## 問題例
- [The 1st Universal Cup. Stage 3: Poland F. Flower Garden](https://qoj.ac/contest/1103/problem/5504?v=1)