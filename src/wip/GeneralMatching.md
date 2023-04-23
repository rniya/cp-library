---
title: 一般マッチング (Tutte Matrix)
documentation_of: ./GeneralMatching.hpp
---

## 概要
二部グラフとは限らない一般のグラフにおける最大マッチングを求める乱択アルゴリズム。

### 完全マッチングの存在判定

#### 定義 (Tutte Matrix)
無向グラフ $G = (V, E)$ について、以下で定まる $n \times n$ 多変数正方行列 $T$ を $G$ の Tutte 行列という。

$$
T_{i, j} = \begin{cases}
0           & ((i, j) \notin E) \\
x_{i, j}    & ((i, j) \in E \land i < j) \\
-x_{i, j}    & ((i, j) \in E \land i > j)
\end{cases}.
$$

#### 定理
$|V|$ が偶数なるグラフ $G = (V, E)$ について、$G$ が完全マッチングをもつことの必要十分条件は $\det T \neq 0$ である。

<details>
<summary>証明</summary>
<div>

$$
\det T = \sum_{\sigma \in \mathfrak{S}_n} \mathrm{sgn}(\sigma) \prod_{i = 1}^n T_{i, \sigma(i)}
$$
である。
$f(\sigma) = \prod_{i = 1}^n T_{i, \sigma(i)}$ とする。

$G$ が完全マッチングをもつとき、これを $M = \{(u_1, v_1), \dots , (u_{n / 2}, v_{n / 2})\}$ とする。
$\sigma_M \in \mathfrak{S}_n$ を $\sigma_M(u_i) = v_i,\ \sigma_M(v_i) = u_i\ (1 \leq i \leq n / 2)$ と定めるとき、$f(\sigma) = f(\sigma_M) = \prod_{i = 1}^{n / 2} (- x_{u_i, v_i}^2)$ なる $\sigma \neq \sigma_M$ は存在しないから $\det T \neq 0$。

次に $\det T \neq 0$ の場合について考える。
一般に $G_\sigma = (V, E_\sigma)$ を $E_\sigma = \{(i, \sigma(i)) \mid 1 \leq i \leq n\}$ で定めるとする。

$G_\sigma$ に自己ループが存在する場合は $T$ の対角成分は $0$ であるから $f(\sigma) = 0$。
そうではなく奇数長の閉路が存在するとき、うち最小の頂点を含む閉路を $u_1, u_2 , \dots , u_k$ とする。
このとき、$\sigma(u_1) = u_2, \dots , \sigma(u_{k - 1}) = u_k, \sigma(u_k) = u_1$ であるが、他については同じで $\sigma^\prime(u_1) = u_k, \sigma(u_2) = u_1, \dots , \sigma(u_k) = u_{k - 1}$ のようにこの閉路に関して反転させた置換 $\sigma^\prime \in \mathfrak{S}_n$ を考えると、$\sigma \neq \sigma^\prime$ で $f(\sigma^\prime) = (- 1)^k f(\sigma) = - f(\sigma)$ であり、$\mathrm{sgn}(\sigma) = \mathrm{sgn}(\sigma^\prime)$ であるから行列式においてこれら 2 つの置換の寄与は相殺する。

以上より、$\det T$ の計算にあたっては $G_\sigma$ が奇数長の閉路をもたないような $\sigma$ についてのみ考えればよく、$\det T \neq 0$ より、$G$ の偶数長の閉路への分解が存在する。
ここで、各閉路について交互に辺を取ることにすると、これは完全マッチングである。
$\blacksquare$

</div>
</details>

これでグラフが完全マッチングをもつことの行列による特徴付けができたが、$\det T$ は最大 $n^2$ 変数 $n$ 次の多項式であり、評価はそのままでは時間を要する。

#### Schwartz-Zippel の補題
$f(x_1, \dots , x_m) \neq 0$ を体 $\mathbb{F}$ 上の全次数 $d$ の $m$ 変数多項式とする。
$S \subseteq \mathbb{F}$ を有限集合とし、$S$ から $a_1, \dots , a_m$ を一様独立に選ぶとき、
$$
\Pr[f(a_1, \dots , a_m) = 0] \leq d / |S|.
$$

<details>
<summary>証明</summary>
<div>

$m$ について帰納的に示す。

$m = 1$ のとき、$d$ 次多項式 $p$ の根は $F$ 上に高々 $d$ 個しか存在しないから明らか。

次に $m - 1$ 変数多項式について主張が正しいとする。
このとき、
$$
f(x_1, \dots , x_m) = \sum_{i = 0}^{d^\prime} p_i(x_1, \dots , x_{m - 1}) x_m^i
$$
であり、
$\blacksquare$

</div>
</details>

体 $\mathbb{F}$ として有限体 $\mathbb{Z} / p \mathbb{Z}$ を取り、$x_{i, j}$ を一様独立に $\mathbb{Z} / p \mathbb{Z}$ から選んで代入した $\det T$ は容易に計算可能であり、また $\det T \neq 0$ の場合に計算結果が誤って $0$ となる確率は $n / p$ で抑えられ、$p$ を十分大きく取ることで安全になる。

### 最大マッチングの構成
上の議論から最大マッチングの大きさは $T$ の最大の正則な主小行列の大きさに一致するが、実はこれは $T$ の $\mathrm{rank}$ に一致する。

<details>
<summary>証明</summary>
<div>

より一般に交代行列 $A$ について示す。

まず行列の $\mathrm{rank}$ の定義から $A$ の任意の正則な主小行列の大きさは $\mathrm{rank}\ A$ 以下である。
よって大きさ $\mathrm{rank}\ A$ の正則な主小行列が存在することを示せばよい。

</div>
</details>

前処理として消去法により最大マッチングの端点集合を求めておく。
以下ではそれを改めて頂点集合 $V = \{1, \dots , n\}$ とする。

$T$ から $X \in V$ に対応する行集合及び $Y \in V$ に対応する列集合を除いた行列を $T_{X, Y}$ と表すことにすると、$\det T = \sum_{j = 1}^n (- 1)^{1 + j} T_{1, j} \det T_{\{1\}, \{j\}}$ であり、$T_{1, 1} = 0$ に注意すると $\det T \neq 0$ だから $\det T_{\{1\}, \{j\}} \neq 0$ なる $j \in \{2, \dots , n\}$ が存在する。

ここで、Tutte 行列 $T$ においては $\det T_{\{1\}, \{j\}} \neq 0 \implies \det T_{\{1, j\}, \{1, j\}} \neq 0$ が成立する。

<details>
<summary>証明</summary>
<div>


</div>
</details>

よって、上記の $j$ を発見する操作を繰り返すことで最大マッチングを構成することが可能になる。
$\det T_{\{1\}, \{j\}} = (- 1)^{1 + j} T^{- 1}_{1, j} \det T$ であるから $T^{- 1}$ を計算することにより $\det T_{\{1\}, \{j\}}$ の非零性は容易に判別できる。

よって逆行列の計算を $O(n)$ 回行うことで構成可能となったが、逆行列の計算については逐一始めから $O(n^3)$ 時間かけて行う必要はなく、前ループの結果と Schur 補行列を利用して $O(n^2)$ 時間で計算可能であり、全体として $O(n^3)$ 時間で最大マッチングを構成できる。

#### Schur 補行列

## Links
- [kopricky さんのメモ](https://kopricky.github.io/code/Academic/maximum_matching_memo.html)

## 問題例
- [The 2021 ICPC Asia Shanghai Regional Programming Contest L. Three,Three,Three](https://codeforces.com/gym/103446/problem/L)