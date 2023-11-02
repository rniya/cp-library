---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/count_clique.hpp
    title: "\u30AF\u30EA\u30FC\u30AF\u306E\u6570\u3048\u4E0A\u3052"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/count_independent_set.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace internal {\n\nunsigned long long f(unsigned long\
    \ long,\n                     const std::vector<unsigned long long>&,\n      \
    \               const std::vector<unsigned long long>&,\n                    \
    \ const std::vector<unsigned long long>&);\nunsigned long long g(unsigned long\
    \ long,\n                     const std::vector<unsigned long long>&,\n      \
    \               const std::vector<unsigned long long>&,\n                    \
    \ const std::vector<unsigned long long>&);\n\nunsigned long long f(unsigned long\
    \ long S,\n                     const std::vector<unsigned long long>& G,\n  \
    \                   const std::vector<unsigned long long>& path,\n           \
    \          const std::vector<unsigned long long>& cycle) {\n    unsigned long\
    \ long res = 1;\n    for (; S;) {\n        int v = __builtin_ctzll(S);\n     \
    \   unsigned long long comp = 1ULL << v, seen = 0;\n        for (; comp & ~seen;)\
    \ {\n            int u = __builtin_ctzll(comp & ~seen);\n            comp |= G[u]\
    \ & S;\n            seen |= 1ULL << u;\n        }\n        res *= g(comp, G, path,\
    \ cycle);\n        S &= ~comp;\n    }\n    return res;\n}\n\nunsigned long long\
    \ g(unsigned long long S,\n                     const std::vector<unsigned long\
    \ long>& G,\n                     const std::vector<unsigned long long>& path,\n\
    \                     const std::vector<unsigned long long>& cycle) {\n    if\
    \ (!S) return 1;\n    if (!(S & (S - 1))) return 2;\n    int maxi = -1, argmax\
    \ = -1, one = 0, tot = __builtin_popcountll(S);\n    for (unsigned long long T\
    \ = S; T;) {\n        int v = __builtin_ctzll(T);\n        T &= ~(1ULL << v);\n\
    \        int deg = __builtin_popcountll(G[v] & S);\n        if (maxi < deg) {\n\
    \            maxi = deg;\n            argmax = v;\n        }\n        one += (deg\
    \ == 1);\n    }\n    if (maxi <= 2) return one ? path[tot] : cycle[tot];\n   \
    \ S &= ~(1ULL << argmax);\n    return f(S, G, path, cycle) + f(S & ~G[argmax],\
    \ G, path, cycle);\n}\n\n}  // namespace internal\n\nunsigned long long count_independent_set(const\
    \ std::vector<unsigned long long>& G) {\n    int n = G.size();\n    assert(n <\
    \ 64);\n    if (n == 0) return 1;\n    std::vector<unsigned long long> path(n\
    \ + 1), cycle(n + 1);\n    path[0] = 1, path[1] = 2;\n    for (int i = 2; i <=\
    \ n; i++) path[i] = path[i - 1] + path[i - 2];\n    cycle[0] = 2, cycle[1] = 1;\n\
    \    for (int i = 2; i <= n; i++) cycle[i] = cycle[i - 1] + cycle[i - 2];\n  \
    \  return internal::f((1ULL << n) - 1, G, path, cycle);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace internal\
    \ {\n\nunsigned long long f(unsigned long long,\n                     const std::vector<unsigned\
    \ long long>&,\n                     const std::vector<unsigned long long>&,\n\
    \                     const std::vector<unsigned long long>&);\nunsigned long\
    \ long g(unsigned long long,\n                     const std::vector<unsigned\
    \ long long>&,\n                     const std::vector<unsigned long long>&,\n\
    \                     const std::vector<unsigned long long>&);\n\nunsigned long\
    \ long f(unsigned long long S,\n                     const std::vector<unsigned\
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
    \  return internal::f((1ULL << n) - 1, G, path, cycle);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/count_independent_set.hpp
  requiredBy:
  - src/graph/count_clique.hpp
  timestamp: '2023-11-03 03:12:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/count_independent_set.hpp
layout: document
title: "\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\u4E0A\u3052"
---

## 概要
$n$ 頂点の自己ループを含まないグラフ $G$ の独立集合の個数を数える．
計算量は $\mathrm{O}(n 1.381^n)$．

`unsigned long long` を使って計算している都合上，$n < 64$ という制約を課している（オーバーフローさせたり mod を取ったりでそれ以上の値でも計算自体は可能）．

## Links
- [指数時間アルゴリズム入門 \| PPT](https://www.slideshare.net/wata_orz/ss-12131479)