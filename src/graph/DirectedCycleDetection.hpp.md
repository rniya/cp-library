---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/cycle_detection.test.cpp
    title: test/yosupo/cycle_detection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/DirectedCycleDetection.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nstruct DirectedCycleDetection\
    \ {\n    DirectedCycleDetection(int n) : n(n), m(0), G(n), used(n, 0), par(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n\
    \        assert(0 <= v and v < n);\n        G[u].emplace_back(v, m++);\n    }\n\
    \n    std::pair<std::vector<int>, std::vector<int>> build() {\n        for (int\
    \ i = 0; i < n; i++) {\n            if (used[i] == 0) {\n                dfs(i);\n\
    \            }\n        }\n        return {vs, es};\n    }\n\n  private:\n   \
    \ int n, m;\n    std::vector<std::vector<std::pair<int, int>>> G;\n    std::vector<int>\
    \ used, vs, es;\n    std::vector<std::pair<int, int>> par;\n\n    void dfs(int\
    \ v) {\n        used[v] = 1;\n        for (auto [u, e] : G[v]) {\n           \
    \ if (not es.empty()) return;\n            if (used[u] == 0) {\n             \
    \   par[u] = {v, e};\n                dfs(u);\n            } else if (used[u]\
    \ == 1) {\n                vs.emplace_back(v);\n                es.emplace_back(e);\n\
    \                for (int cur = v; cur != u; cur = par[cur].first) {\n       \
    \             vs.emplace_back(par[cur].first);\n                    es.emplace_back(par[cur].second);\n\
    \                }\n                std::reverse(vs.begin(), vs.end());\n    \
    \            std::reverse(es.begin(), es.end());\n                return;\n  \
    \          }\n        }\n        used[v] = 2;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nstruct DirectedCycleDetection {\n    DirectedCycleDetection(int\
    \ n) : n(n), m(0), G(n), used(n, 0), par(n) {}\n\n    void add_edge(int u, int\
    \ v) {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n\
    \        G[u].emplace_back(v, m++);\n    }\n\n    std::pair<std::vector<int>,\
    \ std::vector<int>> build() {\n        for (int i = 0; i < n; i++) {\n       \
    \     if (used[i] == 0) {\n                dfs(i);\n            }\n        }\n\
    \        return {vs, es};\n    }\n\n  private:\n    int n, m;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> G;\n    std::vector<int> used, vs, es;\n    std::vector<std::pair<int,\
    \ int>> par;\n\n    void dfs(int v) {\n        used[v] = 1;\n        for (auto\
    \ [u, e] : G[v]) {\n            if (not es.empty()) return;\n            if (used[u]\
    \ == 0) {\n                par[u] = {v, e};\n                dfs(u);\n       \
    \     } else if (used[u] == 1) {\n                vs.emplace_back(v);\n      \
    \          es.emplace_back(e);\n                for (int cur = v; cur != u; cur\
    \ = par[cur].first) {\n                    vs.emplace_back(par[cur].first);\n\
    \                    es.emplace_back(par[cur].second);\n                }\n  \
    \              std::reverse(vs.begin(), vs.end());\n                std::reverse(es.begin(),\
    \ es.end());\n                return;\n            }\n        }\n        used[v]\
    \ = 2;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/DirectedCycleDetection.hpp
  requiredBy: []
  timestamp: '2024-08-25 02:56:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/cycle_detection.test.cpp
documentation_of: src/graph/DirectedCycleDetection.hpp
layout: document
title: Cycle Detection (Directed)
---
