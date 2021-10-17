---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ukuku09_d.cpp
    title: test/atcoder/ukuku09_d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/SegmentTree.md
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"datastructure/SegmentTree.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename Monoid, typename F> struct SegmentTree {\n  \
    \  SegmentTree(int n, const F f, const Monoid& e) : n(n), f(f), e(e) {\n     \
    \   size = 1;\n        while (size < n) size <<= 1;\n        data.assign(size\
    \ << 1, e);\n    }\n\n    void set(int k, Monoid x) {\n        assert(0 <= k &&\
    \ k < n);\n        data[k + size] = x;\n    }\n\n    void build() {\n        for\
    \ (int k = size - 1; k > 0; k--) {\n            data[k] = f(data[k << 1 | 0],\
    \ data[k << 1 | 1]);\n        }\n    }\n\n    void update(int k, Monoid x) {\n\
    \        assert(0 <= k && k < n);\n        k += size;\n        data[k] = x;\n\
    \        while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n  \
    \  }\n\n    void add(int k, Monoid x) {\n        assert(0 <= k && k < n);\n  \
    \      k += size;\n        data[k] += x;\n        while (k >>= 1) data[k] = f(data[k\
    \ << 1 | 0], data[k << 1 | 1]);\n    }\n\n    Monoid query(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        Monoid L = e, R = e;\n\
    \        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) L = f(L, data[l++]);\n            if (r & 1) R = f(data[--r], R);\n\
    \        }\n        return f(L, R);\n    }\n\n    Monoid all_prod() const { return\
    \ data[1]; }\n\n    Monoid operator[](const int& k) const { return data[k + size];\
    \ }\n\n    template <typename C> int find_first(int l, const C& check) {\n   \
    \     assert(0 <= l && l <= n);\n        assert(!check(e));\n        if (l ==\
    \ n) return n;\n        Monoid L = e;\n        if (l == 0) {\n            if (check(f(L,\
    \ data[1]))) return find_subtree(1, check, L, false);\n            return n;\n\
    \        }\n        int r = size;\n        for (l += size, r += size; l < r; l\
    \ >>= 1, r >>= 1) {\n            if (l & 1) {\n                Monoid nxt = f(L,\
    \ data[l]);\n                if (check(nxt)) return find_subtree(l, check, L,\
    \ false);\n                L = nxt;\n                l++;\n            }\n   \
    \     }\n        return n;\n    }\n\n    template <typename C> int find_last(int\
    \ r, const C& check) {\n        assert(0 <= r && r <= n);\n        assert(!check(e));\n\
    \        if (r == 0) return 0;\n        Monoid R = e;\n        if (r == n) {\n\
    \            if (check(f(data[1], R))) return find_subtree(1, check, R, true);\n\
    \            return -1;\n        }\n        int l = size;\n        for (r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n                Monoid\
    \ nxt = f(data[--r], R);\n                if (check(nxt)) return find_subtree(r,\
    \ check, R, false);\n                R = nxt;\n            }\n        }\n    \
    \    return -1;\n    }\n\nprivate:\n    int n, size;\n    std::vector<Monoid>\
    \ data;\n    const F f;\n    const Monoid e;\n\n    template <typename C> int\
    \ find_subtree(int a, const C& check, Monoid& M, bool type) {\n        while (a\
    \ < size) {\n            Monoid nxt = type ? f(data[a << 1 | type], M) : f(M,\
    \ data[a << 1 | type]);\n            if (check(nxt))\n                a = a <<\
    \ 1 | type;\n            else\n                M = nxt, a = (a << 1 | 1) - type;\n\
    \        }\n        return a - size;\n    }\n};\n\n/**\n * @brief Segment Tree\n\
    \ * @docs docs/datastructure/SegmentTree.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ Monoid, typename F> struct SegmentTree {\n    SegmentTree(int n, const F f,\
    \ const Monoid& e) : n(n), f(f), e(e) {\n        size = 1;\n        while (size\
    \ < n) size <<= 1;\n        data.assign(size << 1, e);\n    }\n\n    void set(int\
    \ k, Monoid x) {\n        assert(0 <= k && k < n);\n        data[k + size] = x;\n\
    \    }\n\n    void build() {\n        for (int k = size - 1; k > 0; k--) {\n \
    \           data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n        }\n    }\n\
    \n    void update(int k, Monoid x) {\n        assert(0 <= k && k < n);\n     \
    \   k += size;\n        data[k] = x;\n        while (k >>= 1) data[k] = f(data[k\
    \ << 1 | 0], data[k << 1 | 1]);\n    }\n\n    void add(int k, Monoid x) {\n  \
    \      assert(0 <= k && k < n);\n        k += size;\n        data[k] += x;\n \
    \       while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n   \
    \ }\n\n    Monoid query(int l, int r) const {\n        assert(0 <= l && l <= r\
    \ && r <= n);\n        Monoid L = e, R = e;\n        for (l += size, r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = f(L, data[l++]);\n  \
    \          if (r & 1) R = f(data[--r], R);\n        }\n        return f(L, R);\n\
    \    }\n\n    Monoid all_prod() const { return data[1]; }\n\n    Monoid operator[](const\
    \ int& k) const { return data[k + size]; }\n\n    template <typename C> int find_first(int\
    \ l, const C& check) {\n        assert(0 <= l && l <= n);\n        assert(!check(e));\n\
    \        if (l == n) return n;\n        Monoid L = e;\n        if (l == 0) {\n\
    \            if (check(f(L, data[1]))) return find_subtree(1, check, L, false);\n\
    \            return n;\n        }\n        int r = size;\n        for (l += size,\
    \ r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n          \
    \      Monoid nxt = f(L, data[l]);\n                if (check(nxt)) return find_subtree(l,\
    \ check, L, false);\n                L = nxt;\n                l++;\n        \
    \    }\n        }\n        return n;\n    }\n\n    template <typename C> int find_last(int\
    \ r, const C& check) {\n        assert(0 <= r && r <= n);\n        assert(!check(e));\n\
    \        if (r == 0) return 0;\n        Monoid R = e;\n        if (r == n) {\n\
    \            if (check(f(data[1], R))) return find_subtree(1, check, R, true);\n\
    \            return -1;\n        }\n        int l = size;\n        for (r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n                Monoid\
    \ nxt = f(data[--r], R);\n                if (check(nxt)) return find_subtree(r,\
    \ check, R, false);\n                R = nxt;\n            }\n        }\n    \
    \    return -1;\n    }\n\nprivate:\n    int n, size;\n    std::vector<Monoid>\
    \ data;\n    const F f;\n    const Monoid e;\n\n    template <typename C> int\
    \ find_subtree(int a, const C& check, Monoid& M, bool type) {\n        while (a\
    \ < size) {\n            Monoid nxt = type ? f(data[a << 1 | type], M) : f(M,\
    \ data[a << 1 | type]);\n            if (check(nxt))\n                a = a <<\
    \ 1 | type;\n            else\n                M = nxt, a = (a << 1 | 1) - type;\n\
    \        }\n        return a - size;\n    }\n};\n\n/**\n * @brief Segment Tree\n\
    \ * @docs docs/datastructure/SegmentTree.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/SegmentTree.hpp
  requiredBy:
  - test/atcoder/ukuku09_d.cpp
  timestamp: '2021-09-20 22:49:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
