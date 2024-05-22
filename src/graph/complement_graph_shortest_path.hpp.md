---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/complement_graph_shortest_path.hpp\"\n#include\
    \ <algorithm>\n#include <limits>\n#include <queue>\n#include <vector>\n\nstd::vector<int>\
    \ complement_graph_shortest_path(const std::vector<std::vector<int>>& G, int s)\
    \ {\n    int n = G.size();\n    std::vector<int> dist(n, (1 << 30) - 1);\n   \
    \ dist[s] = 0;\n    std::vector<int> L;\n    std::vector<bool> mark(n, false);\n\
    \    for (int i = 0; i < n; i++) {\n        if (i != s) {\n            L.emplace_back(i);\n\
    \        }\n    }\n    std::queue<int> Q;\n    Q.emplace(s);\n    while (not Q.empty())\
    \ {\n        int v = Q.front();\n        Q.pop();\n        for (const int& u :\
    \ G[v]) mark[u] = true;\n        std::partition(begin(L), end(L), [&](const int\
    \ u) { return mark[u]; });\n        while (not L.empty()) {\n            int u\
    \ = L.back();\n            if (mark[u]) break;\n            L.pop_back();\n  \
    \          dist[u] = dist[v] + 1;\n            Q.emplace(u);\n        }\n    \
    \    for (const int& u : G[v]) mark[u] = false;\n    }\n    return dist;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\nstd::vector<int> complement_graph_shortest_path(const std::vector<std::vector<int>>&\
    \ G, int s) {\n    int n = G.size();\n    std::vector<int> dist(n, (1 << 30) -\
    \ 1);\n    dist[s] = 0;\n    std::vector<int> L;\n    std::vector<bool> mark(n,\
    \ false);\n    for (int i = 0; i < n; i++) {\n        if (i != s) {\n        \
    \    L.emplace_back(i);\n        }\n    }\n    std::queue<int> Q;\n    Q.emplace(s);\n\
    \    while (not Q.empty()) {\n        int v = Q.front();\n        Q.pop();\n \
    \       for (const int& u : G[v]) mark[u] = true;\n        std::partition(begin(L),\
    \ end(L), [&](const int u) { return mark[u]; });\n        while (not L.empty())\
    \ {\n            int u = L.back();\n            if (mark[u]) break;\n        \
    \    L.pop_back();\n            dist[u] = dist[v] + 1;\n            Q.emplace(u);\n\
    \        }\n        for (const int& u : G[v]) mark[u] = false;\n    }\n    return\
    \ dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/complement_graph_shortest_path.hpp
  requiredBy: []
  timestamp: '2023-10-01 16:26:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/complement_graph_shortest_path.hpp
layout: document
title: Shortest Path on Complement Graph
---


## 概要
補グラフ上の頂点 $s$ から各点までの最短経路長を $\mathrm{O}(n + m)$ 時間で求める（ここで、$m$ は元のグラフの辺数）．

補グラフは特に以下のような性質をもつ．
- 各点までの最短路の距離は $\mathrm{O}(\sqrt{m})$ である．
  - ある点までの距離が $d$ とすると、最短経路においてその直前の点を除いた $d - 1$ 点と隣接している必要があることからわかる．
- 各点までの最短路の距離の合計は $\mathrm{O}(n + m)$ である．
  - BFS 木で親の親以上の点に対しては元のグラフで辺が貼られている必要がある．
- もとのグラフが非連結ならばその補グラフは連結．

## Links
- https://twitter.com/noshi91/status/1383110660796518401?s=20&t=6NELIs3eDe0fVQxuwfwvow

## 問題例
- [BPC 1 S5 - Temple](https://dmoj.ca/problem/bpc1s5)
- [Educational Codeforces Round 142 (Rated for Div. 2) F2. Graph Coloring (hard version)](https://codeforces.com/contest/1792/problem/F2)
- [AtCoder Beginner Contest 319 G - Counting Shortest Paths](https://atcoder.jp/contests/abc319/tasks/abc319_g)
