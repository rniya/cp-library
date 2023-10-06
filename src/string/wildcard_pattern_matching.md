---
title: Wildcard Pattern Matching
documentation_of: ./wildcard_pattern_matching.hpp
---

## 概要
長さ $n$ の文字列 $S$ と長さ $m$ の文字列 $T$ を入力とし，$i = 0, \dots , n - m$ について，$S[i, i + m)$ と $T$ が一致するか判定する．
ただし，2 つの文字列は任意の一文字を指し示すワイルドカードを含むことがある．

$$
\mathrm{cmp}(s, t) = s t (s - t)^2
$$
を定めると，$\mathrm{cmp}(s, t)$ は $s = t$ もしくは $s, t$ の少なくとも一方がワイルドカードに一致するときにのみ $0$ となり，それ以外の場合は正の値を取る．
従って，
$$
\begin{aligned}
    S[i,  i + m) = T
    &\iff \sum_{k = 0}^{m - 1} \mathrm{cmp}(S[i + k], T[k]) = 0 \\
    &\iff \sum_{k = 0}^{m - 1} S[i + k]^3 T[k] - 2 S[i + k]^2 T[k]^2 + S[i + k] T[k]^3 = 0
\end{aligned}
$$
が成立し，最後の式を畳み込みにより計算することで $\mathrm{O}((n + m) \log (n + m))$ 時間で計算可能である．

## 問題例
- [AtCoder Beginner Contest 307 Ex - Marquee](https://atcoder.jp/contests/abc307/tasks/abc307_h)