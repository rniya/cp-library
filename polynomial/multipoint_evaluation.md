---
title: multipoint evaluation
documentation_of: ./multipoint_evaluation.hpp
---

## 概要
$n$ 次多項式 $f(x)$ と相異なる $m$ 点 $x_1, x_2, \dots , x_m$ に対し，$f(x_1), f(x_2), \dots , f(x_m)$ を $O(m (\log m)^2 + n \log n)$ で求めるアルゴリズム．

剰余の定理より $f(a) = f(x) \bmod (x - a)$ であるから $f(x_1) \bmod (x - x_1), f(x_2) \bmod (x - x_2), \dots , f(x_m) \bmod (x - x_m)$ が求まれば良い．

ここで，次のような各ノードに多項式をもつ根付き 2 分木 (subproduct tree) を構築する．
まず，木は $m$ 個の葉ノードをもち，各ノードには $x - x_1, x - x_2, \dots , x - x_m$ が書かれている．
そして，葉以外のノードにはその 2 つの子ノードに書かれた多項式の積が書かれている．
subproduct tree は $O(m (\log m)^2)$ 時間で構築可能である．

次に根の多項式を $f \bmod (x - x_1) (x - x_2) \dots (x - x_m)$ に書き換える．
これは $O((n + m) \log (n + m))$ 時間かかる．
また，多項式 $f, g, h$ に対して $(f \bmod g h) \bmod g = f \bmod g$ が成り立つことから，根から葉に逆方向に向かって $f$ をそのノードに書かれた多項式で割った余りを計算できる．
これは最初の構築と同様で $O(m (\log m)^2)$ 時間で処理できる．

こうして最終的に葉ノードに書かれた値が求めたかった評価値である．

## TODO:
middle product を利用した高速化

## 問題例
- [AtCoder Beginner Contest 272 Ex - Flipping Coins 2]

## Links
- [Multipoint Evaluation の アルゴリズム – 37zigenのHP](https://37zigen.com/multipoint-evaluation/)
