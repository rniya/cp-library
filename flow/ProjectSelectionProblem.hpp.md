---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/Dinic.hpp
    title: Dinic (Maximum flow)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/ProjectSelectionProblem.md
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
    \ ProjectSelectionProblem {\n    ProjectSelectionProblem(int n) : n(n + 2), s(n),\
    \ t(n + 1), sum(T(0)), dinic(n + 2) {}\n\n    void x_false_loss(int x, T z) {\n\
    \        assert(0 <= x and x < n);\n        dinic.add_edge(x, t, z);\n    }\n\n\
    \    void x_false_profit(int x, T z) {\n        assert(0 <= x and x < n);\n  \
    \      sum += z;\n        x_true_loss(x, z);\n    }\n\n    void x_true_loss(int\
    \ x, T z) {\n        assert(0 <= x and x < n);\n        dinic.add_edge(s, x, z);\n\
    \    }\n\n    void x_true_profit(int x, T z) {\n        assert(0 <= x and x <\
    \ n);\n        sum += z;\n        x_false_loss(x, z);\n    }\n\n    void x_false_y_true_loss(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        dinic.add_edge(x, y, z);\n    }\n\n    void x_true_y_false_loss(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        dinic.add_edge(y, x, z);\n    }\n\n    void x_false_y_false_profit(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        sum += z;\n        int w = dinic.add_vertex();\n        n++;\n\
    \        x_true_loss(w, z);\n        x_false_y_true_loss(w, x, inf);\n       \
    \ x_false_y_true_loss(w, y, inf);\n    }\n\n    void x_true_y_true_profit(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        sum += z;\n        int w = dinic.add_vertex();\n        n++;\n\
    \        x_false_loss(w, z);\n        x_true_y_false_loss(w, x, inf);\n      \
    \  x_true_y_false_loss(w, y, inf);\n    }\n\n    T solve() { return dinic.max_flow(s,\
    \ t) - sum; }\n\nprivate:\n    int n, s, t;\n    T sum;\n    const T inf = std::numeric_limits<T>::max()\
    \ / 2;\n    Dinic<T, true> dinic;\n};\n\n/**\n * @brief Project Selection Problem\n\
    \ * @docs docs/flow/ProjectSelectionProblem.md\n */\n"
  code: "#pragma once\n#include <limits>\n#include \"Dinic.hpp\"\n\ntemplate <typename\
    \ T> struct ProjectSelectionProblem {\n    ProjectSelectionProblem(int n) : n(n\
    \ + 2), s(n), t(n + 1), sum(T(0)), dinic(n + 2) {}\n\n    void x_false_loss(int\
    \ x, T z) {\n        assert(0 <= x and x < n);\n        dinic.add_edge(x, t, z);\n\
    \    }\n\n    void x_false_profit(int x, T z) {\n        assert(0 <= x and x <\
    \ n);\n        sum += z;\n        x_true_loss(x, z);\n    }\n\n    void x_true_loss(int\
    \ x, T z) {\n        assert(0 <= x and x < n);\n        dinic.add_edge(s, x, z);\n\
    \    }\n\n    void x_true_profit(int x, T z) {\n        assert(0 <= x and x <\
    \ n);\n        sum += z;\n        x_false_loss(x, z);\n    }\n\n    void x_false_y_true_loss(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        dinic.add_edge(x, y, z);\n    }\n\n    void x_true_y_false_loss(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        dinic.add_edge(y, x, z);\n    }\n\n    void x_false_y_false_profit(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        sum += z;\n        int w = dinic.add_vertex();\n        n++;\n\
    \        x_true_loss(w, z);\n        x_false_y_true_loss(w, x, inf);\n       \
    \ x_false_y_true_loss(w, y, inf);\n    }\n\n    void x_true_y_true_profit(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        sum += z;\n        int w = dinic.add_vertex();\n        n++;\n\
    \        x_false_loss(w, z);\n        x_true_y_false_loss(w, x, inf);\n      \
    \  x_true_y_false_loss(w, y, inf);\n    }\n\n    T solve() { return dinic.max_flow(s,\
    \ t) - sum; }\n\nprivate:\n    int n, s, t;\n    T sum;\n    const T inf = std::numeric_limits<T>::max()\
    \ / 2;\n    Dinic<T, true> dinic;\n};\n\n/**\n * @brief Project Selection Problem\n\
    \ * @docs docs/flow/ProjectSelectionProblem.md\n */\n"
  dependsOn:
  - flow/Dinic.hpp
  isVerificationFile: false
  path: flow/ProjectSelectionProblem.hpp
  requiredBy: []
  timestamp: '2021-10-18 23:19:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2903.test.cpp
documentation_of: flow/ProjectSelectionProblem.hpp
layout: document
redirect_from:
- /library/flow/ProjectSelectionProblem.hpp
- /library/flow/ProjectSelectionProblem.hpp.html
title: Project Selection Problem
---
## 概要
Project Selection Problem, いわゆる燃やす埋める問題を解く際の補助ライブラリ.

| メンバ関数                        | 効果                                          | 時間計算量 |
| --------------------------------- | --------------------------------------------- | ---------- |
| `ProjectSelectionProblem(n)`      | 頂点数 $n$ のグラフとして初期化する.          | $O(n)$     |
| `x_false_loss(x, z)`              | $x$ が $0$ のときに $z$ 失う.                 | $O(1)$     |
| `x_false_profit(x, z)`            | $x$ が $0$ のときに $z$ 得る.                 | $O(1)$     |
| `x_true_loss(x, z)`               | $x$ が $1$ のときに $z$ 失う.                 | $O(1)$     |
| `x_true_profit(x, z)`             | $x$ が $1$ のときに $z$ 得る.                 | $O(1)$     |
| `x_false_y_true_loss(x, y, z)`    | $x$ が $0$ かつ $y$ が $1$ のときに $z$ 失う. | $O(1)$     |
| `x_true_y_false_loss(x, y, z)`    | $x$ が $1$ かつ $y$ が $0$ のときに $z$ 失う. | $O(1)$     |
| `x_false_y_false_profit(x, y, z)` | $x$ が $0$ かつ $y$ が $0$ のときに $z$ 得る. | $O(1)$     |
| `x_true_y_true_profit(x, y, z)`   | $x$ が $1$ かつ $y$ が $1$ のときに $z$ 得る. | $O(1)$     |
| `solve()`                         | 損失の最小値を返す.                           | $O(n^2m)$  |

一般にこれ以外の条件に対応する際には 2 部グラフなどの制約が必要になる.

## 問題例
- [Codeforces Round #668 (Div. 1) E. Bricks](https://codeforces.com/contest/1404/problem/E)
- [AtCoder Regular Contest 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [ARC107 F Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
  - 絶対値については, 各頂点に対して$0$(削除), $+1$(連結成分内での$B_i$の合計が正), $-1$(連結成分内での$B_i$の合計が正負)として, 各連結成分内に$+1$と$-1$が割り当てられた頂点が混在することがないようにすれば問題ない. これは$3$つのうちどれかに割り当てる問題になるが, 各頂点に対して$+1$か$+1$以外, $-1$以外か$-1$という2つの選択肢の直積として表現することで解くことができる. ([参照](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607))

## 参照
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)