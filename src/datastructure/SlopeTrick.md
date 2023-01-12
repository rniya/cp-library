---
title: Slope Trick
documentation_of: ./SlopeTrick.hpp
---

## 概要
区分線形凸関数 $f(x)$ を傾きの変化点の集合を管理することで，諸操作を効率的に行えるようにしたデータ構造．

| メンバ関数             | 効果                                                                                            | 時間計算量                                                              |
| ---------------------- | ----------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| `query()`              | $f(x)$ が最小値を取るような $x$ の最小値，最大値，そのときの $f(x)$ の値を `tuple` にして返す． | $O(1)$                                                                  |
| `add_const()`          | $f(x)$ に均一に $a$ を加算する．                                                                | $O(1)$                                                                  |
| `add_a_minus_x(a)`     | $f(x)$ に $\max(x - a, 0)$ を加算する．                                                         | $O(\log N)$                                                             |
| `add_x_minus_a(a)`     | $f(x)$ に $\max(a - x, 0)$ を加算する．                                                         | $O(\log N)$                                                             |
| `add_abs(a)`           | $f(x)$ に $\|x - a\|$ を加算する．                                                              | $O(\log N)$                                                             |
| `chmin_right()`        | $f(x) \leftarrow \min_{y \leq x} f(y)$ とする．                                                 | $O(N)$                                                                  |
| `chmin_left()`         | $f(x) \leftarrow \min_{x \leq y} f(y)$ とする．                                                 | $O(N)$                                                                  |
| `shift(a, b)`          | $f(x) \leftarrow \min_{y \in [x - b, x - a]} f(y)$ とする．$[x - b, x - a]$ であることに注意．  | $O(1)$                                                                  |
| `shift(a)`             | $f(x) \leftarrow f(x - a)$ とする．                                                             | $O(1)$                                                                  |
| `get_destructive(x)`   | $f$ を破壊する代わりに $f(x)$ を返す．                                                          | $O(N)$                                                                  |
| `merge_destructive(g)` | $g$ を破壊する代わりに $f(x)$ に $g(x)$ を加算する．                                            | $f, g$ の大きさをそれぞれ $N, M$ として $O(\min(N, M) \log \max(N, M))$ |

## 問題例
- [AtCoder Beginner Contest 217 H- Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h)
- [Codeforces LATOKEN Round 1 (Div. 1 + Div. 2) G. A New Beginning](https://codeforces.com/contest/1534/problem/G)
- [Codeforces Round #219 (Div. 1) C. Watching Fireworks is Fun](https://codeforces.com/contest/372/problem/C)
  - 想定解はスライド最小値．

## 参照
- [[Tutorial] Slope Trick - Codeforces](https://codeforces.com/blog/entry/47821)
- [Slope trick explained - Codeforces](https://codeforces.com/blog/entry/77298)
- [slope trick (1) 解説編 \| maspyのHP](https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8)
- [Slope-Trick \| Luzhiled’s Library](https://ei1333.github.io/library/structure/others/slope-trick.cpp)
