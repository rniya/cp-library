---
title: オイラー路の構築
documentation_of: ./EulerianTrail.hpp
---

## 概要
有向/無向グラフが与えられたときに, オイラー路/準オイラー路を構築するライブラリ.

| メンバ関数         | 効果                                                                              | 時間計算量 |
| ------------------ | --------------------------------------------------------------------------------- | ---------- |
| `EulerianTrail(n)` | n 頂点のグラフとして初期化する.                                                   | $O(n)$     |
| `add_edge(u, v)`   | 辺 $(u, v)$ を追加する.                                                           | $O(1)$     |
| `solve()`          | 連結成分ごとにオイラー路を構築する. 存在しない連結成分がある場合には空配列を返す. | $O(n + m)$ |
| `solve_semi()`     | 連結成分ごとに準オイラーを構築する. 存在しない連結成分がある場合には空配列を返す. | $O(n + m)$ |
| `operator[k]`      | $k$ 番目に追加された辺の情報を返す.                                               | $O(1)$     |

### Remark
`solve()` や `solve_semi()` が返すのは頂点番号ではなく辺番号であるので注意.

## 計算量
どれも$O(V+E)$

## 問題例
- [Codeforces Round #647 (Div. 1) - Thanks, Algo Muse! C. Johnny and Megan's Necklace](https://codeforces.com/contest/1361/problem/C)
  - 無向グラフにおけるオイラー路の復元.

## 参照
- [競プロにおけるオイラー路とその応用について - Learning Algorithms](https://kokiymgch.hatenablog.com/entry/2017/12/07/193238)
