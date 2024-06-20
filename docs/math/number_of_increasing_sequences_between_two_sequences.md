---
title: Number of Increasing Sequences Between Two Sequences
documentation_of: //src/math/number_of_increasing_sequences_between_two_sequences.hpp
---

## 入力

長さ $n$ の数列 $a, b$

## 出力

任意の $i\ (0 \le i \lt n)$ について $a _ i \le x _ i \lt b _ i$ を満たす長さ $n$ の数列 $x$ の個数

## 計算量

$m := \max _ i b _ i - \min _ i a _ i$ として時間計算量 $\mathrm{O}((n + m) \log ^ 2 (n + m))$

## Links
- [上限付き単調増加列の数え上げ - noshi91のメモ](https://noshi91.hatenablog.com/entry/2023/07/21/235339)

## 出題例
- [XXI Open Cup, Grand Prix of Tokyo J. Japanese Knowledge](https://codeforces.com/gym/102978/problem/J)
- [The 13th Chinese Northeast Collegiate Programming Contest I. Temperature Survey](https://codeforces.com/gym/102220/problem/I)
- [Good Bye 2022: 2023 is NEAR G. Koxia and Bracket](https://codeforces.com/contest/1770/problem/G)
- [Hokkaido University Competitive Programming Camp 2023 Day 1 L: 01 Swap](https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2023Day1/problems/L)
- [AtCoder Grand Contest 058 B - Adjacent Chmax](https://atcoder.jp/contests/agc058/tasks/agc058_b)
- [Codeforces Round 942 (Div. 1) E1. Again Counting Arrays (Easy Version)](https://codeforces.com/contest/1967/problem/E1)
- [The 2nd Universal Cup. Stage 7: Two Capitals C. Cards](https://qoj.ac/contest/1399/problem/7634)
- [AtCoder Beginner Contest 357 G - Stair-like Grid](https://atcoder.jp/contests/abc357/tasks/abc357_g)