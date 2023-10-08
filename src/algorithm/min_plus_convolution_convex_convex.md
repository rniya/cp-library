---
title: Min Plus Convolution (Convex and Convex)
documentation_of: ./min_plus_convolution_convex_convex.hpp
---

## 概要
長さ $n$ の下に凸な数列 $a$ と長さ $m$ の下に凸な数列 $b$ の畳み込み，すなわち，
$$
c_k = \min_{i + j = k} a_i + b_j
$$
で定義される長さ $n + m - 1$ の数列 $c$ を求める．

線分の傾きをマージすることで $\mathrm{O}(n + m)$ 時間で計算可能である．
また，畳み込んでできる数列 $c$ も凸である．
