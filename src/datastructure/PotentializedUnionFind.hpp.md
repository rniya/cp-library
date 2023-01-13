---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/PotentializedUnionFind.hpp\"\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <typename T> struct PotentializedUnionFind\
    \ {\n    PotentializedUnionFind(int n) : n(n), data(n, -1), dist(n, T()) {}\n\n\
    \    int find(int x) {\n        assert(0 <= x && x < n);\n        if (data[x]\
    \ < 0) return x;\n        int r = find(data[x]);\n        dist[x] += dist[data[x]];\n\
    \        return data[x] = r;\n    }\n\n    bool merge(int x, int y, T p) {\n \
    \       p += potential(x) - potential(y);\n        assert(0 <= x && x < n);\n\
    \        assert(0 <= y && y < n);\n        if ((x = find(x)) == (y = find(y)))\
    \ return false;\n        if (-data[x] < -data[y]) {\n            std::swap(x,\
    \ y);\n            p = -p;\n        }\n        data[x] += data[y];\n        data[y]\
    \ = x;\n        dist[y] = p;\n        return true;\n    }\n\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y <\
    \ n);\n        return find(x) == find(y);\n    }\n\n    int size(int x) {\n  \
    \      assert(0 <= x && x < n);\n        return -data[find(x)];\n    }\n\n   \
    \ T potential(int x) {\n        assert(0 <= x && x < n);\n        find(x);\n \
    \       return dist[x];\n    }\n\n    T diff(int x, int y) {\n        assert(0\
    \ <= x && x < n);\n        assert(0 <= y && y < n);\n        return potential(y)\
    \ - potential(x);\n    }\n\n    int operator[](int x) { return find(x); }\n\n\
    private:\n    int n;\n    std::vector<int> data;\n    std::vector<T> dist;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> struct PotentializedUnionFind {\n    PotentializedUnionFind(int n) : n(n),\
    \ data(n, -1), dist(n, T()) {}\n\n    int find(int x) {\n        assert(0 <= x\
    \ && x < n);\n        if (data[x] < 0) return x;\n        int r = find(data[x]);\n\
    \        dist[x] += dist[data[x]];\n        return data[x] = r;\n    }\n\n   \
    \ bool merge(int x, int y, T p) {\n        p += potential(x) - potential(y);\n\
    \        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n        if\
    \ ((x = find(x)) == (y = find(y))) return false;\n        if (-data[x] < -data[y])\
    \ {\n            std::swap(x, y);\n            p = -p;\n        }\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        dist[y] = p;\n        return true;\n\
    \    }\n\n    bool same(int x, int y) {\n        assert(0 <= x && x < n);\n  \
    \      assert(0 <= y && y < n);\n        return find(x) == find(y);\n    }\n\n\
    \    int size(int x) {\n        assert(0 <= x && x < n);\n        return -data[find(x)];\n\
    \    }\n\n    T potential(int x) {\n        assert(0 <= x && x < n);\n       \
    \ find(x);\n        return dist[x];\n    }\n\n    T diff(int x, int y) {\n   \
    \     assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n        return\
    \ potential(y) - potential(x);\n    }\n\n    int operator[](int x) { return find(x);\
    \ }\n\nprivate:\n    int n;\n    std::vector<int> data;\n    std::vector<T> dist;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/PotentializedUnionFind.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_B.test.cpp
documentation_of: src/datastructure/PotentializedUnionFind.hpp
layout: document
title: Potentialized Union Find
---

## 概要
