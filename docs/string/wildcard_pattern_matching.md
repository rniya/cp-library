---
title: Wildcard Pattern Matching
documentation_of: ../../src/string/wildcard_pattern_matching.hpp
---

## 入力
文字列 $S, T\ (|S| \geq |T|)$

以下では $n := |S|, m := |T|$ とする．

## 出力

長さの等しい文字列 $S^\prime, T^\prime$ が各 $0 \leq i < |S^\prime|$ について

- $S^\prime_i = T^\prime_i$
- $S^\prime_i$ が wildcard
- $T^\prime_i$ が wildcard

のいずれかを満たすとき，$S^\prime$ と $T^\prime$ はマッチすると呼ぶことにする．

このときの

$$
v_i = 
\begin{cases}
1 & \text{($S[i, i + m)$ と $T$ がマッチしている)} \\
0 & \text{(otherwise)}
\end{cases}
\quad (0 \leq i \leq n - m)
$$

で定まる長さ $n - m + 1$ の配列 $v$

## 計算量

- 時間計算量 $\mathrm{O}((n + m) \log (n + m))$
- 空間計算量 $\mathrm{O}(n + m)$

## 概要

任意の文字 $s, t$ について

$$
\mathrm{cmp}(s, t) := (s - t)^2 \mathbf{1}(s > 0) \mathbf{1}(t > 0)
$$

と定めると，$\mathrm{cmp}(s, t)$ は $s = t$ もしくは $s, t$ の少なくとも一方が wildcard に一致するときにのみ $0$ となり，それ以外の場合は正の値を取る．
ただし，$\mathbf{1}(x)$ は命題 $x$ が真のとき $1$，偽のとき $0$ を返す関数とする．

従って，

$$
\begin{aligned}
    S[i,  i + |T|) = T
    && \iff & \sum_{k = 0}^{m - 1} \mathrm{cmp}(S[i + k], T[k]) = 0 \\
    && \iff & \sum_{k = 0}^{m - 1} \left[ S[i + k]^2 \mathbf{1}(s > 0) \mathbf{1}(t > 0) \right. \\
    &&& - 2 S[i + k] T[k] \mathbf{1}(s > 0) \mathbf{1}(t > 0) \\
    &&& \left. + T[k]^2 \mathbf{1}(s > 0) \mathbf{1}(t > 0) \right] = 0
\end{aligned}
$$

が成立し，最後の式は畳み込みにより計算可能である．

## 問題例
- [AtCoder Beginner Contest 307 Ex - Marquee](https://atcoder.jp/contests/abc307/tasks/abc307_h)
- [DEGwer さんの D 論応援コンテスト H - Incomplete Notes](https://atcoder.jp/contests/DEGwer2023/tasks/1202Contest_h)