---
title: SMAWK algotirhm
documentation_of: ./SMAWK.hpp
---

## 概要

### 定義

$N \times M$ 行列 $A$ が任意の $i < i^\prime$ について $\underset{j}{\operatorname{argmin}}\ A_{i, j} \leq \underset{j}{\operatorname{argmin}}\ A_{i^\prime, j}$ を満たすとき、$A$ は monotone であるという。

また、$A$ の任意の部分行列が monotone であるとき、$A$ は totally monotone であるという。

#### 補題

$A$ が totally monotone であることは $A$ の任意の $2$ 次正方部分行列が monotone であることと同値である。

<details>
<summary>証明</summary>
<div>

部分行列において行を削除することは totally monotone の条件を緩和するから考えなくて良い。

$\implies$ は明らかであるから $\impliedby$ を示す。
$A$ が totally monotone でない、すなわち $A$ が monotone でない部分行列 $B$ を有するとする。
$B$ の行及び列の添字はもとの行列 $A$ に準拠するとして、$\underset{j}{\operatorname{argmin}}\ B_{i, j} > \underset{j}{\operatorname{argmin}}\ B_{i^\prime, j}$ を満たす $i < i^\prime$ が存在し、$k = \underset{j}{\operatorname{argmin}}\ B_{i, j}, k^\prime = \underset{j}{\operatorname{argmin}}\ B_{i^\prime, j}$ とする。
ここで、$A$ から行 $i, i^\prime$ 及び列 $k, k^\prime$ のみを抽出した $2$ 次正方部分行列は monotone ではない。
よって、$A$ の任意の $2$ 次正方部分行列が monotone であるならば $A$ は totally monotone である。

$\blacksquare$

</div>
</details>


### アルゴリズム

SMAWK algorithm は totally monotone な $N \times M$ 行列 $A$ を入力として、各 $i$ について $\underset{j}{\operatorname{argmin}}\ A_{i, j}$ を $\mathrm{O}(N + M)$ 時間で求める。

## Links
- [SMAWK algorithm as an alternative for D&C optimization - Codeforces](https://codeforces.com/blog/entry/110844)

## 問題例
