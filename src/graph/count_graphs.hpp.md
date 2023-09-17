---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_triangles.test.cpp
    title: test/yosupo/enumerate_triangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/count_graphs.hpp\"\n#include <algorithm>\n#include\
    \ <tuple>\n#include <vector>\n\nnamespace count_graphs {\n\nstd::vector<std::tuple<int,\
    \ int, int>> enumerate_C4(const std::vector<std::vector<int>>& G) {\n    int n\
    \ = G.size();\n    std::vector<int> deg(n);\n    for (int i = 0; i < n; i++) deg[i]\
    \ = G[i].size();\n    auto comp = [&](int u, int v) -> bool { return deg[u] !=\
    \ deg[v] ? deg[u] < deg[v] : u < v; };\n    std::vector<std::vector<int>> H(n);\n\
    \    for (int i = 0; i < n; i++) {\n        for (const int& j : G[i]) {\n    \
    \        if (comp(i, j)) {\n                H[i].emplace_back(j);\n          \
    \  }\n        }\n    }\n    std::vector<bool> f(n, false);\n    std::vector<std::tuple<int,\
    \ int, int>> res;\n    for (int i = 0; i < n; i++) {\n        for (int& j : H[i])\
    \ f[j] = true;\n        for (int& j : H[i]) {\n            for (int& k : H[j])\
    \ {\n                if (f[k]) {\n                    res.emplace_back(i, j, k);\n\
    \                }\n            }\n        }\n        for (int& j : H[i]) f[j]\
    \ = false;\n    }\n    return res;\n}\n\nlong long count_C4(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    std::vector<int> deg(n);\n    for (int i =\
    \ 0; i < n; i++) deg[i] = G[i].size();\n    auto comp = [&](int u, int v) -> bool\
    \ { return deg[u] != deg[v] ? deg[u] < deg[v] : u < v; };\n    std::vector<std::vector<int>>\
    \ H(n);\n    for (int i = 0; i < n; i++) {\n        for (const int& j : G[i])\
    \ {\n            if (comp(i, j)) {\n                H[i].emplace_back(j);\n  \
    \          }\n        }\n    }\n    std::vector<int> f(n, 0);\n    long long res\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        for (const int& j : G[i]) {\n\
    \            for (const int& k : H[j]) {\n                if (comp(i, k)) {\n\
    \                    res += f[k];\n                    f[k]++;\n             \
    \   }\n            }\n        }\n        for (const int& j : G[i]) {\n       \
    \     for (const int& k : H[j]) {\n                f[k] = 0;\n            }\n\
    \        }\n    }\n    return res;\n}\n\nlong long count_K4(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    std::vector<int> deg(n);\n    for (int i =\
    \ 0; i < n; i++) deg[i] = G[i].size();\n    auto comp = [&](int u, int v) -> bool\
    \ { return deg[u] != deg[v] ? deg[u] < deg[v] : u < v; };\n    std::vector<std::vector<int>>\
    \ H(n);\n    for (int i = 0; i < n; i++) {\n        for (const int& j : G[i])\
    \ {\n            if (comp(i, j)) {\n                H[i].emplace_back(j);\n  \
    \          }\n        }\n    }\n    long long res = 0;\n    std::vector<int> idx(n,\
    \ -1);\n    constexpr int B = 64;\n    for (int i = 0; i < n; i++) {\n       \
    \ int len = H[i].size();\n        for (int j = 0; j < len; j++) idx[H[i][j]] =\
    \ j;\n        std::vector<std::vector<int>> I(len);\n        for (int j = 0; j\
    \ < len; j++) {\n            for (int& u : H[H[i][j]]) {\n                if (idx[u]\
    \ == -1) continue;\n                I[j].emplace_back(idx[u]);\n            }\n\
    \        }\n        for (int b = 0; b < (len + B - 1) / B; b++) {\n          \
    \  int L = B * b, R = std::min(len, L + B);\n            std::vector<unsigned\
    \ long long> adj(len, 0);\n            for (int j = L; j < R; j++) {\n       \
    \         for (const int& k : I[j]) {\n                    adj[k] |= 1ULL << (j\
    \ - L);\n                }\n            }\n            for (int j = 0; j < len;\
    \ j++) {\n                for (const int& k : I[j]) {\n                    res\
    \ += __builtin_popcountll(adj[j] & adj[k]);\n                }\n            }\n\
    \        }\n        for (int j = 0; j < len; j++) idx[H[i][j]] = -1;\n    }\n\
    \    return res;\n}\n\n}  // namespace count_graphs\n"
  code: "#include <algorithm>\n#include <tuple>\n#include <vector>\n\nnamespace count_graphs\
    \ {\n\nstd::vector<std::tuple<int, int, int>> enumerate_C4(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    std::vector<int> deg(n);\n    for (int i =\
    \ 0; i < n; i++) deg[i] = G[i].size();\n    auto comp = [&](int u, int v) -> bool\
    \ { return deg[u] != deg[v] ? deg[u] < deg[v] : u < v; };\n    std::vector<std::vector<int>>\
    \ H(n);\n    for (int i = 0; i < n; i++) {\n        for (const int& j : G[i])\
    \ {\n            if (comp(i, j)) {\n                H[i].emplace_back(j);\n  \
    \          }\n        }\n    }\n    std::vector<bool> f(n, false);\n    std::vector<std::tuple<int,\
    \ int, int>> res;\n    for (int i = 0; i < n; i++) {\n        for (int& j : H[i])\
    \ f[j] = true;\n        for (int& j : H[i]) {\n            for (int& k : H[j])\
    \ {\n                if (f[k]) {\n                    res.emplace_back(i, j, k);\n\
    \                }\n            }\n        }\n        for (int& j : H[i]) f[j]\
    \ = false;\n    }\n    return res;\n}\n\nlong long count_C4(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    std::vector<int> deg(n);\n    for (int i =\
    \ 0; i < n; i++) deg[i] = G[i].size();\n    auto comp = [&](int u, int v) -> bool\
    \ { return deg[u] != deg[v] ? deg[u] < deg[v] : u < v; };\n    std::vector<std::vector<int>>\
    \ H(n);\n    for (int i = 0; i < n; i++) {\n        for (const int& j : G[i])\
    \ {\n            if (comp(i, j)) {\n                H[i].emplace_back(j);\n  \
    \          }\n        }\n    }\n    std::vector<int> f(n, 0);\n    long long res\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        for (const int& j : G[i]) {\n\
    \            for (const int& k : H[j]) {\n                if (comp(i, k)) {\n\
    \                    res += f[k];\n                    f[k]++;\n             \
    \   }\n            }\n        }\n        for (const int& j : G[i]) {\n       \
    \     for (const int& k : H[j]) {\n                f[k] = 0;\n            }\n\
    \        }\n    }\n    return res;\n}\n\nlong long count_K4(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    std::vector<int> deg(n);\n    for (int i =\
    \ 0; i < n; i++) deg[i] = G[i].size();\n    auto comp = [&](int u, int v) -> bool\
    \ { return deg[u] != deg[v] ? deg[u] < deg[v] : u < v; };\n    std::vector<std::vector<int>>\
    \ H(n);\n    for (int i = 0; i < n; i++) {\n        for (const int& j : G[i])\
    \ {\n            if (comp(i, j)) {\n                H[i].emplace_back(j);\n  \
    \          }\n        }\n    }\n    long long res = 0;\n    std::vector<int> idx(n,\
    \ -1);\n    constexpr int B = 64;\n    for (int i = 0; i < n; i++) {\n       \
    \ int len = H[i].size();\n        for (int j = 0; j < len; j++) idx[H[i][j]] =\
    \ j;\n        std::vector<std::vector<int>> I(len);\n        for (int j = 0; j\
    \ < len; j++) {\n            for (int& u : H[H[i][j]]) {\n                if (idx[u]\
    \ == -1) continue;\n                I[j].emplace_back(idx[u]);\n            }\n\
    \        }\n        for (int b = 0; b < (len + B - 1) / B; b++) {\n          \
    \  int L = B * b, R = std::min(len, L + B);\n            std::vector<unsigned\
    \ long long> adj(len, 0);\n            for (int j = L; j < R; j++) {\n       \
    \         for (const int& k : I[j]) {\n                    adj[k] |= 1ULL << (j\
    \ - L);\n                }\n            }\n            for (int j = 0; j < len;\
    \ j++) {\n                for (const int& k : I[j]) {\n                    res\
    \ += __builtin_popcountll(adj[j] & adj[k]);\n                }\n            }\n\
    \        }\n        for (int j = 0; j < len; j++) idx[H[i][j]] = -1;\n    }\n\
    \    return res;\n}\n\n}  // namespace count_graphs"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/count_graphs.hpp
  requiredBy: []
  timestamp: '2023-09-18 02:03:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_triangles.test.cpp
