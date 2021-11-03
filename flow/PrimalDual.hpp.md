---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.PrimalDual.test.cpp
    title: test/aoj/GRL_6_B.PrimalDual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1288.test.cpp
    title: test/yukicoder/1288.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1301.test.cpp
    title: test/yukicoder/1301.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/PrimalDual.md
    document_title: Primal Dual (Minimum-cost flow)
    links: []
  bundledCode: "#line 2 \"flow/PrimalDual.hpp\"\n#include <cassert>\n#include <fstream>\n\
    #include <limits>\n#include <queue>\n#include <tuple>\n#include <vector>\n\ntemplate\
    \ <typename Cap, typename Cost> struct PrimalDual {\n    PrimalDual(int n) : n(n),\
    \ G(n), h(n), dist(n), prevv(n), preve(n) {}\n\n    int add_edge(int from, int\
    \ to, Cap cap, Cost cost) {\n        assert(0 <= from && from < n);\n        assert(0\
    \ <= to && to < n);\n        assert(0 <= cap);\n        assert(0 <= cost);\n \
    \       int m = pos.size(), from_id = G[from].size(), to_id = G[to].size();\n\
    \        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, cost, to_id);\n        G[to].emplace_back(from, 0, -cost, from_id);\n \
    \       return m;\n    }\n\n    std::tuple<int, int, Cap, Cap, Cost> get_edge(int\
    \ i) {\n        assert(0 <= i && i < (int)pos.size());\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap, e.cost};\n    }\n\n    std::vector<std::tuple<int, int, Cap,\
    \ Cap, Cost>> edges() {\n        std::vector<std::tuple<int, int, Cap, Cap, Cost>>\
    \ res;\n        for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));\n\
    \        return res;\n    }\n\n    Cost min_cost_flow(int s, int t, Cap flow)\
    \ {\n        auto res = slope(s, t, flow).back();\n        return res.first ==\
    \ flow ? res.second : -1;\n    }\n\n    std::pair<Cap, Cost> min_cost_max_flow(int\
    \ s, int t) { return slope(s, t, std::numeric_limits<Cap>::max()).back(); }\n\n\
    \    std::vector<std::pair<Cap, Cost>> slope(int s, int t) { return slope(s, t,\
    \ std::numeric_limits<Cap>::max()); }\n\n    void dump_graphviz(std::string filename\
    \ = \"mincostflow\") {\n        std::ofstream ofs(filename + \".dot\");\n    \
    \    ofs << \"digraph {\\n\";\n        auto es = edges();\n        for (const\
    \ auto& e : es) {\n            int from, to;\n            Cap cap, flow;\n   \
    \         Cost cost;\n            std::tie(from, to, cap, flow, cost) = e;\n \
    \           ofs << from << \" -> \" << to << \" [label = \\\"\" << flow << \"\
    /\" << cap << \"(\" << flow << \"*\" << cost << \")\"\n                << \"\\\
    \", color = \"\n                << (flow == cap ? \"red\"\n                  \
    \  : flow > 0  ? \"blue\"\n                                : \"black\")\n    \
    \            << \"];\\n\";\n        }\n        ofs << \"}\\n\";\n        ofs.close();\n\
    \        return;\n    }\n\nprivate:\n    struct edge {\n        int to;\n    \
    \    Cap cap;\n        Cost cost;\n        int rev;\n        edge(int to, Cap\
    \ cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}\n    };\n\
    \n    const Cost inf = std::numeric_limits<Cost>::max();\n    int n;\n    std::vector<std::vector<edge>>\
    \ G;\n    std::vector<std::pair<int, int>> pos;\n    std::vector<Cost> h, dist;\n\
    \    std::vector<int> prevv, preve;\n\n    void dijkstra(int s) {\n        struct\
    \ P {\n            Cost c;\n            int v;\n            P(Cost c, int v) :\
    \ c(c), v(v) {}\n            bool operator<(const P& rhs) const { return c > rhs.c;\
    \ }\n        };\n        std::priority_queue<P> pq;\n        fill(dist.begin(),\
    \ dist.end(), inf);\n        dist[s] = 0;\n        pq.emplace(dist[s], s);\n \
    \       while (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n\
    \            int v = p.v;\n            if (dist[v] < p.c) continue;\n        \
    \    for (size_t i = 0; i < G[v].size(); i++) {\n                auto& e = G[v][i];\n\
    \                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])\
    \ {\n                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n   \
    \                 prevv[e.to] = v;\n                    preve[e.to] = i;\n   \
    \                 pq.emplace(dist[e.to], e.to);\n                }\n         \
    \   }\n        }\n    }\n\n    std::vector<std::pair<Cap, Cost>> slope(int s,\
    \ int t, Cap flow_limit) {\n        assert(0 <= s && s < n);\n        assert(0\
    \ <= t && t < n);\n        assert(s != t);\n        Cap flow = 0;\n        Cost\
    \ cost = 0, prev_cost_pre_flow = -1;\n        std::vector<std::pair<Cap, Cost>>\
    \ res;\n        res.emplace_back(flow, cost);\n        while (flow < flow_limit)\
    \ {\n            dijkstra(s);\n            if (dist[t] == inf) break;\n      \
    \      for (int v = 0; v < n; v++) h[v] += dist[v];\n            Cap d = flow_limit\
    \ - flow;\n            for (int v = t; v != s; v = prevv[v]) d = std::min(d, G[prevv[v]][preve[v]].cap);\n\
    \            for (int v = t; v != s; v = prevv[v]) {\n                auto& e\
    \ = G[prevv[v]][preve[v]];\n                e.cap -= d;\n                G[v][e.rev].cap\
    \ += d;\n            }\n            flow += d;\n            cost += d * h[t];\n\
    \            if (prev_cost_pre_flow == d) res.pop_back();\n            res.emplace_back(flow,\
    \ cost);\n            prev_cost_pre_flow = d;\n        }\n        return res;\n\
    \    }\n};\n\n/**\n * @brief Primal Dual (Minimum-cost flow)\n * @docs docs/flow/PrimalDual.md\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <fstream>\n#include <limits>\n\
    #include <queue>\n#include <tuple>\n#include <vector>\n\ntemplate <typename Cap,\
    \ typename Cost> struct PrimalDual {\n    PrimalDual(int n) : n(n), G(n), h(n),\
    \ dist(n), prevv(n), preve(n) {}\n\n    int add_edge(int from, int to, Cap cap,\
    \ Cost cost) {\n        assert(0 <= from && from < n);\n        assert(0 <= to\
    \ && to < n);\n        assert(0 <= cap);\n        assert(0 <= cost);\n       \
    \ int m = pos.size(), from_id = G[from].size(), to_id = G[to].size();\n      \
    \  pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to, cap,\
    \ cost, to_id);\n        G[to].emplace_back(from, 0, -cost, from_id);\n      \
    \  return m;\n    }\n\n    std::tuple<int, int, Cap, Cap, Cost> get_edge(int i)\
    \ {\n        assert(0 <= i && i < (int)pos.size());\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap, e.cost};\n    }\n\n    std::vector<std::tuple<int, int, Cap,\
    \ Cap, Cost>> edges() {\n        std::vector<std::tuple<int, int, Cap, Cap, Cost>>\
    \ res;\n        for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));\n\
    \        return res;\n    }\n\n    Cost min_cost_flow(int s, int t, Cap flow)\
    \ {\n        auto res = slope(s, t, flow).back();\n        return res.first ==\
    \ flow ? res.second : -1;\n    }\n\n    std::pair<Cap, Cost> min_cost_max_flow(int\
    \ s, int t) { return slope(s, t, std::numeric_limits<Cap>::max()).back(); }\n\n\
    \    std::vector<std::pair<Cap, Cost>> slope(int s, int t) { return slope(s, t,\
    \ std::numeric_limits<Cap>::max()); }\n\n    void dump_graphviz(std::string filename\
    \ = \"mincostflow\") {\n        std::ofstream ofs(filename + \".dot\");\n    \
    \    ofs << \"digraph {\\n\";\n        auto es = edges();\n        for (const\
    \ auto& e : es) {\n            int from, to;\n            Cap cap, flow;\n   \
    \         Cost cost;\n            std::tie(from, to, cap, flow, cost) = e;\n \
    \           ofs << from << \" -> \" << to << \" [label = \\\"\" << flow << \"\
    /\" << cap << \"(\" << flow << \"*\" << cost << \")\"\n                << \"\\\
    \", color = \"\n                << (flow == cap ? \"red\"\n                  \
    \  : flow > 0  ? \"blue\"\n                                : \"black\")\n    \
    \            << \"];\\n\";\n        }\n        ofs << \"}\\n\";\n        ofs.close();\n\
    \        return;\n    }\n\nprivate:\n    struct edge {\n        int to;\n    \
    \    Cap cap;\n        Cost cost;\n        int rev;\n        edge(int to, Cap\
    \ cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}\n    };\n\
    \n    const Cost inf = std::numeric_limits<Cost>::max();\n    int n;\n    std::vector<std::vector<edge>>\
    \ G;\n    std::vector<std::pair<int, int>> pos;\n    std::vector<Cost> h, dist;\n\
    \    std::vector<int> prevv, preve;\n\n    void dijkstra(int s) {\n        struct\
    \ P {\n            Cost c;\n            int v;\n            P(Cost c, int v) :\
    \ c(c), v(v) {}\n            bool operator<(const P& rhs) const { return c > rhs.c;\
    \ }\n        };\n        std::priority_queue<P> pq;\n        fill(dist.begin(),\
    \ dist.end(), inf);\n        dist[s] = 0;\n        pq.emplace(dist[s], s);\n \
    \       while (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n\
    \            int v = p.v;\n            if (dist[v] < p.c) continue;\n        \
    \    for (size_t i = 0; i < G[v].size(); i++) {\n                auto& e = G[v][i];\n\
    \                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])\
    \ {\n                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n   \
    \                 prevv[e.to] = v;\n                    preve[e.to] = i;\n   \
    \                 pq.emplace(dist[e.to], e.to);\n                }\n         \
    \   }\n        }\n    }\n\n    std::vector<std::pair<Cap, Cost>> slope(int s,\
    \ int t, Cap flow_limit) {\n        assert(0 <= s && s < n);\n        assert(0\
    \ <= t && t < n);\n        assert(s != t);\n        Cap flow = 0;\n        Cost\
    \ cost = 0, prev_cost_pre_flow = -1;\n        std::vector<std::pair<Cap, Cost>>\
    \ res;\n        res.emplace_back(flow, cost);\n        while (flow < flow_limit)\
    \ {\n            dijkstra(s);\n            if (dist[t] == inf) break;\n      \
    \      for (int v = 0; v < n; v++) h[v] += dist[v];\n            Cap d = flow_limit\
    \ - flow;\n            for (int v = t; v != s; v = prevv[v]) d = std::min(d, G[prevv[v]][preve[v]].cap);\n\
    \            for (int v = t; v != s; v = prevv[v]) {\n                auto& e\
    \ = G[prevv[v]][preve[v]];\n                e.cap -= d;\n                G[v][e.rev].cap\
    \ += d;\n            }\n            flow += d;\n            cost += d * h[t];\n\
    \            if (prev_cost_pre_flow == d) res.pop_back();\n            res.emplace_back(flow,\
    \ cost);\n            prev_cost_pre_flow = d;\n        }\n        return res;\n\
    \    }\n};\n\n/**\n * @brief Primal Dual (Minimum-cost flow)\n * @docs docs/flow/PrimalDual.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/PrimalDual.hpp
  requiredBy: []
  timestamp: '2021-10-21 16:13:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1288.test.cpp
  - test/yukicoder/1301.test.cpp
  - test/aoj/GRL_6_B.PrimalDual.test.cpp
