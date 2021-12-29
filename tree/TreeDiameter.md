---
title: Tree Diameter
documentation_of: ./TreeDiameter.hpp
---

## 概要
木の直径を計算するライブラリ.

| メンバ関数            | 効果                                                                                                                      | 時間計算量 |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------- | ---------- |
| `TreeDiameter(n)`     | 頂点数 $n$ の木として初期化する.                                                                                          | $O(n)$     |
| `add_edge(u, b)`      | 辺 $(u,v)$ を追加する.                                                                                                    | $O(1)$     |
| `get_diameter_path()` | 木の直径の長さとそのパスをペアにして返す.                                                                                 | $O(n)$     |
| `farthest_distance()` | 各頂点から最も遠い頂点までの距離を返す. この最も遠い頂点は直径を構成する端点のどちらかであることが直径の最長性から示せる. | $O(n)$     |

## 問題例
- [AtCoder Regular Contest 108 F - Paint Tree](https://atcoder.jp/contests/arc108/tasks/arc108_f)
- [Codeforces Round #292 (Div. 1) D. Drazil and Morning Exercise](https://codeforces.com/contest/516/problem/D)
