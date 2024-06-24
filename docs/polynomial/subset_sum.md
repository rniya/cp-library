---
title: $\#_p$ Subset Sum
documentation_of: //src/polynomial/subset_sum.hpp
---

## 入力

$N$ 個の非負整数 $s _ 0, \dots , s _ {N - 1}$ 及び正整数 $m$．

## 出力

$t = 1, \dots , m$ について $\sum _ {i \in I} s _ i = t$ となる $I \subseteq \lbrace 0, 1, \dots , N - 1 \rbrace$ の個数．

## 計算量

時間計算量 $\mathrm{O}(N + M \log M)$

## 概要

$s _ i = 0$ については答えを $2$ 倍すれば良いから以降は $s _ i \geq 1$ とする．
$t$ に対する答えは

$$
[x ^ t] \prod _ {i = 0} ^ {N - 1} (1 + x ^ {s _ i}) = \exp \left( \sum _ {i = 0} ^ {N - 1} \log (1 + x ^ {s _ i}) \right)
$$

に等しい．

ここで，

$$
\log (1 + x) = x - \frac{x ^ 2}{2} + \frac{x ^ 3}{3} - \cdots = \sum _ {i \geq 1} \frac{(-1) ^ {i - 1}}{i} x ^ i
$$

であるから $s _ i = k$ なる $i \in \lbrace 0, 1, \dots , N - 1 \rbrace$ の個数を $c _ k\ (k \in \lbrack 1, m \rbrack)$ とすると，

$$
\sum _ {i = 0} ^ {N - 1} \log (1 + x ^ {s _ i}) = \sum _ {k = 1} ^ m c_k \sum _ {k i \leq m} \frac{(-1) ^ {i - 1}}{i} x^{k i}
$$

で，これは $\mathrm{O}(M \log M)$ 時間で計算可能である．


## Links
