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
  bundledCode: "#line 2 \"src/graph/RangeEdgeGraph.hpp\"\n#include <limits>\n#include\
    \ <queue>\n#include <vector>\n\ntemplate <typename T> struct RangeEdgeGraph {\n\
    public:\n    RangeEdgeGraph(int n) : n(n), G(3 * n) {\n        for (int i = 1;\
    \ i < n; i++) {\n            int l = i << 1 | 0, r = i << 1 | 1;\n           \
    \ add_edge(i, l, 0);\n            add_edge(i, r, 0);\n            add_edge(l +\
    \ 2 * n, i + 2 * n, 0);\n            add_edge(r + 2 * n, i + 2 * n, 0);\n    \
    \    }\n    }\n    void add_edge(int l1, int r1, int l2, int r2, T cost) {\n \
    \       int add = G.size();\n        G.emplace_back();\n        for (l1 += n,\
    \ r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {\n            if (l1 & 1) add_edge((l1++)\
    \ + 2 * n, add, 0);\n            if (r1 & 1) add_edge((--r1) + 2 * n, add, 0);\n\
    \        }\n        for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {\n  \
    \          if (l2 & 1) G[add].emplace_back(l2++, cost);\n            if (r2 &\
    \ 1) G[add].emplace_back(--r2, cost);\n        }\n    }\n    std::vector<T> build(int\
    \ s) {\n        std::vector<T> dp(G.size(), std::numeric_limits<T>::max());\n\
    \        s += n;\n        dp[s] = 0;\n        std::priority_queue<edge> pq;\n\
    \        pq.emplace(s, dp[s]);\n        while (!pq.empty()) {\n            auto\
    \ p = pq.top();\n            pq.pop();\n            int v = p.to;\n          \
    \  if (dp[v] < p.cost) continue;\n            for (const auto& e : G[v]) {\n \
    \               int u = e.to;\n                if (dp[v] + e.cost < dp[u]) {\n\
    \                    dp[u] = dp[v] + e.cost;\n                    pq.emplace(u,\
    \ dp[u]);\n                }\n            }\n        }\n        std::vector<T>\
    \ res(dp.begin() + n, dp.begin() + 2 * n);\n        return res;\n    }\n\nprivate:\n\
    \    struct edge {\n        int to;\n        T cost;\n        edge(int to, T cost)\
    \ : to(to), cost(cost) {}\n        bool operator<(const edge& rhs) const { return\
    \ cost > rhs.cost; }\n    };\n    int n;\n    std::vector<std::vector<edge>> G;\n\
    \    void add_edge(int u, int v, T cost) { G[(3 * n <= u ? u - 2 * n : u)].emplace_back(v,\
    \ cost); }\n};\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include <vector>\n\n\
    template <typename T> struct RangeEdgeGraph {\npublic:\n    RangeEdgeGraph(int\
    \ n) : n(n), G(3 * n) {\n        for (int i = 1; i < n; i++) {\n            int\
    \ l = i << 1 | 0, r = i << 1 | 1;\n            add_edge(i, l, 0);\n          \
    \  add_edge(i, r, 0);\n            add_edge(l + 2 * n, i + 2 * n, 0);\n      \
    \      add_edge(r + 2 * n, i + 2 * n, 0);\n        }\n    }\n    void add_edge(int\
    \ l1, int r1, int l2, int r2, T cost) {\n        int add = G.size();\n       \
    \ G.emplace_back();\n        for (l1 += n, r1 += n; l1 < r1; l1 >>= 1, r1 >>=\
    \ 1) {\n            if (l1 & 1) add_edge((l1++) + 2 * n, add, 0);\n          \
    \  if (r1 & 1) add_edge((--r1) + 2 * n, add, 0);\n        }\n        for (l2 +=\
    \ n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {\n            if (l2 & 1) G[add].emplace_back(l2++,\
    \ cost);\n            if (r2 & 1) G[add].emplace_back(--r2, cost);\n        }\n\
    \    }\n    std::vector<T> build(int s) {\n        std::vector<T> dp(G.size(),\
    \ std::numeric_limits<T>::max());\n        s += n;\n        dp[s] = 0;\n     \
    \   std::priority_queue<edge> pq;\n        pq.emplace(s, dp[s]);\n        while\
    \ (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n   \
    \         int v = p.to;\n            if (dp[v] < p.cost) continue;\n         \
    \   for (const auto& e : G[v]) {\n                int u = e.to;\n            \
    \    if (dp[v] + e.cost < dp[u]) {\n                    dp[u] = dp[v] + e.cost;\n\
    \                    pq.emplace(u, dp[u]);\n                }\n            }\n\
    \        }\n        std::vector<T> res(dp.begin() + n, dp.begin() + 2 * n);\n\
    \        return res;\n    }\n\nprivate:\n    struct edge {\n        int to;\n\
    \        T cost;\n        edge(int to, T cost) : to(to), cost(cost) {}\n     \
    \   bool operator<(const edge& rhs) const { return cost > rhs.cost; }\n    };\n\
    \    int n;\n    std::vector<std::vector<edge>> G;\n    void add_edge(int u, int\
    \ v, T cost) { G[(3 * n <= u ? u - 2 * n : u)].emplace_back(v, cost); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/RangeEdgeGraph.hpp
  requiredBy: []
  timestamp: '2023-02-14 22:43:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/RangeEdgeGraph.hpp
layout: document
title: Range Edge Graph
---

## 概要
区間から区間に辺が伸びるようなグラフ上での最短路を計算する. Segment Treeの構造を利用して頂点数$3n+q$, 辺数$4n+q\log n$のグラフを構成している.

- 'add_edge(l1, r1, l2, r2, cost)'：$[l1,r1)$から$[l2,r2)$に対して伸びる重み$cost$の辺を追加する.
- 'build(s)'：$s$を始点にしたときの各点までの最短距離を計算する.

## 計算量
- 'add_edge(l1, r1, l2, r2, cost)'：$O(\log n)$
- 'build(s)'：$O(n+q\log n)\log(n+q)$

## 参照
[区間に辺を張るテクの実装例（Dijkstra法セット）と使用例 - Lorent’s diary](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)

## 問題例
- [The 1st Universal Cup. Stage 3: Poland F. Flower Garden](https://qoj.ac/contest/1103/problem/5504?v=1)