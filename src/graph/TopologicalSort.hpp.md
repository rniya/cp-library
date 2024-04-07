---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_4_A.TopologicalSort.test.cpp
    title: test/aoj/GRL_4_A.TopologicalSort.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/TopologicalSort.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <queue>\n#include <vector>\n\nstruct TopologicalSort\
    \ {\n    std::vector<std::vector<int>> G;\n\n    TopologicalSort(int n) : G(n),\
    \ n(n), indeg(n, 0) {}\n\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v);\n\
    \        indeg[v]++;\n    }\n\n    std::vector<int> build() {\n        std::queue<int>\
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
  path: src/graph/TopologicalSort.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_4_A.TopologicalSort.test.cpp
documentation_of: src/graph/TopologicalSort.hpp
layout: document
title: Topological Sort
---

## 概要
有向グラフ $G$ が DAG（Directed Acyclic Graph, 有向閉路をもたないグラフ）であるかの判定及びそうである際に頂点をトポロジカル順序に並び替える．

| メンバ関数           | 効果                                                                              | 時間計算量 |
| -------------------- | --------------------------------------------------------------------------------- | ---------- |
| `TopologicalSort(n)` | $n$ 頂点 $0$ 辺のグラフとして初期化する．                                         | $O(n)$     |
| `add_edge(u, v)`     | 頂点 $u$ から頂点 $v$ への有向辺を追加する．                                      | $O(1)$     |
| `build()`            | 頂点をトポロジカル順序に並べ替えて返す．グラフが DAG でない場合には空配列を返す． | $O(n + m)$ |
