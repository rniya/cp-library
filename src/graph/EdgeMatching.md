---
title: Edge Matching
documentation_of: ./EdgeMatching.hpp
---

## 概要
一般グラフ $G(V, E)$ において、端点を共有する辺同士の最大マッチングを構成する．

| メンバ関数        | 効果                                                                                 | 時間計算量          |
| ----------------- | ------------------------------------------------------------------------------------ | ------------------- |
| `EdgeMatching(n)` | 頂点数 $n$ のグラフとして初期化する．                                                | $\mathrm{O}(n)$     |
| `add_edge(u, v)`  | 頂点 $u$ と頂点 $v$ を結ぶ辺を追加する．                                             | $\mathrm{O}(1)$     |
| `build()`         | 最大マッチングを求める．ここで辺 $i$ は `add_edge` で $i$ 番目に追加された辺である． | $\mathrm{O}(n + m)$ |



## 問題例
- [AtCoder Regular Contest 045 D - みんな仲良し高橋君](https://atcoder.jp/contests/arc045/tasks/arc045_d)
- [The 1st Universal Cup. Stage 0: Nanjing (Trial Contest) J. Perfect Matching](https://qoj.ac/contest/1093/problem/5423)
- [The 1st Universal Cup. Stage 16: Gomel H. Classical Maximization Problem](https://qoj.ac/contest/1223/problem/6414?v=1)