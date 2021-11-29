---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.test.cpp
    title: test/aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
    title: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/LazySegmentTree.md
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"datastructure/LazySegmentTree.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <typename Monoid, typename OperatorMonoid, typename\
    \ F, typename G, typename H> struct LazySegmentTree {\n    LazySegmentTree(int\
    \ n, const F f, const G g, const H h, const Monoid& e, const OperatorMonoid& id)\n\
    \        : n(n), f(f), g(g), h(h), e(e), id(id) {\n        size = 1;\n       \
    \ height = 0;\n        while (size < n) size <<= 1, height++;\n        data.assign(size\
    \ << 1, e);\n        lazy.assign(size << 1, id);\n    }\n\n    void set(int k,\
    \ Monoid x) {\n        assert(0 <= k && k < n);\n        data[k + size] = x;\n\
    \    }\n\n    void build() {\n        for (int k = size - 1; k > 0; k--) {\n \
    \           data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n        }\n    }\n\
    \n    void update(int a, int b, const OperatorMonoid& x) {\n        assert(0 <=\
    \ a && a <= b && b <= n);\n        if (a == b) return;\n        thrust(a += size);\n\
    \        thrust(b += size - 1);\n        for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n      \
    \      if (r & 1) --r, lazy[r] = h(lazy[r], x);\n        }\n        recalc(a);\n\
    \        recalc(b);\n    }\n\n    void set_val(int k, Monoid x) {\n        assert(0\
    \ <= k && k < n);\n        thrust(k += size);\n        data[k] = x;\n        lazy[k]\
    \ = id;\n        recalc(k);\n    }\n\n    Monoid query(int a, int b) {\n     \
    \   assert(0 <= a && a <= b && b <= n);\n        if (a == b) return e;\n     \
    \   thrust(a += size);\n        thrust(b += size - 1);\n        Monoid L = e,\
    \ R = e;\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n    \
    \        if (l & 1) L = f(L, apply(l++));\n            if (r & 1) R = f(apply(--r),\
    \ R);\n        }\n        return f(L, R);\n    }\n\n    Monoid operator[](int\
    \ k) {\n        thrust(k += size);\n        return apply(k);\n    }\n\n    template\
    \ <typename C> int find_first(int l, const C& check) {\n        assert(0 <= l\
    \ && l <= n);\n        assert(!check(e));\n        if (l == n) return n;\n   \
    \     Monoid L = e;\n        if (l == 0) {\n            if (check(f(L, apply(1))))\
    \ return find_subtree(1, check, L, false);\n            return n;\n        }\n\
    \        thrust(l + size);\n        int r = size;\n        for (l += size, r +=\
    \ size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n               \
    \ Monoid nxt = f(L, apply(l));\n                if (check(nxt)) return find_subtree(l,\
    \ check, L, false);\n                L = nxt;\n                l++;\n        \
    \    }\n        }\n        return n;\n    }\n\n    template <typename C> int find_last(int\
    \ r, const C& check) {\n        assert(0 <= r && r <= n);\n        assert(!check(e));\n\
    \        if (r == 0) return 0;\n        Monoid R = e;\n        if (r == n) {\n\
    \            if (check(f(apply(1), R))) return find_subtree(1, check, R, true);\n\
    \            return -1;\n        }\n        thrust(r + size - 1);\n        int\
    \ l = size;\n        for (r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (r & 1) {\n                Monoid nxt = f(apply(--r), R);\n                if\
    \ (check(nxt)) return find_subtree(r, check, R, true);\n                R = nxt;\n\
    \            }\n        }\n        return -1;\n    }\n\nprivate:\n    int n, size,\
    \ height;\n    std::vector<Monoid> data;\n    std::vector<OperatorMonoid> lazy;\n\
    \    const F f;\n    const G g;\n    const H h;\n    const Monoid e;\n    const\
    \ OperatorMonoid id;\n\n    inline Monoid apply(int k) { return lazy[k] == id\
    \ ? data[k] : g(data[k], lazy[k]); }\n\n    inline void propagate(int k) {\n \
    \       if (lazy[k] == id) return;\n        lazy[k << 1 | 0] = h(lazy[k << 1 |\
    \ 0], lazy[k]);\n        lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);\n  \
    \      data[k] = apply(k);\n        lazy[k] = id;\n    }\n\n    inline void thrust(int\
    \ k) {\n        for (int i = height; i > 0; i--) propagate(k >> i);\n    }\n\n\
    \    inline void recalc(int k) {\n        while (k >>= 1) data[k] = f(apply(k\
    \ << 1 | 0), apply(k << 1 | 1));\n    }\n\n    template <typename C> int find_subtree(int\
    \ a, const C& check, Monoid& M, bool type) {\n        while (a < size) {\n   \
    \         propagate(a);\n            Monoid nxt = type ? f(apply(a << 1 | type),\
    \ M) : f(M, apply(a << 1 | type));\n            if (check(nxt))\n            \
    \    a = a << 1 | type;\n            else\n                M = nxt, a = (a <<\
    \ 1 | 1) - type;\n        }\n        return a - size;\n    }\n};\n\n/**\n * @brief\
    \ Lazy Segment Tree\n * @docs docs/datastructure/LazySegmentTree.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ Monoid, typename OperatorMonoid, typename F, typename G, typename H> struct\
    \ LazySegmentTree {\n    LazySegmentTree(int n, const F f, const G g, const H\
    \ h, const Monoid& e, const OperatorMonoid& id)\n        : n(n), f(f), g(g), h(h),\
    \ e(e), id(id) {\n        size = 1;\n        height = 0;\n        while (size\
    \ < n) size <<= 1, height++;\n        data.assign(size << 1, e);\n        lazy.assign(size\
    \ << 1, id);\n    }\n\n    void set(int k, Monoid x) {\n        assert(0 <= k\
    \ && k < n);\n        data[k + size] = x;\n    }\n\n    void build() {\n     \
    \   for (int k = size - 1; k > 0; k--) {\n            data[k] = f(data[k << 1\
    \ | 0], data[k << 1 | 1]);\n        }\n    }\n\n    void update(int a, int b,\
    \ const OperatorMonoid& x) {\n        assert(0 <= a && a <= b && b <= n);\n  \
    \      if (a == b) return;\n        thrust(a += size);\n        thrust(b += size\
    \ - 1);\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n     \
    \       if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n            if (r & 1) --r,\
    \ lazy[r] = h(lazy[r], x);\n        }\n        recalc(a);\n        recalc(b);\n\
    \    }\n\n    void set_val(int k, Monoid x) {\n        assert(0 <= k && k < n);\n\
    \        thrust(k += size);\n        data[k] = x;\n        lazy[k] = id;\n   \
    \     recalc(k);\n    }\n\n    Monoid query(int a, int b) {\n        assert(0\
    \ <= a && a <= b && b <= n);\n        if (a == b) return e;\n        thrust(a\
    \ += size);\n        thrust(b += size - 1);\n        Monoid L = e, R = e;\n  \
    \      for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) L = f(L, apply(l++));\n            if (r & 1) R = f(apply(--r), R);\n \
    \       }\n        return f(L, R);\n    }\n\n    Monoid operator[](int k) {\n\
    \        thrust(k += size);\n        return apply(k);\n    }\n\n    template <typename\
    \ C> int find_first(int l, const C& check) {\n        assert(0 <= l && l <= n);\n\
    \        assert(!check(e));\n        if (l == n) return n;\n        Monoid L =\
    \ e;\n        if (l == 0) {\n            if (check(f(L, apply(1)))) return find_subtree(1,\
    \ check, L, false);\n            return n;\n        }\n        thrust(l + size);\n\
    \        int r = size;\n        for (l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) {\n                Monoid nxt = f(L, apply(l));\n\
    \                if (check(nxt)) return find_subtree(l, check, L, false);\n  \
    \              L = nxt;\n                l++;\n            }\n        }\n    \
    \    return n;\n    }\n\n    template <typename C> int find_last(int r, const\
    \ C& check) {\n        assert(0 <= r && r <= n);\n        assert(!check(e));\n\
    \        if (r == 0) return 0;\n        Monoid R = e;\n        if (r == n) {\n\
    \            if (check(f(apply(1), R))) return find_subtree(1, check, R, true);\n\
    \            return -1;\n        }\n        thrust(r + size - 1);\n        int\
    \ l = size;\n        for (r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (r & 1) {\n                Monoid nxt = f(apply(--r), R);\n                if\
    \ (check(nxt)) return find_subtree(r, check, R, true);\n                R = nxt;\n\
    \            }\n        }\n        return -1;\n    }\n\nprivate:\n    int n, size,\
    \ height;\n    std::vector<Monoid> data;\n    std::vector<OperatorMonoid> lazy;\n\
    \    const F f;\n    const G g;\n    const H h;\n    const Monoid e;\n    const\
    \ OperatorMonoid id;\n\n    inline Monoid apply(int k) { return lazy[k] == id\
    \ ? data[k] : g(data[k], lazy[k]); }\n\n    inline void propagate(int k) {\n \
    \       if (lazy[k] == id) return;\n        lazy[k << 1 | 0] = h(lazy[k << 1 |\
    \ 0], lazy[k]);\n        lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);\n  \
    \      data[k] = apply(k);\n        lazy[k] = id;\n    }\n\n    inline void thrust(int\
    \ k) {\n        for (int i = height; i > 0; i--) propagate(k >> i);\n    }\n\n\
    \    inline void recalc(int k) {\n        while (k >>= 1) data[k] = f(apply(k\
    \ << 1 | 0), apply(k << 1 | 1));\n    }\n\n    template <typename C> int find_subtree(int\
    \ a, const C& check, Monoid& M, bool type) {\n        while (a < size) {\n   \
    \         propagate(a);\n            Monoid nxt = type ? f(apply(a << 1 | type),\
    \ M) : f(M, apply(a << 1 | type));\n            if (check(nxt))\n            \
    \    a = a << 1 | type;\n            else\n                M = nxt, a = (a <<\
    \ 1 | 1) - type;\n        }\n        return a - size;\n    }\n};\n\n/**\n * @brief\
    \ Lazy Segment Tree\n * @docs docs/datastructure/LazySegmentTree.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2021-09-21 14:13:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1270.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/2667.test.cpp
  - test/aoj/DSL_2_E.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: datastructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/datastructure/LazySegmentTree.hpp
