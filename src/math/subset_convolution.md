---
title: Subset Convolution
documentation_of: ./subset_convolution.hpp
---

## 概要

$[n] \coloneqq \{0, 1, \dots , n - 1\}$ 、及び $\mathbb{K}$ を環とする。
集合関数 $f \colon 2^{[n]} \to \mathbb{K},\ g \colon 2^{[n]} \to \mathbb{K}$ の subset convolution $f \ast g$ を以下で定義する：
$$
(f \ast g) \colon S \in 2^{[n]} \to \sum_{T \subseteq S} f(T) g(S \setminus T) \in \mathbb{K}
$$

subset convolution はランク付き zeta / mobius 変換を経由して $\mathrm{O}(n^2 2^n)$ 時間で計算することができる。


## Links
- [Xmas Contest 2020 H: Hierarchical Phylogeny 解説 - hos.lyric's blog](https://hos-lyric.hatenablog.com/entry/2021/01/14/201231)
- [Subset Convolutionのアルゴリズム – 37zigenのHP](https://37zigen.com/subset-convolution/)
- [Optimal Algorithm on Polynomial Composite Set Power Series - Codeforces](https://codeforces.com/blog/entry/92183)
- [集合冪級数 (Set Power Series) のダブリングまとめ - suisen のブログ](https://suisen-kyopro.hatenablog.com/entry/2023/04/07/041318)
- [集合べき級数解説 \| maspyのHP](https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0)

## 問題例
