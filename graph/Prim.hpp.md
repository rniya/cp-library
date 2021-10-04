---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.Prim.test.cpp
    title: test/aoj/GRL_2_A.Prim.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/Prim.md
    document_title: Prim
    links: []
  bundledCode: "#line 2 \"graph/Prim.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\ntemplate <typename T> struct Prim {\n \
    \   Prim(int n) : n(n), G(n), dist(n, std::numeric_limits<T>::max()), used(n,\
    \ false) {}\n\n    void add_edge(int u, int v, T cost) {\n        assert(0 <=\
    \ u && u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v,\
    \ cost);\n        G[v].emplace_back(u, cost);\n    }\n\n    T build() {\n    \
    \    T res = 0;\n        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T,\
    \ int>>, std::greater<std::pair<T, int>>> pq;\n        dist[0] = 0;\n        pq.emplace(0,\
    \ 0);\n        while (!pq.empty()) {\n            auto p = pq.top();\n       \
    \     pq.pop();\n            int v = p.second;\n            if (used[v]) continue;\n\
    \            used[v] = true;\n            res += p.first;\n            for (auto&\
    \ e : G[v]) {\n                int u = e.first;\n                if (!used[u]\
    \ && e.second < dist[u]) {\n                    dist[u] = e.second;\n        \
    \            pq.emplace(e.second, u);\n                }\n            }\n    \
    \    }\n        return res;\n    }\n\nprivate:\n    int n;\n    std::vector<std::vector<std::pair<int,\
    \ T>>> G;\n    std::vector<T> dist;\n    std::vector<bool> used;\n};\n\n/**\n\
    \ * @brief Prim\n * @docs docs/graph/Prim.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\ntemplate <typename T> struct Prim {\n    Prim(int n) : n(n), G(n),\
    \ dist(n, std::numeric_limits<T>::max()), used(n, false) {}\n\n    void add_edge(int\
    \ u, int v, T cost) {\n        assert(0 <= u && u < n);\n        assert(0 <= v\
    \ && v < n);\n        G[u].emplace_back(v, cost);\n        G[v].emplace_back(u,\
    \ cost);\n    }\n\n    T build() {\n        T res = 0;\n        std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;\n\
    \        dist[0] = 0;\n        pq.emplace(0, 0);\n        while (!pq.empty())\
    \ {\n            auto p = pq.top();\n            pq.pop();\n            int v\
    \ = p.second;\n            if (used[v]) continue;\n            used[v] = true;\n\
    \            res += p.first;\n            for (auto& e : G[v]) {\n           \
    \     int u = e.first;\n                if (!used[u] && e.second < dist[u]) {\n\
    \                    dist[u] = e.second;\n                    pq.emplace(e.second,\
    \ u);\n                }\n            }\n        }\n        return res;\n    }\n\
    \nprivate:\n    int n;\n    std::vector<std::vector<std::pair<int, T>>> G;\n \
    \   std::vector<T> dist;\n    std::vector<bool> used;\n};\n\n/**\n * @brief Prim\n\
    \ * @docs docs/graph/Prim.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Prim.hpp
  requiredBy: []
  timestamp: '2021-10-04 09:56:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.Prim.test.cpp
documentation_of: graph/Prim.hpp
layout: document
redirect_from:
- /library/graph/Prim.hpp
- /library/graph/Prim.hpp.html
title: Prim
---
## 概要

## 計算量