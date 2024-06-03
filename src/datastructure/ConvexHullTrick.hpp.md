---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/952.test.cpp
    title: test/yukicoder/952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/ConvexHullTrick.hpp\"\n#include <cassert>\n\
    #include <queue>\n\ntemplate <typename T, bool isMin = true> struct ConvexHullTrick\
    \ {\n    std::deque<std::pair<T, T>> lines;  // slope decreases as index increases\n\
    \n    bool empty() const { return lines.empty(); }\n\n    void add(T a, T b) {\n\
    \        if (!isMin) a *= -1, b *= -1;\n        std::pair<T, T> l(a, b);\n   \
    \     if (empty()) {\n            lines.emplace_back(a, b);\n            return;\n\
    \        }\n        if (lines.front().first <= a) {\n            if (lines.front().first\
    \ == a) {\n                if (lines.front().second <= b) return;\n          \
    \      lines.pop_front();\n            }\n            while (lines.size() >= 2\
    \ && check(l, lines.front(), lines[1])) lines.pop_front();\n            lines.emplace_front(l);\n\
    \        } else if (a <= lines.back().first) {\n            if (lines.back().first\
    \ == a) {\n                if (lines.back().second <= b) return;\n           \
    \     lines.pop_back();\n            }\n            while (lines.size() >= 2 &&\
    \ check(lines[lines.size() - 2], lines.back(), l)) lines.pop_back();\n       \
    \     lines.emplace_back(l);\n        } else\n            assert(false);\n   \
    \ }\n\n    T query(T x) {\n        assert(!called_query_monotonic_inc && !called_query_monotonic_dec);\n\
    \        assert(!empty());\n        called_query = true;\n        int lb = -1,\
    \ ub = lines.size() - 1;\n        while (ub - lb > 1) {\n            int mid =\
    \ (ub + lb) >> 1;\n            (f(lines[mid], x) >= f(lines[mid + 1], x) ? lb\
    \ : ub) = mid;\n        }\n        T res = f(lines[ub], x);\n        return isMin\
    \ ? res : -res;\n    }\n\n    T query_monotone_inc(T x) {\n        assert(!called_query\
    \ && !called_query_monotonic_dec);\n        assert(!empty());\n        if (!called_query_monotonic_inc)\n\
    \            called_query_monotonic_inc = true;\n        else\n            assert(prev_query\
    \ <= x);\n        prev_query = x;\n        while (lines.size() >= 2 && f(lines.front(),\
    \ x) >= f(lines[1], x)) lines.pop_front();\n        T res = f(lines.front(), x);\n\
    \        return isMin ? res : -res;\n    }\n\n    T query_monotone_dec(T x) {\n\
    \        assert(!called_query && !called_query_monotonic_inc);\n        assert(!empty());\n\
    \        if (!called_query_monotonic_dec)\n            called_query_monotonic_dec\
    \ = true;\n        else\n            assert(x <= prev_query);\n        prev_query\
    \ = x;\n        while (lines.size() >= 2 && f(lines.back(), x) >= f(lines[lines.size()\
    \ - 2], x)) lines.pop_back();\n        T res = f(lines.back(), x);\n        return\
    \ isMin ? res : -res;\n    }\n\n  private:\n    bool called_query = false, called_query_monotonic_inc\
    \ = false, called_query_monotonic_dec = false;\n    T prev_query;\n\n    using\
    \ D = long double;\n\n    // check if b is unnecessary\n    inline bool check(const\
    \ std::pair<T, T>& a, const std::pair<T, T>& b, const std::pair<T, T>& c) {\n\
    \        // return (b.first - a.first) * (c.second - b.second) >= (c.first - b.first)\
    \ * (b.second - a.second);\n        // note that slopes are distinct and decrease\n\
    \        return D(c.second - b.second) / (c.first - b.first) >= D(b.second - a.second)\
    \ / (b.first - a.first);\n    }\n\n    inline T f(const std::pair<T, T>& l, T\
    \ x) { return l.first * x + l.second; }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <queue>\n\ntemplate <typename\
    \ T, bool isMin = true> struct ConvexHullTrick {\n    std::deque<std::pair<T,\
    \ T>> lines;  // slope decreases as index increases\n\n    bool empty() const\
    \ { return lines.empty(); }\n\n    void add(T a, T b) {\n        if (!isMin) a\
    \ *= -1, b *= -1;\n        std::pair<T, T> l(a, b);\n        if (empty()) {\n\
    \            lines.emplace_back(a, b);\n            return;\n        }\n     \
    \   if (lines.front().first <= a) {\n            if (lines.front().first == a)\
    \ {\n                if (lines.front().second <= b) return;\n                lines.pop_front();\n\
    \            }\n            while (lines.size() >= 2 && check(l, lines.front(),\
    \ lines[1])) lines.pop_front();\n            lines.emplace_front(l);\n       \
    \ } else if (a <= lines.back().first) {\n            if (lines.back().first ==\
    \ a) {\n                if (lines.back().second <= b) return;\n              \
    \  lines.pop_back();\n            }\n            while (lines.size() >= 2 && check(lines[lines.size()\
    \ - 2], lines.back(), l)) lines.pop_back();\n            lines.emplace_back(l);\n\
    \        } else\n            assert(false);\n    }\n\n    T query(T x) {\n   \
    \     assert(!called_query_monotonic_inc && !called_query_monotonic_dec);\n  \
    \      assert(!empty());\n        called_query = true;\n        int lb = -1, ub\
    \ = lines.size() - 1;\n        while (ub - lb > 1) {\n            int mid = (ub\
    \ + lb) >> 1;\n            (f(lines[mid], x) >= f(lines[mid + 1], x) ? lb : ub)\
    \ = mid;\n        }\n        T res = f(lines[ub], x);\n        return isMin ?\
    \ res : -res;\n    }\n\n    T query_monotone_inc(T x) {\n        assert(!called_query\
    \ && !called_query_monotonic_dec);\n        assert(!empty());\n        if (!called_query_monotonic_inc)\n\
    \            called_query_monotonic_inc = true;\n        else\n            assert(prev_query\
    \ <= x);\n        prev_query = x;\n        while (lines.size() >= 2 && f(lines.front(),\
    \ x) >= f(lines[1], x)) lines.pop_front();\n        T res = f(lines.front(), x);\n\
    \        return isMin ? res : -res;\n    }\n\n    T query_monotone_dec(T x) {\n\
    \        assert(!called_query && !called_query_monotonic_inc);\n        assert(!empty());\n\
    \        if (!called_query_monotonic_dec)\n            called_query_monotonic_dec\
    \ = true;\n        else\n            assert(x <= prev_query);\n        prev_query\
    \ = x;\n        while (lines.size() >= 2 && f(lines.back(), x) >= f(lines[lines.size()\
    \ - 2], x)) lines.pop_back();\n        T res = f(lines.back(), x);\n        return\
    \ isMin ? res : -res;\n    }\n\n  private:\n    bool called_query = false, called_query_monotonic_inc\
    \ = false, called_query_monotonic_dec = false;\n    T prev_query;\n\n    using\
    \ D = long double;\n\n    // check if b is unnecessary\n    inline bool check(const\
    \ std::pair<T, T>& a, const std::pair<T, T>& b, const std::pair<T, T>& c) {\n\
    \        // return (b.first - a.first) * (c.second - b.second) >= (c.first - b.first)\
    \ * (b.second - a.second);\n        // note that slopes are distinct and decrease\n\
    \        return D(c.second - b.second) / (c.first - b.first) >= D(b.second - a.second)\
    \ / (b.first - a.first);\n    }\n\n    inline T f(const std::pair<T, T>& l, T\
    \ x) { return l.first * x + l.second; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/ConvexHullTrick.hpp
  requiredBy: []
  timestamp: '2024-06-04 01:15:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/952.test.cpp
