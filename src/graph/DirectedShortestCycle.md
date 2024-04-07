---
title: Directed Shortest Cycle
documentation_of: ./DirectedShortestCycle.hpp
---

## 概要

| メンバ関数                 | 効果                                                        | 時間計算量             |
| -------------------------- | ----------------------------------------------------------- | ---------------------- |
| `DirectedShortestCycle(n)` | $n$ 頂点 $0$ 辺のグラフとして初期化する．                   | $\mathrm{O}(n)$        |
| `add_edge(u, v, w)`        | 頂点 $u$ から $v$ への重み $w$ の有向辺を追加する．         | $\mathrm{O}(1)$        |
| `solve(r)`                 | 頂点 $r$ を含む最小重みサイクルの周長，頂点列，辺列を返す． | $\mathrm{O}(m \log n)$ |


## 問題例
- [AtCoder Beginner Contest 308 Ex - Make Q](https://atcoder.jp/contests/abc308/tasks/abc308_h)
