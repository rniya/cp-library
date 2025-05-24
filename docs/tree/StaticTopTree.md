---
title: Static Top Tree
documentation_of: //src/tree/StaticTopTree.hpp
---

## 概要

木の生成過程を二分木としてもつデータ構造．
Static Top Tree の各頂点はもとの木における 1 つのパスが expose された部分木を表す．
Static Top Tree の葉はもとの木の各頂点（と virtual な根を結んだ木）に対応し，これらを virtual な根同士を縮約するようにマージする rake 操作，heavy path に沿って上下にマージする compress 操作によって全体の木を作り上げている（[このブログ](https://maspypy.com/library-checker-point-set-tree-path-composite-sum)の図がわかりやすい）．
$n$ 頂点の木に対する Static Top Tree の高さは $\mathrm{O}(\log n)$ であり，これにより分割統治等各種計算を効率的に行える．

実装の際には以下のような構造体 `TreeDP` を要する．
`T` には部分木内の各種データや expose されたパスに対応するデータをもつと良い．
また，`rake(l, r)` においては `l` の expose されたパスがマージ後のそれに対応し，`compress(l, r)` では `l` のパスの下に `r` のパスをつなげるようにマージが行われる．

`DynamicTreeDP` では各頂点に対して，その頂点に載るデータだけでなくそれと親頂点を結ぶ辺（これが expose されていると考えて良い）上のデータも載せる．

```c++
struct TreeDP {
    struct T {};

    static T rake(const T& l, const T& r) {}

    static T compress(const T& l, const T& r) {}
};
```


## 出題例
- [AtCoder Beginner Contest 269 Ex - Antichain](https://atcoder.jp/contests/abc269/tasks/abc269_h)
- [AtCoder Beginner Contest 351 G - Hash on Tree](https://atcoder.jp/contests/abc351/tasks/abc351_g)
- [The 3rd Universal Cup. Stage 37: Wuhan B. Black Red Tree](https://contest.ucup.ac/contest/2025/problem/10737)