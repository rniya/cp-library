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
  bundledCode: "#line 1 \"src/graph/FunctionalGraph.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\nstruct FunctionalGraph {\n    int n, L;\n    std::vector<int> visit;\n\
    \    std::vector<std::vector<int>> loops, G;\n\n    FunctionalGraph(int n) : n(n),\
    \ L(1), visit(n), G(n), nxt(n, -1) {}\n\n    void add_edge(int u, int v) {\n \
    \       assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n       \
    \ nxt[u] = v;\n    }\n\n    void build() {\n        for (int i = 0; i < n; i++)\
    \ {\n            if (visit[i] != 0) continue;\n            std::vector<int> loop;\n\
    \            dfs(i, loop);\n            if (not loop.empty()) loops.emplace_back(loop);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            if (visit[i] <\
    \ 0) {\n                G[nxt[i]].emplace_back(i);\n            }\n        }\n\
    \    }\n\n  private:\n    std::vector<int> nxt;\n\n    void make_loop(int s, std::vector<int>&\
    \ loop) {\n        loop.emplace_back(s);\n        visit[s] = L;\n        for (int\
    \ cur = nxt[s]; cur != s; cur = nxt[cur]) {\n            loop.emplace_back(cur);\n\
    \            visit[cur] = L;\n        }\n    }\n\n    int dfs(int v, std::vector<int>&\
    \ loop) {\n        visit[v] = -L;\n        int u = nxt[v];\n        if (visit[u]\
    \ == -L) {\n            make_loop(v, loop);\n            L++;\n            return\
    \ 0;\n        } else if (visit[u] == 0) {\n            int res = dfs(u, loop);\n\
    \            if (res == 0) return 0;\n            return visit[v] = res;\n   \
    \     }\n        return visit[v] = (visit[u] > 0 ? -visit[u] : visit[u]);\n  \
    \  }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\nstruct FunctionalGraph {\n    int\
    \ n, L;\n    std::vector<int> visit;\n    std::vector<std::vector<int>> loops,\
    \ G;\n\n    FunctionalGraph(int n) : n(n), L(1), visit(n), G(n), nxt(n, -1) {}\n\
    \n    void add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n     \
    \   assert(0 <= v and v < n);\n        nxt[u] = v;\n    }\n\n    void build()\
    \ {\n        for (int i = 0; i < n; i++) {\n            if (visit[i] != 0) continue;\n\
    \            std::vector<int> loop;\n            dfs(i, loop);\n            if\
    \ (not loop.empty()) loops.emplace_back(loop);\n        }\n        for (int i\
    \ = 0; i < n; i++) {\n            if (visit[i] < 0) {\n                G[nxt[i]].emplace_back(i);\n\
    \            }\n        }\n    }\n\n  private:\n    std::vector<int> nxt;\n\n\
    \    void make_loop(int s, std::vector<int>& loop) {\n        loop.emplace_back(s);\n\
    \        visit[s] = L;\n        for (int cur = nxt[s]; cur != s; cur = nxt[cur])\
    \ {\n            loop.emplace_back(cur);\n            visit[cur] = L;\n      \
    \  }\n    }\n\n    int dfs(int v, std::vector<int>& loop) {\n        visit[v]\
    \ = -L;\n        int u = nxt[v];\n        if (visit[u] == -L) {\n            make_loop(v,\
    \ loop);\n            L++;\n            return 0;\n        } else if (visit[u]\
    \ == 0) {\n            int res = dfs(u, loop);\n            if (res == 0) return\
    \ 0;\n            return visit[v] = res;\n        }\n        return visit[v] =\
    \ (visit[u] > 0 ? -visit[u] : visit[u]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/FunctionalGraph.hpp
  requiredBy: []
  timestamp: '2023-09-18 22:25:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/FunctionalGraph.hpp
layout: document
title: Functional Graph
---

## 概要
Functional Graph とは各頂点の出次数が丁度 $1$ であるような有向グラフのことを指す．
グラフはいくつかのループをもち，全体として各ループを根とするような森となる．
`visit[v]` は $v$ が $i$ (0-indexed) 番目のループ上にあるなら $i + 1$，ループ上になく $i$ 番目のループにたどり着く場合には $- (i + 1)$ を格納する．
`G` はループ上の頂点から葉へ向かう逆方向の森である．

## 問題例
- [AtCoder Beginner Contest 296 E - Transition Game](https://atcoder.jp/contests/abc296/tasks/abc296_e)