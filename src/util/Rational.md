---
title: Rational Number
documentation_of: ./Rational.hpp
---

## 概要
有理数を効率的に処理するためのライブラリ. 基本的な四則演算や比較演算子等に対応している. また $1/0$ や $-1/0$ によって $\pm \infty$ にも対応している.

デフォルトでは約分は行わない設定となっている (約分する際には分子と分母の $\gcd$ を求める必要があるが, これによって TLE する可能性がある [問題例](https://onlinejudge.u-aizu.ac.jp/problems/1131)) ．
引数 `Reduce` を `true` にすることで自動で約分を行うようにできる．
ただし，`my_gcd` 内で 64 bit 整数特有の計算を行っているため 128 bit 整数を扱う際には注意が必要である．

## 問題例
- [AtCoder Beginner Contest 301 G - Worst Picture](https://atcoder.jp/contests/abc301/tasks/abc301_g)
