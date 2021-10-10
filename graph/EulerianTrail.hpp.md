---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/583.test.cpp
    title: test/yukicoder/583.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/EulerianTrail.md
    document_title: Eulerian Trail
    links: []
  bundledCode: "#line 2 \"graph/EulerianTrail.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <bool directed> struct EulerianTrail\
    \ {\n    std::vector<std::vector<std::pair<int, int>>> G;\n\n    EulerianTrail(int\
    \ n) : G(n), n(n), m(0), deg(n, 0), used_vertex(n, false) {}\n\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v\
    \ < n);\n        edges.emplace_back(u, v);\n        used_edge.emplace_back(false);\n\
    \        G[u].emplace_back(v, m);\n        deg[u]++;\n        if (directed)\n\
    \            deg[v]--;\n        else {\n            G[v].emplace_back(u, m);\n\
    \            deg[v]++;\n        }\n        m++;\n    }\n\n    std::vector<std::vector<int>>\
    \ solve() {\n        if (directed) {\n            if (std::count_if(deg.begin(),\
    \ deg.end(), [](int x) { return x != 0; })) return {};\n        } else {\n   \
    \         if (std::count_if(deg.begin(), deg.end(), [](int x) { return (x & 1)\
    \ != 0; })) return {};\n        }\n        std::vector<std::vector<int>> res;\n\
    \        for (int i = 0; i < n; i++) {\n            if (G[i].empty() or used_vertex[i])\
    \ continue;\n            res.emplace_back(go(i));\n        }\n        return res;\n\
    \    }\n\n    std::vector<std::vector<int>> solve_semi() {\n        checked_vertex.assign(n,\
    \ false);\n        std::vector<std::vector<int>> res;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (checked_vertex[i]) continue;\n            int\
    \ s = -1, t = -1;\n            if (!dfs(i, s, t)) return {};\n            res.emplace_back(go(s\
    \ >= 0 ? s : i));\n            if (res.back().empty()) res.pop_back();\n     \
    \   }\n        return res;\n    }\n\n    std::pair<int, int> operator[](int k)\
    \ const { return edges[k]; }\n\nprivate:\n    int n, m;\n    std::vector<int>\
    \ deg;\n    std::vector<std::pair<int, int>> edges;\n    std::vector<bool> used_vertex,\
    \ used_edge, checked_vertex;\n\n    bool dfs(int v, int& s, int& t) {\n      \
    \  checked_vertex[v] = true;\n        if (directed) {\n            if (deg[v]\
    \ < -1 or 1 < deg[v]) return false;\n            if (deg[v] == 1) {\n        \
    \        if (s >= 0) return false;\n                s = v;\n            }\n  \
    \      } else {\n            if (deg[v] & 1) {\n                if (s == -1)\n\
    \                    s = v;\n                else if (t == -1)\n             \
    \       t = v;\n                else\n                    return false;\n    \
    \        }\n        }\n        for (const auto& e : G[v]) {\n            int u\
    \ = e.first;\n            if (checked_vertex[u]) continue;\n            if (!dfs(u,\
    \ s, t)) return false;\n        }\n        return true;\n    }\n\n    std::vector<int>\
    \ go(int s) {\n        std::vector<std::pair<int, int>> st;\n        std::vector<int>\
    \ order;\n        st.emplace_back(s, -1);\n        while (!st.empty()) {\n   \
    \         int v = st.back().first;\n            used_vertex[v] = true;\n     \
    \       if (G[v].empty()) {\n                order.emplace_back(st.back().second);\n\
    \                st.pop_back();\n            } else {\n                auto e\
    \ = G[v].back();\n                G[v].pop_back();\n                if (used_edge[e.second])\
    \ continue;\n                used_edge[e.second] = true;\n                st.emplace_back(e);\n\
    \            }\n        }\n        order.pop_back();\n        reverse(order.begin(),\
    \ order.end());\n        return order;\n    }\n};\n\n/**\n * @brief Eulerian Trail\n\
    \ * @docs docs/graph/EulerianTrail.md\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <bool directed> struct EulerianTrail {\n    std::vector<std::vector<std::pair<int,\
    \ int>>> G;\n\n    EulerianTrail(int n) : G(n), n(n), m(0), deg(n, 0), used_vertex(n,\
    \ false) {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u and u\
    \ < n);\n        assert(0 <= v and v < n);\n        edges.emplace_back(u, v);\n\
    \        used_edge.emplace_back(false);\n        G[u].emplace_back(v, m);\n  \
    \      deg[u]++;\n        if (directed)\n            deg[v]--;\n        else {\n\
    \            G[v].emplace_back(u, m);\n            deg[v]++;\n        }\n    \
    \    m++;\n    }\n\n    std::vector<std::vector<int>> solve() {\n        if (directed)\
    \ {\n            if (std::count_if(deg.begin(), deg.end(), [](int x) { return\
    \ x != 0; })) return {};\n        } else {\n            if (std::count_if(deg.begin(),\
    \ deg.end(), [](int x) { return (x & 1) != 0; })) return {};\n        }\n    \
    \    std::vector<std::vector<int>> res;\n        for (int i = 0; i < n; i++) {\n\
    \            if (G[i].empty() or used_vertex[i]) continue;\n            res.emplace_back(go(i));\n\
    \        }\n        return res;\n    }\n\n    std::vector<std::vector<int>> solve_semi()\
    \ {\n        checked_vertex.assign(n, false);\n        std::vector<std::vector<int>>\
    \ res;\n        for (int i = 0; i < n; i++) {\n            if (checked_vertex[i])\
    \ continue;\n            int s = -1, t = -1;\n            if (!dfs(i, s, t)) return\
    \ {};\n            res.emplace_back(go(s >= 0 ? s : i));\n            if (res.back().empty())\
    \ res.pop_back();\n        }\n        return res;\n    }\n\n    std::pair<int,\
    \ int> operator[](int k) const { return edges[k]; }\n\nprivate:\n    int n, m;\n\
    \    std::vector<int> deg;\n    std::vector<std::pair<int, int>> edges;\n    std::vector<bool>\
    \ used_vertex, used_edge, checked_vertex;\n\n    bool dfs(int v, int& s, int&\
    \ t) {\n        checked_vertex[v] = true;\n        if (directed) {\n         \
    \   if (deg[v] < -1 or 1 < deg[v]) return false;\n            if (deg[v] == 1)\
    \ {\n                if (s >= 0) return false;\n                s = v;\n     \
    \       }\n        } else {\n            if (deg[v] & 1) {\n                if\
    \ (s == -1)\n                    s = v;\n                else if (t == -1)\n \
    \                   t = v;\n                else\n                    return false;\n\
    \            }\n        }\n        for (const auto& e : G[v]) {\n            int\
    \ u = e.first;\n            if (checked_vertex[u]) continue;\n            if (!dfs(u,\
    \ s, t)) return false;\n        }\n        return true;\n    }\n\n    std::vector<int>\
    \ go(int s) {\n        std::vector<std::pair<int, int>> st;\n        std::vector<int>\
    \ order;\n        st.emplace_back(s, -1);\n        while (!st.empty()) {\n   \
    \         int v = st.back().first;\n            used_vertex[v] = true;\n     \
    \       if (G[v].empty()) {\n                order.emplace_back(st.back().second);\n\
    \                st.pop_back();\n            } else {\n                auto e\
    \ = G[v].back();\n                G[v].pop_back();\n                if (used_edge[e.second])\
    \ continue;\n                used_edge[e.second] = true;\n                st.emplace_back(e);\n\
    \            }\n        }\n        order.pop_back();\n        reverse(order.begin(),\
    \ order.end());\n        return order;\n    }\n};\n\n/**\n * @brief Eulerian Trail\n\
    \ * @docs docs/graph/EulerianTrail.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/EulerianTrail.hpp
  requiredBy: []
  timestamp: '2021-10-10 16:06:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/583.test.cpp
