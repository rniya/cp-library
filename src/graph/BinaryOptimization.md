---
title: Binary Optimization (Project Selection Problem)
documentation_of: ./BinaryOptimization.hpp
---

**`add(i, j, k, x), add_all_0(is, x), add_all_1(is, x)` は未 verify につき注意**

## 概要
Project Selection Problem，いわゆる燃やす埋める問題を解く際の補助ライブラリ．
具体的には $n$ 個の $01$ 変数 $x_1, \dots , x_n$ に対して各種損失条件が与えられる際に損失を最小化する割当を求める．
すなわち，$\alpha \in \mathbb{Z},\ \theta_i \colon \{0, 1\} \to \mathbb{Z},\ \phi_{i, j} \colon \{0, 1\}^2 \to \mathbb{Z},\ \psi_{i, j, k} \colon \{0, 1\}^3 \to \mathbb{Z}$ について
$$
\begin{alignedat}{3}
    & \mathrm{Minimize}     & \quad & \alpha + \sum_i \theta_i(x_i) + \sum_{i < j} \phi_{i, j}(x_i, x_j) + \sum_{i < j < k} \psi_{i, j, k}(x_i, x_j, x_k) \\
    & \mathrm{subject\ to}  & \quad & x \in \{0, 1\}^n
\end{alignedat}
$$
を解く．
また，$x_{i_1} = x_{i_2} = \dots x_{i_m}$ のときにのみ $c$ を減らすような関数も考慮可能である．

頂点 $i$ から $j$ への容量 $c$ の辺は $x_i = 0$ かつ $x_j = 1$ のときにのみコスト $c$ を発生させるものと考えると良い．
最大化したい場合は template 引数の `MINIMIZE` を `false` にする．

| メンバ関数              | 効果                                                 | 時間計算量           |
| ----------------------- | ---------------------------------------------------- | -------------------- |
| `BinaryOptimization(n)` | 頂点数 $n$ のグラフとして初期化する．                | $O(n)$               |
| `add(x)`                | $\alpha$ に $x$ を加える．                           | $O(1)$               |
| `add(i, x)`             | $\theta_i$ を設定する．                              | $O(1)$               |
| `add(i, j, x)`          | $\phi_{i, j}$ を設定する．                           | $O(1)$               |
| `add(i, j, k, x)`       | $\psi_{i, j, k}$ を設定する．                        | $O(1)$               |
| `add_all_0(is, x)`      | $\textit{is}$ の要素が全て $0$ のときに $x$ を得る． | $O(\|\textit{is}\|)$ |
| `add_all_1(is, x)`      | $\textit{is}$ の要素が全て $1$ のときに $x$ を得る． | $O(\|\textit{is}\|)$ |
| `solve()`               | 損失の最小値及びそれを達成する割当を返す．           | $O(n^2m)$            |

一般にこれ以外の条件に対応する際には 2 部グラフなどの制約が必要になる．

## 問題例
- [Codeforces Round #668 (Div. 1) E. Bricks](https://codeforces.com/contest/1404/problem/E)
- [AtCoder Regular Contest 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AtCoder Regular Contest 107 F - Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
- [AtCoder Regular Contest 129 E - Yet Another Minimization](https://atcoder.jp/contests/arc129/tasks/arc129_e)
  - 2 択だけでなく選択肢が $k$ 個あるような場合の問題．[このブログ](https://maspypy.com/atcoder-%e5%8f%82%e5%8a%a0%e6%84%9f%e6%83%b3-2020-10-31arc107)の F の解説にある辺の張り方が参考になる．ライブラリにしていいかもしれない．
- [2023牛客暑期多校训练营2 B Link with Railway Company](https://ac.nowcoder.com/acm/contest/57356/F)

## Links
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)
- [燃やす埋める問題と劣モジュラ関数のグラフ表現可能性 その① - 私と理論](https://theory-and-me.hatenablog.com/entry/2020/03/13/180935)