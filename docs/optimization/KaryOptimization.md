---
title: $K$-ary Optimization
documentation_of: //src/optimization/KaryOptimization.hpp
---

**`MINIMIZE = false` は未 verify につき注意**

## 概要
$[k] := \lbrace 0, 1, \dots , k - 1 \rbrace$ とする．
$\alpha \in \mathbb{Z}, \theta _ i \colon [k] \to \mathbb{Z}$ 及び Monge な関数 $\phi _ {i, j} \colon [k] ^ 2 \to \mathbb{Z}$ について
$$
\begin{alignedat}{3}
    & \mathrm{Minimize}     & \quad & \alpha + \sum _ i \theta _ i(x _ i) + \sum _ {i \lt j} \phi _ {i, j}(x _ i, x _ j) \\
    & \mathrm{subject\ to}  & \quad & x \in [k] ^ n
\end{alignedat}
$$
を解く．
ここで，$0 \le i _ 1 \lt i _ 2 \lt k$ 及び $0 \le j _ 1 \lt j _ 2 \lt k$ を満たす任意の整数の組 $(i _ 1, i _ 2, j _ 1, j _ 2)$ について，$\phi(i _ 1, j _ 1) + \phi(i _ 2, j _ 2) \le \phi(i _ 1, j _ 2) + \phi(i _ 2, j _ 1)$ が成立するとき，$\phi$ は Monge であるという．
また，これは $0 \le i \lt k - 1$ 及び $0 \le j \lt k - 1$ を満たす任意の整数の組 
$(i, j)$ について，$\phi(i, j) + \phi(i + 1, j + 1) \leq \phi(i, j + 1) + \phi(i + 1, j)$ が成立することと同値である．

## 出題例
- [AtCoder Regular Contest 129 E - Yet Another Minimization](https://atcoder.jp/contests/arc129/tasks/arc129_e?lang=ja)
- [AtCoder Beginner Contest 347 G - Grid Coloring 2](https://atcoder.jp/contests/abc347/tasks/abc347_g)

## Links
- [最小カット問題の $k$ 値への一般化 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2021/06/29/044225)
