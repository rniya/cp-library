---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_B.test.cpp
    title: test/aoj/GRL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/TreeDiameter.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename T = int> struct TreeDiameter {\n    std::vector<std::vector<std::pair<int,\
    \ T>>> G;\n\n    TreeDiameter(int n) : G(n), n(n), dist(n), par(n) {}\n\n    void\
    \ add_edge(int u, int v, T c = 1) {\n        assert(0 <= u && u < n);\n      \
    \  assert(0 <= v && v < n);\n        G[u].emplace_back(v, c);\n        G[v].emplace_back(u,\
    \ c);\n    }\n\n    std::pair<T, std::vector<int>> get_diameter_path() {\n   \
    \     argmax = 0;\n        dfs(argmax, -1);\n        dfs(argmax, -1);\n      \
    \  T diam = dist[argmax];\n        std::vector<int> path;\n        while (argmax\
    \ >= 0) {\n            path.emplace_back(argmax);\n            argmax = par[argmax];\n\
    \        }\n        return {diam, path};\n    }\n\n    std::vector<T> farthest_distance()\
    \ {\n        auto path = get_diameter_path().second;\n        int s = path.front(),\
    \ t = path.back();\n        dfs(s, -1);\n        auto dist_s = dist;\n       \
    \ dfs(t, -1);\n        auto dist_t = dist;\n        for (int i = 0; i < n; i++)\
    \ dist_s[i] = std::max(dist_s[i], dist_t[i]);\n        return dist_s;\n    }\n\
    \nprivate:\n    int n, argmax;\n    std::vector<T> dist;\n    std::vector<int>\
    \ par;\n\n    void dfs(int v, int p) {\n        par[v] = p;\n        if (p < 0)\
    \ dist[v] = T(0);\n        if (dist[argmax] < dist[v]) argmax = v;\n        for\
    \ (auto& e : G[v]) {\n            int u = e.first;\n            if (u == p) continue;\n\
    \            dist[u] = dist[v] + e.second;\n            dfs(u, v);\n        }\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T = int> struct TreeDiameter {\n    std::vector<std::vector<std::pair<int, T>>>\
    \ G;\n\n    TreeDiameter(int n) : G(n), n(n), dist(n), par(n) {}\n\n    void add_edge(int\
    \ u, int v, T c = 1) {\n        assert(0 <= u && u < n);\n        assert(0 <=\
    \ v && v < n);\n        G[u].emplace_back(v, c);\n        G[v].emplace_back(u,\
    \ c);\n    }\n\n    std::pair<T, std::vector<int>> get_diameter_path() {\n   \
    \     argmax = 0;\n        dfs(argmax, -1);\n        dfs(argmax, -1);\n      \
    \  T diam = dist[argmax];\n        std::vector<int> path;\n        while (argmax\
    \ >= 0) {\n            path.emplace_back(argmax);\n            argmax = par[argmax];\n\
    \        }\n        return {diam, path};\n    }\n\n    std::vector<T> farthest_distance()\
    \ {\n        auto path = get_diameter_path().second;\n        int s = path.front(),\
    \ t = path.back();\n        dfs(s, -1);\n        auto dist_s = dist;\n       \
    \ dfs(t, -1);\n        auto dist_t = dist;\n        for (int i = 0; i < n; i++)\
    \ dist_s[i] = std::max(dist_s[i], dist_t[i]);\n        return dist_s;\n    }\n\
    \nprivate:\n    int n, argmax;\n    std::vector<T> dist;\n    std::vector<int>\
    \ par;\n\n    void dfs(int v, int p) {\n        par[v] = p;\n        if (p < 0)\
    \ dist[v] = T(0);\n        if (dist[argmax] < dist[v]) argmax = v;\n        for\
    \ (auto& e : G[v]) {\n            int u = e.first;\n            if (u == p) continue;\n\
    \            dist[u] = dist[v] + e.second;\n            dfs(u, v);\n        }\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/TreeDiameter.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_B.test.cpp
  - test/yosupo/tree_diameter.test.cpp
documentation_of: src/tree/TreeDiameter.hpp
layout: document
title: Tree Diameter
---

## 概要
木の直径を計算するライブラリ．

| メンバ関数            | 効果                                                                                                                       | 時間計算量 |
| --------------------- | -------------------------------------------------------------------------------------------------------------------------- | ---------- |
| `TreeDiameter(n)`     | 頂点数 $n$ の木として初期化する．                                                                                          | $O(n)$     |
| `add_edge(u, b)`      | 辺 $(u,v)$ を追加する．                                                                                                    | $O(1)$     |
| `get_diameter_path()` | 木の直径の長さとそのパスをペアにして返す．                                                                                 | $O(n)$     |
| `farthest_distance()` | 各頂点から最も遠い頂点までの距離を返す．この最も遠い頂点は直径を構成する端点のどちらかであることが直径の最長性から示せる． | $O(n)$     |

## 問題例
- [AtCoder Regular Contest 108 F - Paint Tree](https://atcoder.jp/contests/arc108/tasks/arc108_f)
- [Codeforces Round #292 (Div. 1) D. Drazil and Morning Exercise](https://codeforces.com/contest/516/problem/D)
