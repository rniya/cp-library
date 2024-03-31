---
title: K-ary Optimization
documentation_of: ./KaryOptimization.hpp
---

**`MINIMIZE = false` は未 verify につき注意**

## 概要
$[k] \coloneqq \{0, 1, \dots , k - 1\}$ とする．
$\alpha \in \mathbb{Z},\ \theta_i \colon [k] \to \mathbb{Z}$ 及び Monge な関数 $phi_{i, j} \colon [k]^2 \to \mathbb{Z}$ について
$$
\begin{alignedat}{3}
    & \mathrm{Minimize}     & \quad & \alpha + \sum_i \theta_i(x_i) + \sum_{i < j} \phi_{i, j}(x_i, x_j) \\
    & \mathrm{subject\ to}  & \quad & x \in [k]^n
\end{alignedat}
$$
を解く．
ここで，$0 \leq i_1 < i_2 < k$ 及び $0 \leq j_1 < j_2 < k$ を満たす任意の整数の組 $(i_1, i_2, j_1, j_2)$ について，$\phi(i_1, j_1) + \phi(i_2, j_2) \leq \phi(i_1, j_2) + \phi(i_2, j_1)$ が成立するとき，$\phi$ は Monge であるという．
また，これは $0 \leq i < k - 1$ 及び $0 \leq j < k - 1$ を満たす任意の整数の組 
$(i, j)$ について，$\phi(i, j) +phi(i + 1, j + 1) \leq \phi(i, j + 1) + \phi(i + 1, j)$ が成立することと同値である．

## 問題例
- [AtCoder Regular Contest 129 E - Yet Another Minimization](https://atcoder.jp/contests/arc129/tasks/arc129_e?lang=ja)
- [AtCoder Beginner Contest 347 G - Grid Coloring 2](https://atcoder.jp/contests/abc347/tasks/abc347_g)

## Links
- [最小カット問題の k 値への一般化 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2021/06/29/044225)