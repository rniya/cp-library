---
title: Monotone Minima
documentation_of: ./monotone_minima.hpp
---

## 概要
totally monotone な $N \times M$ 行列 $A$ を入力として，各 $i$ について $\underset{j}{\operatorname{argmin}}\ A_{i, j}$ を $\mathrm{O}(N + M \log N)$ 時間で求める．
実装中の関数 `select(i, j, k)` は $j < k$ が保証されているもとで，$A_{i, j}$ よりも $A_{i, k}$ が好ましいとされる場合に `true` を，そうでないときは `false` を返す関数である．

計算量は SMAWK algorithm に劣るが，定数倍の関係上実用的には SMAWK algorithm より高速なケースが多い．