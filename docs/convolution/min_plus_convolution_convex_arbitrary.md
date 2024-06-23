---
title: Min Plus Convolution (Convex and Arbitary)
documentation_of: //src/convolution/min_plus_convolution_convex_arbitrary.hpp
---

## 入力

数列 $a, b$ 

ここで数列 $a$ は下に凸である．
すなわち，任意の $0 \leq i \lt N - 2$ に対して $a _ {i + 1} - a _ i \leq a _ {i + 2} - a _ {i + 1}$ が成立する．

2 つの数列の長さをそれぞれ $n, m$ とする．

## 出力

数列 $a$ と $b$ の畳み込み．
すなわち，

$$
c _ k = \min _ {i + j = k} (a _ i + b _ j)
$$

で定義される長さ $n + m - 1$ の数列 $c$．

## 計算量

時間計算量 $\mathrm{O}((n + m) \log (n + m))$

## 概要

$(n + m - 1) \times m$ 行列 $X$ を

$$
X _ {i, j} := a _ {i - j} + b _ j
$$

により定めたとき，$X$ は totally monotone であり，monotone minima（時間計算量では SMAWK algorithm に劣るが，実用上はこちらの方が高速なのでこちらを採用している）により各行の最小値，すなわち所望の数列 $c$ を計算することが可能となる．
ここで，$i \lt 0$ や $n \leq i$ に対する $a_i$ は $a$ の凸性を保つような十分大きい値を取るとする．

<details>
<summary>totally monotone であることの証明</summary>
<div>

$X$ の任意の $2$ 次正方部分行列が monotone であることを示せば良い．
$X$ の行 $i, i ^ \prime\ (i \lt i ^ \prime)$ 及び列 $j, j ^ \prime\ (j \lt j ^ \prime)$ を取り出した部分行列を考える．
$X _ {i, j} > X _ {i, j ^ \prime} \implies X _ {i ^ \prime, j} \gt X _ {i ^ \prime, j ^ \prime}$ を示せば十分だが，これは $i \lt i ^ \prime$ より，

$$
0 \lt X _ {i, j} - X _ {i, j ^ \prime} = a _ {i - j} - a _ {i - j ^ \prime} \leq a _ {i ^ \prime - j} - a _ {i ^ \prime - j ^ \prime} = X _ {i ^ \prime, j} - X _ {i ^ \prime, j ^ \prime}
$$

だから成立する．

$\blacksquare$

</div>
</details>

## 出題例
[The 2nd Universal Cup. Stage 3: Binjiang L. Partially Free Meal](https://contest.ucup.ac/contest/1358/problem/7523)