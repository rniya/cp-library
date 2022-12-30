---
title: monotone minima
documentation_of: ./monotone_minima.hpp
---

## 概要
$N \times M$ 行列 $A$ が, $1 \leq i < k \leq H,\ 1 \leq j < l \leq W$ を満たす任意の $i, j, k, l$ について，
$$A_{i, j} + A_{k, l} \leq A_{i, l} + A_{j, k}$$
を満たすとき，$A$ は Monge 行列であるという．
$A$ が Monge 行列となる必要十分条件は $1 \leq i < H,\ 1 \leq j < W$ を満たす任意の $i, j$ について，
$$A_{i, j} + A_{i + 1, j + 1} \leq A_{i, j + 1} + A_{i + 1, j}$$
であることも容易にわかる．

Monge 行列を特徴づける性質として monotone というものがある．
これは $f(i)$ を行 $i$ の最小要素のうち最左にあるものの列番号とすると，$1 \leq i < H$ を満たす任意の $i$ について $f(i) \leq f(i + 1)$，すなわち $f(i)$ が単調増加となるというものである．
さらに，行列 $A$ の任意の部分行列が monotone であるとき，$A$ は totally monotone であるといい，「$A$ が Monge 行列 $\Rightarrow$ $A$ は totally monotone $\Rightarrow$ $A$ は monotone」というような論理関係にある．
また，$A$ が totally monotone であることの必要十分条件は $A$ の任意の $2 \times 2$ 部分行列が monotone であることでもある．

monotone minima とは，monotone な行列における $f(i)\ (1 \leq i < H)$ を全て求める効率的な分割統治アルゴリズムである．
この分割統治の手法としては主要なものが 2 種類ある．1 つ目は偶数行目だけ取り出した部分行列について解を再帰的に求め，この情報をもとに残りの奇数行目についても解を求めるというものである．
この考え方は，totally monotone 性を仮定して $f(i)$ をより高速に求める SMAWK algorithm に応用される．
弊実装はこの手法を取っている．
2 つ目の手法は中央の行の $f$ の値を愚直に求め，その情報をもとに他の行での探索範囲を狭めていくというアイデアで，この考え方は Divide and Conquer Optimization に効いてくる．

ソースコードにおいて，引数の関数 `select(i, j, k)` は $A_{i, j} > A_{i, k}$ を判定する関数である．
行列を陽にもつと空間計算量が $O(HW)$ かかってしまうのでこのような形式を取っている．

## 計算量
$O(W + H \log W)$

## 問題例
- [2020-2021 Summer Petrozavodsk Camp, Day 6: Korean Contest F. Rhythm Game](https://codeforces.com/gym/102984/problem/F)

## 参照
- [Monge 行列と monotone minima について - Lorent’s diary](https://lorent-kyopro.hatenablog.com/entry/2021/04/04/133958)
- [DP高速化 - ferinの競プロ帳](https://ferin-tech.hatenablog.com/entry/2018/02/23/071343)
- [Knuth-Yao speedup - 週刊 spaghetti_source - TopCoder部](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html)