---
title: Bell Number
documentation_of: //src/enumerative_combinatorics/bell_number.hpp
---

## 入力

整数 $N$．

## 出力

$n$ 元集合を空でない部分集合に分割する方法の個数を $B _ n$（ベル数）とし，$B _ 0, \dots , B _ N$ を列挙．

## 計算量

時間計算量 $\mathrm{O}(N \log N)$

## 概要

$n$ 元集合 $\lbrace 1, \dots , n \rbrace$ を空でない部分集合に分割するに際し，要素 $1$ の属する集合のサイズを $i$ とすると，この集合の残り $i - 1$ 要素の選び方は $\binom{n - 1}{i - 1}$ 通りあり，残った $n - i$ 要素の分割方法の個数は $B _ {n - i}$ となるため，

$$
B _ n = \sum _ {i = 1} ^ n \binom{n - 1}{i - 1} B _ {n - i} = \sum _ {i = 0} ^ {n - 1} \binom{n - 1}{i} B _ i
$$

が成立する．

これを指数型母関数 $B(x) := \sum _ {n \ge 0} \frac{B _ n}{n!} x ^ n$ について変形すると，

$$
\begin{aligned}
    B _ n = \sum _ {i = 0} ^ {n - 1} \frac{(n - 1)!}{i! (n - 1 - i)!} B _ i
    &\implies n \frac{B _ n}{n!} = \sum _ {i = 0} ^ {n - 1} \frac{B _ i}{i!} \frac{1}{(n - 1 - i)!} \\
    & \implies \sum _ {n \ge 1} n \frac{B _ n}{n!} x ^ n = \sum _ {n \ge 1} x \sum _ {i = 0} ^ {n - 1} \frac{B _ i}{i!} x ^ i \frac{x ^ {n - 1 - i}}{(n - 1 - i)!} \\
    & \implies x B ^ \prime (x) = x B(x) e ^ x \\
    & \implies \frac{B ^ \prime(x)}{B(x)} = e ^ x
\end{aligned}
$$

を得る．
両辺を積分することで $c$ を定数として，

$$
\log B(x) = e ^ x + c
$$

となり，$B(0) = B _ 0 = 1$ より $c = -1$ である．

以上より，$B(x) = e ^ {e ^ x - 1}$ が成立する．
これは形式的冪級数の基本演算により $\mathrm{O}(N \log N)$ 時間で計算可能である．

## 出題例
- [AtCoder Beginner Contest 387 G - Prime Circuit](https://atcoder.jp/contests/abc387/tasks/abc387_g)
  - ほぼ同様の式変形を用いる．

## Links
- [[Tutorial] Generating Functions in Competitive Programming (Part 1) - Codeforces](https://codeforces.com/blog/entry/77468)