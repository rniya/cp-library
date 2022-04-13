---
title: Formal Power Series（形式的冪級数）
documentation_of: ./FormalPowerSeries.hpp
---

## 概要
形式的冪級数 (Formal Power Series) を効率的に扱うためのライブラリ．
AC Library の convolution に準拠している．
`inv` 等の関数について特に $\mathbb{F}_{998244353}[x]$ 等 $\bmod$ が NTT-friendly な場合を想定した高速化のもとに実装しているため，$\mathbb{F}_{10^9 + 7}[x]$ 等を扱う際は注意が必要である．

以下では

$$
f(x) = \sum_{i = 0}^{N - 1} a_ix^i
$$

に対する操作を想定する．

| メンバ関数       | 効果                                                           | 時間計算量    |
| ---------------- | -------------------------------------------------------------- | ------------- |
| `differential()` | $f^\prime(x)$ を求める．                                       | $O(N)$        |
| `integral()`     | $\int f(x) \mathrm{d}x$ を求める．                             | $O(N)$        |
| `inv()`          | $\frac{1}{f(x)}$ を求める．                                    | $O(N \log N)$ |
| `log()`          | $\log (f(x))$ を求める．                                       | $O(N \log N)$ |
| `sqrt()`         | $\sqrt{f(x)}$ を求める．                                       | $O(N \log N)$ |
| `exp()`          | $\exp (f(x))$ を求める．                                       | $O(N \log N)$ |
| `pow(k)`         | $f(x)^k$ を求める．                                            | $O(N \log N)$ |
| `eval(x)`        | $f(x)$ について $x$ に実際に値を代入した際の式の値を計算する． | $O(N \log N)$ |

メンバ関数 `inv(), log(), sqrt(), exp(), pow()` については引数に `deg` を指定することでその次数で計算を打ち切ることが可能である．
これらの操作では高次の項がより次数の低い項に影響を及ぼすことはないため，打ち切りに問題はない．

### 各種アルゴリズムの詳細

#### 乗算
$f(x)g(x)$ を求める．
これは Number Theoretic Transform により $O(N \log N)$ で計算可能である．

#### 微分・積分
$f^\prime(x), \int f(x) \mathrm{d}x$ を求める．
ただし，不定積分の積分定数は $0$ とする．
これは naive に計算可能である．
ここで，積分については $1$ から $N$ の $\mathbb{F}_p$ における逆元を求める必要があるが，これは愚直に求めようとすると時間計算量として $O(N \log \bmod)$ を要するが，$O(N)$ で求める方法がある．

$x$ の $\mathbb{F}_p$ における逆元を求めたい．
$p$ を $x$ で割ったときの商を $q$，余りを $r (r < x)$ とする．
$p = qx + r$ より，

$$
\begin{aligned}
    qx + r \equiv 0 \pmod{p}
    &\iff q + rx^{-1} \equiv 0 \pmod{p} \\
    &\iff r^{-1}q + x^{-1} \equiv 0 \pmod{p} \\
    &\iff x^{-1} \equiv -r^{-1}q \pmod{p}
\end{aligned}
$$

$r < x$ だから，上式に基づいて逆元テーブルを昇順に構築できる．

#### inv
$f(x)g(x) \equiv 1 \pmod{x^N}$ なる $g(x) = \sum_{i = 0}^{N - 1} b_ix^i$ を求める．
これを $\frac{1}{f(x)}$ とも表すことにする．

###### 補題
$fg_n \equiv 1 \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
このとき，

$$
g_{2n} = 2g_n - fg_n^2
$$

が成立する．

###### 証明
$fg_n \equiv 1 \pmod{x^n}$ より，$fg_n - 1= hx^n$ と表せる．
このとき，$(fg_n - 1)^2 = h^2x^{2n}$ だから，

$$
\begin{aligned}
    (fg_n - 1)^2 \equiv 0 \pmod{x^{2n}}
    &\iff f^2g_n^2 -2fg_n + 1 \equiv 0 \pmod{x^{2n}} \\
    &\iff f(2g_n - fg_n^2) \equiv 1 \pmod{x^{2n}} \\
    &\iff fg_{2n} \equiv 1 \pmod{x^{2n}} \quad (g_{2n} = 2g_n - fg_n^2)
\end{aligned}
$$

となる．

$\blacksquare$

$a_0 \neq 0$ のとき，$g_1 = a_0^{-1}$ だから帰納的にダブリングの要領で計算することが可能となる．
計算量は

$$
T(n) = T(n/2) + O(n \log n)
$$

より $O(N \log N)$ を得る．
また，$a_0 \neq 0$ が逆元の存在の必要条件にもなる．

ここで，以下の性質に注目する．

- $g_{2n}$ の $[0, n)$ 次の係数は $g_n$ のそれに一致する．
  よって，$g_{2n}$ の計算においては $fg_n^2$ の $[n, 2n)$ 次の係数が求まれば良い．
- $fg_n \equiv 1 \pmod{x^n}$ より $fg_n$ の $[1, n)$ 次の係数は $0$ であり，$fg_n$ の $n$ 次未満の部分の多項式を $h$ とすると，$h$ は $0$ 次の多項式となり，$g_n$ は $n - 1$ 次以下であるから $hg_n$ は $n - 1$ 次以下となり，$g_{2n}$ の計算においては無視して良い．

