---
title: Project Selection Problem (based on ac-library)
documentation_of: ./ProjectSelectionProblem.hpp
---

## 概要
Project Selection Problem，いわゆる燃やす埋める問題を解く際の補助ライブラリ．
具体的には $n$ 個の $01$ 変数 $x_1, \dots , x_n$ に対して各種損失条件が与えられる際に損失を最小化する割当を求める．

| メンバ関数                    | 効果                                                         | 時間計算量 |
| ----------------------------- | ------------------------------------------------------------ | ---------- |
| `ProjectSelectionProblem(n)`  | 頂点数 $n$ のグラフとして初期化する．                        | $O(n)$     |
| `add_cost_0(x, cost)`         | $x$ が $0$ のときに $\textit{cost}$ 失う．                   | $O(1)$     |
| `add_cost_1(x, cost)`         | $x$ が $1$ のときに $\textit{cost}$ 失う．                   | $O(1)$     |
| `add_profit_0(x, profit)`     | $x$ が $0$ のときに $\textit{profit}$ 得る．                 | $O(1)$     |
| `add_profit_1(x, profit)`     | $x$ が $1$ のときに $\textit{profit}$ 得る．                 | $O(1)$     |
| `add_cost_01(x, y, cost)`     | $x$ が $0$ かつ $y$ が $1$ のときに $\textit{cost}$ 失う．   | $O(1)$     |
| `add_cost_10(x, y, cost)`     | $x$ が $1$ かつ $y$ が $0$ のときに $\textit{cost}$ 失う．   | $O(1)$     |
| `add_profit_00(x, y, profit)` | $x$ が $0$ かつ $y$ が $0$ のときに $\textit{profit}$ 得る． | $O(1)$     |
| `add_profit_11(x, y, profit)` | $x$ が $1$ かつ $y$ が $1$ のときに $\textit{profit}$ 得る． | $O(1)$     |
| `add_profit_all_0(v, profit)` | $v$ の要素が全て $0$ のときに $\textit{profit}$ 得る．       | $O(n^2m)$  |
| `add_profit_all_1(v, profit)` | $v$ の要素が全て $1$ のときに $\textit{profit}$ 得る．       | $O(n^2m)$  |
| `min_cost()`                  | 損失の最小値及びそれを達成する割当を返す．                   | $O(n^2m)$  |
| `max_profit()`                | 利得の最大値及びそれを達成する割当を返す．                   | $O(n^2m)$  |

一般にこれ以外の条件に対応する際には 2 部グラフなどの制約が必要になる．

## 問題例
- [Codeforces Round #668 (Div. 1) E. Bricks](https://codeforces.com/contest/1404/problem/E)
- [AtCoder Regular Contest 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AtCoder Regular Contest 107 F - Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
- [AtCoder Regular Contest 129 E - Yet Another Minimization](https://atcoder.jp/contests/arc129/tasks/arc129_e)
  - 2 択だけでなく選択肢が $k$ 個あるような場合の問題．[このブログ](https://maspypy.com/atcoder-%e5%8f%82%e5%8a%a0%e6%84%9f%e6%83%b3-2020-10-31arc107)の F の解説にある辺の張り方が参考になる．ライブラリにしていいかもしれない．
- [2023牛客暑期多校训练营2 B Link with Railway Company](https://ac.nowcoder.com/acm/contest/57356/F)

## 参照
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)
