---
title: Binary Optimization (Project Selection Problem)
documentation_of: //src/optimization/BinaryOptimization.hpp
---

**`add(i, j, k, x), add_all_0(is, x), add_all_1(is, x)` は未 verify につき注意**

## 概要

Project Selection Problem，いわゆる燃やす埋める問題を解く際の補助ライブラリ．
具体的には $n$ 個の $01$ 変数 $x _ 1, \dots , x _ n$ に対して各種損失条件が与えられる際に損失を最小化する割当を求める．
すなわち，$\alpha \in \mathbb{Z}, \theta _ i \colon \lbrace 0, 1 \rbrace \to \mathbb{Z}, \phi _ {i, j} \colon \lbrace 0, 1 \rbrace ^ 2 \to \mathbb{Z}, \psi _ {i, j, k} \colon \lbrace 0, 1 \rbrace ^ 3 \to \mathbb{Z}$ について，

$$
\begin{alignedat}{3}
    & \mathrm{Minimize}     & \quad & \alpha + \sum _ i \theta _ i(x _ i) + \sum _ {i \lt j} \phi _ {i, j}(x _ i, x _ j) + \sum _ {i \lt j \lt k} \psi _ {i, j, k}(x _ i, x _ j, x _ k) \\
    & \mathrm{subject\ to}  & \quad & x \in \lbrace 0, 1 \rbrace ^ n
\end{alignedat}
$$

を解く．
また，$x _ {i _ 1} = x _ {i _ 2} = \dots x _ {i _ m}$ のときにのみ $c$ を減らすような関数も考慮可能である．

頂点 $i$ から $j$ への容量 $c$ の辺は $x _ i = 0$ かつ $x _ j = 1$ のときにのみコスト $c$ を発生させるものと考えると良い．
最大化したい場合は template 引数の `MINIMIZE` を `false` にする．

| メンバ関数              | 効果                                                 | 時間計算量                            |
| ----------------------- | ---------------------------------------------------- | ------------------------------------- |
| `BinaryOptimization(n)` | 頂点数 $n$ のグラフとして初期化する．                | $\mathrm{O}(n)$                       |
| `add(x)`                | $\alpha$ に $x$ を加える．                           | $\mathrm{O}(1)$                       |
| `add(i, x)`             | $\theta _ i$ を設定する．                            | $\mathrm{O}(1)$                       |
| `add(i, j, x)`          | $\phi _ {i, j}$ を設定する．                         | $\mathrm{O}(1)$                       |
| `add(i, j, k, x)`       | $\psi _ {i, j, k}$ を設定する．                      | $\mathrm{O}(1)$                       |
| `add_all_0(is, x)`      | $\textit{is}$ の要素が全て $0$ のときに $x$ を得る． | $\mathrm{O}(\vert \textit{is} \vert)$ |
| `add_all_1(is, x)`      | $\textit{is}$ の要素が全て $1$ のときに $x$ を得る． | $\mathrm{O}(\vert \textit{is} \vert)$ |
| `solve()`               | 損失の最小値及びそれを達成する割当を返す．           | $\mathrm{O}(n^2m)$                    |

`solve()` の計算量に現れる $n, m$ はそれぞれできあがったネットワークの頂点の個数，辺の本数である．
一般にこれ以外の条件に対応する際には 2 部グラフなどの制約が必要になる．

## 出題例
- [Codeforces Round #668 (Div. 1) E. Bricks](https://codeforces.com/contest/1404/problem/E)
- [AtCoder Regular Contest 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AtCoder Grand Contest 038 F - Two Permutations](https://atcoder.jp/contests/agc038/tasks/agc038_f)
- [AtCoder Regular Contest 107 F - Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
- [2023牛客暑期多校训练营2 B Link with Railway Company](https://ac.nowcoder.com/acm/contest/57356/F)
- [AtCoder Regular Contest 176 E - Max Vector](https://atcoder.jp/contests/arc176/tasks/arc176_e)

## Links
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)
- [燃やす埋める問題と劣モジュラ関数のグラフ表現可能性 その① - 私と理論](https://theory-and-me.hatenablog.com/entry/2020/03/13/180935)
