---
title: Multipoint Evaluation
documentation_of: //src/polynomial/multipoint_evaluation.hpp
---

## 入力

$N - 1$ 次多項式 $f(x)$ 及び数列 $x _ 0, \dots , x _ {M - 1}$．

## 出力

評価値 $f(x _ 0), \dots , f(x _ {M - 1})$．

## 計算量

時間計算量 $\mathrm{O}(M \log ^ 2 M + N \log N)$

## 概要

剰余の定理より $f(a) = f(x) \bmod (x - a)$ であるから $f(x _ 0) \bmod (x - x _ 0), f(x _ 1) \bmod (x - x _ 1), \dots , f(x _ {M - 1}) \bmod (x - x _ {M - 1})$ が求まれば良い．

ここで，次のような各ノードに多項式をもつ根付き 2 分木 (subproduct tree) を構築する．
まず，木は $M$ 個の葉ノードをもち，各ノードには $x - x _ 0, x - x _ 1, \dots , x - x _ {M - 1}$ が書かれている．
そして，葉以外のノードにはその 2 つの子ノードに書かれた多項式の積が書かれている．
subproduct tree は $\mathrm{O}(M \log ^2 M)$ 時間で構築可能である．

次に根の多項式を $f \bmod (x - x _ 0) (x - x _ 1) \dots (x - x _ {M - 1})$ に書き換える．
これは $\mathrm{O}((N + M) \log (N + M))$ 時間かかる．
また，多項式 $f, g, h$ に対して $(f \bmod g h) \bmod g = f \bmod g$ が成り立つことから，根から葉に逆方向に向かって $f$ をそのノードに書かれた多項式で割った余りを計算できる．
これは最初の構築と同様で $\mathrm{O}(M \log ^ 2 M)$ 時間で処理できる．

こうして最終的に葉ノードに書かれた値が求めたかった評価値である．

## TODO:
middle product を利用した高速化

## 出題例
- [AtCoder Beginner Contest 272 Ex - Flipping Coins 2](https://atcoder.jp/contests/abc272/tasks/abc272_h)
- [技術室奥プログラミングコンテスト#6 Day2 K - Ball in the Box 2](https://atcoder.jp/contests/tkppc6-2/tasks/tkppc6_2_k)
- [The 1st Universal Cup. Stage 16: Gomel E. Classical FFT Problem](https://qoj.ac/contest/1223/problem/6411?v=1)

## Links
- [Multipoint Evaluation の アルゴリズム – 37zigenのHP](https://37zigen.com/multipoint-evaluation/)
