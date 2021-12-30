---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_A.TopologicalSort.test.cpp
    title: test/aoj/GRL_4_A.TopologicalSort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/TopologicalSort.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <vector>\n\nstruct TopologicalSort {\n\
    \    std::vector<std::vector<int>> G;\n\n    TopologicalSort(int n) : G(n), n(n),\
    \ indeg(n, 0) {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v);\n \
    \       indeg[v]++;\n    }\n\n    std::vector<int> build() {\n        std::queue<int>\
    \ que;\n        for (int i = 0; i < n; i++) {\n            if (indeg[i] == 0)\
    \ {\n                que.emplace(i);\n            }\n        }\n        std::vector<int>\
    \ order;\n        while (!que.empty()) {\n            int v = que.front();\n \
    \           que.pop();\n            order.emplace_back(v);\n            for (int&\
    \ u : G[v]) {\n                if (--indeg[u] == 0) {\n                    que.emplace(u);\n\
    \                }\n            }\n        }\n        if (*std::max_element(indeg.begin(),\
    \ indeg.end()) != 0) return {};\n        return order;\n    }\n\nprivate:\n  \
    \  int n;\n    std::vector<int> indeg;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <vector>\n\nstruct TopologicalSort {\n    std::vector<std::vector<int>>\
    \ G;\n\n    TopologicalSort(int n) : G(n), n(n), indeg(n, 0) {}\n\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        G[u].emplace_back(v);\n        indeg[v]++;\n    }\n\n    std::vector<int>\
    \ build() {\n        std::queue<int> que;\n        for (int i = 0; i < n; i++)\
    \ {\n            if (indeg[i] == 0) {\n                que.emplace(i);\n     \
    \       }\n        }\n        std::vector<int> order;\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            order.emplace_back(v);\n\
    \            for (int& u : G[v]) {\n                if (--indeg[u] == 0) {\n \
    \                   que.emplace(u);\n                }\n            }\n      \
    \  }\n        if (*std::max_element(indeg.begin(), indeg.end()) != 0) return {};\n\
    \        return order;\n    }\n\nprivate:\n    int n;\n    std::vector<int> indeg;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/TopologicalSort.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:50:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_4_A.TopologicalSort.test.cpp
documentation_of: graph/TopologicalSort.hpp
layout: document
redirect_from:
- /library/graph/TopologicalSort.hpp
- /library/graph/TopologicalSort.hpp.html
title: graph/TopologicalSort.hpp
---
