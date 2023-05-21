---
title: Shift of Sampling Points of Polynomial
documentation_of: ./shift_of_sampling_points_of_polynomial.hpp
---

## 概要

次数 $N$ 未満の多項式 $f(x)$ の標本点 $f(0), f(1), \dots , f(N - 1)$ を入力として $f(c), f(c + 1), \dots , f(c + M - 1)$ を $\mathrm{O}((N + M) \log (N + M))$ 時間で計算する。

以下では、下降階乗冪 
$$
x^{\underline{n}} = \prod_{k = 1}^n (x - k + 1)
$$
を用いる。

#### 補題 1

$$
f(x) = \sum_{i = 0}^{N - 1} \left(\sum_{j = 0}^i \frac{(-1)^{i - j}}{(i - j)!} \frac{f(j)}{j!}\right) x^{\underline{[i]}}.
$$

<details>
<summary>証明</summary>
<div>

両辺 $N$ 次未満の多項式であるから $N$ 点 $x = 0, 1, \dots , N - 1$ における値が一致することを示せば良い。

$k \in \{0, 1, \dots , N - 1\}$ について、
$$
\begin{aligned}
    \sum_{i = 0}^{N - 1} \left(\sum_{j = 0}^i \frac{(-1)^{i - j}}{(i - j)!} \frac{f(j)}{j!}\right) k^{\underline{[i]}}
    &= \sum_{i = 0}^{k} \sum_{j = 0}^i \frac{(-1)^{i - j}}{(i - j)!} \frac{f(j)}{j!} \frac{k!}{(k - i)!} \\
    &= \sum_{p + q + r = k} \frac{(-1)^q k!}{p! q! r!} f(p) \\
    &= \sum_{p = 0}^k \frac{f(p)}{p!} k! \sum_{q + r = k - p} \frac{(-1)^q}{q!r!} \\
    &= \sum_{p = 0}^k \frac{f(p)}{p!} \frac{k!}{(k - p)!} \sum_{q + r = k - p} \binom{k - p}{r} 1^r (-1)^q \\
    &= \sum_{p = 0}^k \frac{f(p)}{p!} \frac{k!}{(k - p)!} \sum_{q + r = k - p} (1 - 1)^{k - p} \\
    &= f(k).
\end{aligned}
$$

$\blacksquare$

</div>
</details>

この補題から、$f(x) = \sum_{i = 0}^{N - 1} a_i x^{\underline{i}}$ なる数列 $a_0, a_1, \dots , a_{N - 1}$ が畳み込みで $\mathrm{O}(N \log N)$ 時間で得られることがわかる。

#### 補題 2

任意の $0$ 以上の整数 $n$ について、
$$
(a + b)^{\underline{n}} = \sum_{i = 0}^n \binom{n}{i} a^{\underline{i}} b^{\underline{n - i}}.
$$

<details>
<summary>証明</summary>
<div>

$n$ についての帰納法により示す。

$n = 0$ のときは明らか。

$(a + b)^{\underline{n}} = \sum_{i = 0}^n \binom{n}{i} a^{\underline{i}} b^{\underline{n - i}}$ を仮定したとき、
$$
\begin{aligned}
    (a + b)^{\underline{n + 1}}
    &= (a + b)^{\underline{n}} (a + b - n) \\
    &= \sum_{i = 0}^n \binom{n}{i} a^{\underline{i}} b^{\underline{n - i}} [(a - i) + (b - n + i)] \\
    &= \sum_{i = 0}^n \binom{n}{i} a^{\underline{i + 1}} b^{\underline{n - i}} + \sum_{i = 0}^n \binom{n}{i} a^{\underline{i}} b^{\underline{n + 1 - i}} \\
    &= \sum_{i = 1}^{n + 1} \binom{n}{i - 1} a^{\underline{i}} b^{\underline{n + 1 - i}} + \sum_{i = 0}^n \binom{n}{i} a^{\underline{i}} b^{\underline{n + 1 - i}} \\
    &= \sum_{i = 0}^{n + 1} \binom{n + 1}{i} a^{\underline{i}} b^{\underline{n + 1 - i}}.
\end{aligned}
$$
$\blacksquare$

</div>
</details>

#### 補題 3

以上より、$k \in \{0, 1, \dots , M - 1\}$ 及びシフト幅 $c$ について、
$$
\begin{aligned}
    f(k + c)
    &= \sum_{i = 0}^{N - 1} a_i (k + c)^{\underline{i}} & \\
    &= \sum_{i = 0}^{N - 1} a_i \sum_{j = 0}^i \binom{i}{j} c^{\underline{i - j}} k^{\underline{j}} && \\
    &= \sum_{j = 0}^{N - 1} \frac{k^{\underline{j}}}{j!} \sum_{i = j}^{N - 1} (a_i i!) \frac{c^{\underline{i - j}}}{(i - j)!} && \\
    &= \sum_{j = 0}^k \binom{k}{j} \sum_{i = 0}^{N - 1 - j} [a_{i + j} (i + j)!] \frac{c^{\underline{i}}}{i!} && \\
    &= \sum_{j = 0}^k \binom{k}{j} \sum_{i = 0}^{N - 1 - j} a^\prime_{N - 1 - j - i} \frac{c^{\underline{i}}}{i!} && \quad (a^\prime_i \coloneqq a_{N - 1 - i} (N - 1 - i)!) \\
    &= \sum_{j = 0}^k \binom{k}{j} b_{N - 1 - j} && \quad \left(b_i \coloneqq \sum_{j = 0}^i a^\prime_{i - j} \frac{c^{\underline{j}}}{j!}\right) \\
    &= k! \sum_{j = 0}^k \frac{b_{N - 1 - j}}{j!} \cdot \frac{1}{(k - j)!}. &&
\end{aligned}
$$

$b$ は畳み込みにより $\mathrm{O}(N \log N)$ 時間で計算でき、これにより求めたい各点値も畳み込みで $\mathrm{O}((N + M) \log (N + M))$ 時間で得られる。

## 問題例
- [The 1st Universal Cup. Stage 17: Guangzhou M. Expression 3](https://qoj.ac/contest/1244/problem/6513?v=1)