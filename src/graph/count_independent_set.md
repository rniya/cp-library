---
title: Count Independent Sets
documentation_of: ./count_independent_set.hpp
---

## 概要
$n$ 頂点の自己ループを含まないグラフ $G$ の独立集合の個数を数える．
計算量は $\mathrm{O}(n 1.381^n)$．

`unsigned long long` を使って計算している都合上，$n < 64$ という制約を課している（オーバーフローさせたり mod を取ったりでそれ以上の値でも計算自体は可能）．

## Links
- [指数時間アルゴリズム入門 \| PPT](https://www.slideshare.net/wata_orz/ss-12131479)