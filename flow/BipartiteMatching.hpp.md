---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/BipartiteMatching.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <random>\n#include <utility>\n#include\
    \ <vector>\n\nstruct BipartiteMatching {\n    int U, V, t;\n    bool solved;\n\
    \    std::vector<std::vector<int>> G;\n    std::vector<int> L, R, visited;\n\n\
    \    BipartiteMatching(int U, int V) : U(U), V(V), t(0), solved(false), G(U),\
    \ L(U, -1), R(V, -1), visited(U, -1) {}\n\n    void add_edge(int u, int v) {\n\
    \        assert(0 <= u && u < U);\n        assert(0 <= v && v < V);\n        G[u].emplace_back(v);\n\
    \    }\n\n    void shuffle() {\n        static std::mt19937 mt;\n        for (auto&\
    \ v : G) std::shuffle(v.begin(), v.end(), mt);\n    }\n\n    int solve() {\n \
    \       for (bool updated = true; std::exchange(updated, false); t++) {\n    \
    \        for (int i = 0; i < U; i++) {\n                if (L[i] == -1) {\n  \
    \                  updated |= dfs(i);\n                }\n            }\n    \
    \    }\n        solved = true;\n        return U - std::count(L.begin(), L.end(),\
    \ -1);\n    }\n\n    std::vector<std::pair<int, int>> max_matching() const {\n\
    \        assert(solved);\n        std::vector<std::pair<int, int>> res;\n    \
    \    for (int i = 0; i < U; i++) {\n            if (~L[i]) {\n               \
    \ res.emplace_back(i, L[i]);\n            }\n        }\n        return res;\n\
    \    }\n\nprivate:\n    bool dfs(int u) {\n        if (std::exchange(visited[u],\
    \ t) == t) return false;\n        for (int& v : G[u]) {\n            if (R[v]\
    \ == -1) {\n                L[u] = v, R[v] = u;\n                return true;\n\
    \            }\n        }\n        for (int& v : G[u]) {\n            if (dfs(R[v]))\
    \ {\n                L[u] = v, R[v] = u;\n                return true;\n     \
    \       }\n        }\n        return false;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <random>\n#include <utility>\n#include <vector>\n\nstruct BipartiteMatching\
    \ {\n    int U, V, t;\n    bool solved;\n    std::vector<std::vector<int>> G;\n\
    \    std::vector<int> L, R, visited;\n\n    BipartiteMatching(int U, int V) :\
    \ U(U), V(V), t(0), solved(false), G(U), L(U, -1), R(V, -1), visited(U, -1) {}\n\
    \n    void add_edge(int u, int v) {\n        assert(0 <= u && u < U);\n      \
    \  assert(0 <= v && v < V);\n        G[u].emplace_back(v);\n    }\n\n    void\
    \ shuffle() {\n        static std::mt19937 mt;\n        for (auto& v : G) std::shuffle(v.begin(),\
    \ v.end(), mt);\n    }\n\n    int solve() {\n        for (bool updated = true;\
    \ std::exchange(updated, false); t++) {\n            for (int i = 0; i < U; i++)\
    \ {\n                if (L[i] == -1) {\n                    updated |= dfs(i);\n\
    \                }\n            }\n        }\n        solved = true;\n       \
    \ return U - std::count(L.begin(), L.end(), -1);\n    }\n\n    std::vector<std::pair<int,\
    \ int>> max_matching() const {\n        assert(solved);\n        std::vector<std::pair<int,\
    \ int>> res;\n        for (int i = 0; i < U; i++) {\n            if (~L[i]) {\n\
    \                res.emplace_back(i, L[i]);\n            }\n        }\n      \
    \  return res;\n    }\n\nprivate:\n    bool dfs(int u) {\n        if (std::exchange(visited[u],\
    \ t) == t) return false;\n        for (int& v : G[u]) {\n            if (R[v]\
    \ == -1) {\n                L[u] = v, R[v] = u;\n                return true;\n\
    \            }\n        }\n        for (int& v : G[u]) {\n            if (dfs(R[v]))\
    \ {\n                L[u] = v, R[v] = u;\n                return true;\n     \
    \       }\n        }\n        return false;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2022-09-04 18:06:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bipartitematching.test.cpp
documentation_of: flow/BipartiteMatching.hpp
layout: document
title: Bipartite Matching
---

## 概要
2部グラフにおける最大マッチング，最小点被覆，最大独立集合，最小辺被覆を求める．
- 最大マッチング：どの2辺も端点を共有しないような辺集合．
- 最小点被覆：各辺の端点のうち少なくとも一方を必ず含むような点集合．
- 最大独立集合：どの2頂点も辺で結ばれていないような点集合．
- 最小辺被覆：各頂点を端点にもつ辺を必ず含むような辺集合．

一般に，点被覆の補集合は独立集合をなし，その逆も成立する．
よって，最小点被覆の補集合が最大安定集合となり，その逆も成り立つ．

また，最大マッチングの辺集合に対して，マッチングの端点になっていないような各頂点を端点にもつような辺を Greedy に追加していくと最小辺被覆になる．

ここで，2 部グラフにおいては最大マッチングの大きさと最小点被覆の大きさが等しくなる．また，最大マッチングを構築する際の残余グラフから最小点被覆を実際に構成でき，他についても構成可能となる．

よって，それぞれの大きさは頂点集合の大きさを $\|V\|$，最大マッチングの大きさを $\|M\|$ とすると，最小点被覆の大きさは $\|M\|$，最大独立集合の大きさは $\|V\| - \|M\|$，最小辺被覆の大きさは $\|V\| - \|M\|$ (ただし，孤立点が存在する場合は辺被覆は存在しない)となる．

実装は Kuhn の $O(VE)$ のアルゴリズムを改善したもので，実用上は十分高速で Hopcroft-Karp にも勝ることが多い．
これでも間に合わない際には `shuffle()` をするか大人しく他のライブラリに頼る．

## TODO
最小点被覆、最大独立集合、最小辺被覆の実装
## Links
- [二部グラフの最小点被覆、最大安定集合 (最大独立集合)、最小辺被覆を総整理！ - Qiita](https://qiita.com/drken/items/7f98315b56c95a6181a4)
- [二部グラフの最小点被覆と最大安定集合と最小辺被覆の求め方](https://www.slideshare.net/drken1215/ss-86894312)
- [2部グラフにおける最大マッチングの個数と最小点被覆の個数の一致 - komiyamの日記](https://komiyam.hatenadiary.org/entry/20110208/1297112982)
- [Паросочетание. Быстрый Кун. - Codeforces](https://codeforces.com/blog/entry/17023)
- [二部マッチングでTLEに苦しんだ話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2019/05/07/013609)
