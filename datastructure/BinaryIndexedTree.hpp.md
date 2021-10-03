---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.test.cpp
    title: test/yosupo/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/BinaryIndexedTree.md
    document_title: Binary Indexd Tree (Fenwick Tree)
    links: []
  bundledCode: "#line 2 \"datastructure/BinaryIndexedTree.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <typename T> struct BinaryIndexedTree {\n    BinaryIndexedTree(int\
    \ n) : n(n), data(n) {}\n\n    void add(int k, T x) {\n        assert(0 <= k &&\
    \ k < n);\n        for (k++; k <= n; k += k & -k) data[k - 1] += x;\n    }\n\n\
    \    T query(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return sum(r) - sum(l);\n    }\n\n    T operator[](int i) const { return\
    \ query(i, i + 1); }\n\n    int lower_bound(T x) const {\n        if (x <= 0)\
    \ return 0;\n        int cur = 0, k = 1;\n        while (k < n) k <<= 1;\n   \
    \     for (; k > 0; k >>= 1) {\n            if (cur + k <= n && data[cur + k -\
    \ 1] < x) {\n                x -= data[cur + k - 1];\n                cur += k;\n\
    \            }\n        }\n        return cur;\n    }\n    int upper_bound(T x)\
    \ const { return lower_bound(x + 1); }\n\nprivate:\n    int n;\n    std::vector<T>\
    \ data;\n\n    T sum(int r) const {\n        T res = 0;\n        for (; r > 0;\
    \ r -= r & -r) res += data[r - 1];\n        return res;\n    }\n};\n\n/**\n *\
    \ @brief Binary Indexd Tree (Fenwick Tree)\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> struct BinaryIndexedTree {\n    BinaryIndexedTree(int n) : n(n), data(n)\
    \ {}\n\n    void add(int k, T x) {\n        assert(0 <= k && k < n);\n       \
    \ for (k++; k <= n; k += k & -k) data[k - 1] += x;\n    }\n\n    T query(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ sum(r) - sum(l);\n    }\n\n    T operator[](int i) const { return query(i, i\
    \ + 1); }\n\n    int lower_bound(T x) const {\n        if (x <= 0) return 0;\n\
    \        int cur = 0, k = 1;\n        while (k < n) k <<= 1;\n        for (; k\
    \ > 0; k >>= 1) {\n            if (cur + k <= n && data[cur + k - 1] < x) {\n\
    \                x -= data[cur + k - 1];\n                cur += k;\n        \
    \    }\n        }\n        return cur;\n    }\n    int upper_bound(T x) const\
    \ { return lower_bound(x + 1); }\n\nprivate:\n    int n;\n    std::vector<T> data;\n\
    \n    T sum(int r) const {\n        T res = 0;\n        for (; r > 0; r -= r &\
    \ -r) res += data[r - 1];\n        return res;\n    }\n};\n\n/**\n * @brief Binary\
    \ Indexd Tree (Fenwick Tree)\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2021-09-20 21:09:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/yosupo/static_range_inversions_query.test.cpp
  - test/yosupo/point_add_rectangle_sum.test.cpp
  - test/yukicoder/1270.test.cpp
documentation_of: datastructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/datastructure/BinaryIndexedTree.hpp
- /library/datastructure/BinaryIndexedTree.hpp.html
title: Binary Indexd Tree (Fenwick Tree)
---
## 概要
長さ $n$ の数列に対して一点加算及び区間和取得を $O(\log n)$ で行えるデータ構造. 一般的には 1-indexed で実装されることが多いが, この実装は 0-indexed であることに注意.

| メンバ関数                | 効果                                                          | 時間計算量  |
| ------------------------- | ------------------------------------------------------------- | ----------- |
| `BinaryIndexedTree<T>(n)` | 長さ $n$ の 0 で初期化された数列で構築する.                   | $O(n)$      |
| `add(k, x)`               | $k$ 番目の要素に $x$ を加算する.                              | $O(\log n)$ |
| `query(l, r)`             | 区間 $[l, r)$ の総和を取得する.                               | $O(\log n)$ |
| `operator[i]`             | $i$ 番目の要素を取得する.                                     | $O(\log n)$ |
| `lower_bound(x)`          | 区間 $[0, k]$ の総和が $x$ 以上となるような最小の $k$ を返す. | $O(\log n)$ |
| `upper_bound(x)`          | 区間 $[0, k]$ の総和が $x$ を上回るような最小の $k$ を返す.   | $O(\log n)$ |

## Links
- [Binary Indexed Tree のはなし - hos.ac](http://hos.ac/slides/20140319_bit.pdf)
