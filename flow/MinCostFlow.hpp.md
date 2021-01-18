---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/flow/MinCostFlow.md
    document_title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/MinCostFlow.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41\n * @docs docs/flow/MinCostFlow.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T,typename\
    \ E>\nstruct MinCostFlow{\n    const E inf=numeric_limits<E>::max();\n    struct\
    \ edge{\n        int to,rev; T cap; E cost;\n        edge(int to,T cap,E cost,int\
    \ rev):to(to),cap(cap),cost(cost),rev(rev){}\n    };\n    vector<vector<edge>>\
    \ G;\n    vector<pair<int,int>> pos;\n    vector<E> dist;\n    vector<int> prevv,preve;\n\
    \    MinCostFlow(int n):G(n),dist(n),prevv(n),preve(n){}\n    int add_edge(int\
    \ from,int to,T cap,E cost){\n        pos.emplace_back(from,G[from].size());\n\
    \        G[from].emplace_back(to,cap,cost,G[to].size());\n        G[to].emplace_back(from,0,-cost,G[from].size()-1);\n\
    \        return pos.size()-1;\n    }\n    tuple<int,int,int,int,int> get_edge(int\
    \ i){\n        auto e=G[pos[i].first][pos[i].second];\n        auto re=G[e.to][e.rev];\n\
    \        return {pos[i].first,e.to,e.cap+re.cap,re.cap,e.cost};\n    }\n    vector<tuple<int,int,int,int,int>>\
    \ edges(){\n        vector<tuple<int,int,int,int,int>> res;\n        for (int\
    \ i=0;i<pos.size();++i){\n            res.emplace_back(get_edge(i));\n       \
    \ }\n        return res;\n    }\n    E min_cost_flow(int s,int t,T f){\n     \
    \   E res=0;\n        while(f>0){\n            fill(dist.begin(),dist.end(),inf);\n\
    \            dist[s]=0;\n            bool update=true;\n            while(update){\n\
    \                update=false;\n                for (int v=0;v<G.size();++v){\n\
    \                    if (dist[v]==inf) continue;\n                    for (int\
    \ i=0;i<G[v].size();++i){\n                        edge &e=G[v][i];\n        \
    \                if (e.cap>0&&dist[e.to]>dist[v]+e.cost){\n                  \
    \          dist[e.to]=dist[v]+e.cost;\n                            prevv[e.to]=v;\
    \ preve[e.to]=i;\n                            update=true;\n                 \
    \       }\n                    }\n                }\n            }\n         \
    \   if (dist[t]==inf) return -1;\n            T d=f;\n            for (int v=t;v!=s;v=prevv[v]){\n\
    \                d=min(d,G[prevv[v]][preve[v]].cap);\n            }\n        \
    \    f-=d;\n            res+=dist[t]*d;\n            for (int v=t;v!=s;v=prevv[v]){\n\
    \                edge &e=G[prevv[v]][preve[v]];\n                e.cap-=d; G[v][e.rev].cap+=d;\n\
    \            }\n        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/MinCostFlow.hpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_6_B.test.cpp
documentation_of: flow/MinCostFlow.hpp
layout: document
redirect_from:
- /library/flow/MinCostFlow.hpp
- /library/flow/MinCostFlow.hpp.html
title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
---
## 概要

## 計算量