documentation_of: graph/EulerianTrail.hpp
layout: document
redirect_from:
- /library/graph/EulerianTrail.hpp
- /library/graph/EulerianTrail.hpp.html
title: Eulerian Trail
---
## 概要
有向/無向グラフが与えられたときに, オイラー路/準オイラー路を構築するライブラリ.

| メンバ関数         | 効果                                                                              | 時間計算量 |
| ------------------ | --------------------------------------------------------------------------------- | ---------- |
| `EulerianTrail(n)` | n 頂点のグラフとして初期化する.                                                   | $O(n)$     |
| `add_edge(u, v)`   | 辺 $(u, v)$ を追加する.                                                           | $O(1)$     |
| `solve()`          | 連結成分ごとにオイラー路を構築する. 存在しない連結成分がある場合には空配列を返す. | $O(n + m)$ |
| `solve_semi()`     | 連結成分ごとに準オイラーを構築する. 存在しない連結成分がある場合には空配列を返す. | $O(n + m)$ |
| `operator[k]`      | $k$ 番目に追加された辺の情報を返す.                                               | $O(1)$     |

### Remark
`solve()` や `solve_semi()` が返すのは頂点番号ではなく辺番号であるので注意.

## 計算量
どれも$O(V+E)$

## 問題例
- [Codeforces Round #647 (Div. 1) - Thanks, Algo Muse! C. Johnny and Megan's Necklace](https://codeforces.com/contest/1361/problem/C)
  - 無向グラフにおけるオイラー路の復元.

## 参照
- [競プロにおけるオイラー路とその応用について - Learning Algorithms](https://kokiymgch.hatenablog.com/entry/2017/12/07/193238)