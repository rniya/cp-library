---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2891.test.cpp
    title: test/aoj/2891.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_A.test.cpp
    title: test/aoj/GRL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/CycleDetection.hpp\"\n#include <stack>\n#include <vector>\n\
    \ntemplate <bool directed> struct CycleDetection {\n    std::vector<std::vector<int>>\
    \ G;\n    int n, pos;\n\n    CycleDetection(int n) : G(n), n(n), pos(-1), seen(n,\
    \ 0), finished(n, 0) {}\n\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        if (!directed) G[v].emplace_back(u);\n    }\n\n    std::vector<int> build()\
    \ {\n        for (int v = 0; v < n; v++) {\n            if (!seen[v]) dfs(v, -1);\n\
    \            if (~pos) break;\n        }\n        std::vector<int> res;\n    \
    \    while (!hist.empty()) {\n            int t = hist.top();\n            hist.pop();\n\
    \            res.emplace_back(t);\n            if (t == pos) break;\n        }\n\
    \        return res;\n    }\n\nprivate:\n    std::vector<int> seen, finished;\n\
    \    std::stack<int> hist;\n\n    void dfs(int v, int p) {\n        seen[v] =\
    \ 1;\n        hist.emplace(v);\n        for (int u : G[v]) {\n            if (!directed\
    \ and u == p) continue;\n            if (finished[u]) continue;\n            if\
    \ (seen[u] and !finished[u]) {\n                pos = u;\n                return;\n\
    \            }\n            dfs(u, v);\n            if (~pos) return;\n      \
    \  }\n        finished[v] = 1;\n        hist.pop();\n    }\n};\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\n\ntemplate <bool directed>\
    \ struct CycleDetection {\n    std::vector<std::vector<int>> G;\n    int n, pos;\n\
    \n    CycleDetection(int n) : G(n), n(n), pos(-1), seen(n, 0), finished(n, 0)\
    \ {}\n\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n   \
    \     if (!directed) G[v].emplace_back(u);\n    }\n\n    std::vector<int> build()\
    \ {\n        for (int v = 0; v < n; v++) {\n            if (!seen[v]) dfs(v, -1);\n\
    \            if (~pos) break;\n        }\n        std::vector<int> res;\n    \
    \    while (!hist.empty()) {\n            int t = hist.top();\n            hist.pop();\n\
    \            res.emplace_back(t);\n            if (t == pos) break;\n        }\n\
    \        return res;\n    }\n\nprivate:\n    std::vector<int> seen, finished;\n\
    \    std::stack<int> hist;\n\n    void dfs(int v, int p) {\n        seen[v] =\
    \ 1;\n        hist.emplace(v);\n        for (int u : G[v]) {\n            if (!directed\
    \ and u == p) continue;\n            if (finished[u]) continue;\n            if\
    \ (seen[u] and !finished[u]) {\n                pos = u;\n                return;\n\
    \            }\n            dfs(u, v);\n            if (~pos) return;\n      \
    \  }\n        finished[v] = 1;\n        hist.pop();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2022-05-04 22:04:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_4_A.test.cpp
  - test/aoj/2891.test.cpp
documentation_of: graph/CycleDetection.hpp
layout: document
title: Cycle Detection
---

## 概要

TODO: 多重辺に対応させる。