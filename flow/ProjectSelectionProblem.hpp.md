---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: flow/Dinic.hpp
    title: Dinic (Maximum flow)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/flow/ProjectSelectionPorblem.md
    document_title: Project Selection Problem
    links: []
  bundledCode: "#line 2 \"flow/ProjectSelectionProblem.hpp\"\n#include <limits>\n\
    #line 2 \"flow/Dinic.hpp\"\n#include <cassert>\n#line 4 \"flow/Dinic.hpp\"\n#include\
    \ <queue>\n#include <vector>\n\ntemplate <typename Cap, bool directed> struct\
    \ Dinic {\n    Dinic(int n) : n(n), G(n), level(n), iter(n) {}\n\n    int add_edge(int\
    \ from, int to, Cap cap) {\n        assert(0 <= from && from < n);\n        assert(0\
    \ <= to && to < n);\n        assert(0 <= cap);\n        assert(from != to);\n\
    \        int m = pos.size(), from_id = G[from].size(), to_id = G[to].size();\n\
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
    \      return res;\n    }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        assert(0 <= i && i < (int)pos.size());\n        assert(0 <= new_flow\
    \ && new_flow <= new_cap);\n        auto& e = G[pos[i].first][pos[i].second];\n\
    \        auto& re = G[e.to][e.rev];\n        e.cap = new_cap - new_flow;\n   \
    \     re.cap = (directed ? new_flow : new_cap + new_flow);\n    }\n\n    Cap max_flow(int\
    \ s, int t) { return max_flow(s, t, std::numeric_limits<Cap>::max()); }\n\n  \
    \  Cap max_flow(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s <\
    \ n);\n        assert(0 <= t && t < n);\n        if (s == t) return 0;\n     \
    \   Cap flow = 0;\n        while (flow < flow_limit) {\n            bfs(s, t);\n\
    \            if (level[t] < 0) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            while (flow < flow_limit) {\n                Cap f = dfs(s,\
    \ t, flow_limit - flow);\n                if (f == 0) break;\n               \
    \ flow += f;\n            }\n        }\n        return flow;\n    }\n\n    std::vector<bool>\
    \ min_cut(int s) {\n        assert(0 <= s && s < n);\n        std::vector<bool>\
    \ visited(n);\n        std::queue<int> que;\n        visited[s] = true;\n    \
    \    que.emplace(s);\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            for (const auto& e : G[v]) {\n          \
    \      if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.emplace(e.to);\n                }\n            }\n  \
    \      }\n        return visited;\n    }\n\nprivate:\n    struct edge {\n    \
    \    int to;\n        Cap cap;\n        int rev;\n        edge(int to, Cap cap,\
    \ int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\n    int n;\n    std::vector<std::vector<edge>>\
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
    \    return 0;\n    }\n};\n\n/**\n * @brief Dinic (Maximum flow)\n * @docs docs/flow/Dinic.md\n\
    \ */\n#line 4 \"flow/ProjectSelectionProblem.hpp\"\n\ntemplate <typename T> struct\
    \ ProjectSelectionProblem {\n    ProjectSelectionProblem(int n) : n(n), s(n),\
    \ t(n + 1), dinic(n + 2) {}\n\n    void x_false_loss(int x, T z) {\n        assert(0\
    \ <= x and x < n);\n        dinic.add_edge(x, t, z);\n    }\n\n    void x_false_profit(int\
    \ x, T z) {\n        assert(0 <= x and x < n);\n        sum += z;\n        x_true_loss(x,\
    \ z);\n    }\n\n    void x_true_loss(int x, T z) {\n        assert(0 <= x and\
    \ x < n);\n        dinic.add_edge(s, x, z);\n    }\n\n    void x_true_profit(int\
    \ x, T z) {\n        assert(0 <= x and x < n);\n        sum += z;\n        x_false_loss(x,\
    \ z);\n    }\n\n    void x_false_y_true_loss(int x, int y, T z) {\n        assert(0\
    \ <= x and x < n);\n        assert(0 <= y and y < n);\n        dinic.add_edge(x,\
    \ y, z);\n    }\n\n    void x_true_y_false_loss(int x, int y, T z) {\n       \
    \ assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n        dinic.add_edge(y,\
    \ x, z);\n        int w = dinic.add_vertex();\n        x_false_loss(w, z);\n \
    \       x_true_y_false_loss(w, x, inf);\n        x_true_y_false_loss(w, y, inf);\n\
    \    }\n\n    void x_false_y_false_profit(int x, int y, T z) {\n        assert(0\
    \ <= x and x < n);\n        assert(0 <= y and y < n);\n        sum += z;\n   \
    \     int w = dinic.add_vertex();\n        x_true_loss(w, z);\n        x_false_y_true_loss(w,\
    \ x, inf);\n        x_false_y_true_loss(w, y, inf);\n    }\n\n    void x_true_y_true_profit(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n    }\n\n    T solve() {}\n\nprivate:\n    int n, s, t;\n    T sum;\n\
    \    const T inf = std::numeric_limits<T>::max() / 2;\n    Dinic<T, true> dinic;\n\
    };\n\n/**\n * @brief Project Selection Problem\n * @docs docs/flow/ProjectSelectionPorblem.md\n\
    \ */\n"
  code: "#pragma once\n#include <limits>\n#include \"Dinic.hpp\"\n\ntemplate <typename\
    \ T> struct ProjectSelectionProblem {\n    ProjectSelectionProblem(int n) : n(n),\
    \ s(n), t(n + 1), dinic(n + 2) {}\n\n    void x_false_loss(int x, T z) {\n   \
    \     assert(0 <= x and x < n);\n        dinic.add_edge(x, t, z);\n    }\n\n \
    \   void x_false_profit(int x, T z) {\n        assert(0 <= x and x < n);\n   \
    \     sum += z;\n        x_true_loss(x, z);\n    }\n\n    void x_true_loss(int\
    \ x, T z) {\n        assert(0 <= x and x < n);\n        dinic.add_edge(s, x, z);\n\
    \    }\n\n    void x_true_profit(int x, T z) {\n        assert(0 <= x and x <\
    \ n);\n        sum += z;\n        x_false_loss(x, z);\n    }\n\n    void x_false_y_true_loss(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        dinic.add_edge(x, y, z);\n    }\n\n    void x_true_y_false_loss(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        dinic.add_edge(y, x, z);\n        int w = dinic.add_vertex();\n\
    \        x_false_loss(w, z);\n        x_true_y_false_loss(w, x, inf);\n      \
    \  x_true_y_false_loss(w, y, inf);\n    }\n\n    void x_false_y_false_profit(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        sum += z;\n        int w = dinic.add_vertex();\n        x_true_loss(w,\
    \ z);\n        x_false_y_true_loss(w, x, inf);\n        x_false_y_true_loss(w,\
    \ y, inf);\n    }\n\n    void x_true_y_true_profit(int x, int y, T z) {\n    \
    \    assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n    }\n\n \
    \   T solve() {}\n\nprivate:\n    int n, s, t;\n    T sum;\n    const T inf =\
    \ std::numeric_limits<T>::max() / 2;\n    Dinic<T, true> dinic;\n};\n\n/**\n *\
    \ @brief Project Selection Problem\n * @docs docs/flow/ProjectSelectionPorblem.md\n\
    \ */\n"
  dependsOn:
  - flow/Dinic.hpp
  isVerificationFile: false
  path: flow/ProjectSelectionProblem.hpp
  requiredBy: []
  timestamp: '2021-10-18 22:54:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/2903.test.cpp
documentation_of: flow/ProjectSelectionProblem.hpp
layout: document
redirect_from:
- /library/flow/ProjectSelectionProblem.hpp
- /library/flow/ProjectSelectionProblem.hpp.html
title: Project Selection Problem
---
