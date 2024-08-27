---
title: Sum of Multiplicative Function
documentation_of: //src/math/sum_of_multiplicative_function.hpp
---

## 入力

整数 $N$．

## 出力

素数 $p$ に対して $f(p)$ が $p$ についての多項式となるような乗法的関数 $f$ の和 $\sum _ {i = 1} ^ N f(i)$．

ただし，$\mathbb{Z} _ {> 0}$ を定義域とする関数 $f$ が，

- $f(1) = 1$
- $\gcd(a, b) = 1 \implies f(a b) = f(a) f(b)$

を満たすとき，$f$ は乗法的関数 (multiplicative function) であるという．

## 計算量

- 時間計算量 $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$（詳細を後述）
- 空間計算量 $\mathrm{O}(\sqrt{N})$

## 概要

### Black Algorithm

$\mathrm{gpf}(n)$ を $n$ の最大の素因数 (greatest prime factor) とする．

$1$ を根として，$1 < n \le N$ についてその親を $n / \mathrm{gpf}(n)$ とするような $N$ 頂点の木を考える．
この木上の葉でない頂点 $n$ について，その子頂点の集合を $T(n)$ として $\sum _ {t \in T(n)} f(t)$ を求めたい．

小さい方から $k$ 番目の素数を $p _ k$ とする．
$n > 1$ について，$\mathrm{gpf}(n) = p _ l$ とし，$n p _ k \le N$ を満たす最大の $k$ を $r$ とする．
このとき，$T(n) = \{n p _ l, n p _ {l + 1}, \dots , n p _ r\}$ である．
また，$n$ は葉ではなく $n p _ l \le N$ であるから，$p _ l \le \sqrt{N}$ が成立する．
$n = m p _ l ^ c\ (\gcd(m, p) = 1)$ と表せるとき，乗法的関数の性質から，

$$
\begin{aligned}
    \sum _ {t \in T(n)} f(t)
    &= \sum _ {l \le i \le r} f(n p _ i) \\
    &= f(m p _ l ^ {c + 1}) + \sum _ {l + 1 \le i \le r} f(n) f(p _ i) \quad (\because \gcd(n, p _ i) = 1) \\
    &= f(m) f(p _ l ^ {c + 1}) + f(n) \left( S _ \mathrm{prime} \left( \left \lfloor \frac{N}{n} \right \rfloor \right) - S _ \mathrm{prime} (p _ l)\right)
\end{aligned}
$$

として所望の値が計算できる．
ここで，$S _ \mathrm{prime}(n) := \sum _ {p \le n, p \text{ is prime}} f(p)$ と定めた．

### $S _ \mathrm{prime}(n)$ の列挙

$S _ \mathrm{prime}(n)$ の値が必要となる $n$ は $\sqrt{n}$ 以下の素数及び $\left \lfloor \frac{N}{i} \right \rfloor\ (i \ge 1)$ と表せるような計 $\mathrm{O}(\sqrt{N})$ 個である．
素数 $p$ に対して $f(p)$ が $p$ についての多項式であり $f(p) = \sum _ i a _ i p ^ i$ と表せるとき，

$$
S _ \mathrm{prime}(n)
= \sum _ {p \le n, p \text{ is prime}} \sum _ i a _ i p ^ i
= \sum _ i a _ i \sum _ {p \le n, p \text{ is prime}} p ^ i
$$

となるため，$S _ \mathrm{prime} ^ i(n) := \sum _ {p \le n, p \text{ is prime}} p ^ i$ が列挙できれば良い．
これは Counting Primes と同様の動的計画法により可能である．

$f ^ i(n, x)$ を $2$ 以上 $n$ 以下であって，$x$ 以下でふるいをかけた際に残る整数 $p$ についての $p ^ i$ の和の個数と定めると，

$$
S _ \mathrm{prime} ^ i(n) = f ^ i\left( N, \left \lfloor \sqrt{N} \right \rfloor \right)
$$

である．
このとき，

$$
f ^ i(n, x) =
\begin{cases}
    f ^ i(n, x - 1) & (x \text{ is not prime} \lor n < x ^ 2) \\
    f ^ i(n, x - 1) - x ^ i \left( f ^ i \left( \left \lfloor \frac{n}{x} \right \rfloor, x - 1 \right) - S _ \mathrm{prime} ^ i(x - 1) \right) & (\text{o.w.})
\end{cases}
$$

が成立する．
$S _ \mathrm{prime} ^ i(n)$ を求めるにあたり必要となる $f ^ i(n, x)$ の値は $n = \left \lfloor \frac{N}{1} \right \rfloor, \left \lfloor \frac{N}{2} \right \rfloor, \dots , \left \lfloor \frac{N}{N} \right \rfloor$ 及び $x = 1, \dots , \left \lfloor \sqrt{N} \right \rfloor$ のみで，これを動的計画法により計算していく．
ライブラリでは登場頻度の高い $S _ \mathrm{prime} ^ 0(n), S _ \mathrm{prime} ^ 1(n)$ の列挙については補助関数を導入しているが，$2$ 次以上の場合は適宜加える必要がある．

全体の時間計算量について，後半の $S _ \mathrm{prime}(n)$ を求めるパートについては Counting Primes と同じく $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ である．
一方，前半パートの計算量は考えた木の葉でない頂点の数に比例するが，その数は一般には $\mathrm{O}(N ^ {1 - \epsilon})$ となる．
しかし，競技プログラミングで登場する制約内（$N \le 10 ^ {12}$ 程度を想定）では $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ として抑えることができ，実際高速に動作する．

**テンプレート引数の `f(p, c)` には $f(p ^ c)$ の値を返す関数を渡す．**

| メンバ関数                  | 効果                                                                                                                                            | 時間計算量                                            |
| --------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------- |
| `counting_primes()`         | $S _ \mathrm{prime}^0(n)$，すなわち $n$ 以下の素数の個数を $\left \lfloor \frac{N}{i} \right \rfloor$ として表せる $n$ について降順に列挙する． | $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ |
| `summing_primes()`          | $S _ \mathrm{prime}^1(n)$，すなわち $n$ 以下の素数の総和を $\left \lfloor \frac{N}{i} \right \rfloor$ として表せる $n$ について降順に列挙する． | $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ |
| `solve(S_prime)`            | $S _ \mathrm{prime}$ のテーブルを引数として $\sum _ {i = 1} ^ N f(i)$ を計算する．                                                              | $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ |
| `sum_of_totient_function()` | $\sum _ {i = 1} ^ N \phi(i)$ を計算する．                                                                                                       | $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ |

**$S _ {\mathrm{prime}}$ のテーブルは $S _ \mathrm{prime}^0, S _ \mathrm{prime}^1$ 等の線形結合により各自で計算する必要があることに注意．**

### 乗法的関数の例

- totient 関数 $\phi(n)$


## 出題例
- [第五回日本最強プログラマー学生選手権 -決勝- B - Erase Multiples](https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_b)