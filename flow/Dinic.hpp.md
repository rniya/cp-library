---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/ProjectSelectionProblem.hpp
    title: Project Selection Problem
  - icon: ':warning:'
    path: test/atcoder/arc085_c.cpp
    title: test/atcoder/arc085_c.cpp
  - icon: ':warning:'
    path: test/codeforces/1404_E.cpp
    title: test/codeforces/1404_E.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.test.cpp
    title: test/aoj/2313.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.DInic.test.cpp
    title: test/aoj/GRL_6_A.DInic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/Dinic.md
    document_title: Dinic
    links: []
  bundledCode: "#line 2 \"flow/Dinic.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\ntemplate <typename Cap, bool directed>\
    \ struct Dinic {\n    Dinic(int n) : n(n), G(n), level(n), iter(n) {}\n\n    int\
    \ add_edge(int from, int to, Cap cap) {\n        assert(0 <= from && from < n);\n\
    \        assert(0 <= to && to < n);\n        assert(0 <= cap);\n        assert(from\
    \ != to);\n        int m = pos.size(), from_id = G[from].size(), to_id = G[to].size();\n\
    \        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, to_id);\n        G[to].emplace_back(from, directed ? 0 : cap, from_id);\n\
    \        return m;\n    }\n\n    int add_vertex() {\n        G.emplace_back();\n\
    \        level.emplace_back();\n        iter.emplace_back();\n        return n++;\n\
    \    }\n\n    std::tuple<int, int, Cap, Cap> get_edge(int i) {\n        assert(0\
    \ <= i && i < (int)pos.size());\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap};\n    }\n\n    std::vector<std::tuple<int, int, Cap, Cap>>\
    \ edges() {\n        std::vector<std::tuple<int, int, Cap, Cap>> res;\n      \
    \  for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));\n  \
    \  }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow) {\n        assert(0\
    \ <= i && i < (int)pos.size());\n        assert(0 <= new_flow && new_flow <= new_cap);\n\
    \        auto& e = G[pos[i].first][pos[i].second];\n        auto& re = G[e.to][e.rev];\n\
    \        e.cap = new_cap - new_flow;\n        re.cap = (directed ? new_flow :\
    \ new_cap + new_flow);\n    }\n\n    Cap max_flow(int s, int t) { return max_flow(s,\
    \ t, std::numeric_limits<Cap>::max()); }\n\n    Cap max_flow(int s, int t, Cap\
    \ flow_limit) {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t\
    \ < n);\n        if (s == t) return 0;\n        Cap flow = 0;\n        while (flow\
    \ < flow_limit) {\n            bfs(s, t);\n            if (level[t] < 0) break;\n\
    \            std::fill(iter.begin(), iter.end(), 0);\n            while (flow\
    \ < flow_limit) {\n                Cap f = dfs(s, t, flow_limit - flow);\n   \
    \             if (f == 0) break;\n                flow += f;\n            }\n\
    \        }\n        return flow;\n    }\n\n    std::vector<bool> min_cut(int s)\
    \ {\n        assert(0 <= s && s < n);\n        std::vector<bool> visited(n);\n\
    \        std::queue<int> que;\n        visited[s] = true;\n        que.emplace(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (const auto& e : G[v]) {\n                if (e.cap\
    \ && !visited[e.to]) {\n                    visited[e.to] = true;\n          \
    \          que.emplace(e.to);\n                }\n            }\n        }\n \
    \       return visited;\n    }\n\nprivate:\n    struct edge {\n        int to;\n\
    \        Cap cap;\n        int rev;\n        edge(int to, Cap cap, int rev) :\
    \ to(to), cap(cap), rev(rev) {}\n    };\n\n    int n;\n    std::vector<std::vector<edge>>\
    \ G;\n    std::vector<std::pair<int, int>> pos;\n    std::vector<int> level, iter;\n\
    \n    void bfs(int s, int t) {\n        std::fill(level.begin(), level.end(),\
    \ -1);\n        std::queue<int> que;\n        level[s] = 0;\n        que.emplace(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (const auto& e : G[v]) {\n                if (e.cap\
    \ > 0 && level[e.to] < 0) {\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.emplace(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    Cap dfs(int v, int\
    \ t, Cap f) {\n        if (v == t) return f;\n        for (int& i = iter[v]; i\
    \ < (int)G[v].size(); i++) {\n            auto& e = G[v][i];\n            if (e.cap\
    \ <= 0 || level[v] >= level[e.to]) continue;\n            Cap d = dfs(e.to, t,\
    \ min(f, e.cap));\n            if (d <= 0) continue;\n            e.cap -= d;\n\
    \            G[e.to][e.rev].cap += d;\n            return d;\n        }\n    \
    \    return 0;\n    }\n};\n\n/**\n * @brief Dinic\n * @docs docs/flow/Dinic.md\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\ntemplate <typename Cap, bool directed> struct Dinic {\n    Dinic(int\
    \ n) : n(n), G(n), level(n), iter(n) {}\n\n    int add_edge(int from, int to,\
    \ Cap cap) {\n        assert(0 <= from && from < n);\n        assert(0 <= to &&\
    \ to < n);\n        assert(0 <= cap);\n        assert(from != to);\n        int\
    \ m = pos.size(), from_id = G[from].size(), to_id = G[to].size();\n        pos.emplace_back(from,\
    \ G[from].size());\n        G[from].emplace_back(to, cap, to_id);\n        G[to].emplace_back(from,\
    \ directed ? 0 : cap, from_id);\n        return m;\n    }\n\n    int add_vertex()\
    \ {\n        G.emplace_back();\n        level.emplace_back();\n        iter.emplace_back();\n\
    \        return n++;\n    }\n\n    std::tuple<int, int, Cap, Cap> get_edge(int\
    \ i) {\n        assert(0 <= i && i < (int)pos.size());\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap};\n    }\n\n    std::vector<std::tuple<int, int, Cap, Cap>>\
    \ edges() {\n        std::vector<std::tuple<int, int, Cap, Cap>> res;\n      \
    \  for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));\n  \
    \  }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow) {\n        assert(0\
    \ <= i && i < (int)pos.size());\n        assert(0 <= new_flow && new_flow <= new_cap);\n\
    \        auto& e = G[pos[i].first][pos[i].second];\n        auto& re = G[e.to][e.rev];\n\
    \        e.cap = new_cap - new_flow;\n        re.cap = (directed ? new_flow :\
    \ new_cap + new_flow);\n    }\n\n    Cap max_flow(int s, int t) { return max_flow(s,\
    \ t, std::numeric_limits<Cap>::max()); }\n\n    Cap max_flow(int s, int t, Cap\
    \ flow_limit) {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t\
    \ < n);\n        if (s == t) return 0;\n        Cap flow = 0;\n        while (flow\
    \ < flow_limit) {\n            bfs(s, t);\n            if (level[t] < 0) break;\n\
    \            std::fill(iter.begin(), iter.end(), 0);\n            while (flow\
    \ < flow_limit) {\n                Cap f = dfs(s, t, flow_limit - flow);\n   \
    \             if (f == 0) break;\n                flow += f;\n            }\n\
    \        }\n        return flow;\n    }\n\n    std::vector<bool> min_cut(int s)\
    \ {\n        assert(0 <= s && s < n);\n        std::vector<bool> visited(n);\n\
    \        std::queue<int> que;\n        visited[s] = true;\n        que.emplace(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (const auto& e : G[v]) {\n                if (e.cap\
    \ && !visited[e.to]) {\n                    visited[e.to] = true;\n          \
    \          que.emplace(e.to);\n                }\n            }\n        }\n \
    \       return visited;\n    }\n\nprivate:\n    struct edge {\n        int to;\n\
    \        Cap cap;\n        int rev;\n        edge(int to, Cap cap, int rev) :\
    \ to(to), cap(cap), rev(rev) {}\n    };\n\n    int n;\n    std::vector<std::vector<edge>>\
    \ G;\n    std::vector<std::pair<int, int>> pos;\n    std::vector<int> level, iter;\n\
    \n    void bfs(int s, int t) {\n        std::fill(level.begin(), level.end(),\
    \ -1);\n        std::queue<int> que;\n        level[s] = 0;\n        que.emplace(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (const auto& e : G[v]) {\n                if (e.cap\
    \ > 0 && level[e.to] < 0) {\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.emplace(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    Cap dfs(int v, int\
    \ t, Cap f) {\n        if (v == t) return f;\n        for (int& i = iter[v]; i\
    \ < (int)G[v].size(); i++) {\n            auto& e = G[v][i];\n            if (e.cap\
    \ <= 0 || level[v] >= level[e.to]) continue;\n            Cap d = dfs(e.to, t,\
    \ min(f, e.cap));\n            if (d <= 0) continue;\n            e.cap -= d;\n\
    \            G[e.to][e.rev].cap += d;\n            return d;\n        }\n    \
    \    return 0;\n    }\n};\n\n/**\n * @brief Dinic\n * @docs docs/flow/Dinic.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: flow/Dinic.hpp
  requiredBy:
  - flow/ProjectSelectionProblem.hpp
  - test/atcoder/arc085_c.cpp
  - test/codeforces/1404_E.cpp
  timestamp: '2021-09-21 22:57:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.DInic.test.cpp
  - test/aoj/2903.test.cpp
  - test/aoj/2313.test.cpp
