---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFind.hpp
    title: Union Find (Disjoint Set Union)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/Kruskal.md
    document_title: Kruskal
    links: []
  bundledCode: "#line 2 \"graph/Kruskal.hpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"datastructure/UnionFind.hpp\"\n#include <algorithm>\n#line 5 \"datastructure/UnionFind.hpp\"\
    \n\nstruct UnionFind {\n    UnionFind(int n) : n(n), num(n), data(n, -1) {}\n\n\
    \    int find(int x) {\n        assert(0 <= x && x < n);\n        return data[x]\
    \ < 0 ? x : data[x] = find(data[x]);\n    }\n\n    bool merge(int x, int y) {\n\
    \        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n        if\
    \ ((x = find(x)) == (y = find(y))) return false;\n        if (-data[x] < -data[y])\
    \ std::swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n      \
    \  num--;\n        return true;\n    }\n\n    bool same(int x, int y) {\n    \
    \    assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) {\n        assert(0 <= x &&\
    \ x < n);\n        return -data[find(x)];\n    }\n\n    int count() const { return\
    \ num; }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(n);\n        for (int i = 0; i < n; i++) res[find(i)].emplace_back(i);\n\
    \        res.erase(std::remove_if(res.begin(), res.end(), [&](const std::vector<int>&\
    \ v) { return v.empty(); }));\n        return res;\n    }\n\n    int operator[](int\
    \ x) { return find(x); }\n\nprivate:\n    int n, num;\n    // root node : -1 *\
    \ component size\n    // otherwise : parent\n    std::vector<int> data;\n};\n\n\
    /**\n * @brief Union Find (Disjoint Set Union)\n * @docs docs/datastructure/UnionFind.md\n\
    \ */\n#line 5 \"graph/Kruskal.hpp\"\n\ntemplate <typename T> struct Kruskal {\n\
    \    Kruskal(int n) : n(n), called_build(false) {}\n\n    void add_edge(int u,\
    \ int v, T cost, int idx = 0) {\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        es.emplace_back(u, v, cost, idx);\n    }\n\n    T build()\
    \ {\n        called_build = true;\n        std::sort(es.begin(), es.end());\n\
    \        UnionFind uf(n);\n        T res = 0;\n        for (auto& e : es) {\n\
    \            if (uf.merge(e.u, e.v)) {\n                res += e.cost;\n     \
    \           e.used = true;\n            }\n        }\n        return res;\n  \
    \  }\n\n    std::vector<int> used_edges() {\n        assert(called_build);\n \
    \       int m = es.size();\n        std::vector<int> res(m);\n        for (int\
    \ i = 0; i < m; i++) res[es[i].idx] = es[i].used;\n        return res;\n    }\n\
    \nprivate:\n    struct edge {\n        int u, v;\n        T cost;\n        int\
    \ idx, used;\n        edge(int u, int v, T cost, int idx) : u(u), v(v), cost(cost),\
    \ idx(idx), used(false) {}\n        bool operator<(const edge& e) const { return\
    \ cost < e.cost; }\n    };\n    int n;\n    bool called_build;\n    std::vector<edge>\
    \ es;\n};\n\n/**\n * @brief Kruskal\n * @docs docs/graph/Kruskal.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../datastructure/UnionFind.hpp\"\
    \n\ntemplate <typename T> struct Kruskal {\n    Kruskal(int n) : n(n), called_build(false)\
    \ {}\n\n    void add_edge(int u, int v, T cost, int idx = 0) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        es.emplace_back(u,\
    \ v, cost, idx);\n    }\n\n    T build() {\n        called_build = true;\n   \
    \     std::sort(es.begin(), es.end());\n        UnionFind uf(n);\n        T res\
    \ = 0;\n        for (auto& e : es) {\n            if (uf.merge(e.u, e.v)) {\n\
    \                res += e.cost;\n                e.used = true;\n            }\n\
    \        }\n        return res;\n    }\n\n    std::vector<int> used_edges() {\n\
    \        assert(called_build);\n        int m = es.size();\n        std::vector<int>\
    \ res(m);\n        for (int i = 0; i < m; i++) res[es[i].idx] = es[i].used;\n\
    \        return res;\n    }\n\nprivate:\n    struct edge {\n        int u, v;\n\
    \        T cost;\n        int idx, used;\n        edge(int u, int v, T cost, int\
    \ idx) : u(u), v(v), cost(cost), idx(idx), used(false) {}\n        bool operator<(const\
    \ edge& e) const { return cost < e.cost; }\n    };\n    int n;\n    bool called_build;\n\
    \    std::vector<edge> es;\n};\n\n/**\n * @brief Kruskal\n * @docs docs/graph/Kruskal.md\n\
    \ */\n"
  dependsOn:
  - datastructure/UnionFind.hpp
  isVerificationFile: false
  path: graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2021-10-04 09:56:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
documentation_of: graph/Kruskal.hpp
layout: document
redirect_from:
- /library/graph/Kruskal.hpp
- /library/graph/Kruskal.hpp.html
title: Kruskal
---
## 概要

## 計算量