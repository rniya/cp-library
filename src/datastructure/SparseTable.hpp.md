---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/SparseTable.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct SparseTable\
    \ {\n    SparseTable() {}\n\n    SparseTable(const std::vector<S>& v) : n(v.size())\
    \ {\n        table.resize(n + 1);\n        table[0] = table[1] = 0;\n        for\
    \ (int i = 2; i <= n; i++) table[i] = table[i >> 1] + 1;\n        int h = table.back()\
    \ + 1;\n        d.assign(h, std::vector<S>(n, e()));\n        d[0] = v;\n    \
    \    for (int i = 1; i < h; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ n; j++) {\n                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n    }\n    S prod(int l, int r) const {\n\
    \        assert(0 <= l and r <= n);\n        if (l >= r) return e();\n       \
    \ int h = table[r - l];\n        return op(d[h][l], d[h][r - (1 << h)]);\n   \
    \ }\n\n  private:\n    int n;\n    std::vector<std::vector<S>> d;\n    std::vector<int>\
    \ table;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <class S,\
    \ S (*op)(S, S), S (*e)()> struct SparseTable {\n    SparseTable() {}\n\n    SparseTable(const\
    \ std::vector<S>& v) : n(v.size()) {\n        table.resize(n + 1);\n        table[0]\
    \ = table[1] = 0;\n        for (int i = 2; i <= n; i++) table[i] = table[i >>\
    \ 1] + 1;\n        int h = table.back() + 1;\n        d.assign(h, std::vector<S>(n,\
    \ e()));\n        d[0] = v;\n        for (int i = 1; i < h; i++) {\n         \
    \   for (int j = 0; j + (1 << i) <= n; j++) {\n                d[i][j] = op(d[i\
    \ - 1][j], d[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n \
    \   S prod(int l, int r) const {\n        assert(0 <= l and r <= n);\n       \
    \ if (l >= r) return e();\n        int h = table[r - l];\n        return op(d[h][l],\
    \ d[h][r - (1 << h)]);\n    }\n\n  private:\n    int n;\n    std::vector<std::vector<S>>\
    \ d;\n    std::vector<int> table;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: src/datastructure/SparseTable.hpp
layout: document
title: Sparse Table
---

## 概要
