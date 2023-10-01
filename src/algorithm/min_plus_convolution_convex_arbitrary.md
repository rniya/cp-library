---
title: Min Plus Convolution (Convex and Arbitary)
documentation_of: ./min_plus_convolution_convex_arbitrary.hpp
---

## 概要
長さ $n$ の下に凸な数列 $a$ と長さ $m$ の任意の数列 $b$ の畳み込み，すなわち，
$$
c_k = \min_{i + j = k} a_i + b_j
$$
で定義される長さ $n + m - 1$ の数列 $c$ を求める．

$(n + m - 1) \times m$ 行列 $X$ を
$$
X_{i, j} \coloneqq a_{i - j} + b_j
$$
により定めたとき，$X$ は totally monotone であり，monotone minima (時間計算量では SMAWK algorithm に劣るが，実用上はこちらの方が高速なのでこちらを採用している) により各行の最小値，すなわち所望の数列 $c$ を計算することが可能となる．
ここで，$i < 0$ や $n \leq i$ に対する $a_i$ は $a$ の凸性を保つような十分大きい値を取るとする．

<details>
<summary>totally monotone であることの証明</summary>
<div>

$X$ の任意の $2$ 次正方部分行列が monotone であることを示せば良い．
$X$ の行 $i, i^\prime\ (i < i^\prime)$ 及び列 $j, j^\prime\ (j < j^\prime)$ を取り出した部分行列を考える．
$X_{i, j} > X_{i, j^\prime} \implies X_{i^\prime, j} > X_{i^\prime, j^\prime}$ を示せば十分だが，これは $i < i^\prime$ より，
$$
0 < X_{i, j} - X_{i, j^\prime} = a_{i - j} - a_{i - j^\prime} \leq a_{i^\prime - j} - a_{i^\prime - j^\prime} = X_{i^\prime, j} - X_{i^\prime, j^\prime}
$$
だから成立する．

$\blacksquare$

</div>
</details>


## 問題例
[The 2nd Universal Cup. Stage 3: Binjiang L. Partially Free Meal](https://contest.ucup.ac/contest/1358/problem/7523)