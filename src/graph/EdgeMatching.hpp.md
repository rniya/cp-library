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
  bundledCode: "#line 2 \"src/graph/EdgeMatching.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\nstruct EdgeMatching {\n    EdgeMatching(int\
    \ n) : n(n), G(n), seen(n), dep(n) {}\n    void add_edge(int u, int v) {\n   \
    \     assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n        int\
    \ idx = es.size();\n        G[u].emplace_back(idx);\n        G[v].emplace_back(idx);\n\
    \        es.emplace_back(u, v);\n    }\n\n    std::vector<std::pair<int, int>>\
    \ build() {\n        std::vector<std::pair<int, int>> res;\n        for (int i\
    \ = 0; i < n; i++) {\n            if (not seen[i]) {\n                dfs(i, -1,\
    \ 0, res);\n            }\n        }\n        return res;\n    }\n\n    std::pair<int,\
    \ int> operator[](int k) const { return es[k]; }\n\n  private:\n    int n;\n \
    \   std::vector<std::pair<int, int>> es;\n    std::vector<std::vector<int>> G;\n\
    \    std::vector<bool> seen;\n    std::vector<int> dep;\n\n    int dfs(int v,\
    \ int p, int d, std::vector<std::pair<int, int>>& res) {\n        seen[v] = true;\n\
    \        dep[v] = d;\n        int r = -1;\n        for (const int& e : G[v]) {\n\
    \            int u = es[e].first ^ es[e].second ^ v;\n            if (e == p)\
    \ continue;\n            if (seen[u]) {\n                if (dep[u] < dep[v])\
    \ {\n                    if (r == -1)\n                        r = e;\n      \
    \              else {\n                        res.emplace_back(r, e);\n     \
    \                   r = -1;\n                    }\n                }\n      \
    \      } else {\n                int ch = dfs(u, e, d + 1, res);\n           \
    \     if (r == -1)\n                    r = ch;\n                else if (ch !=\
    \ -1) {\n                    res.emplace_back(r, ch);\n                    r =\
    \ -1;\n                }\n            }\n        }\n        if (r != -1 and p\
    \ != -1) {\n            res.emplace_back(r, p);\n            return -1;\n    \
    \    }\n        return p;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nstruct EdgeMatching {\n    EdgeMatching(int n) : n(n), G(n), seen(n), dep(n)\
    \ {}\n    void add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n \
    \       assert(0 <= v and v < n);\n        int idx = es.size();\n        G[u].emplace_back(idx);\n\
    \        G[v].emplace_back(idx);\n        es.emplace_back(u, v);\n    }\n\n  \
    \  std::vector<std::pair<int, int>> build() {\n        std::vector<std::pair<int,\
    \ int>> res;\n        for (int i = 0; i < n; i++) {\n            if (not seen[i])\
    \ {\n                dfs(i, -1, 0, res);\n            }\n        }\n        return\
    \ res;\n    }\n\n    std::pair<int, int> operator[](int k) const { return es[k];\
    \ }\n\n  private:\n    int n;\n    std::vector<std::pair<int, int>> es;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<bool> seen;\n    std::vector<int> dep;\n\n    int dfs(int\
    \ v, int p, int d, std::vector<std::pair<int, int>>& res) {\n        seen[v] =\
    \ true;\n        dep[v] = d;\n        int r = -1;\n        for (const int& e :\
    \ G[v]) {\n            int u = es[e].first ^ es[e].second ^ v;\n            if\
    \ (e == p) continue;\n            if (seen[u]) {\n                if (dep[u] <\
    \ dep[v]) {\n                    if (r == -1)\n                        r = e;\n\
    \                    else {\n                        res.emplace_back(r, e);\n\
    \                        r = -1;\n                    }\n                }\n \
    \           } else {\n                int ch = dfs(u, e, d + 1, res);\n      \
    \          if (r == -1)\n                    r = ch;\n                else if\
    \ (ch != -1) {\n                    res.emplace_back(r, ch);\n               \
    \     r = -1;\n                }\n            }\n        }\n        if (r != -1\
    \ and p != -1) {\n            res.emplace_back(r, p);\n            return -1;\n\
    \        }\n        return p;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/EdgeMatching.hpp
  requiredBy: []
  timestamp: '2023-06-17 00:08:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/EdgeMatching.hpp
layout: document
title: "\u8FBA\u540C\u58EB\u306E\u30DE\u30C3\u30C1\u30F3\u30B0"
---

## 概要
一般グラフ $G(V, E)$ において、端点を共有する辺同士の最大マッチングを構成する．

| メンバ関数        | 効果                                                                                 | 時間計算量          |
| ----------------- | ------------------------------------------------------------------------------------ | ------------------- |
| `EdgeMatching(n)` | 頂点数 $n$ のグラフとして初期化する．                                                | $\mathrm{O}(n)$     |
| `add_edge(u, v)`  | 頂点 $u$ と頂点 $v$ を結ぶ辺を追加する．                                             | $\mathrm{O}(1)$     |
| `build()`         | 最大マッチングを求める．ここで辺 $i$ は `add_edge` で $i$ 番目に追加された辺である． | $\mathrm{O}(n + m)$ |



## 問題例
- [AtCoder Regular Contest 045 D - みんな仲良し高橋君](https://atcoder.jp/contests/arc045/tasks/arc045_d)
- [The 1st Universal Cup. Stage 0: Nanjing (Trial Contest) J. Perfect Matching](https://qoj.ac/contest/1093/problem/5423)
- [The 1st Universal Cup. Stage 16: Gomel H. Classical Maximization Problem](https://qoj.ac/contest/1223/problem/6414?v=1)