documentation_of: src/datastructure/ConvexHullTrick.hpp
layout: document
title: Convex Hull Trick (Add-Monotonic Slope Optimization)
---

## 概要
直線 $f(x) = ax + b$ の追加（ただし, $a$ は単調増加もしくは単調減少）及びある $x$ での最小値（最大値）クエリを効率的に処理するデータ構造．
最小値を求めることを考えると，

- 固定された $x$ に対して最小値を取る直線の傾きは $x$ が増加するにつれて減少する．
- 不必要な直線がない（どの直線もそれで最小値を取るような $x$ が存在する）とき，固定された $x$ での直線上の値は直線の傾き順に並べると下に凸となる．

といった性質があることに注目して高速化が行える．
1 つ目の性質より，直線は傾きの降順に追加される `deque` によって管理することが可能である．
2 つ目の性質より最小値クエリは二分探索によって答えることができる．
また，最小値クエリにおける $x$ にも単調性がある際にはさらに計算量を削減することができる．

以下に記す時間計算量における $n$ は追加される直線の本数，$q$ は最小値クエリの数である．

| メンバ関数              | 効果                                       | 時間計算量         |
| ----------------------- | ------------------------------------------ | ------------------ |
| `empty()`               | 直線が空か確認する．                       | $O(1)$             |
| `add(a, b)`             | 直線 $f(x) = ax + b$ を追加する．          | 全体 $O(n)$        |
| `query(x)`              | $x$ における最小値を求める．               | クエリ $O(\log n)$ |
| `query_monotone_inc(x)` | $x$ が単調増加であるときに最小値を求める． | 全体 $O(n + q)$    |
| `query_monotone_dec(x)` | $x$ が単調減少であるときに最小値を求める． | 全体 $O(n + q)$    |

## 問題例
- [Codeforces Round #222 (Div. 1) E. Cookie Clicker](https://codeforces.com/contest/377/problem/E)
- [Codeforces Round #549 (Div. 1) C. U2](https://codeforces.com/contest/1142/problem/C)
- [AtCoder Regular Contest 051 D - 長方形](https://atcoder.jp/contests/arc051/tasks/arc051_d)
- [COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred) M. Managing Telephone Poles](https://codeforces.com/contest/1575/problem/M)
  - 式変形すると，
    $$\begin{aligned}
        (x_i - x_j)^2 + (y_i - y_j)^2
        &= (-2x_ix_j - 2y_iy_j + x_j^2 + y_j^2) + (x_i^2 + y_i^2) \\
        &= \left[-2x_jx_i + \left(-2\frac{y_j}{x_j}y_i + x_j + \frac{y_j^2}{x_j}\right)x_j\right] + (x_i^2 + y_i^2) \\
    \end{aligned}$$
    となる．
    カッコ内の式は内側から順に計算していけばそれぞれ $y_i, x_i$ の $1$ 次式の最小化と見なせる．
    クエリや直線追加の順番を適切にすることで全体 $O(nm)$ で解くことができる．

## Links
- [Convex-Hull Trick - sataniC++](https://satanic0258.hatenablog.com/entry/2016/08/16/181331)
- [Convex-Hull-Trick-Add-Monotone \| Luzhiled’s Library](https://ei1333.github.io/library/structure/convex-hull-trick/convex-hull-trick-add-monotone.cpp)
