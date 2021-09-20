---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/UnionFind.md
    document_title: Union Find (Disjoint Set Union)
    links: []
  bundledCode: "#line 2 \"datastructure/UnionFind.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nstruct UnionFind {\n    UnionFind(int n) : n(n),\
    \ num(n), data(n, -1) {}\n    int find(int x) {\n        assert(0 <= x && x <\
    \ n);\n        return data[x] < 0 ? x : data[x] = find(data[x]);\n    }\n    bool\
    \ merge(int x, int y) {\n        assert(0 <= x && x < n);\n        assert(0 <=\
    \ y && y < n);\n        if ((x = find(x)) == (y = find(y))) return false;\n  \
    \      if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n        num--;\n        return true;\n    }\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y <\
    \ n);\n        return find(x) == find(y);\n    }\n    int size(int x) {\n    \
    \    assert(0 <= x && x < n);\n        return -data[find(x)];\n    }\n    int\
    \ count() const { return num; }\n    std::vector<std::vector<int>> groups() {\n\
    \        std::vector<std::vector<int>> res(n);\n        for (int i = 0; i < n;\
    \ i++) res[find(i)].emplace_back(i);\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), [&](const std::vector<int>& v) { return v.empty(); }));\n       \
    \ return res;\n    }\n    int operator[](int x) { return find(x); }\n\nprivate:\n\
    \    int n, num;\n    // root node : -1 * component size\n    // otherwise : parent\n\
    \    std::vector<int> data;\n};\n\n/**\n * @brief Union Find (Disjoint Set Union)\n\
    \ * @docs docs/datastructure/UnionFind.md\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nstruct UnionFind {\n    UnionFind(int n) : n(n), num(n), data(n, -1) {}\n  \
    \  int find(int x) {\n        assert(0 <= x && x < n);\n        return data[x]\
    \ < 0 ? x : data[x] = find(data[x]);\n    }\n    bool merge(int x, int y) {\n\
    \        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n        if\
    \ ((x = find(x)) == (y = find(y))) return false;\n        if (-data[x] < -data[y])\
    \ std::swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n      \
    \  num--;\n        return true;\n    }\n    bool same(int x, int y) {\n      \
    \  assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n        return\
    \ find(x) == find(y);\n    }\n    int size(int x) {\n        assert(0 <= x &&\
    \ x < n);\n        return -data[find(x)];\n    }\n    int count() const { return\
    \ num; }\n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(n);\n        for (int i = 0; i < n; i++) res[find(i)].emplace_back(i);\n\
    \        res.erase(std::remove_if(res.begin(), res.end(), [&](const std::vector<int>&\
    \ v) { return v.empty(); }));\n        return res;\n    }\n    int operator[](int\
    \ x) { return find(x); }\n\nprivate:\n    int n, num;\n    // root node : -1 *\
    \ component size\n    // otherwise : parent\n    std::vector<int> data;\n};\n\n\
    /**\n * @brief Union Find (Disjoint Set Union)\n * @docs docs/datastructure/UnionFind.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2021-09-20 18:15:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_A.test.cpp
  - test/yosupo/unionfind.test.cpp
documentation_of: datastructure/UnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/UnionFind.hpp
- /library/datastructure/UnionFind.hpp.html
title: Union Find (Disjoint Set Union)
---
## 概要
各集合をその集合内の代表元によって特徴づけることで素集合を扱うデータ構造。主に頂点 $x, y$ の属する集合のマージやそれらが同一の集合に属しているかの判定をならし $O(\alpha(n))$ で行うことができる。ここで、$\alpha(n)$ は Ackermann 関数 $A(n, n)$ の逆関数である。

| メンバ関数     | 効果                                         | 時間計算量            |
| -------------- | -------------------------------------------- | --------------------- |
| `UnionFind(n)` | 要素数 $n$ で初期化する。                    | $O(n)$                |
| `find(x)`      | 頂点 $x$ の属する集合の代表元を返す。        | ならし $O(\alpha(n))$ |
| `merge(x,y)`   | 頂点 $x, y$ が属する集合を併合する。         | ならし $O(\alpha(n))$ |
| `same(x,y)`    | 頂点 $x, y$ が同一の集合に属するか判定する。 | ならし $O(\alpha(n))$ |
| `size(x)`      | 頂点 $x$ が属する集合の要素数を返す。        | ならし $O(\alpha(n))$ |
| `count()`      | 素集合の数を返す。                           | $O(1)$                |
| `groups()`     | 頂点を連結性で分割した同値類の情報を返す。   | $O(n)                 |
| `operator[x]`  | 頂点 $x$ の属する集合の代表元を返す。        | ならし $O(\alpha(n))$ |
