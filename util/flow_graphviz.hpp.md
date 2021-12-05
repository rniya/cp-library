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
  bundledCode: "#line 2 \"util/flow_graphviz.hpp\"\n#include <fstream>\n#line 1 \"\
    atcoder/maxflow.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\n#line 1 \"atcoder/internal_queue.hpp\"\
    \n\n\n\n#line 5 \"atcoder/internal_queue.hpp\"\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\ntemplate <class T> struct simple_queue {\n    std::vector<T> payload;\n\
    \    int pos = 0;\n    void reserve(int n) { payload.reserve(n); }\n    int size()\
    \ const { return int(payload.size()) - pos; }\n    bool empty() const { return\
    \ pos == int(payload.size()); }\n    void push(const T& t) { payload.push_back(t);\
    \ }\n    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n}  // namespace internal\n\
    \n}  // namespace atcoder\n\n\n#line 11 \"atcoder/maxflow.hpp\"\n\nnamespace atcoder\
    \ {\n\ntemplate <class Cap> struct mf_graph {\n  public:\n    mf_graph() : _n(0)\
    \ {}\n    explicit mf_graph(int n) : _n(n), g(n) {}\n\n    int add_edge(int from,\
    \ int to, Cap cap) {\n        assert(0 <= from && from < _n);\n        assert(0\
    \ <= to && to < _n);\n        assert(0 <= cap);\n        int m = int(pos.size());\n\
    \        pos.push_back({from, int(g[from].size())});\n        int from_id = int(g[from].size());\n\
    \        int to_id = int(g[to].size());\n        if (from == to) to_id++;\n  \
    \      g[from].push_back(_edge{to, to_id, cap});\n        g[to].push_back(_edge{from,\
    \ from_id, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        int\
    \ m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n\n        std::vector<int> level(_n),\
    \ iter(_n);\n        internal::simple_queue<int> que;\n\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d =\n                    self(self, e.to, std::min(up - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == up) return res;\n            }\n  \
    \          level[v] = _n;\n            return res;\n        };\n\n        Cap\
    \ flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n       \
    \     if (level[t] == -1) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\
    \ break;\n            flow += f;\n        }\n        return flow;\n    }\n\n \
    \   std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(_n);\n\
    \        internal::simple_queue<int> que;\n        que.push(s);\n        while\
    \ (!que.empty()) {\n            int p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n            for (auto e : g[p]) {\n         \
    \       if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\n  private:\n    int _n;\n    struct _edge\
    \ {\n        int to, rev;\n        Cap cap;\n    };\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<std::vector<_edge>> g;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 1 \"atcoder/mincostflow.hpp\"\n\n\n\n#line 9 \"atcoder/mincostflow.hpp\"\
    \n\n#line 1 \"atcoder/internal_csr.hpp\"\n\n\n\n#line 5 \"atcoder/internal_csr.hpp\"\
    \n#include <utility>\n#line 7 \"atcoder/internal_csr.hpp\"\n\nnamespace atcoder\
    \ {\nnamespace internal {\n\ntemplate <class E> struct csr {\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    explicit csr(int n, const std::vector<std::pair<int,\
    \ E>>& edges)\n        : start(n + 1), elist(edges.size()) {\n        for (auto\
    \ e : edges) {\n            start[e.first + 1]++;\n        }\n        for (int\
    \ i = 1; i <= n; i++) {\n            start[i] += start[i - 1];\n        }\n  \
    \      auto counter = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n#line 12 \"atcoder/mincostflow.hpp\"\n\nnamespace atcoder {\n\n\
    template <class Cap, class Cost> struct mcf_graph {\n  public:\n    mcf_graph()\
    \ {}\n    explicit mcf_graph(int n) : _n(n) {}\n\n    int add_edge(int from, int\
    \ to, Cap cap, Cost cost) {\n        assert(0 <= from && from < _n);\n       \
    \ assert(0 <= to && to < _n);\n        assert(0 <= cap);\n        assert(0 <=\
    \ cost);\n        int m = int(_edges.size());\n        _edges.push_back({from,\
    \ to, cap, 0, cost});\n        return m;\n    }\n\n    struct edge {\n       \
    \ int from, to;\n        Cap cap, flow;\n        Cost cost;\n    };\n\n    edge\
    \ get_edge(int i) {\n        int m = int(_edges.size());\n        assert(0 <=\
    \ i && i < m);\n        return _edges[i];\n    }\n    std::vector<edge> edges()\
    \ { return _edges; }\n\n    std::pair<Cap, Cost> flow(int s, int t) {\n      \
    \  return flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    std::pair<Cap,\
    \ Cost> flow(int s, int t, Cap flow_limit) {\n        return slope(s, t, flow_limit).back();\n\
    \    }\n    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {\n        return\
    \ slope(s, t, std::numeric_limits<Cap>::max());\n    }\n    std::vector<std::pair<Cap,\
    \ Cost>> slope(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n\
    \        assert(0 <= t && t < _n);\n        assert(s != t);\n\n        int m =\
    \ int(_edges.size());\n        std::vector<int> edge_idx(m);\n\n        auto g\
    \ = [&]() {\n            std::vector<int> degree(_n), redge_idx(m);\n        \
    \    std::vector<std::pair<int, _edge>> elist;\n            elist.reserve(2 *\
    \ m);\n            for (int i = 0; i < m; i++) {\n                auto e = _edges[i];\n\
    \                edge_idx[i] = degree[e.from]++;\n                redge_idx[i]\
    \ = degree[e.to]++;\n                elist.push_back({e.from, {e.to, -1, e.cap\
    \ - e.flow, e.cost}});\n                elist.push_back({e.to, {e.from, -1, e.flow,\
    \ -e.cost}});\n            }\n            auto _g = internal::csr<_edge>(_n, elist);\n\
    \            for (int i = 0; i < m; i++) {\n                auto e = _edges[i];\n\
    \                edge_idx[i] += _g.start[e.from];\n                redge_idx[i]\
    \ += _g.start[e.to];\n                _g.elist[edge_idx[i]].rev = redge_idx[i];\n\
    \                _g.elist[redge_idx[i]].rev = edge_idx[i];\n            }\n  \
    \          return _g;\n        }();\n\n        auto result = slope(g, s, t, flow_limit);\n\
    \n        for (int i = 0; i < m; i++) {\n            auto e = g.elist[edge_idx[i]];\n\
    \            _edges[i].flow = _edges[i].cap - e.cap;\n        }\n\n        return\
    \ result;\n    }\n\n  private:\n    int _n;\n    std::vector<edge> _edges;\n\n\
    \    // inside edge\n    struct _edge {\n        int to, rev;\n        Cap cap;\n\
    \        Cost cost;\n    };\n\n    std::vector<std::pair<Cap, Cost>> slope(internal::csr<_edge>&\
    \ g,\n                                            int s,\n                   \
    \                         int t,\n                                           \
    \ Cap flow_limit) {\n        // variants (C = maxcost):\n        // -(n-1)C <=\
    \ dual[s] <= dual[i] <= dual[t] = 0\n        // reduced cost (= e.cost + dual[e.from]\
    \ - dual[e.to]) >= 0 for all edge\n\n        // dual_dist[i] = (dual[i], dist[i])\n\
    \        std::vector<std::pair<Cost, Cost>> dual_dist(_n);\n        std::vector<int>\
    \ prev_e(_n);\n        std::vector<bool> vis(_n);\n        struct Q {\n      \
    \      Cost key;\n            int to;\n            bool operator<(Q r) const {\
    \ return key > r.key; }\n        };\n        std::vector<int> que_min;\n     \
    \   std::vector<Q> que;\n        auto dual_ref = [&]() {\n            for (int\
    \ i = 0; i < _n; i++) {\n                dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \            }\n            std::fill(vis.begin(), vis.end(), false);\n      \
    \      que_min.clear();\n            que.clear();\n\n            // que[0..heap_r)\
    \ was heapified\n            size_t heap_r = 0;\n\n            dual_dist[s].second\
    \ = 0;\n            que_min.push_back(s);\n            while (!que_min.empty()\
    \ || !que.empty()) {\n                int v;\n                if (!que_min.empty())\
    \ {\n                    v = que_min.back();\n                    que_min.pop_back();\n\
    \                } else {\n                    while (heap_r < que.size()) {\n\
    \                        heap_r++;\n                        std::push_heap(que.begin(),\
    \ que.begin() + heap_r);\n                    }\n                    v = que.front().to;\n\
    \                    std::pop_heap(que.begin(), que.end());\n                \
    \    que.pop_back();\n                    heap_r--;\n                }\n     \
    \           if (vis[v]) continue;\n                vis[v] = true;\n          \
    \      if (v == t) break;\n                // dist[v] = shortest(s, v) + dual[s]\
    \ - dual[v]\n                // dist[v] >= 0 (all reduced cost are positive)\n\
    \                // dist[v] <= (n-1)C\n                Cost dual_v = dual_dist[v].first,\
    \ dist_v = dual_dist[v].second;\n                for (int i = g.start[v]; i <\
    \ g.start[v + 1]; i++) {\n                    auto e = g.elist[i];\n         \
    \           if (!e.cap) continue;\n                    // |-dual[e.to] + dual[v]|\
    \ <= (n-1)C\n                    // cost <= C - -(n-1)C + 0 = nC\n           \
    \         Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n             \
    \       if (dual_dist[e.to].second - dist_v > cost) {\n                      \
    \  Cost dist_to = dist_v + cost;\n                        dual_dist[e.to].second\
    \ = dist_to;\n                        prev_e[e.to] = e.rev;\n                \
    \        if (dist_to == dist_v) {\n                            que_min.push_back(e.to);\n\
    \                        } else {\n                            que.push_back(Q{dist_to,\
    \ e.to});\n                        }\n                    }\n                }\n\
    \            }\n            if (!vis[t]) {\n                return false;\n  \
    \          }\n\n            for (int v = 0; v < _n; v++) {\n                if\
    \ (!vis[v]) continue;\n                // dual[v] = dual[v] - dist[t] + dist[v]\n\
    \                //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n\
    \                //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,\n\
    \                //         t) + dual[t] + shortest(s, v) = shortest(s, v) -\n\
    \                //         shortest(s, t) >= 0 - (n-1)C\n                dual_dist[v].first\
    \ -= dual_dist[t].second - dual_dist[v].second;\n            }\n            return\
    \ true;\n        };\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n        std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \        while (flow < flow_limit) {\n            if (!dual_ref()) break;\n  \
    \          Cap c = flow_limit - flow;\n            for (int v = t; v != s; v =\
    \ g.elist[prev_e[v]].to) {\n                c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n\
    \            }\n            for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n                auto& e = g.elist[prev_e[v]];\n                e.cap += c;\n\
    \                g.elist[e.rev].cap -= c;\n            }\n            Cost d =\
    \ -dual_dist[s].first;\n            flow += c;\n            cost += c * d;\n \
    \           if (prev_cost_per_flow == d) {\n                result.pop_back();\n\
    \            }\n            result.push_back({flow, cost});\n            prev_cost_per_flow\
    \ = d;\n        }\n        return result;\n    }\n};\n\n}  // namespace atcoder\n\
    \n\n#line 5 \"util/flow_graphviz.hpp\"\n\nnamespace atcoder {\n\ntemplate <class\
    \ Cap> void dump_graphviz(mf_graph<Cap> graph, std::string filename = \"maxflow\"\
    ) {\n    std::ofstream ofs(filename + \".dot\");\n    ofs << \"digraph {\\n\"\
    ;\n    auto edges = graph.edges();\n    for (const auto& e : edges) {\n      \
    \  ofs << e.from << \" -> \" << e.to << \" [label = \\\"\" << e.flow << \"/\"\
    \ << e.cap << \"\\\", color = \"\n            << (e.flow == e.cap ? \"red\"\n\
    \                : e.flow > 0    ? \"blue\"\n                                :\
    \ \"black\")\n            << \"];\\n\";\n    }\n    ofs << \"}\\n\";\n    ofs.close();\n\
    \    return;\n}\n\ntemplate <class Cap, class Cost> void dump_graphviz(mcf_graph<Cap,\
    \ Cost> graph, std::string filename = \"mincostflow\") {\n    std::ofstream ofs(filename\
    \ + \".dot\");\n    ofs << \"digraph {\\n\";\n    auto edges = graph.edges();\n\
    \    for (const auto& e : edges) {\n        ofs << e.from << \" -> \" << e.to\
    \ << \" [label = \\\"\" << e.flow << \"/\" << e.cap << \"(\" << e.flow << \"*\"\
    \ << e.cost\n            << \")\"\n            << \"\\\", color = \"\n       \
    \     << (e.flow == e.cap ? \"red\"\n                : e.flow > 0    ? \"blue\"\
    \n                                : \"black\")\n            << \"];\\n\";\n  \
    \  }\n    ofs << \"}\\n\";\n    ofs.close();\n    return;\n}\n\n}  // namespace\
    \ atcoder\n"
  code: "#pragma once\n#include <fstream>\n#include \"atcoder/maxflow\"\n#include\
    \ \"atcoder/mincostflow\"\n\nnamespace atcoder {\n\ntemplate <class Cap> void\
    \ dump_graphviz(mf_graph<Cap> graph, std::string filename = \"maxflow\") {\n \
    \   std::ofstream ofs(filename + \".dot\");\n    ofs << \"digraph {\\n\";\n  \
    \  auto edges = graph.edges();\n    for (const auto& e : edges) {\n        ofs\
    \ << e.from << \" -> \" << e.to << \" [label = \\\"\" << e.flow << \"/\" << e.cap\
    \ << \"\\\", color = \"\n            << (e.flow == e.cap ? \"red\"\n         \
    \       : e.flow > 0    ? \"blue\"\n                                : \"black\"\
    )\n            << \"];\\n\";\n    }\n    ofs << \"}\\n\";\n    ofs.close();\n\
    \    return;\n}\n\ntemplate <class Cap, class Cost> void dump_graphviz(mcf_graph<Cap,\
    \ Cost> graph, std::string filename = \"mincostflow\") {\n    std::ofstream ofs(filename\
    \ + \".dot\");\n    ofs << \"digraph {\\n\";\n    auto edges = graph.edges();\n\
    \    for (const auto& e : edges) {\n        ofs << e.from << \" -> \" << e.to\
    \ << \" [label = \\\"\" << e.flow << \"/\" << e.cap << \"(\" << e.flow << \"*\"\
    \ << e.cost\n            << \")\"\n            << \"\\\", color = \"\n       \
    \     << (e.flow == e.cap ? \"red\"\n                : e.flow > 0    ? \"blue\"\
    \n                                : \"black\")\n            << \"];\\n\";\n  \
    \  }\n    ofs << \"}\\n\";\n    ofs.close();\n    return;\n}\n\n}  // namespace\
    \ atcoder\n"
  dependsOn: []
  isVerificationFile: false
  path: util/flow_graphviz.hpp
  requiredBy: []
  timestamp: '2021-12-05 15:22:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/flow_graphviz.hpp
layout: document
redirect_from:
- /library/util/flow_graphviz.hpp
- /library/util/flow_graphviz.hpp.html
title: util/flow_graphviz.hpp
---
