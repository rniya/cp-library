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
  bundledCode: "#line 1 \"src/graph/complement_graph_shortest_path.hpp\"\n#include\
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
  code: "#include <algorithm>\n#include <limits>\n#include <queue>\n#include <vector>\n\
    \nstd::vector<int> complement_graph_shortest_path(const std::vector<std::vector<int>>&\
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
  timestamp: '2023-09-11 12:23:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/complement_graph_shortest_path.hpp
layout: document
redirect_from:
- /library/src/graph/complement_graph_shortest_path.hpp
- /library/src/graph/complement_graph_shortest_path.hpp.html
title: src/graph/complement_graph_shortest_path.hpp
---
