## 概要
区分線形凸関数 $f(x)$ を傾きの変化点の集合を管理することで, 諸操作を効率的に行えるようにしたデータ構造.

- `query()` : $f(x)$ が最小値を取るような $x$ の最小値, 最大値, そのときの $f(x)$ の値を `tuple` にして返す.
- `add_all(a)` : $f(x)$ に均一に $a$ を加算する.
- `add_x_minus_a(a)` : $f(x)$ に $\max(x - a, 0)$ を加算する.
- `add_a_minus_x(a)` : $f(x)$ に $\max(a - x, 0)$ を加算する.
- `add_abs(a)` : $f(x)$ に $|x - a|$ を加算する.
- `cumulative_min_left()` : $f(x) \leftarrow \min_{y \leq x} f(y)$ とする.
- `cumulative_min_right()` : $f(x) \leftarrow \min_{x \leq y} f(y)$ とする.
- `shift(a, b)` : $f(x) \leftarrow \min_{y \in [x - b, x - a]} f(y)$ とする.
- `shift(a)` : $f(x) \leftarrow f(x - a)$ とする.
- `get(x)` : $f(x)$ を取得する. その際, それまでに取得した直線の情報は全て消えてしまうので注意.

## 計算量
- `query(), add_all()` : $O(1)$
- `add_x_minus_a(a), add_a_minus_x(a), add_abs(a)` : $O(\log Q)$
- `cumulative_min_left(), cumulative_min_right()` : $O(Q)$
- `shift(a, b), shift(a)` : $O(1)$
- `get(x)` : $O(Q)$

## 問題例
[AtCoder Beginner Contest 217 H- Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h)
[Codeforces LATOKEN Round 1 (Div. 1 + Div. 2) G. A New Beginning](https://codeforces.com/contest/1534/problem/G)

## 参照
[[Tutorial] Slope Trick - Codeforces](https://codeforces.com/blog/entry/47821)
[Slope trick explained - Codeforces](https://codeforces.com/blog/entry/77298)
[slope trick (1) 解説編 | maspyのHP](https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8)
[Slope-Trick | Luzhiled’s Library](https://ei1333.github.io/library/structure/others/slope-trick.cpp)