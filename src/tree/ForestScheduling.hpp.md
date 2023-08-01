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
  bundledCode: "#line 2 \"src/tree/ForestScheduling.hpp\"\n#include <cassert>\n#include\
    \ <queue>\n#include <vector>\n\ntemplate <class S, S (*op)(S, S)> struct ForestScheduling\
    \ {\n    S tot;\n    std::vector<int> ord;\n\n    ForestScheduling(const std::vector<int>&\
    \ par, std::vector<S> x) : tot() {\n        int n = par.size();\n        assert(int(x.size())\
    \ == n);\n        dsu.assign(n + 1, -1);\n        std::priority_queue<T> pq;\n\
    \        std::vector<int> tails(n + 1), nxt(n + 1, -1);\n        for (int i =\
    \ 0; i < n; i++) {\n            tails[i] = i;\n            pq.push({x[i], i, i});\n\
    \        }\n        tails[n] = n;\n        while (not pq.empty()) {\n        \
    \    auto [tmp, v, tail] = pq.top();\n            pq.pop();\n            if (tails[v]\
    \ == tail) {\n                int u = leader(par[v] >= 0 ? par[v] : n);\n    \
    \            merge(u, v);\n                nxt[tails[u]] = v;\n              \
    \  tails[u] = tail;\n                if (u == n)\n                    tot = op(tot,\
    \ x[v]);\n                else {\n                    x[u] = op(x[u], x[v]);\n\
    \                    pq.push({x[u], u, tail});\n                }\n          \
    \  }\n        }\n        for (int i = 0, cur = n; i < n; i++) {\n            cur\
    \ = nxt[cur];\n            ord.emplace_back(cur);\n        }\n    }\n\n    int\
    \ operator[](int i) const { return ord[i]; }\n\n  private:\n    struct T {\n \
    \       S s;\n        int head, tail;\n        bool operator<(const T& rhs) const\
    \ { return rhs.s < s; }\n    };\n    std::vector<int> dsu;\n\n    int leader(int\
    \ u) { return dsu[u] < 0 ? u : (dsu[u] = leader(dsu[u])); }\n\n    bool merge(int\
    \ u, int v) {\n        u = leader(u), v = leader(v);\n        if (u == v) return\
    \ false;\n        dsu[u] += dsu[v];\n        dsu[v] = u;\n        return true;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <queue>\n#include <vector>\n\n\
    template <class S, S (*op)(S, S)> struct ForestScheduling {\n    S tot;\n    std::vector<int>\
    \ ord;\n\n    ForestScheduling(const std::vector<int>& par, std::vector<S> x)\
    \ : tot() {\n        int n = par.size();\n        assert(int(x.size()) == n);\n\
    \        dsu.assign(n + 1, -1);\n        std::priority_queue<T> pq;\n        std::vector<int>\
    \ tails(n + 1), nxt(n + 1, -1);\n        for (int i = 0; i < n; i++) {\n     \
    \       tails[i] = i;\n            pq.push({x[i], i, i});\n        }\n       \
    \ tails[n] = n;\n        while (not pq.empty()) {\n            auto [tmp, v, tail]\
    \ = pq.top();\n            pq.pop();\n            if (tails[v] == tail) {\n  \
    \              int u = leader(par[v] >= 0 ? par[v] : n);\n                merge(u,\
    \ v);\n                nxt[tails[u]] = v;\n                tails[u] = tail;\n\
    \                if (u == n)\n                    tot = op(tot, x[v]);\n     \
    \           else {\n                    x[u] = op(x[u], x[v]);\n             \
    \       pq.push({x[u], u, tail});\n                }\n            }\n        }\n\
    \        for (int i = 0, cur = n; i < n; i++) {\n            cur = nxt[cur];\n\
    \            ord.emplace_back(cur);\n        }\n    }\n\n    int operator[](int\
    \ i) const { return ord[i]; }\n\n  private:\n    struct T {\n        S s;\n  \
    \      int head, tail;\n        bool operator<(const T& rhs) const { return rhs.s\
    \ < s; }\n    };\n    std::vector<int> dsu;\n\n    int leader(int u) { return\
    \ dsu[u] < 0 ? u : (dsu[u] = leader(dsu[u])); }\n\n    bool merge(int u, int v)\
    \ {\n        u = leader(u), v = leader(v);\n        if (u == v) return false;\n\
    \        dsu[u] += dsu[v];\n        dsu[v] = u;\n        return true;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/ForestScheduling.hpp
  requiredBy: []
  timestamp: '2023-06-17 00:18:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/ForestScheduling.hpp
layout: document
title: "\u68EE\u4E0A\u306E\u30B9\u30B1\u30B8\u30E5\u30FC\u30EA\u30F3\u30B0\u554F\u984C"
---

## 概要

根付き森が与えられ，頂点を先祖が子孫の頂点の右側に置かれないように並べ替えるときに頂点に書かれた値の列のスコアを最大（最小）化する問題を $\mathrm{O}(n \log n)$ 時間で解く．
この際，値の列の優先関係について，反射律と推移律，完全律が成立する弱順序となっている必要がある．
`S` に単位元と `<` の演算子，マージ関数 `op` が定義されている必要がある．

## 問題例
- [AtCoder Grand Contest 023 F - 01 on Tree](https://atcoder.jp/contests/agc023/tasks/agc023_f)
- [Toyota Programming Contest 2023 Spring Final G - Git Gud](https://atcoder.jp/contests/toyota2023spring-final/tasks/toyota2023spring_final_g)
- [The 1st Universal Cup. Stage 19: America D. Fail Fast](https://qoj.ac/contest/1248/problem/6561?v=1)