これらより，以下のより高速なアルゴリズムが提案される．
1. $f$ の $[0, n)$ 次の項を取り出したものを改めて $f$ と定める．
2. $h = fg_n \equiv x^{2n}$ を計算する．
3. $h$ の $[n, 2n)$ 次の項を取り出したものを改めて $h$ と定める．
4. $-hg_n$ を計算し，これの $[n, 2n)$ 次の係数が $g_{2n}$ のそれに一致する．

NTT と INTT をうまく組み合わせることでわざわざ畳み込む必要がなくなり，高速化が可能である．

#### log
$\log (f(x))$，すなわち，

$$
f(x) \equiv \sum_{k = 0}^{N - 1} \frac{g(x)^k}{k!} \pmod{x^N}
$$

なる $g(x)$ を求める．
$g(x)$ の定数項を $0$ とすると，$k \geq N$ については $g(x)^k$ の次数が $N$ 以上となるので打ち切っても問題はない．
逆にそうでなければ，$f(x)$ の定数項が不定となり計算不可能である．
また，このとき $a_0 = 0^0 = 1$ である．

$\log(f(x))$ と $\int \frac{f^\prime(x)}{f(x)} \mathrm{d}x$ の $N$ 次未満の項は一致することが確認できる．
これを素直に実装すれば良い．

#### sqrt
$f(x) \equiv g(x)^2 \pmod{x^N}$ なる $g(x)$ を求める．
これを $\sqrt{f(x)}$ とも表すことにする．

これも inv と同様の考え方で計算可能である．

$g_n^2 \equiv f \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
$a_0 \neq 0$ であれば $g_n$ の 0 次の係数は $0$ ではないので $g_n$ には逆元が存在する．
このとき，

$$
\begin{aligned}
    (g_n^2 - f)^2 \equiv 0 \pmod{x^{2n}}
    &\iff g_n^4 - 2fg_n^2 + f^2 \equiv 0 \pmod{x^{2n}} \\
    &\iff g_n^2 - 2f + f^2g_n^{-2} \equiv 0 \pmod{x^{2n}} \\
    &\iff 4f \equiv g_n^2 + 2f + f^2g_n^{-2} \pmod{x^{2n}} \\
    &\iff f \equiv \left[\frac{1}{2}(g_n + fg_n^{-1})\right]^2 \pmod{x^{2n}} \\
\end{aligned}
$$

より，

$$
g_{2n} = \frac{1}{2}(g_n + fg_n^{-1})
$$

とすれば $g_{2n}^2 \equiv f \pmod{x^{2n}}$ が成立する．
$g_1$ については別途離散対数問題を解くことで計算可能である．
あとはダブリングの要領で計算でき，計算量は $g_n^{-1}$ の計算がネックとなり，

$$
T(n) = T(n/2) + O(n \log n)
$$

より $O(N \log N)$ を得る．

次に $a_0 = 0$ の場合について考える．
$f$ の非零係数をもつ項の次数の最小値を $i$ とすると，$i$ が奇数であれば求めたい平方根が存在しないことは容易にわかる．
$i$ が偶数の場合は $[i, n)$ 次の項を抽出し $x^{-i}$ をかけて詰めた多項式を改めて $f$ と定めれば，上記のアルゴリズムを適用することができ，その結果得られた多項式に $x^{i/2}$ をかけたものが求めたい平方根となる．

#### exp
$\exp (f(x))$ ，すなわち，

$$
g(x) \equiv \sum_{k = 0}^{N - 1} \frac{f(x)^k}{k!} \pmod{x^N}
$$

なる $g(x)$ を求める．
$a_0 = 0$ とすると，$k \geq N$ については $f(x)^k$ の次数が $N$ 以上となるので打ち切っても問題はない．
逆にそうでなければ，$g(x)$ の定数項が不定となり計算不可能である．

$\exp (f) \equiv g_n \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
このとき， inv や sqrt と同様にして，

$$
g_{2n} = g_n(1 + f - \log g_n)
$$

が成立する．
計算量は同じく $O(N \log N)$ である．

これは一般の場合に計算可能な方法だが，$\bmod$ が NTT-friendly な場合には別のより高速な手法を用いることができる [1] ．

#### pow
$f(x)^k \pmod{x^N}$ を求める．繰り返し二乗法を用いると $O(N \log N \log k)$ で計算可能であるが，$O(N \log N)$ で計算することができる．

$a_0 = 1$ のとき，

$$
f(x)^k \equiv \exp (k \log f(x)) \pmod{x^N}
$$

が成立することを利用する．
定数項が $1$ の多項式 $g(x)$ を用いて $f(x) = cx^lg(x)\ (l \geq 0)$ と表せる．
このとき，$f(x)^k = c^kx^{lk}g(x)^k$ であることを利用すれば良い．

## 問題例
- [Codeforces Round #250 (Div. 1) E. The Child and Binary Tree](https://codeforces.com/contest/438/problem/E)

## Reference
[1] [A simple and fast algorithm for computing exponentials of power series](https://arxiv.org/pdf/1301.5804.pdf)

## Links
- [Operations on Formal Power Series - Codeforces](https://codeforces.com/blog/entry/56422)
- [fpsのニュートン法高速化(簡易版) – Dropbox Paper](https://paper.dropbox.com/doc/fps-EoHXQDZxfduAB8wD1PMBW)
