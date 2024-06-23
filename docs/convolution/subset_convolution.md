---
title: Subset Convolution
documentation_of: //src/convolution/subset_convolution.hpp
---

## 入力

$\lbrack n \rbrack := \lbrace 0, 1, \dots , n - 1 \rbrace$，$\mathbb{K}$ を環とする．
このもとでの集合関数 $f \colon 2 ^ {\lbrack n \rbrack} \to \mathbb{K},\ g \colon 2 ^ {\lbrack n \rbrack} \to \mathbb{K}$．

## 出力
関数 $f, g$ の subset convolution．
すなわち，

$$
(f \ast g) \colon 2 ^ {\lbrack n \rbrack} \ni S \to \sum_{T \subseteq S} f(T) g(S \setminus T) \in \mathbb{K}
$$

で定義される集合関数 $(f \ast g)$．

## 計算量

時間計算量 $\mathrm{O}(n ^ 2 2 ^ n)$

## Links
- [Xmas Contest 2020 H: Hierarchical Phylogeny 解説 - hos.lyric's blog](https://hos-lyric.hatenablog.com/entry/2021/01/14/201231)
- [Subset Convolutionのアルゴリズム – 37zigenのHP](https://37zigen.com/subset-convolution/)
- [Optimal Algorithm on Polynomial Composite Set Power Series - Codeforces](https://codeforces.com/blog/entry/92183)
- [集合冪級数 (Set Power Series) のダブリングまとめ - suisen のブログ](https://suisen-kyopro.hatenablog.com/entry/2023/04/07/041318)
- [集合べき級数解説 \| maspyのHP](https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0)

## 出題例
