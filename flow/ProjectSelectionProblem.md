---
title: Project Selection Problem (based on ac-library)
documentation_of: ./ProjectSelectionProblem.hpp
---

## 概要
Project Selection Problem，いわゆる燃やす埋める問題を解く際の補助ライブラリ．

| メンバ関数                        | 効果                                           | 時間計算量 |
| --------------------------------- | ---------------------------------------------- | ---------- |
| `ProjectSelectionProblem(n)`      | 頂点数 $n$ のグラフとして初期化する．          | $O(n)$     |
| `x_false_loss(x, z)`              | $x$ が $0$ のときに $z$ 失う．                 | $O(1)$     |
| `x_false_profit(x, z)`            | $x$ が $0$ のときに $z$ 得る．                 | $O(1)$     |
| `x_true_loss(x, z)`               | $x$ が $1$ のときに $z$ 失う．                 | $O(1)$     |
| `x_true_profit(x, z)`             | $x$ が $1$ のときに $z$ 得る．                 | $O(1)$     |
| `x_false_y_true_loss(x, y, z)`    | $x$ が $0$ かつ $y$ が $1$ のときに $z$ 失う． | $O(1)$     |
| `x_true_y_false_loss(x, y, z)`    | $x$ が $1$ かつ $y$ が $0$ のときに $z$ 失う． | $O(1)$     |
| `x_false_y_false_profit(x, y, z)` | $x$ が $0$ かつ $y$ が $0$ のときに $z$ 得る． | $O(1)$     |
| `x_true_y_true_profit(x, y, z)`   | $x$ が $1$ かつ $y$ が $1$ のときに $z$ 得る． | $O(1)$     |
| `min_loss()`                      | 損失の最小値を返す．                           | $O(n^2m)$  |
| `max_profit()`                    | 利得の最大値を返す．                           | $O(n^2m)$  |

一般にこれ以外の条件に対応する際には 2 部グラフなどの制約が必要になる．

## 問題例
- [Codeforces Round #668 (Div. 1) E. Bricks](https://codeforces.com/contest/1404/problem/E)
- [AtCoder Regular Contest 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AtCoder Regular Contest 107 F - Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
- [AtCoder Regular Contest 129 E - Yet Another Minimization](https://atcoder.jp/contests/arc129/tasks/arc129_e)
  - 2 択だけでなく選択肢が $k$ 個あるような場合の問題．[このブログ](https://maspypy.com/atcoder-%e5%8f%82%e5%8a%a0%e6%84%9f%e6%83%b3-2020-10-31arc107)の F の解説にある辺の張り方が参考になる．ライブラリにしていいかもしれない．

## 参照
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)
