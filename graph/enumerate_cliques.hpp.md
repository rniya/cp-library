---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2306.test.cpp
    title: test/aoj/2306.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_cliques.test.cpp
    title: test/yosupo/enumerate_cliques.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/enumerate_cliques.hpp\"\n#include <queue>\n#include\
    \ <vector>\n\nstd::vector<std::vector<int>> enumerate_cliques(std::vector<std::vector<bool>>\
    \ G) {\n    int n = G.size(), m = 0;\n    std::vector<int> deg(n, 0);\n    for\
    \ (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) deg[i] += G[i][j];\n\
    \        m += deg[i];\n    }\n    std::vector<std::vector<int>> cliques;\n\n \
    \   auto add_clique = [&](const std::vector<int>& cand, bool last) {\n       \
    \ int size = cand.size() - last;\n        std::vector<int> not_adj(size);\n  \
    \      for (int i = 0; i < size; i++) {\n            for (int j = 0; j < size;\
    \ j++) {\n                if (i != j && !G[cand[i]][cand[j]]) {\n            \
    \        not_adj[i] |= 1 << j;\n                }\n            }\n        }\n\
    \        for (int mask = 1 - last; mask < (1 << (size)); mask++) {\n         \
    \   bool ok = true;\n            for (int i = 0; i < size; i++) {\n          \
    \      if ((mask >> i & 1) && (mask & not_adj[i])) {\n                    ok =\
    \ false;\n                    break;\n                }\n            }\n     \
    \       if (!ok) continue;\n            std::vector<int> clique;\n           \
    \ if (last) clique.emplace_back(cand.back());\n            for (int i = 0; i <\
    \ size; i++) {\n                if (mask >> i & 1) {\n                    clique.emplace_back(cand[i]);\n\
    \                }\n            }\n            cliques.emplace_back(clique);\n\
    \        }\n    };\n\n    std::vector<bool> used(n, false);\n    std::queue<int>\
    \ que;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] * (deg[i] + 1) <=\
    \ m) {\n            used[i] = true;\n            que.emplace(i);\n        }\n\
    \    }\n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        std::vector<int> cand;\n        for (int u = 0; u < n; u++) {\n     \
    \       if (G[v][u]) {\n                cand.emplace_back(u);\n            }\n\
    \        }\n        cand.emplace_back(v);\n        add_clique(cand, true);\n \
    \       for (int u = 0; u < n; u++) {\n            if (!G[v][u]) continue;\n \
    \           G[v][u] = G[u][v] = false;\n            deg[u]--;\n            if\
    \ (!used[u] && deg[u] * (deg[u] + 1) <= m) {\n                used[u] = true;\n\
    \                que.emplace(u);\n            }\n        }\n    }\n    std::vector<int>\
    \ rest;\n    for (int i = 0; i < n; i++) {\n        if (!used[i]) {\n        \
    \    rest.emplace_back(i);\n        }\n    }\n    add_clique(rest, false);\n \
    \   return cliques;\n}\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\n\nstd::vector<std::vector<int>>\
    \ enumerate_cliques(std::vector<std::vector<bool>> G) {\n    int n = G.size(),\
    \ m = 0;\n    std::vector<int> deg(n, 0);\n    for (int i = 0; i < n; i++) {\n\
    \        for (int j = 0; j < n; j++) deg[i] += G[i][j];\n        m += deg[i];\n\
    \    }\n    std::vector<std::vector<int>> cliques;\n\n    auto add_clique = [&](const\
    \ std::vector<int>& cand, bool last) {\n        int size = cand.size() - last;\n\
    \        std::vector<int> not_adj(size);\n        for (int i = 0; i < size; i++)\
    \ {\n            for (int j = 0; j < size; j++) {\n                if (i != j\
    \ && !G[cand[i]][cand[j]]) {\n                    not_adj[i] |= 1 << j;\n    \
    \            }\n            }\n        }\n        for (int mask = 1 - last; mask\
    \ < (1 << (size)); mask++) {\n            bool ok = true;\n            for (int\
    \ i = 0; i < size; i++) {\n                if ((mask >> i & 1) && (mask & not_adj[i]))\
    \ {\n                    ok = false;\n                    break;\n           \
    \     }\n            }\n            if (!ok) continue;\n            std::vector<int>\
    \ clique;\n            if (last) clique.emplace_back(cand.back());\n         \
    \   for (int i = 0; i < size; i++) {\n                if (mask >> i & 1) {\n \
    \                   clique.emplace_back(cand[i]);\n                }\n       \
    \     }\n            cliques.emplace_back(clique);\n        }\n    };\n\n    std::vector<bool>\
    \ used(n, false);\n    std::queue<int> que;\n    for (int i = 0; i < n; i++) {\n\
    \        if (deg[i] * (deg[i] + 1) <= m) {\n            used[i] = true;\n    \
    \        que.emplace(i);\n        }\n    }\n    while (!que.empty()) {\n     \
    \   int v = que.front();\n        que.pop();\n        std::vector<int> cand;\n\
    \        for (int u = 0; u < n; u++) {\n            if (G[v][u]) {\n         \
    \       cand.emplace_back(u);\n            }\n        }\n        cand.emplace_back(v);\n\
    \        add_clique(cand, true);\n        for (int u = 0; u < n; u++) {\n    \
    \        if (!G[v][u]) continue;\n            G[v][u] = G[u][v] = false;\n   \
    \         deg[u]--;\n            if (!used[u] && deg[u] * (deg[u] + 1) <= m) {\n\
    \                used[u] = true;\n                que.emplace(u);\n          \
    \  }\n        }\n    }\n    std::vector<int> rest;\n    for (int i = 0; i < n;\
    \ i++) {\n        if (!used[i]) {\n            rest.emplace_back(i);\n       \
    \ }\n    }\n    add_clique(rest, false);\n    return cliques;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/enumerate_cliques.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:50:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_cliques.test.cpp
  - test/aoj/2306.test.cpp
documentation_of: graph/enumerate_cliques.hpp
layout: document
title: "\u30AF\u30EA\u30FC\u30AF\u5168\u5217\u6319"
---

## 概要
グラフのクリークを全列挙する．
時間計算量は頂点数 $n$，辺数 $m$ として $O(2^{\sqrt{2m}} n)$ となる．
あまり見ない計算量だが，$n, m \sim 200$ でも高速に動作する．

## Links
- [指数時間アルゴリズム入門](https://www.slideshare.net/wata_orz/ss-12131479)
