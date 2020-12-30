---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/Dijkstra.md
    document_title: Dijkstra
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/Dijkstra.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Dijkstra\n * @docs docs/graph/Dijkstra.md\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nstruct Dijkstra{\n\
    \    struct edge{\n        int to; T cost;\n        edge(int to,T cost):to(to),cost(cost){}\n\
    \        bool operator<(const edge &e) const {\n            return cost>e.cost;\n\
    \        }\n    };\n    vector<vector<edge>> G;\n    vector<T> dp;\n    vector<int>\
    \ pre;\n    Dijkstra(int n):G(n),dp(n),pre(n){}\n    void add_edge(int u,int v,T\
    \ c){\n        G[u].emplace_back(v,c);\n    }\n    void build(int s){\n      \
    \  int n=G.size();\n        fill(dp.begin(),dp.end(),numeric_limits<T>::max());\n\
    \        fill(pre.begin(),pre.end(),-1);\n        priority_queue<edge> pq;\n \
    \       dp[s]=0;\n        pq.emplace(s,dp[s]);\n        while(!pq.empty()){\n\
    \            auto p=pq.top(); pq.pop();\n            int v=p.to;\n           \
    \ if (dp[v]<p.cost) continue;\n            for (auto e:G[v]){\n              \
    \  if (dp[v]+e.cost<dp[e.to]){\n                    dp[e.to]=dp[v]+e.cost;\n \
    \                   pre[e.to]=v;\n                    pq.emplace(e.to,dp[e.to]);\n\
    \                }\n            }\n        }\n    }\n    vector<int> restore(int\
    \ t){\n        vector<int> res;\n        if (pre[t]<0) return res;\n        while(~t){\n\
    \            res.emplace_back(t);\n            t=pre[t];\n        }\n        reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n    T operator[](int to){return dp[to];}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/shortest_path.test.cpp
  - test/aoj/GRL_1_A.test.cpp
documentation_of: graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/graph/Dijkstra.hpp
- /library/graph/Dijkstra.hpp.html
title: Dijkstra
---
## 概要

## 計算量