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
  bundledCode: "#line 1 \"src/graph/UndirectedShortestCycle.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <tuple>\n#include\
    \ <vector>\n\ntemplate <typename T> struct UndirectedShortestCycle {\n    struct\
    \ edge {\n        int from, to;\n        T cost;\n        edge(int from, int to,\
    \ T cost) : from(from), to(to), cost(cost) {}\n    };\n\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<edge> edges;\n\n    UndirectedShortestCycle(int n) : n(n),\
    \ G(n) {}\n\n    void add_edge(int u, int v, T w) {\n        assert(0 <= u and\
    \ u < n);\n        assert(0 <= v and v < n);\n        assert(w >= 0);\n      \
    \  G[u].emplace_back(edges.size());\n        G[v].emplace_back(edges.size());\n\
    \        edges.emplace_back(u, v, w);\n    }\n\n    std::tuple<T, std::vector<int>,\
    \ std::vector<int>> solve(int r) {\n        std::vector<int> label(n, -1), prve(n,\
    \ -1);\n        std::vector<T> dist(n, inf);\n        std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<>> pq;\n        dist[r] =\
    \ 0;\n        pq.emplace(dist[r], r);\n        label[r] = r;\n        while (not\
    \ pq.empty()) {\n            auto [d, v] = pq.top();\n            pq.pop();\n\
    \            if (dist[v] < d) continue;\n            for (const int& idx : G[v])\
    \ {\n                int u = edges[idx].from ^ edges[idx].to ^ v, w = edges[idx].cost;\n\
    \                if (dist[u] <= dist[v] + w) continue;\n                dist[u]\
    \ = dist[v] + w;\n                label[u] = label[v] == r ? u : label[v];\n \
    \               prve[u] = idx;\n                pq.emplace(dist[u], u);\n    \
    \        }\n        }\n\n        std::vector<bool> used(edges.size(), false);\n\
    \        for (int& idx : prve) {\n            if (idx != -1) {\n             \
    \   used[idx] = true;\n            }\n        }\n        T mini = inf;\n     \
    \   int argmin = -1;\n        for (int i = 0; i < int(edges.size()); i++) {\n\
    \            if (used[i]) continue;\n            auto [u, v, w] = edges[i];\n\
    \            if (label[u] == -1) continue;\n            if (label[u] == label[v])\
    \ continue;\n            if (dist[u] + dist[v] + w < mini) {\n               \
    \ mini = dist[u] + dist[v] + w;\n                argmin = i;\n            }\n\
    \        }\n        if (argmin == -1) return {mini, {}, {}};\n\n        std::vector<int>\
    \ vs, es;\n        int a = edges[argmin].from, b = edges[argmin].to;\n       \
    \ while (a != r) {\n            int idx = prve[a];\n            vs.emplace_back(a);\n\
    \            es.emplace_back(idx);\n            a = edges[idx].from ^ edges[idx].to\
    \ ^ a;\n        }\n        vs.emplace_back(a);\n        std::reverse(vs.begin(),\
    \ vs.end());\n        std::reverse(es.begin(), es.end());\n        es.emplace_back(argmin);\n\
    \        while (b != r) {\n            int idx = prve[b];\n            vs.emplace_back(b);\n\
    \            es.emplace_back(idx);\n            b = edges[idx].from ^ edges[idx].to\
    \ ^ b;\n        }\n        return {mini, vs, es};\n    }\n\n  private:\n    constexpr\
    \ static T inf = std::numeric_limits<T>::max() / 2;\n    int n;\n};\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n\
    #include <tuple>\n#include <vector>\n\ntemplate <typename T> struct UndirectedShortestCycle\
    \ {\n    struct edge {\n        int from, to;\n        T cost;\n        edge(int\
    \ from, int to, T cost) : from(from), to(to), cost(cost) {}\n    };\n\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<edge> edges;\n\n    UndirectedShortestCycle(int n) : n(n),\
    \ G(n) {}\n\n    void add_edge(int u, int v, T w) {\n        assert(0 <= u and\
    \ u < n);\n        assert(0 <= v and v < n);\n        assert(w >= 0);\n      \
    \  G[u].emplace_back(edges.size());\n        G[v].emplace_back(edges.size());\n\
    \        edges.emplace_back(u, v, w);\n    }\n\n    std::tuple<T, std::vector<int>,\
    \ std::vector<int>> solve(int r) {\n        std::vector<int> label(n, -1), prve(n,\
    \ -1);\n        std::vector<T> dist(n, inf);\n        std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<>> pq;\n        dist[r] =\
    \ 0;\n        pq.emplace(dist[r], r);\n        label[r] = r;\n        while (not\
    \ pq.empty()) {\n            auto [d, v] = pq.top();\n            pq.pop();\n\
    \            if (dist[v] < d) continue;\n            for (const int& idx : G[v])\
    \ {\n                int u = edges[idx].from ^ edges[idx].to ^ v, w = edges[idx].cost;\n\
    \                if (dist[u] <= dist[v] + w) continue;\n                dist[u]\
    \ = dist[v] + w;\n                label[u] = label[v] == r ? u : label[v];\n \
    \               prve[u] = idx;\n                pq.emplace(dist[u], u);\n    \
    \        }\n        }\n\n        std::vector<bool> used(edges.size(), false);\n\
    \        for (int& idx : prve) {\n            if (idx != -1) {\n             \
    \   used[idx] = true;\n            }\n        }\n        T mini = inf;\n     \
    \   int argmin = -1;\n        for (int i = 0; i < int(edges.size()); i++) {\n\
    \            if (used[i]) continue;\n            auto [u, v, w] = edges[i];\n\
    \            if (label[u] == -1) continue;\n            if (label[u] == label[v])\
    \ continue;\n            if (dist[u] + dist[v] + w < mini) {\n               \
    \ mini = dist[u] + dist[v] + w;\n                argmin = i;\n            }\n\
    \        }\n        if (argmin == -1) return {mini, {}, {}};\n\n        std::vector<int>\
    \ vs, es;\n        int a = edges[argmin].from, b = edges[argmin].to;\n       \
    \ while (a != r) {\n            int idx = prve[a];\n            vs.emplace_back(a);\n\
    \            es.emplace_back(idx);\n            a = edges[idx].from ^ edges[idx].to\
    \ ^ a;\n        }\n        vs.emplace_back(a);\n        std::reverse(vs.begin(),\
    \ vs.end());\n        std::reverse(es.begin(), es.end());\n        es.emplace_back(argmin);\n\
    \        while (b != r) {\n            int idx = prve[b];\n            vs.emplace_back(b);\n\
    \            es.emplace_back(idx);\n            b = edges[idx].from ^ edges[idx].to\
    \ ^ b;\n        }\n        return {mini, vs, es};\n    }\n\n  private:\n    constexpr\
    \ static T inf = std::numeric_limits<T>::max() / 2;\n    int n;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/UndirectedShortestCycle.hpp
  requiredBy: []
  timestamp: '2024-04-07 21:00:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1320.test.cpp
documentation_of: src/graph/UndirectedShortestCycle.hpp
layout: document
title: Undirected Shortest Cycle
---

## 概要

| メンバ関数                   | 効果                                                        | 時間計算量             |
| ---------------------------- | ----------------------------------------------------------- | ---------------------- |
| `UndirectedShortestCycle(n)` | $n$ 頂点 $0$ 辺のグラフとして初期化する．                   | $\mathrm{O}(n)$        |
| `add_edge(u, v, w)`          | 頂点 $u, v$ 間に重み $w$ の無向辺を追加する．               | $\mathrm{O}(1)$        |
| `solve(r)`                   | 頂点 $r$ を含む最小重みサイクルの周長，頂点列，辺列を返す． | $\mathrm{O}(m \log n)$ |


## 問題例
- [AtCoder Beginner Contest 308 Ex - Make Q](https://atcoder.jp/contests/abc308/tasks/abc308_h)