documentation_of: flow/PrimalDual.hpp
layout: document
redirect_from:
- /library/flow/PrimalDual.hpp
- /library/flow/PrimalDual.hpp.html
title: Primal Dual (Minimum-cost flow)
---
## 概要
最小費用流を計算する.

| メンバ関数                      | 効果                                                                                                                                                                                                                                               | 時間計算量         |
| ------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------ |
| `PrimalDual(n)`                 | $n$ 頂点 0 辺のグラフとして初期化する.                                                                                                                                                                                                             | $O(n)$             |
| `add_edge(from, to, cap, cost)` | $from$ から $to$ へ容量 $cap$, コスト $cost$ の辺を追加する.                                                                                                                                                                                       | $O(1)$             |
| `get_edge(i)`                   | $i$ 番目に追加された辺の始点, 終点, 容量, 実際に流れている量をまとめて返す.                                                                                                                                                                        | $O(1)$             |
| `edges()`                       | `get_edge` で返されるデータをすべての辺について配列にして返す.                                                                                                                                                                                     | $O(m)$             |
| `min_cost_flow(s, t, flow)`     | 頂点 $s$ から 頂点 $t$ へ流量 $flow$ を流す際の最小費用を求める.                                                                                                                                                                                   | $O(fm \log n)$     |
| `min_cost_max_flow(s, t)`       | 頂点 $s$ から 頂点 $t$ へ可能な最大流量を流す際の最小費用を求める.                                                                                                                                                                                 | $O(\max fm\log n)$ |
| `slope(s, t)`                   | 頂点 $s$ から 頂点 $t$ へ流す際の流量とそのときの最小費用との関係を求める. 流量とそのときの最小費用を二次元平面上にプロットすると, これは関数が返す点を直線で結んだ形となるので, これによって任意の流量に対する最小費用を復元することが可能となる. | $O(\max fm\log n)$ |
| `dump_graphviz()`               | グラフを `.dot` 形式で出力する. 容量丁度の流量が流れる辺は赤色, そうでなく正の流量が流れる辺は青, 全く流れない辺は黒で出力される.                                                                                                                  | $O(m)$             |

## 双対
