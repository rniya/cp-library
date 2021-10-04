---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/agc002_d.cpp
    title: test/atcoder/agc002_d.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/datastructure/PartiallyPersistentUnionFind.md
    document_title: Partially Persistent Union Find
    links: []
  bundledCode: "#line 2 \"datastructure/PartiallyPersistentUnionFind.hpp\"\n#include\
    \ <cassert>\n#include <limits>\n#include <vector>\n\nstruct PartiallyPersistentUnionFind\
    \ {\n    PartiallyPersistentUnionFind(int n)\n        : n(n), time(0), data(n,\
    \ -1), last(n, std::numeric_limits<int>::max()), history(n) {\n        for (auto&\
    \ v : history) v.emplace_back(-1, -1);\n    }\n\n    int find(int t, int x) const\
    \ {\n        assert(0 <= x && x < n);\n        return t < last[x] ? x : find(t,\
    \ data[x]);\n    }\n\n    bool merge(int x, int y) {\n        assert(0 <= x &&\
    \ x < n);\n        assert(0 <= y && y < n);\n        time++;\n        if ((x =\
    \ find(time, x)) == (y = find(time, y))) return false;\n        if (-data[x] <\
    \ -data[y]) std::swap(x, y);\n        data[x] += data[y];\n        history[x].emplace_back(time,\
    \ data[x]);\n        data[y] = x;\n        last[y] = time;\n        return true;\n\
    \    }\n\n    bool same(int t, int x, int y) const {\n        assert(0 <= x &&\
    \ x < n);\n        assert(0 <= y && y < n);\n        return find(t, x) == find(t,\
    \ y);\n    }\n\n    int size(int t, int x) const {\n        assert(0 <= x && x\
    \ < n);\n        x = find(t, x);\n        return -prev(lower_bound(history[x].begin(),\
    \ history[x].end(), std::make_pair(t, 0)))->second;\n    }\n\nprivate:\n    int\
    \ n, time;\n    std::vector<int> data, last;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> history;\n};\n\n/**\n * @brief Partially Persistent Union Find\n * @docs\
    \ docs/datastructure/PartiallyPersistentUnionFind.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <vector>\n\n\
    struct PartiallyPersistentUnionFind {\n    PartiallyPersistentUnionFind(int n)\n\
    \        : n(n), time(0), data(n, -1), last(n, std::numeric_limits<int>::max()),\
    \ history(n) {\n        for (auto& v : history) v.emplace_back(-1, -1);\n    }\n\
    \n    int find(int t, int x) const {\n        assert(0 <= x && x < n);\n     \
    \   return t < last[x] ? x : find(t, data[x]);\n    }\n\n    bool merge(int x,\
    \ int y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n\
    \        time++;\n        if ((x = find(time, x)) == (y = find(time, y))) return\
    \ false;\n        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] +=\
    \ data[y];\n        history[x].emplace_back(time, data[x]);\n        data[y] =\
    \ x;\n        last[y] = time;\n        return true;\n    }\n\n    bool same(int\
    \ t, int x, int y) const {\n        assert(0 <= x && x < n);\n        assert(0\
    \ <= y && y < n);\n        return find(t, x) == find(t, y);\n    }\n\n    int\
    \ size(int t, int x) const {\n        assert(0 <= x && x < n);\n        x = find(t,\
    \ x);\n        return -prev(lower_bound(history[x].begin(), history[x].end(),\
    \ std::make_pair(t, 0)))->second;\n    }\n\nprivate:\n    int n, time;\n    std::vector<int>\
    \ data, last;\n    std::vector<std::vector<std::pair<int, int>>> history;\n};\n\
    \n/**\n * @brief Partially Persistent Union Find\n * @docs docs/datastructure/PartiallyPersistentUnionFind.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/PartiallyPersistentUnionFind.hpp
  requiredBy:
  - test/atcoder/agc002_d.cpp
  timestamp: '2021-10-04 17:13:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/PartiallyPersistentUnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/PartiallyPersistentUnionFind.hpp
- /library/datastructure/PartiallyPersistentUnionFind.hpp.html
title: Partially Persistent Union Find
---
## 概要
経路圧縮を行わずにマージテクを利用して集合を管理する際に, 変更される値が少ないことを利用してタイムスタンプを用いて過去の頂点の連結成分やその頂点数といったデータを取得できるようにしたデータ構造.

以下に記す内容について, 時刻 $t$ は 0 からスタートし `merge` が呼び出されるごとに操作直前にインクリメントされる. すなわち $i$ 回目 (1-indexed) のマージ後の関係を調べるためには引数 $t$ はそのまま $i$ でよく,  1-indexed であることに注意が必要である.

| メンバ関数                        | 効果                                                             | 時間計算量  |
| --------------------------------- | ---------------------------------------------------------------- | ----------- |
| `PartiallyPersistentUnionFind(n)` | 要素数 $n$ で初期化する.                                         | $O(n)$      |
| `find(t, x)`                      | 時刻 $t$ において頂点 $x$ が属していた集合の代表元を返す.        | $O(\log n)$ |
| `merge(x, y)`                     | 頂点 $x, y$ が属する集合を併合する.                              | $O(\log n)$ |
| `same(t, x, y)`                   | 時刻 $t$ において頂点 $x, y$ が同一の集合に属していたか判定する. | $O(\log n)$ |
| `size(t, x)`                      | 時刻 $t$ において頂点 $x$ が属していた集合の要素数を返す.        | $O(\log n)$ |

## 問題例
- [AtCoder Grand Contest 002 D - Stamp Rally](https://atcoder.jp/contests/agc002/tasks/agc002_d)

## Links
- [UnionFindTree に関する知見の諸々 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2018/05/30/191943)