- /library/datastructure/LazySegmentTree.hpp.html
title: Lazy Segment Tree
---
## 概要
遅延伝搬を採用することで, Segment Tree には行えなかった区間更新を可能にしたデータ構造. モノイド $(S, \cdot, e)$ と $S$ から $S$ への写像の集合 $F$ について,

- $F$ はモノイド : 結合律が成立し, 単位元 $id$ が存在する ($id$ は恒等写像) .
- $F$ は $S$ について準同型 : $\forall f \in F,\ \forall a, b \in S,\ f(a \cdot b) = f(a) \cdot f(b)$
- $F$ は写像の合成について閉じている : $\forall f, g \in F,\ g \circ f \in F,\ \forall a \in S,\ (g \circ f)(a) = g(f(a))$

を満たしていることが要件となる. このとき, 区間全体に $f \in F$ を作用させたり区間取得が $O(\log n)$ で可能となる.

| メンバ関数                           | 効果                                                                                                                                                                      | 時間計算量  |
| ------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------- |
| `LazySegmentTree(n, f, g, h, e, id)` | 要素数 $n$ の単位元で初期化する. ここで, $f$ は $S$ 上の二項演算, $g$ は $F$ から $S$ への作用, $h$ は $F$ 上の二項演算, $e$ は $S$ の単位元, $id$ は $F$ の単位元である. | $O(n)$      |
| `set(k, x)`                          | $k$ 番目の要素に $x$ を代入する. ここで, この後各クエリに答えるには `build()` を挟んで親ノードの情報を更新してからでないといけないことに注意.                             | $O(1)$      |
| `build()`                            | `set` された情報をもとに Segment Tree を構築する.                                                                                                                         | $O(n)$      |
| `update(a, b, x)`                    | 区間 $[a, b)$ の要素について作用素 $x$ を適用する.                                                                                                                        | $O(\log n)$ |
| `set_val(k, x)`                      | $k$ 番目の要素に $x$ を代入して更新する.                                                                                                                                  | $O(\log n)$ |
| `query(a, b)`                        | 区間 $[a, b)$ の要素について二項演算を適用した結果を返す. 結合律が成立することからこの結果は一意に定まる.                                                                 | $O(\log n)$ |
| `operator[k]`                        | $k$ 番目の要素を返す.                                                                                                                                                     | $O(\log n)$ |
| `find_first(l, check)`               | $[l, x]$ (右端点を含む) が `check` を満たすような最小の $x$ を返す. 存在しない場合は $n$ を返す.                                                                          | $O(\log n)$ |
| `find_last(r, check)`                | $[x, r)$ (左端点を含む) が `check` を満たすような最大の $x$ を返す. 存在しない場合は $-1$ を返す.                                                                         | $O(\log n)$ |

## Remark
- [Educational Codeforces Round 101 (Rated for Div. 2) F. Power Sockets](https://codeforces.com/contest/1469/problem/F)
  - 区間加算区間和取得において `find_first` といった二分探索関数を用いる際には, 始点を厳密に定めないと想定し得ない挙動を起こすので注意.
