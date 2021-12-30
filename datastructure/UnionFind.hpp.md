---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/Kruskal.hpp
    title: Kruskal
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/UnionFind.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nstruct UnionFind {\n    UnionFind(int n) : n(n),\
    \ num(n), data(n, -1) {}\n\n    int find(int x) {\n        assert(0 <= x && x\
    \ < n);\n        return data[x] < 0 ? x : data[x] = find(data[x]);\n    }\n\n\
    \    bool merge(int x, int y) {\n        assert(0 <= x && x < n);\n        assert(0\
    \ <= y && y < n);\n        if ((x = find(x)) == (y = find(y))) return false;\n\
    \        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n        num--;\n        return true;\n    }\n\n    bool\
    \ same(int x, int y) {\n        assert(0 <= x && x < n);\n        assert(0 <=\
    \ y && y < n);\n        return find(x) == find(y);\n    }\n\n    int size(int\
    \ x) {\n        assert(0 <= x && x < n);\n        return -data[find(x)];\n   \
    \ }\n\n    int count() const { return num; }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<std::vector<int>> res(n);\n        for (int\
    \ i = 0; i < n; i++) res[find(i)].emplace_back(i);\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), [&](const std::vector<int>& v) { return v.empty(); }));\n       \
    \ return res;\n    }\n\n    int operator[](int x) { return find(x); }\n\nprivate:\n\
    \    int n, num;\n    // root node : -1 * component size\n    // otherwise : parent\n\
    \    std::vector<int> data;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nstruct UnionFind {\n    UnionFind(int n) : n(n), num(n), data(n, -1) {}\n\n\
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
    \ component size\n    // otherwise : parent\n    std::vector<int> data;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/UnionFind.hpp
  requiredBy:
  - graph/Kruskal.hpp
  timestamp: '2021-12-30 22:50:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/DSL_1_A.test.cpp
  - test/yosupo/unionfind.test.cpp
documentation_of: datastructure/UnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/UnionFind.hpp
- /library/datastructure/UnionFind.hpp.html
title: datastructure/UnionFind.hpp
---
