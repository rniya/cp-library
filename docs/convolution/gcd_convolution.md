---
title: GCD Convolution
documentation_of: //src/convolution/gcd_convolution.hpp
---

## 入力

ともに長さ $n$ の数列 $a _ 1, \dots , a _ n$ 及び $b _ 1, \dots , b _ n$．

## 出力

数列 $a$ と $b$ の index の最大公約数についての畳み込み．
すなわち，

$$
c _ k = \sum _ {\gcd(i, j) = k} a _ i b _ j
$$

で定義される長さ $n$ の数列 $c$．

## 計算量

時間計算量 $\mathrm{O}(n \log \log n)$

## 出題例
- [AtCoder Grand Contest 038 C - LCMs](https://atcoder.jp/contests/agc038/tasks/agc038_c)
- [COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred) G. GCD Festival](https://codeforces.com/contest/1575/problem/G)

## Links
- [約数集合でのゼータ変換・メビウス変換的なやつと畳み込み - kazuma8128’s blog](https://kazuma8128.hatenablog.com/entry/2018/07/29/231819)
- [添え字 gcd での畳み込みで AGC038-C を解く - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/09/23/002445)
- [高速ゼータ変換の約数版 $O(N \log(\log(N)))$ - noshi91のメモ](https://noshi91.hatenablog.com/entry/2018/12/27/121649)
