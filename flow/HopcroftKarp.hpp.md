---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
    title: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/HopcroftKarp.md
    document_title: Hopcroft Karp
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/HopcroftKarp.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Hopcroft Karp\n * @docs docs/flow/HopcroftKarp.md\n */\n\n\
    #pragma once\n\n#include \"../base.hpp\"\n\nstruct HopcroftKarp{\nprivate:\n \
    \   int n,m; bool matched;\n    vector<vector<int>> G,rG;\n    vector<int> match_l,match_r,level;\n\
    \    void levelize(){\n        queue<int> que;\n        for (int i=0;i<n;++i){\n\
    \            level[i]=-1;\n            if (match_l[i]<0){\n                level[i]=0;\n\
    \                que.emplace(i);\n            }\n        }\n        while (!que.empty()){\n\
    \            int v=que.front(); que.pop();\n            for (int u:G[v]){\n  \
    \              int w=match_r[u];\n                if (~w&&level[w]<0){\n     \
    \               level[w]=level[v]+1;\n                    que.emplace(w);\n  \
    \              }\n            }\n        }\n    }\n    bool find_augumenting_path(int\
    \ v){\n        for (int u:G[v]){\n            int w=match_r[u];\n            if\
    \ (w<0||(level[w]>level[v]&&find_augumenting_path(w))){\n                match_l[v]=u;\
    \ match_r[u]=v;\n                return true;\n            }\n        }\n    \
    \    return false;\n    }\n    vector<vector<int>> build_residual_graph(){\n \
    \       if (!matched) max_matching();\n        const int s=n+m,t=n+m+1;\n    \
    \    vector<vector<int>> res(n+m+2);\n        for (int i=0;i<n;++i){\n       \
    \     if (match_l[i]<0){\n                res[s].emplace_back(i);\n          \
    \  }\n        }\n        for (int i=0;i<n;++i){\n            for (int j:G[i]){\n\
    \                if (match_l[i]==j) res[j+n].emplace_back(i);\n              \
    \  else res[i].emplace_back(j+n);\n            }\n        }\n        return res;\n\
    \    }\n    vector<bool> find_residual_path(){\n        auto g=build_residual_graph();\n\
    \        queue<int> que;\n        vector<bool> visited(n+m+2);\n        que.emplace(n+m);\
    \ visited[n+m]=true;\n        while (!que.empty()){\n            int v=que.front();\
    \ que.pop();\n            for (int u:g[v]){\n                if (visited[u]) continue;\n\
    \                visited[u]=true; que.emplace(u);\n            }\n        }\n\
    \        return visited;\n    }\n\npublic:\n    HopcroftKarp(int n,int m):n(n),m(m),G(n),rG(m),match_l(n,-1),match_r(m,-1),level(n),matched(false){}\n\
    \    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n        rG[v].emplace_back(u);\n\
    \    }\n    vector<pair<int,int>> max_matching(){\n        matched=true;\n   \
    \     while (1){\n            levelize();\n            int match=0;\n        \
    \    for (int i=0;i<n;++i){\n                if (match_l[i]<0){\n            \
    \        match+=find_augumenting_path(i);\n                }\n            }\n\
    \            if (!match) break;\n        }\n        vector<pair<int,int>> res;\n\
    \        for (int i=0;i<n;++i){\n            if (~match_l[i]){\n             \
    \   res.emplace_back(i,match_l[i]);\n            }\n        }\n        return\
    \ res;\n    }\n    vector<int> min_vertex_cover(){\n        auto visited=find_residual_path();\n\
    \        vector<int> res;\n        for (int i=0;i<n+m;++i){\n            if (visited[i]^(i<n)){\n\
    \                res.emplace_back(i);\n            }\n        }\n        return\
    \ res;\n    }\n    vector<int> max_independent_set(){\n        auto visited=find_residual_path();\n\
    \        vector<int> res;\n        for (int i=0;i<n+m;++i){\n            if (visited[i]^(i>=n)){\n\
    \                res.emplace_back(i);\n            }\n        }\n        return\
    \ res;\n    }\n    vector<pair<int,int>> min_edge_cover(){\n        auto res=max_matching();\n\
    \        for (int i=0;i<n;++i){\n            if (~match_l[i]) continue;\n    \
    \        if (G[i].empty()) return {};\n            res.emplace_back(i,G[i][0]);\n\
    \        }\n        for (int i=0;i<m;++i){\n            if (~match_r[i]) continue;\n\
    \            if (rG[i].empty()) return {};\n            res.emplace_back(rG[i][0],i);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/HopcroftKarp.hpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bipartitematching.test.cpp
  - test/aoj/GRL_7_A.HopcroftKarp.test.cpp
documentation_of: flow/HopcroftKarp.hpp
layout: document
redirect_from:
- /library/flow/HopcroftKarp.hpp
- /library/flow/HopcroftKarp.hpp.html
title: Hopcroft Karp
---
## 概要
Hopcroft-Karpのアルゴリズムにより2部グラフにおける最大マッチング, 最小点被覆, 最大独立集合, 最小辺被覆を求める.
- 最大マッチング：どの2辺も端点を共有しないような辺集合.
- 最小点被覆：各辺の端点のうち少なくとも一方を必ず含むような点集合.
- 最大独立集合：どの2頂点も辺で結ばれていないような点集合.
- 最小辺被覆：各頂点を端点にもつ辺を必ず含むような辺集合.

一般に, 点被覆の補集合は独立集合をなし, その逆も成立する. よって, 最小点被覆の補集合が最大安定集合となり, その逆も成り立つ.

また, 最大マッチングの辺集合に対して, マッチングの端点になっていないような各頂点を端点にもつような辺をGreedyに追加していくと最小辺被覆になる.

ここで, 2部グラフにおいては最大マッチングの大きさと最小点被覆の大きさが等しくなる. また, 最大マッチングを構築する際の残余グラフから最小点被覆を実際に構成でき, 他についても構成可能となる.

よって, それぞれの大きさについては, 頂点集合の大きさを$|V|$, 最大マッチングの大きさを$|M|$とすると, 最小点被覆は$|M|$, 最大独立集合は$|V|-|M|$, 最小辺被覆は$|V|-|M|$(ただし, 孤立点が存在する場合は辺被覆は存在しない)となる.

- `add_edge(u,v)`：$u$と$v$の間に辺を張る.
- `max_matching()`：最大マッチングを求める.
- `min_vertex_cover()`：最小点被覆を求める.
- `max_independent_set()`：最大独立集合を求める.
- `min_edge_cover()`：最小辺被覆を求める.

また, 頂点番号の振り方に注意.
## 計算量
各クエリ$O(E\sqrt{V})$

## 参照
- [二部グラフの最小点被覆、最大安定集合 (最大独立集合)、最小辺被覆を総整理！ - Qiita](https://qiita.com/drken/items/7f98315b56c95a6181a4)
- [二部グラフの最小点被覆と最大安定集合と最小辺被覆の求め方](https://www.slideshare.net/drken1215/ss-86894312)
- [2部グラフにおける最大マッチングの個数と最小点被覆の個数の一致 - komiyamの日記](https://komiyam.hatenadiary.org/entry/20110208/1297112982)