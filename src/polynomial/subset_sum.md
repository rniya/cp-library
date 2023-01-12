---
title: $\#_p$ Subset Sum
documentation_of: ./subset_sum.hpp
---

## 概要
$n$ 個の正整数 $s_0, \dots , s_{n - 1}$ と正整数 $m$ が与えられるとき，$t = 1, \dots , m$ について $\sum_{i \in I} s_i = t$ なる $I \subseteq \{0, 1, \dots , n - 1\}$ の個数を $O(n + m \log m)$ で求める．

$s_i = 0$ については答えを $2$ 倍すれば良いから以降は $s_i \geq 1$ とする．
$t$ に対する答えは

$$
[x^t] \prod_{i = 0}^{n - 1} (1 + x^{s_i}) = \exp\left(\sum_{i = 0}^{n - 1} \log (1 + x^{s_i}) \right)
$$

に等しい．

ここで，

$$
\log (1 + x) = x - \frac{x^2}{2} + \frac{x^3}{3} - \cdots = \sum_{i \geq 1} \frac{(-1)^{i - 1}}{i} x^i
$$

であるから $s_i = k$ なる $i \in \{0, 1, \dots , n - 1\}$ の個数を $c_k\ (k \in [1, m])$ とすると，

$$
\sum_{i = 0}^{n - 1} \log (1 + x^{s_i}) = \sum_{k = 1}^m c_k \sum_{k i \leq m} \frac{(-1)^{i - 1}}{i} x^{k i}
$$

で，これは $O(m \log m)$ で計算可能である．


## Links
