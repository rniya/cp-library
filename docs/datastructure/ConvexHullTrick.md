## 概要
直線 $f(x) = ax + b$ の追加 (ただし, $a$ は単調増加もしくは単調減少) 及びある $x$ での最小値 (最大値) クエリを効率的に処理するデータ構造.
最小値を求めることを考えると,

- 固定された $x$ に対して最小値を取る直線の傾きは $x$ が増加するにつれて減少する.
- 不必要な直線がない (どの直線もそれで最小値を取るような $x$ が存在する) とき, 固定された $x$ での直線上の値は直線の傾き順に並べると下に凸となる.

といった性質があることに注目して高速化が行える. 1 つ目の性質より, 直線は傾きの降順に追加される `deque` によって管理することが可能である. 2 つ目の性質より最小値クエリは二分探索によって答えることができる. また, 最小値クエリにおける $x$ にも単調性がある際にはさらに計算量を削減することができる.

以下に記す時間計算量における $n$ は追加される直線の本数, $q$ は最小値クエリの数である.

| メンバ関数              | 効果                                      | 時間計算量         |
| ----------------------- | ----------------------------------------- | ------------------ |
| `empty()`               | 直線が空か確認する.                       | $O(1)$             |
| `add(a, b)`             | 直線 $f(x) = ax + b$ を追加する.          | 全体 $O(n)$        |
| `query(x)`              | $x$ における最小値を求める.               | クエリ $O(\log n)$ |
| `query_monotone_inc(x)` | $x$ が単調増加であるときに最小値を求める. | 全体 $O(n + q)$    |
| `query_monotone_dec(x)` | $x$ が単調減少であるときに最小値を求める. | 全体 $O(n + q)$    |

## 問題例
- [Codeforces Round #222 (Div. 1) E. Cookie Clicker](https://codeforces.com/contest/377/problem/E)
- [Codeforces Round #549 (Div. 1) C. U2](https://codeforces.com/contest/1142/problem/C)
- [AtCoder Regular Contest 051 D - 長方形](https://atcoder.jp/contests/arc051/tasks/arc051_d)

## Links
- [Convex-Hull Trick - sataniC++](https://satanic0258.hatenablog.com/entry/2016/08/16/181331)
- [Convex-Hull-Trick-Add-Monotone \| Luzhiled’s Library](https://ei1333.github.io/library/structure/convex-hull-trick/convex-hull-trick-add-monotone.cpp)