documentation_of: src/graph/count_graphs.hpp
layout: document
title: "$C_3$ \u306E\u5217\u6319\uFF0C$C_4, K_4$ \u306E\u6570\u3048\u4E0A\u3052"
---

## 概要

$n$ 頂点 $m$ 辺の無向グラフ $G$ に含まれる $C_3$ の列挙及び $C_4, K_4$ の数え上げを以下に述べる時間計算量で行う．

基本的には各辺を次数の小さい頂点から大きい頂点に向き付けた有向グラフ $H$ を考えることにする．
このとき，各頂点の次数は $\sqrt{2 m}$ で抑えることができる．

#### $C_3$

$H$ 上で $a$ から辺が出ている点 $b$，$b$ から辺が出ている点 $c$ を走査する．
$1$ 本目の辺が $m$ 本で，$2$ 本目の辺がそれぞれ $\mathrm{O}(\sqrt{m})$ 本だから全体で $\mathrm{O}(m\sqrt{m})$ 時間で計算可能である．

#### $C_4$

$4$ 頂点のうち次数が最大の点 $c$ の対角にある頂点 $a$ を固定する．
$1, 2$ 本目の辺をそれぞれ $G, H$ 上にとるような $a$ から $c$ への長さ $2$ のパスを $2$ つ選ぶ選び方を合計すれば良い．

計算量は $\mathrm{O}(m \sqrt{m})$．

#### $K_4$

$K_4$ に含まれる頂点のうち最も小さい頂点 $a$ を固定する．
$a, b, c, d$ が $K_4$ を成すのは $H$ 上で $a$ から $b, c, d$ に辺が張られており，かつ $b, c, d$ が $G$ 上で $C_3$ を成すのと同値であるから，$a$ の $H$ での隣接点からなる誘導部分グラフの中で $C_3$ を数えればよい．

計算量はワードサイズを $w$ として $\mathrm{O}\left(m \sqrt{m} + \frac{m^2}{w}\right)$．

## Links
- [ecnerwala のコメント](https://codeforces.com/blog/entry/97762#comment-866645)

## 問題例
- [The 1st Universal Cup. Stage 13: Iberia K. 4](https://qoj.ac/problem/6354)