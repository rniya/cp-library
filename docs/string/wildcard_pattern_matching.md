---
title: Wildcard Pattern Matching
documentation_of: //src/string/wildcard_pattern_matching.hpp
---

## 入力
文字列 $S, T\ (\vert S \vert \geq \vert T \vert)$

## 出力

長さの等しい文字列 $S ^ \prime, T ^ \prime$ が各 $0 \leq i < \vert S ^ \prime \vert $ について

- $S ^ \prime _ i = T ^ \prime _ i$
- $S ^ \prime _ i$ が wildcard
- $T ^ \prime _ i$ が wildcard

のいずれかを満たすとき，$S ^ \prime$ と $T ^ \prime$ はマッチすると呼ぶことにする．

このときの

$$
v_i = 
\begin{cases}
1 & \text{($S \lbrack i, i + \vert T \vert)$ と $T$ がマッチしている)} \\
0 & \text{(otherwise)}
\end{cases}
\quad (0 \leq i \leq \vert S \vert - \vert T \vert)
$$

で定まる長さ $\vert S \vert - \vert T \vert + 1$ の配列 $v$

## 計算量

- 時間計算量 $\mathrm{O}((\vert S \vert + \vert T \vert) \log (\vert S \vert + \vert T \vert))$
- 空間計算量 $\mathrm{O}(\vert S \vert + \vert T \vert)$

## 概要

任意の文字 $s, t$ について

$$
\mathrm{cmp}(s, t) := (s - t)^2 \mathbf{1}(s \gt 0) \mathbf{1}(t \gt 0)
$$

と定めると，$\mathrm{cmp}(s, t)$ は $s = t$ もしくは $s, t$ の少なくとも一方が wildcard に一致するときにのみ $0$ となり，それ以外の場合は正の値を取る．
ただし，$\mathbf{1}(x)$ は命題 $x$ が真のとき $1$，偽のとき $0$ を返す関数とする．

従って，

$$
\begin{aligned}
    S \lbrack i,  i + \vert T \vert) = T
    && \iff & \sum _ {k = 0} ^ {\vert T \vert - 1} \mathrm{cmp}(S \lbrack i + k \rbrack, T \lbrack k \rbrack) = 0 \\
    && \iff & \sum _ {k = 0} ^ {\vert T \vert - 1} \left \lbrack  S \lbrack i + k \rbrack^2 \mathbf{1}(S \lbrack i + k \rbrack \gt 0) \mathbf{1}(T \lbrack k \rbrack \gt 0) \right. \\
    &&& - 2 S \lbrack i + k \rbrack T \lbrack k \rbrack \mathbf{1}(S \lbrack i + k \rbrack \gt 0) \mathbf{1}(T \lbrack k \rbrack \gt 0) \\
    &&& \left. + T \lbrack k \rbrack^2 \mathbf{1}(S \lbrack i + k \rbrack \gt 0) \mathbf{1}(T \lbrack k \rbrack \gt 0) \right \rbrack = 0
\end{aligned}
$$

が成立し，最後の式は畳み込みにより計算可能である．

また，現れる文字の種類数を $\sigma$ として，畳み込んだ結果現れる数値の最大値 $(\sigma - 1) ^ 2 |T|$ が畳み込みで用いる $\text{mod}$ 未満ならば判定は決定的となる．

## 出題例
- [AtCoder Beginner Contest 307 Ex - Marquee](https://atcoder.jp/contests/abc307/tasks/abc307_h)
- [DEGwer さんの D 論応援コンテスト H - Incomplete Notes](https://atcoder.jp/contests/DEGwer2023/tasks/1202Contest_h)
- [Codeforces Round 947 (Div. 1 + Div. 2) G. Zimpha Fan Club](https://codeforces.com/contest/1975/problem/G)

## Links
- [ワイルドカードマッチングの高速化 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2024/05/26/060854)