documentation_of: flow/Dinic.hpp
layout: document
redirect_from:
- /library/flow/Dinic.hpp
- /library/flow/Dinic.hpp.html
title: Dinic
---
## 概要
最大流を計算する.

| メンバ関数                          | 効果                                                                                                                                                 | 時間計算量 |
| ----------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| `Dinic(n)`                          | $n$ 頂点 0 辺のグラフとして初期化する.                                                                                                               | $O(n)$     |
| `add_edge(from, to, cap)`           | $from$ から $to$ へ容量 $cap$ の辺を追加する.                                                                                                        | $O(1)$     |
| `add_vertex()`                      | 頂点を 1 つ追加する.                                                                                                                                 | $O(1)$     |
| `get_edge(i)`                       | $i$ 番目に追加された辺の始点, 終点, 容量, 実際に流れている量をまとめて返す.                                                                          | $O(1)$     |
| `edges()`                           | `get_edge` で返されるデータをすべての辺について配列にして返す.                                                                                       | $O(m)$     |
| `change_edge(i, new_cap, new_flow)` | $i$ 番目に追加された辺の容量を $new_cap$ に, 流れている量を $new_flow$ に変更する.                                                                   | $O(1)$     |
| `max_flow(s, t)`                    | $s$ から $t$ へ流れる最大流を求める.                                                                                                                 | $O(n^2m)$  |
| `min_cut(s)`                        | $s$ から到達できる頂点群を返す. 頂点の全体集合を $V$ , この関数が返す頂点集合を $S$ とすると, $S$ と $V \setminus S$ を結ぶ辺が最小カットに相等する. | $O(n + m)$ |

`max_flow` の計算量はケースごとにかなり異なり, 一般的には上記の計算量より高速に動作することが多い. 詳しくは Links にもある[Dinic 法とその時間計算量 - みさわめも](https://misawa.github.io/others/flow/dinic_time_complexity.html)を参照.

## Links
[Dinic 法の速さ - れんしゅうちょう.  - TopCoder部](https://topcoder-g-hatena-ne-jp.jag-icpc.org/Mi_Sawa/20140311/1394730337.html)
[Dinic 法とその時間計算量 - みさわめも](https://misawa.github.io/others/flow/dinic_time_complexity.html)