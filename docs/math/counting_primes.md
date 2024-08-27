---
title: Counting Primes
documentation_of: //src/math/counting_primes.hpp
---

## 入力

整数 $N$．

## 出力

$N$ 以下の素数の個数．

## 計算量

- 時間計算量 $\mathrm{O} \left( \frac{N ^ {3 / 4}}{\log N} \right)$
- 空間計算量 $\mathrm{O}(\sqrt{N})$

## 概要

$\pi(n)$ を $n$ 以下の素数の個数とする．
求めたいのは $\pi(N)$ である．

$f(n, x)$ を $2$ 以上 $n$ 以下であって，$x$ 以下でふるいをかけた際に残る数の個数と定めると，

$$
\pi(N) = f\left( N, \left \lfloor \sqrt{N} \right \rfloor \right)
$$

である．
このとき，

$$
f(n, x) =
\begin{cases}
    f(n, x - 1) & (x \text{ is not prime} \lor n < x ^ 2) \\
    f(n, x - 1) - \left( f\left( \left \lfloor \frac{n}{x} \right \rfloor, x - 1 \right) - \pi(x - 1) \right) & (\text{o.w.})
\end{cases}
$$

が成立する．
$\pi(N)$ を求めるにあたり必要となる $f(n, x)$ の値は $n = \left \lfloor \frac{N}{1} \right \rfloor, \left \lfloor \frac{N}{2} \right \rfloor, \dots , \left \lfloor \frac{N}{N} \right \rfloor$ 及び $x = 1, \dots , \left \lfloor \sqrt{N} \right \rfloor$ のみで，これを動的計画法により計算していく．

実装中の `internal::pi_table(N)` は $i$ 要素目 (1-indexed) が $\left \lfloor \frac{N}{i} \right \rfloor$ 及び $\pi(\frac{N}{i})$ に等しい配列を返している．

また，応用して $N$ 以下の素数の $k$ 乗和を求めることも可能である（今回は $k = 0$，[参照](https://rsk0315.github.io/slides/prime-counting.pdf)）．