documentation_of: datastructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/datastructure/SegmentTree.hpp
- /library/datastructure/SegmentTree.hpp.html
title: Segment Tree
---
## 概要
モノイド $(S, \cdot)$ を扱うデータ構造. 集合 $S$ とその上の二項演算 $\cdot : S \times S \to S$ について,

- 結合律 : $\forall a, b, c \in S,\ (a \cdot b) \cdot c = a \cdot (b \cdot c)$
- 単位元の存在 : $\exists e \in S,\ \forall a \in S,\ a \cdot e = e \cdot a = a$

といった群に対する要求の一部をを満たすとき, 組 $(S,\cdot)$ はモノイドと呼ばれる. また, 単位元をもつ半群という認識でも良い.

Segment Tree はモノイドに対する一点更新及び区間取得といった処理を $O(\log n)$ で行うことができる. 内部実装においては 1-indexed の完全二分木を保持している.

| メンバ関数             | 効果                                                                                                                                          | 時間計算量  |
| ---------------------- | --------------------------------------------------------------------------------------------------------------------------------------------- | ----------- |
| `SegmentTree(n, f, e)` | 要素数 $n$ の単位元で初期化する. ここで, $f$ は二項演算, $e$ は単位元である.                                                                  | $O(n)$      |
| `set(k, x)`            | $k$ 番目の要素に $x$ を代入する. ここで, この後各クエリに答えるには `build()` を挟んで親ノードの情報を更新してからでないといけないことに注意. | $O(1)$      |
| `build()`              | `set` された情報をもとに Segment Tree を構築する.                                                                                             | $O(n)$      |
| `update(k, x)`         | $k$ 番目の要素に $x$ を代入して更新する. こちらは `set` とは違い親ノードの更新も含む.                                                         | $O(\log n)$ |
| `add(k, x)`            | $k$ 番目の要素に $x$ を加算して更新する.                                                                                                      | $O(\log n)$ |
| `query(l, r)`          | 区間 $[l, r)$ の要素について二項演算を適用した結果を返す. 結合律が成立することからこの結果は一意に定まる.                                     | $O(\log n)$ |
| `all_prod()`           | 全体, すなわち区間 $[0, n)$ に二項演算を適用した結果を返す.                                                                                   | $O(1)$      |
| `operator[k]`          | $k$ 番目の要素を返す.                                                                                                                         | $O(1)$      |
| `find_first(l, check)` | $[l, x]$ (右端点を含む) が `check` を満たすような最小の $x$ を返す. 存在しない場合は $n$ を返す.                                              | $O(\log n)$ |
| `find_last(r, check)`  | $[x, r)$ (左端点を含む) が `check` を満たすような最大の $x$ を返す. 存在しない場合は $-1$ を返す.                                             | $O(\log n)$ |
