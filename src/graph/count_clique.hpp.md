---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/graph/count_independent_set.hpp
    title: "\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\u4E0A\u3052"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/count_clique.hpp\"\n#include <algorithm>\n#line\
    \ 2 \"src/graph/count_independent_set.hpp\"\n#include <cassert>\n#include <vector>\n\
    \nnamespace internal {\n\nunsigned long long f(unsigned long long,\n         \
    \            const std::vector<unsigned long long>&,\n                     const\
    \ std::vector<unsigned long long>&,\n                     const std::vector<unsigned\
    \ long long>&);\nunsigned long long g(unsigned long long,\n                  \
    \   const std::vector<unsigned long long>&,\n                     const std::vector<unsigned\
    \ long long>&,\n                     const std::vector<unsigned long long>&);\n\
    \nunsigned long long f(unsigned long long S,\n                     const std::vector<unsigned\
    \ long long>& G,\n                     const std::vector<unsigned long long>&\
    \ path,\n                     const std::vector<unsigned long long>& cycle) {\n\
    \    unsigned long long res = 1;\n    for (; S;) {\n        int v = __builtin_ctzll(S);\n\
    \        unsigned long long comp = 1ULL << v, seen = 0;\n        for (; comp &\
    \ ~seen;) {\n            int u = __builtin_ctzll(comp & ~seen);\n            comp\
    \ |= G[u] & S;\n            seen |= 1ULL << u;\n        }\n        res *= g(comp,\
    \ G, path, cycle);\n        S &= ~comp;\n    }\n    return res;\n}\n\nunsigned\
    \ long long g(unsigned long long S,\n                     const std::vector<unsigned\
    \ long long>& G,\n                     const std::vector<unsigned long long>&\
    \ path,\n                     const std::vector<unsigned long long>& cycle) {\n\
    \    if (!S) return 1;\n    if (!(S & (S - 1))) return 2;\n    int maxi = -1,\
    \ argmax = -1, one = 0, tot = __builtin_popcountll(S);\n    for (unsigned long\
    \ long T = S; T;) {\n        int v = __builtin_ctzll(T);\n        T &= ~(1ULL\
    \ << v);\n        int deg = __builtin_popcountll(G[v] & S);\n        if (maxi\
    \ < deg) {\n            maxi = deg;\n            argmax = v;\n        }\n    \
    \    one += (deg == 1);\n    }\n    if (maxi <= 2) return one ? path[tot] : cycle[tot];\n\
    \    S &= ~(1ULL << argmax);\n    return f(S, G, path, cycle) + f(S & ~G[argmax],\
    \ G, path, cycle);\n}\n\n}  // namespace internal\n\nunsigned long long count_independent_set(const\
    \ std::vector<unsigned long long>& G) {\n    int n = G.size();\n    assert(n <\
    \ 64);\n    if (n == 0) return 1;\n    std::vector<unsigned long long> path(n\
    \ + 1), cycle(n + 1);\n    path[0] = 1, path[1] = 2;\n    for (int i = 2; i <=\
    \ n; i++) path[i] = path[i - 1] + path[i - 2];\n    cycle[0] = 2, cycle[1] = 1;\n\
    \    for (int i = 2; i <= n; i++) cycle[i] = cycle[i - 1] + cycle[i - 2];\n  \
    \  return internal::f((1ULL << n) - 1, G, path, cycle);\n}\n#line 4 \"src/graph/count_clique.hpp\"\
    \n\ntemplate <typename T> T count_clique(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    T res = 1;\n    std::vector<int> deg(n), idx(n,\
    \ -1);\n    for (int i = 0; i < n; i++) deg[i] = G[i].size();\n    while (true)\
    \ {\n        int v = -1;\n        for (int i = 0; i < n; i++) {\n            if\
    \ (deg[i] != -1 and (v == -1 or deg[i] < deg[v])) {\n                v = i;\n\
    \            }\n        }\n        if (v == -1) break;\n        deg[v] = -1;\n\
    \        int adj = 0;\n        for (const int& u : G[v]) {\n            if (deg[u]\
    \ == -1) continue;\n            --deg[u];\n            idx[u] = adj++;\n     \
    \   }\n        std::vector<unsigned long long> g(adj, (1ULL << adj) - 1);\n  \
    \      for (const int& u : G[v]) {\n            if (idx[u] == -1) continue;\n\
    \            int x = idx[u];\n            g[x] &= ~(1ULL << x);\n            for\
    \ (const int& w : G[u]) {\n                if (idx[w] == -1) continue;\n     \
    \           int y = idx[w];\n                g[x] &= ~(1ULL << y);\n         \
    \       g[y] &= ~(1ULL << x);\n            }\n        }\n        res += count_independent_set(g);\n\
    \        for (const int& u : G[v]) {\n            if (deg[u] == -1) continue;\n\
    \            idx[u] = -1;\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include \"count_independent_set.hpp\"\
    \n\ntemplate <typename T> T count_clique(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    T res = 1;\n    std::vector<int> deg(n), idx(n,\
    \ -1);\n    for (int i = 0; i < n; i++) deg[i] = G[i].size();\n    while (true)\
    \ {\n        int v = -1;\n        for (int i = 0; i < n; i++) {\n            if\
    \ (deg[i] != -1 and (v == -1 or deg[i] < deg[v])) {\n                v = i;\n\
    \            }\n        }\n        if (v == -1) break;\n        deg[v] = -1;\n\
    \        int adj = 0;\n        for (const int& u : G[v]) {\n            if (deg[u]\
    \ == -1) continue;\n            --deg[u];\n            idx[u] = adj++;\n     \
    \   }\n        std::vector<unsigned long long> g(adj, (1ULL << adj) - 1);\n  \
    \      for (const int& u : G[v]) {\n            if (idx[u] == -1) continue;\n\
    \            int x = idx[u];\n            g[x] &= ~(1ULL << x);\n            for\
    \ (const int& w : G[u]) {\n                if (idx[w] == -1) continue;\n     \
    \           int y = idx[w];\n                g[x] &= ~(1ULL << y);\n         \
    \       g[y] &= ~(1ULL << x);\n            }\n        }\n        res += count_independent_set(g);\n\
    \        for (const int& u : G[v]) {\n            if (deg[u] == -1) continue;\n\
    \            idx[u] = -1;\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/graph/count_independent_set.hpp
  isVerificationFile: false
  path: src/graph/count_clique.hpp
  requiredBy: []
  timestamp: '2023-11-03 03:12:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/count_clique.hpp
layout: document
title: "\u30AF\u30EA\u30FC\u30AF\u306E\u6570\u3048\u4E0A\u3052"
---

## 概要
$n$ 頂点の自己ループを含まないグラフ $G$ のクリークの個数を数える．


## 問題例
- [The 2nd Universal Cup. Stage 3: Binjiang C. Clique Challenge](https://contest.ucup.ac/contest/1358/problem/7514)