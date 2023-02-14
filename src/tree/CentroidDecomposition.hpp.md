---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/CentroidDecomposition.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nstruct CentroidDecomposition {\n    std::vector<std::vector<int>>\
    \ G;\n\n    CentroidDecomposition(int n) : G(n), n(n), sub(n), is_centroid(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    std::vector<int> build(int x = 0) {\n        centroids.clear();\n\
    \        fill(is_centroid.begin(), is_centroid.end(), false);\n        centroid_decomposition(x);\n\
    \        return centroids;\n    }\n\nprivate:\n    int n;\n    std::vector<int>\
    \ sub, centroids;\n    std::vector<bool> is_centroid;\n\n    int dfs_sz(int v,\
    \ int p) {\n        sub[v] = 1;\n        for (int& u : G[v]) {\n            if\
    \ (u == p || is_centroid[u]) continue;\n            sub[v] += dfs_sz(u, v);\n\
    \        }\n        return sub[v];\n    }\n\n    int dfs_search_centroid(int v,\
    \ int p, int mid) {\n        for (int& u : G[v]) {\n            if (u == p ||\
    \ is_centroid[u]) continue;\n            if (sub[u] > mid) return dfs_search_centroid(u,\
    \ v, mid);\n        }\n        return v;\n    }\n\n    void centroid_decomposition(int\
    \ r) {\n        int centroid = dfs_search_centroid(r, -1, dfs_sz(r, -1) / 2);\n\
    \        centroids.emplace_back(centroid);\n        is_centroid[centroid] = true;\n\
    \        for (int& ch : G[centroid]) {\n            if (is_centroid[ch]) continue;\n\
    \            centroid_decomposition(ch);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nstruct CentroidDecomposition\
    \ {\n    std::vector<std::vector<int>> G;\n\n    CentroidDecomposition(int n)\
    \ : G(n), n(n), sub(n), is_centroid(n) {}\n\n    void add_edge(int u, int v) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n\n    std::vector<int> build(int x = 0)\
    \ {\n        centroids.clear();\n        fill(is_centroid.begin(), is_centroid.end(),\
    \ false);\n        centroid_decomposition(x);\n        return centroids;\n   \
    \ }\n\nprivate:\n    int n;\n    std::vector<int> sub, centroids;\n    std::vector<bool>\
    \ is_centroid;\n\n    int dfs_sz(int v, int p) {\n        sub[v] = 1;\n      \
    \  for (int& u : G[v]) {\n            if (u == p || is_centroid[u]) continue;\n\
    \            sub[v] += dfs_sz(u, v);\n        }\n        return sub[v];\n    }\n\
    \n    int dfs_search_centroid(int v, int p, int mid) {\n        for (int& u :\
    \ G[v]) {\n            if (u == p || is_centroid[u]) continue;\n            if\
    \ (sub[u] > mid) return dfs_search_centroid(u, v, mid);\n        }\n        return\
    \ v;\n    }\n\n    void centroid_decomposition(int r) {\n        int centroid\
    \ = dfs_search_centroid(r, -1, dfs_sz(r, -1) / 2);\n        centroids.emplace_back(centroid);\n\
    \        is_centroid[centroid] = true;\n        for (int& ch : G[centroid]) {\n\
    \            if (is_centroid[ch]) continue;\n            centroid_decomposition(ch);\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/CentroidDecomposition.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
documentation_of: src/tree/CentroidDecomposition.hpp
layout: document
title: "Centroid Decomposition\uFF08\u6728\u306E\u91CD\u5FC3\u5206\u89E3\uFF09"
---

## 概要
木の重心分解を扱う．

| メンバ関数                 | 効果                              | 時間計算量    |
| -------------------------- | --------------------------------- | ------------- |
| `CentroidDecomposition(n)` | 頂点数 $n$ の木として初期化する． | $O(n)$        |
| `add_edge(u, v)`           | 辺 $(u,v)$ を追加する．           | $O(1)$        |
| `build()`                  | 重心分解を構築する（後述）        | $O(n \log n)$ |

木の重心とは，その頂点を取り除いて残るすべての部分木のうち最大のものの頂点数が最小になる頂点である．
特に嬉しいのは，重心を取り除いて残るすべての部分木の頂点数がもとの木の頂点数の半分以下になっているという性質で，これにより再帰の深さは $O(\log n)$ で抑えられる．
各深さ帯においての処理に $O(n)$ かけてもよく，現在の部分木の頂点を全探索するといったことも行える．
このためパスの数え上げ等の問題によく用いられる手法である．

メンバ関数 `build()` はもとの木を重心分解していく過程における重心を dfs-order に列挙する．
これをもとにまた別に重心を潰しながら探索していくのが良い．

## 問題例
- [COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred) E. Eye-Pleasing City Park Tour](https://codeforces.com/contest/1575/problem/E)
  - 頂点に重みがついた，距離 $k$ 以下のパスの重みの総和の数え上げ．
- [AtCoder Regular Contest 087 F - Squirrel Migration](https://atcoder.jp/contests/arc087/tasks/arc087_d)
  - 直接重心分解を用いる訳ではないが重心の性質を利用する．