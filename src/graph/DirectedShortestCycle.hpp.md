---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1320.test.cpp
    title: test/yukicoder/1320.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/DirectedShortestCycle.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <tuple>\n#include\
    \ <vector>\n\ntemplate <typename T> struct DirectedShortestCycle {\n    struct\
    \ edge {\n        int from, to;\n        T cost;\n        edge(int from, int to,\
    \ T cost) : from(from), to(to), cost(cost) {}\n    };\n\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<edge> edges;\n\n    DirectedShortestCycle(int n) : n(n),\
    \ G(n) {}\n\n    void add_edge(int u, int v, T w) {\n        assert(0 <= u and\
    \ u < n);\n        assert(0 <= v and v < n);\n        assert(w >= 0);\n      \
    \  G[u].emplace_back(edges.size());\n        edges.emplace_back(u, v, w);\n  \
    \  }\n\n    std::tuple<T, std::vector<int>, std::vector<int>> solve(int r) {\n\
    \        std::vector<int> prve(n, -1);\n        std::vector<T> dist(n, inf);\n\
    \        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<>> pq;\n        for (const int& idx : G[r]) {\n            int\
    \ u = edges[idx].to, w = edges[idx].cost;\n            if (w < dist[u]) {\n  \
    \              dist[u] = w;\n                prve[u] = idx;\n                pq.emplace(dist[u],\
    \ u);\n            }\n        }\n        while (not pq.empty()) {\n          \
    \  auto [d, v] = pq.top();\n            pq.pop();\n            if (dist[v] < d)\
    \ continue;\n            for (const int& idx : G[v]) {\n                int u\
    \ = edges[idx].to, w = edges[idx].cost;\n                if (dist[u] <= dist[v]\
    \ + w) continue;\n                dist[u] = dist[v] + w;\n                prve[u]\
    \ = idx;\n                pq.emplace(dist[u], u);\n            }\n        }\n\n\
    \        if (dist[r] == inf) return {inf, {}, {}};\n        std::vector<int> vs,\
    \ es;\n        vs.emplace_back(r);\n        while (true) {\n            int idx\
    \ = prve[vs.back()];\n            es.emplace_back(idx);\n            vs.emplace_back(edges[idx].from);\n\
    \            if (vs.back() == r) break;\n        }\n        std::reverse(vs.begin(),\
    \ vs.end());\n        std::reverse(es.begin(), es.end());\n        vs.pop_back();\n\
    \        return {dist[r], vs, es};\n    }\n\n  private:\n    constexpr static\
    \ T inf = std::numeric_limits<T>::max() / 2;\n    int n;\n};\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n\
    #include <tuple>\n#include <vector>\n\ntemplate <typename T> struct DirectedShortestCycle\
    \ {\n    struct edge {\n        int from, to;\n        T cost;\n        edge(int\
    \ from, int to, T cost) : from(from), to(to), cost(cost) {}\n    };\n\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<edge> edges;\n\n    DirectedShortestCycle(int n) : n(n),\
    \ G(n) {}\n\n    void add_edge(int u, int v, T w) {\n        assert(0 <= u and\
    \ u < n);\n        assert(0 <= v and v < n);\n        assert(w >= 0);\n      \
    \  G[u].emplace_back(edges.size());\n        edges.emplace_back(u, v, w);\n  \
    \  }\n\n    std::tuple<T, std::vector<int>, std::vector<int>> solve(int r) {\n\
    \        std::vector<int> prve(n, -1);\n        std::vector<T> dist(n, inf);\n\
    \        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\
    \ std::greater<>> pq;\n        for (const int& idx : G[r]) {\n            int\
    \ u = edges[idx].to, w = edges[idx].cost;\n            if (w < dist[u]) {\n  \
    \              dist[u] = w;\n                prve[u] = idx;\n                pq.emplace(dist[u],\
    \ u);\n            }\n        }\n        while (not pq.empty()) {\n          \
    \  auto [d, v] = pq.top();\n            pq.pop();\n            if (dist[v] < d)\
    \ continue;\n            for (const int& idx : G[v]) {\n                int u\
    \ = edges[idx].to, w = edges[idx].cost;\n                if (dist[u] <= dist[v]\
    \ + w) continue;\n                dist[u] = dist[v] + w;\n                prve[u]\
    \ = idx;\n                pq.emplace(dist[u], u);\n            }\n        }\n\n\
    \        if (dist[r] == inf) return {inf, {}, {}};\n        std::vector<int> vs,\
    \ es;\n        vs.emplace_back(r);\n        while (true) {\n            int idx\
    \ = prve[vs.back()];\n            es.emplace_back(idx);\n            vs.emplace_back(edges[idx].from);\n\
    \            if (vs.back() == r) break;\n        }\n        std::reverse(vs.begin(),\
    \ vs.end());\n        std::reverse(es.begin(), es.end());\n        vs.pop_back();\n\
    \        return {dist[r], vs, es};\n    }\n\n  private:\n    constexpr static\
    \ T inf = std::numeric_limits<T>::max() / 2;\n    int n;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/DirectedShortestCycle.hpp
  requiredBy: []
  timestamp: '2024-04-07 21:00:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1320.test.cpp
documentation_of: src/graph/DirectedShortestCycle.hpp
layout: document
title: Directed Shortest Cycle
---

## 概要

| メンバ関数                 | 効果                                                        | 時間計算量             |
| -------------------------- | ----------------------------------------------------------- | ---------------------- |
| `DirectedShortestCycle(n)` | $n$ 頂点 $0$ 辺のグラフとして初期化する．                   | $\mathrm{O}(n)$        |
| `add_edge(u, v, w)`        | 頂点 $u$ から $v$ への重み $w$ の有向辺を追加する．         | $\mathrm{O}(1)$        |
| `solve(r)`                 | 頂点 $r$ を含む最小重みサイクルの周長，頂点列，辺列を返す． | $\mathrm{O}(m \log n)$ |


## 問題例
- [AtCoder Beginner Contest 308 Ex - Make Q](https://atcoder.jp/contests/abc308/tasks/abc308_h)
