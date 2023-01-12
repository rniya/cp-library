---
title: Line Container (based on kactl)
documentation_of: ./LineContainer.hpp
---

## 概要
直線 $f(x) = ax + b$ の追加及びある $x$ での最小値（最大値）クエリを効率的に処理するデータ構造．
Convex Hull Trick と異なり，追加する直線の傾きの単調性は問わない．
実装は [kactl](https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h#L1) から．
__実数での処理を行う際にはコメントにある注意に沿って適宜書き換える必要がある．__

| メンバ関数  | 効果                             | 時間計算量         |
| ----------- | -------------------------------- | ------------------ |
| `add(k, m)` | 直線 $f(x) = kx + m$ を追加する. | 全体 $O(n \log n)$ |
| `query(x)`  | $x$ における最小値を求める.      | クエリ $O(\log n)$ |

## 問題例
- [TOKI Regular Open Contest #22 F. MCD](https://tlx.toki.id/contests/troc-22/problems/F)
  - 2 乗和は Slope Optimization．
- [AtCoder Beginner Contest 244 H - Linear Maximization](https://atcoder.jp/contests/abc244/tasks/abc244_h)
  - 実数での処理．