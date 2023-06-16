---
title: Dulmage-Mendelsohn Decomposition (DM 分解)
documentation_of: ./Dulmage_Mendelsohn.hpp
---

## 概要

以下では 2 部グラフ $G(U, V ; E)$ について考えることにする。

#### 劣モジュラ関数
集合関数 $f : 2^U \to \mathbb{R}$ について $\forall X, Y \subseteq U,\ f(X) + f(Y) \geq f(X \cup Y) + f(X \cap Y)$ が成立するとき $f$ は劣モジュラ関数であるという。
$X \subseteq U$ に対し $\Gamma(U) \subseteq V$ を $X$ の点に隣接する $V$ の部分集合として $\Gamma : 2^U \to 2^V$ を定める。
$f : 2^U \to \mathbb{Z}$ を $f(X) = |\Gamma(X)| - |X|$ とすると、$f$ は劣モジュラ関数である。

<details>
<summary>証明</summary>
<div>

$\Gamma(X \cup Y) = \Gamma(X) \cup \Gamma(Y),\ \Gamma(X \cap Y) \subseteq \Gamma(X) \cap \Gamma(Y)$ より、
$$
\begin{aligned}
    f(X) + f(Y)
    & = |\Gamma(X)| + |\Gamma(Y)| - (|X| + |Y|) \\
    & = |\Gamma(X) \cup \Gamma(Y)| + |\Gamma(X) \cap \Gamma(Y)| - (|X \cup Y| + |X \cap Y|) \\
    & \geq (|\Gamma(X \cup Y)| - |X \cup Y|) + (|\Gamma(X \cap Y)| - |X \cap Y|) \\
    & = f(X \cup Y) + f(X \cap Y).
\end{aligned}
$$
$\blacksquare$

</div>
</details>

$$
\mathcal{D}(f) \coloneqq \{X \subseteq U \mid \forall Z \subseteq U,\ f(X) \leq f(Z)\}
$$
とする。
すなわち、$\mathcal{D}(f)$ は $f$ の最小化元の集合である。
このとき、$X, Y \in \mathcal{D}(f) \implies X \cup Y, X \cap Y \in \mathcal{D}(f)$ が成立する。

<details>
<summary>証明</summary>
<div>

$\alpha \coloneqq \min_{Z \subseteq U} f(Z)$ とすると、$X, Y \in \mathcal{D}(f)$ のとき、$f$ は劣モジュラ関数かつ $\alpha$ の定義と併せると、
$$
2 \alpha = f(X) + f(Y) \geq f(X \cup Y) + f(X \cap Y) \geq 2 \alpha.
$$
$$
\therefore f(X \cup Y) + f(X \cap Y) = 2 \alpha.
$$
再び $\alpha$ の最小性から $f(X \cup Y), f(X \cap Y) \geq \alpha$ だから
$$
f(X \cup Y) = f(X \cap Y) = \alpha
$$
に限り、従って $X \cup Y, X \cap Y \in \mathcal{D}(f)$。
$\blacksquare$

</div>
</details>

#### 分配束

半順序集合 $L$ について、$x \vee y$ を $x$ と $y$ の共通上界 $U \coloneqq \{z \in L \mid z \geq x,\ z \geq y\}$ の最小元として定める。
すなわち、$w \in U$ であって任意の $z \in U$ に対し $z \geq w$ を満たす $w$ を $x \vee y$ とする。

同様にして $x \wedge y$ を $x$ と $y$ の共通下界 $\{z \in L \mid z \leq x,\ z \leq y\}$ の最大元として定める。

半順序集合 $L$ について、任意の $x, y \in L$ に対して $x \vee y$ 及び $x \wedge y$ が定まるとき $L$ は束であるという。

束 $L$ と任意の $x, y, z \in L$ について以下の分配不等式が成立する。
$$
\begin{aligned}
    x \vee (y \wedge z) & \leq (x \vee y) \wedge (x \vee z), \\
    x \wedge (y \vee z) & \geq (x \wedge y) \vee (x \wedge z).
\end{aligned}
$$

<details>
<summary>証明</summary>
<div>

第 1 式を示す。
$\vee$ の定義より $x \leq (x \vee y),\ x \leq (x \vee z)$ であり、右辺の $(x \vee y) \wedge (x \vee z)$ は $(x \vee y)$ と $(x \vee z)$ の共通下界の最大元であったから $x \leq (x \vee y) \wedge (x \vee z)$。
また、$(y \wedge z) \leq y \leq (x \vee y),\ (y \wedge z) \leq z \leq (x \vee z)$ だから、同様にして $(y \wedge z) \leq (x \vee y) \wedge (x \vee z)$。

よって、右辺の $(x \vee y) \wedge (x \vee z)$ は $x$ と $y \wedge z$ の共通上界に含まれ、左辺の $x \vee (y \wedge z)$ はその共通上界の最小元であるから与式が成立する。

第 2 式も同様にして証明可能である。
$\blacksquare$

</div>
</details>

束 $L$ について、任意の $x, y, z \in L$ に対し分配不等式が等号で成立するとき、特に $L$ を分配束であるという。

ここで、一般に有限集合 $S$ とその集合族 $\mathcal{F} \subseteq 2^S$ について、$X, Y \in \mathcal{F} \implies X \cup Y, X \cap Y \in \mathcal{F}$ が成立するならば $\mathcal{F}$ を包含関係により順序付けた半順序集合は分配束である。
これは条件より $\mathcal{F}$ は束を成し、集合の包含関係についての分配法則が成り立つことから分配束であることは明らかである。

以上より、先に定めた $\mathcal{D}(f)$ は分配束であることがわかる。

#### 分配束の極大鎖
<!-- 極大鎖の大きさ、つまり分配束の高さがその取り方によらず一定であること -->
<!-- 集合の要素に踏み込んだ極大鎖ついての各性質も説明が必要そう -->

#### アルゴリズム

#### マッチングにおける諸性質
<!-- 必ず使われる辺かを判定できる等の話 -->

## 書くこと
- マッチングとの関連性（必ず使われる辺）

## 問題例
- [yukicoder No.1615 Double Down](https://yukicoder.me/problems/no/1615)
- [yukicoder No.1744 Selfish Spies 1 (à la Princess' Perfectionism)](https://yukicoder.me/problems/no/1744)
- [yukicoder No.1745 Selfish Spies 2 (à la Princess' Perfectionism)](https://yukicoder.me/problems/no/1745)
- [AtCoder Beginner Contest 223 G. Vertex Deletion](https://atcoder.jp/contests/abc223/tasks/abc223_g)
- [ICPC 2021 国内予選 F 完璧主義な王女様](https://icpc.iisf.or.jp/past-icpc/domestic2021/contest/F_ja.html)
- [AtCoder Regular Contest 161 F - Everywhere is Sparser than Whole (Judge)](https://atcoder.jp/contests/arc161/tasks/arc161_f)

## Links
- [Dulmage–Mendelsohn 分解 (DM 分解)](http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf)
- K. Murota: Matrices and Matroids for Systems Analysis, Springer-Verlag, Berlin, 2000.