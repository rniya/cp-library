---
title: Relaxed Convolution
documentation_of: //src/convolution/RelaxedConvolution.hpp
---

## 概要
未知の $N$ 次多項式 $f, g$ があり，$h(x) = f(x) g(x)$ であるとき，$i = 0, 1, \dots , N$ の順に以下のクエリを計 $\mathrm{O}(N \log ^ 2 N)$ 時間で処理する．
- $[x ^ i] f(x), [x ^ i] g(x)$ が与えられるので，$[x ^ i] h(x)$ を返す．

## 出題例
- [AtCoder Beginner Contest 230 H - Bullion](https://atcoder.jp/contests/abc230/tasks/abc230_h)
- [AtCoder Beginner Contest 315 Ex - Typical Convolution Problem](https://atcoder.jp/contests/abc315/tasks/abc315_h)

## Links
- [オンライン畳み込み - Qiita](https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c)
