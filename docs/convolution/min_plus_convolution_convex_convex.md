---
title: Min Plus Convolution (Convex and Convex)
documentation_of: //src/min_plus_convolution_convex_convex.hpp
---

## 入力

数列 $a, b$ 

ここで数列 $a, b$ はどちらも下に凸である．
すなわち，任意の $0 \leq i \lt N - 2$ に対して $a _ {i + 1} - a _ i \leq a _ {i + 2} - a _ {i + 1},\ b _ {i + 1} - b _ i \leq b _ {i + 2} - b _ {i + 1}$ が成立する．

2 つの数列の長さをそれぞれ $n, m$ とする．

## 出力

数列 $a$ と $b$ の畳み込み．
すなわち，
$$
c _ k = \min _ {i + j = k} (a _ i + b _ j)
$$
で定義される長さ $n + m - 1$ の数列 $c$．

## 計算量

時間計算量 $\mathrm{O}(n + m)$

## 概要

線分の傾きをマージすることで $\mathrm{O}(n + m)$ 時間で計算可能である．
また，畳み込んでできる数列 $c$ も凸である．
