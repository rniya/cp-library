---
title: Rectangle Set
documentation_of: ./RectangleSet.hpp
---

## 概要
「$x \geqq a$ または $y \geqq b$」という条件が追加されていく際の $\min x + y$ を逐次計算する．

| メンバ関数  | 効果                                                     | 時間計算量       |
| ----------- | -------------------------------------------------------- | ---------------- |
| `add(a, b)` | 「$x \geqq a$ または $y \geqq b$」という条件を追加する． | 均し $O(\log n)$ |
| `query()`   | その時点での $\min x + y$ を返す．                       | $O(\log n)$      |

## 問題例
[Codeforces Round #230 (Div. 1) D. Three Arrays](https://codeforces.com/contest/392/problem/D)
