---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/TwoSAT.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/StronglyConnectedComponents.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nstruct StronglyConnectedComponents {\n\
    \    std::vector<std::vector<int>> G;\n    std::vector<int> comp;  // component\
    \ id vertex v belongs to\n\n    StronglyConnectedComponents(int n) : G(n), comp(n,\
    \ -1), n(n), time(0), group_num(0), ord(n, -1), low(n) {}\n\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        G[u].emplace_back(v);\n    }\n\n    int add_vertex() {\n      \
    \  G.emplace_back();\n        comp.emplace_back(-1);\n        ord.emplace_back(-1);\n\
    \        low.emplace_back();\n        return n++;\n    }\n\n    std::vector<std::vector<int>>\
    \ build() {\n        for (int i = 0; i < n; i++) {\n            if (ord[i] < 0)\
    \ {\n                dfs(i);\n            }\n        }\n        for (int& x :\
    \ comp) x = group_num - 1 - x;\n        std::vector<std::vector<int>> groups(group_num);\n\
    \        for (int i = 0; i < n; i++) groups[comp[i]].emplace_back(i);\n      \
    \  return groups;\n    }\n\n    std::vector<std::vector<int>> make_graph() {\n\
    \        std::vector<std::vector<int>> dag(group_num);\n        for (int v = 0;\
    \ v < n; v++) {\n            for (int& u : G[v]) {\n                if (comp[v]\
    \ != comp[u]) {\n                    dag[comp[v]].emplace_back(comp[u]);\n   \
    \             }\n            }\n        }\n        for (auto& to : dag) {\n  \
    \          std::sort(to.begin(), to.end());\n            to.erase(unique(to.begin(),\
    \ to.end()), to.end());\n        }\n        return dag;\n    }\n\n    int operator[](int\
    \ v) const { return comp[v]; }\n\nprivate:\n    int n, time, group_num;\n    std::vector<int>\
    \ ord, low, visited;\n\n    void dfs(int v) {\n        ord[v] = low[v] = time++;\n\
    \        visited.emplace_back(v);\n        for (int& u : G[v]) {\n           \
    \ if (ord[u] == -1) {\n                dfs(u);\n                low[v] = std::min(low[v],\
    \ low[u]);\n            } else if (comp[u] < 0) {\n                low[v] = std::min(low[v],\
    \ ord[u]);\n            }\n        }\n        if (ord[v] == low[v]) {\n      \
    \      while (true) {\n                int u = visited.back();\n             \
    \   visited.pop_back();\n                comp[u] = group_num;\n              \
    \  if (u == v) break;\n            }\n            group_num++;\n        }\n  \
    \  }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nstruct StronglyConnectedComponents {\n    std::vector<std::vector<int>> G;\n\
    \    std::vector<int> comp;  // component id vertex v belongs to\n\n    StronglyConnectedComponents(int\
    \ n) : G(n), comp(n, -1), n(n), time(0), group_num(0), ord(n, -1), low(n) {}\n\
    \n    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n      \
    \  assert(0 <= v && v < n);\n        G[u].emplace_back(v);\n    }\n\n    int add_vertex()\
    \ {\n        G.emplace_back();\n        comp.emplace_back(-1);\n        ord.emplace_back(-1);\n\
    \        low.emplace_back();\n        return n++;\n    }\n\n    std::vector<std::vector<int>>\
    \ build() {\n        for (int i = 0; i < n; i++) {\n            if (ord[i] < 0)\
    \ {\n                dfs(i);\n            }\n        }\n        for (int& x :\
    \ comp) x = group_num - 1 - x;\n        std::vector<std::vector<int>> groups(group_num);\n\
    \        for (int i = 0; i < n; i++) groups[comp[i]].emplace_back(i);\n      \
    \  return groups;\n    }\n\n    std::vector<std::vector<int>> make_graph() {\n\
    \        std::vector<std::vector<int>> dag(group_num);\n        for (int v = 0;\
    \ v < n; v++) {\n            for (int& u : G[v]) {\n                if (comp[v]\
    \ != comp[u]) {\n                    dag[comp[v]].emplace_back(comp[u]);\n   \
    \             }\n            }\n        }\n        for (auto& to : dag) {\n  \
    \          std::sort(to.begin(), to.end());\n            to.erase(unique(to.begin(),\
    \ to.end()), to.end());\n        }\n        return dag;\n    }\n\n    int operator[](int\
    \ v) const { return comp[v]; }\n\nprivate:\n    int n, time, group_num;\n    std::vector<int>\
    \ ord, low, visited;\n\n    void dfs(int v) {\n        ord[v] = low[v] = time++;\n\
    \        visited.emplace_back(v);\n        for (int& u : G[v]) {\n           \
    \ if (ord[u] == -1) {\n                dfs(u);\n                low[v] = std::min(low[v],\
    \ low[u]);\n            } else if (comp[u] < 0) {\n                low[v] = std::min(low[v],\
    \ ord[u]);\n            }\n        }\n        if (ord[v] == low[v]) {\n      \
    \      while (true) {\n                int u = visited.back();\n             \
    \   visited.pop_back();\n                comp[u] = group_num;\n              \
    \  if (u == v) break;\n            }\n            group_num++;\n        }\n  \
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/StronglyConnectedComponents.hpp
  requiredBy:
  - graph/TwoSAT.hpp
  timestamp: '2022-04-14 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_C.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
documentation_of: graph/StronglyConnectedComponents.hpp
layout: document
title: "Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
  \uFF09"
---

## 概要
有向グラフを強連結成分に分解する．
各強連結成分の番号は強連結成分を 1 つの頂点にするように縮約した DAG におけるトポロジカル順序を同時に表す．
実装は Tarjan の考案したアルゴリズムに沿っている．

| メンバ関数                       | 効果                                            | 時間計算量            |
| -------------------------------- | ----------------------------------------------- | --------------------- |
| `StronglyConnectedComponents(n)` | $n$ 頂点 $0$ 辺のグラフとして初期化する．       | $O(n)$                |
| `add_edge(u, v)`                 | 頂点 $u$ から頂点 $v$ への有向辺を追加する．    | $O(1)$                |
| `build()`                        | 強連結成分分解， 各強連結成分の頂点集合を返す． | $O(n + m)$            |
| `make_graph()`                   | 各強連結成分を頂点とする DAG の辺情報を返す．   | $O(n + m + m \log m)$ |

`make_graph` では利便性を考えてソートして多重辺を除去しているが，特にその必要もなく時間計算量が問題であればこのパートは除いて良い．
