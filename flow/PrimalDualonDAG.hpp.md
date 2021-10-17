---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1678.test.cpp
    title: test/yukicoder/1678.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/PrimalDualonDAG.md
    document_title: Primal Dual on DAG (allow negative-cost edge)
    links: []
  bundledCode: "#line 2 \"flow/PrimalDualonDAG.hpp\"\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\ntemplate <typename Cap, typename\
    \ Cost> struct PrimalDualonDAG {\n    PrimalDualonDAG(int n) : n(n), G(n), h(n),\
    \ dist(n), prevv(n), preve(n), indeg(n, 0) {}\n\n    int add_edge(int from, int\
    \ to, Cap cap, Cost cost) {\n        assert(0 <= from && from < n);\n        assert(0\
    \ <= to && to < n);\n        assert(0 <= cap);\n        // assert(0 <= cost);\n\
    \        int m = pos.size(), from_id = G[from].size(), to_id = G[to].size();\n\
    \        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, cost, to_id);\n        G[to].emplace_back(from, 0, -cost, from_id);\n \
    \       if (cap > 0) indeg[to]++;\n        return m;\n    }\n\n    std::tuple<int,\
    \ int, Cap, Cap, Cost> get_edge(int i) {\n        assert(0 <= i && i < (int)pos.size());\n\
    \        auto e = G[pos[i].first][pos[i].second];\n        auto re = G[e.to][e.rev];\n\
    \        return {pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost};\n    }\n\
    \n    std::vector<std::tuple<int, int, Cap, Cap, Cost>> edges() {\n        std::vector<std::tuple<int,\
    \ int, Cap, Cap, Cost>> res;\n        for (size_t i = 0; i < pos.size(); i++)\
    \ res.emplace_back(get_edge(i));\n        return res;\n    }\n\n    Cost min_cost_flow(int\
    \ s, int t, Cap flow) {\n        auto res = slope(s, t, flow).back();\n      \
    \  return res.first == flow ? res.second : -1;\n    }\n\n    std::pair<Cap, Cost>\
    \ min_cost_max_flow(int s, int t) { return slope(s, t, std::numeric_limits<Cap>::max()).back();\
    \ }\n\n    std::vector<std::pair<Cap, Cost>> slope(int s, int t) { return slope(s,\
    \ t, std::numeric_limits<Cap>::max()); }\n\nprivate:\n    struct edge {\n    \
    \    int to;\n        Cap cap;\n        Cost cost;\n        int rev;\n       \
    \ edge(int to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev)\
    \ {}\n    };\n\n    const Cost inf = std::numeric_limits<Cost>::max();\n    int\
    \ n;\n    std::vector<std::vector<edge>> G;\n    std::vector<std::pair<int, int>>\
    \ pos;\n    std::vector<Cost> h, dist;\n    std::vector<int> prevv, preve, indeg,\
    \ order;\n\n    bool topological_sort() {\n        std::queue<int> que;\n    \
    \    for (int i = 0; i < n; i++) {\n            if (indeg[i] == 0) {\n       \
    \         que.emplace(i);\n            }\n        }\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            order.emplace_back(v);\n\
    \            for (const auto& e : G[v]) {\n                if (e.cap > 0 && --indeg[e.to]\
    \ == 0) {\n                    que.emplace(e.to);\n                }\n       \
    \     }\n        }\n\n        return *max_element(indeg.begin(), indeg.end())\
    \ == 0;\n    }\n\n    void calc_potential(int s) {\n        fill(h.begin(), h.end(),\
    \ inf);\n        h[s] = 0;\n        for (int& v : order) {\n            if (h[v]\
    \ == inf) continue;\n            for (const auto& e : G[v]) {\n              \
    \  if (e.cap > 0) {\n                    h[e.to] = std::min(h[e.to], h[v] + e.cost);\n\
    \                }\n            }\n        }\n    }\n\n    void dijkstra(int s)\
    \ {\n        struct P {\n            Cost c;\n            int v;\n           \
    \ P(Cost c, int v) : c(c), v(v) {}\n            bool operator<(const P& rhs) const\
    \ { return c > rhs.c; }\n        };\n        std::priority_queue<P> pq;\n    \
    \    fill(dist.begin(), dist.end(), inf);\n        dist[s] = 0;\n        pq.emplace(dist[s],\
    \ s);\n        while (!pq.empty()) {\n            auto p = pq.top();\n       \
    \     pq.pop();\n            int v = p.v;\n            if (dist[v] < p.c) continue;\n\
    \            for (size_t i = 0; i < G[v].size(); i++) {\n                auto&\
    \ e = G[v][i];\n                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost\
    \ + h[v] - h[e.to]) {\n                    dist[e.to] = dist[v] + e.cost + h[v]\
    \ - h[e.to];\n                    prevv[e.to] = v;\n                    preve[e.to]\
    \ = i;\n                    pq.emplace(dist[e.to], e.to);\n                }\n\
    \            }\n        }\n    }\n\n    std::vector<std::pair<Cap, Cost>> slope(int\
    \ s, int t, Cap flow_limit) {\n        assert(0 <= s && s < n);\n        assert(0\
    \ <= t && t < n);\n        assert(s != t);\n        assert(topological_sort());\n\
    \        calc_potential(s);\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_pre_flow\
    \ = -1;\n        std::vector<std::pair<Cap, Cost>> res;\n        res.emplace_back(flow,\
    \ cost);\n        while (flow < flow_limit) {\n            dijkstra(s);\n    \
    \        if (dist[t] == inf) break;\n            for (int v = 0; v < n; v++) h[v]\
    \ += dist[v];\n            Cap d = flow_limit - flow;\n            for (int v\
    \ = t; v != s; v = prevv[v]) d = std::min(d, G[prevv[v]][preve[v]].cap);\n   \
    \         for (int v = t; v != s; v = prevv[v]) {\n                auto& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n            flow += d;\n            cost += d * h[t];\n            if\
    \ (prev_cost_pre_flow == d) res.pop_back();\n            res.emplace_back(flow,\
    \ cost);\n            prev_cost_pre_flow = d;\n        }\n        return res;\n\
    \    }\n};\n\n/**\n * @brief Primal Dual on DAG (allow negative-cost edge)\n *\
    \ @docs docs/flow/PrimalDualonDAG.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\ntemplate <typename Cap, typename Cost> struct PrimalDualonDAG {\n\
    \    PrimalDualonDAG(int n) : n(n), G(n), h(n), dist(n), prevv(n), preve(n), indeg(n,\
    \ 0) {}\n\n    int add_edge(int from, int to, Cap cap, Cost cost) {\n        assert(0\
    \ <= from && from < n);\n        assert(0 <= to && to < n);\n        assert(0\
    \ <= cap);\n        // assert(0 <= cost);\n        int m = pos.size(), from_id\
    \ = G[from].size(), to_id = G[to].size();\n        pos.emplace_back(from, G[from].size());\n\
    \        G[from].emplace_back(to, cap, cost, to_id);\n        G[to].emplace_back(from,\
    \ 0, -cost, from_id);\n        if (cap > 0) indeg[to]++;\n        return m;\n\
    \    }\n\n    std::tuple<int, int, Cap, Cap, Cost> get_edge(int i) {\n       \
    \ assert(0 <= i && i < (int)pos.size());\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap, e.cost};\n    }\n\n    std::vector<std::tuple<int, int, Cap,\
    \ Cap, Cost>> edges() {\n        std::vector<std::tuple<int, int, Cap, Cap, Cost>>\
    \ res;\n        for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));\n\
    \        return res;\n    }\n\n    Cost min_cost_flow(int s, int t, Cap flow)\
    \ {\n        auto res = slope(s, t, flow).back();\n        return res.first ==\
    \ flow ? res.second : -1;\n    }\n\n    std::pair<Cap, Cost> min_cost_max_flow(int\
    \ s, int t) { return slope(s, t, std::numeric_limits<Cap>::max()).back(); }\n\n\
    \    std::vector<std::pair<Cap, Cost>> slope(int s, int t) { return slope(s, t,\
    \ std::numeric_limits<Cap>::max()); }\n\nprivate:\n    struct edge {\n       \
    \ int to;\n        Cap cap;\n        Cost cost;\n        int rev;\n        edge(int\
    \ to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}\n\
    \    };\n\n    const Cost inf = std::numeric_limits<Cost>::max();\n    int n;\n\
    \    std::vector<std::vector<edge>> G;\n    std::vector<std::pair<int, int>> pos;\n\
    \    std::vector<Cost> h, dist;\n    std::vector<int> prevv, preve, indeg, order;\n\
    \n    bool topological_sort() {\n        std::queue<int> que;\n        for (int\
    \ i = 0; i < n; i++) {\n            if (indeg[i] == 0) {\n                que.emplace(i);\n\
    \            }\n        }\n        while (!que.empty()) {\n            int v =\
    \ que.front();\n            que.pop();\n            order.emplace_back(v);\n \
    \           for (const auto& e : G[v]) {\n                if (e.cap > 0 && --indeg[e.to]\
    \ == 0) {\n                    que.emplace(e.to);\n                }\n       \
    \     }\n        }\n\n        return *max_element(indeg.begin(), indeg.end())\
    \ == 0;\n    }\n\n    void calc_potential(int s) {\n        fill(h.begin(), h.end(),\
    \ inf);\n        h[s] = 0;\n        for (int& v : order) {\n            if (h[v]\
    \ == inf) continue;\n            for (const auto& e : G[v]) {\n              \
    \  if (e.cap > 0) {\n                    h[e.to] = std::min(h[e.to], h[v] + e.cost);\n\
    \                }\n            }\n        }\n    }\n\n    void dijkstra(int s)\
    \ {\n        struct P {\n            Cost c;\n            int v;\n           \
    \ P(Cost c, int v) : c(c), v(v) {}\n            bool operator<(const P& rhs) const\
    \ { return c > rhs.c; }\n        };\n        std::priority_queue<P> pq;\n    \
    \    fill(dist.begin(), dist.end(), inf);\n        dist[s] = 0;\n        pq.emplace(dist[s],\
    \ s);\n        while (!pq.empty()) {\n            auto p = pq.top();\n       \
    \     pq.pop();\n            int v = p.v;\n            if (dist[v] < p.c) continue;\n\
    \            for (size_t i = 0; i < G[v].size(); i++) {\n                auto&\
    \ e = G[v][i];\n                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost\
    \ + h[v] - h[e.to]) {\n                    dist[e.to] = dist[v] + e.cost + h[v]\
    \ - h[e.to];\n                    prevv[e.to] = v;\n                    preve[e.to]\
    \ = i;\n                    pq.emplace(dist[e.to], e.to);\n                }\n\
    \            }\n        }\n    }\n\n    std::vector<std::pair<Cap, Cost>> slope(int\
    \ s, int t, Cap flow_limit) {\n        assert(0 <= s && s < n);\n        assert(0\
    \ <= t && t < n);\n        assert(s != t);\n        assert(topological_sort());\n\
    \        calc_potential(s);\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_pre_flow\
    \ = -1;\n        std::vector<std::pair<Cap, Cost>> res;\n        res.emplace_back(flow,\
    \ cost);\n        while (flow < flow_limit) {\n            dijkstra(s);\n    \
    \        if (dist[t] == inf) break;\n            for (int v = 0; v < n; v++) h[v]\
    \ += dist[v];\n            Cap d = flow_limit - flow;\n            for (int v\
    \ = t; v != s; v = prevv[v]) d = std::min(d, G[prevv[v]][preve[v]].cap);\n   \
    \         for (int v = t; v != s; v = prevv[v]) {\n                auto& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n            flow += d;\n            cost += d * h[t];\n            if\
    \ (prev_cost_pre_flow == d) res.pop_back();\n            res.emplace_back(flow,\
    \ cost);\n            prev_cost_pre_flow = d;\n        }\n        return res;\n\
    \    }\n};\n\n/**\n * @brief Primal Dual on DAG (allow negative-cost edge)\n *\
    \ @docs docs/flow/PrimalDualonDAG.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/PrimalDualonDAG.hpp
  requiredBy: []
  timestamp: '2021-10-17 17:14:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1678.test.cpp
documentation_of: flow/PrimalDualonDAG.hpp
layout: document
redirect_from:
- /library/flow/PrimalDualonDAG.hpp
- /library/flow/PrimalDualonDAG.hpp.html
title: Primal Dual on DAG (allow negative-cost edge)
---
## 概要
負辺を含む最小費用流を計算する際に, 各頂点のポテンシャルの初期値さえ計算できれば後は Dijkstra 法で問題ない. このポテンシャルの初期値の計算について, 負辺があったとしても Bellman-Ford 法を用いれば負閉路がない限りは $O(nm)$ で問題なく計算できる. ここで, 最小費用流において負辺が登場するのはグラフが特殊な形状, 特に DAG であるケースが多く, この場合はさらに高速に $O(n + m)$ で前計算が可能となる.

## 問題例
- [AtCoder Beginner Contest 214 H - Collecting](https://atcoder.jp/contests/abc214/tasks/abc214_h)

## Links
- [負辺を含む最小費用流について(Attack the Moles) - sigma425のブログ](https://sigma425.hatenablog.com/entry/2014/10/12/122018?utm_source=pocket_mylist)
