---
title: Tree Diameter
documentation_of: //src/tree/TreeDiameter.hpp
---

## 概要

木の直径を計算するライブラリ．

| メンバ関数            | 効果                                                                                                                       | 時間計算量      |
| --------------------- | -------------------------------------------------------------------------------------------------------------------------- | --------------- |
| `TreeDiameter(n)`     | 頂点数 $n$ の木として初期化する．                                                                                          | $\mathrm{O}(n)$ |
| `add_edge(u, b)`      | 辺 $(u,v)$ を追加する．                                                                                                    | $\mathrm{O}(1)$ |
| `get_diameter_path()` | 木の直径の長さとそのパスをペアにして返す．                                                                                 | $\mathrm{O}(n)$ |
| `farthest_distance()` | 各頂点から最も遠い頂点までの距離を返す．この最も遠い頂点は直径を構成する端点のどちらかであることが直径の最長性から示せる． | $\mathrm{O}(n)$ |

## 出題例
- [Codeforces Round #292 (Div. 1) D. Drazil and Morning Exercise](https://codeforces.com/contest/516/problem/D)
- [AtCoder Regular Contest 108 F - Paint Tree](https://atcoder.jp/contests/arc108/tasks/arc108_f)
