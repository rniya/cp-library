---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/codeforces/1404_E.cpp
    title: test/codeforces/1404_E.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.PrimalDual.test.cpp
    title: test/aoj/GRL_6_B.PrimalDual.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/flow/PrimalDual.md
    document_title: Primal Dual
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/PrimalDual.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Primal Dual\n * @docs docs/flow/PrimalDual.md\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n\ntemplate<typename T,typename E>\nstruct\
    \ PrimalDual{\n    const E inf=numeric_limits<E>::max();\n    struct edge{\n \
    \       int to,rev; T cap; E cost;\n        edge(int to,T cap,E cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}\n\
    \    };\n    vector<vector<edge>> G;\n    vector<pair<int,int>> pos;\n    vector<E>\
    \ h,dist;\n    vector<int> prevv,preve;\n    PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}\n\
    \    int add_edge(int from,int to,T cap,E cost){\n        pos.emplace_back(from,G[from].size());\n\
    \        G[from].emplace_back(to,cap,cost,G[to].size());\n        G[to].emplace_back(from,0,-cost,G[from].size()-1);\n\
    \        return pos.size()-1;\n    }\n    tuple<int,int,int,int,int> get_edge(int\
    \ i){\n        auto e=G[pos[i].first][pos[i].second];\n        auto re=G[e.to][e.rev];\n\
    \        return {pos[i].first,e.to,e.cap+re.cap,re.cap,e.cost};\n    }\n    vector<tuple<int,int,int,int,int>>\
    \ edges(){\n        vector<tuple<int,int,int,int,int>> res;\n        for (int\
    \ i=0;i<pos.size();++i){\n            res.emplace_back(get_edge(i));\n       \
    \ }\n        return res;\n    }\n    void dijkstra(int s){\n        struct P{\n\
    \            E c; int v;\n            P(E c,int v):c(c),v(v){}\n            bool\
    \ operator<(const P &rhs) const {return c>rhs.c;}\n        };\n        priority_queue<P>\
    \ pq;\n        fill(dist.begin(),dist.end(),inf);\n        dist[s]=0; pq.emplace(dist[s],s);\n\
    \        while(!pq.empty()){\n            auto p=pq.top(); pq.pop();\n       \
    \     int v=p.v;\n            if (dist[v]<p.c) continue;\n            for (int\
    \ i=0;i<G[v].size();++i){\n                auto &e=G[v][i];\n                if\
    \ (e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){\n                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];\n\
    \                    prevv[e.to]=v; preve[e.to]=i;\n                    pq.emplace(dist[e.to],e.to);\n\
    \                }\n            }\n        }\n    }\n    vector<pair<T,E>> slope(int\
    \ s,int t,T lim){\n        T f=0; E c=0,pre=-1;\n        vector<pair<T,E>> res;\n\
    \        res.emplace_back(f,c);\n        while(f<lim){\n            dijkstra(s);\n\
    \            if (dist[t]==inf) break;\n            for (int v=0;v<G.size();++v)\
    \ h[v]+=dist[v];\n            T d=lim-f;\n            for (int v=t;v!=s;v=prevv[v]){\n\
    \                d=min(d,G[prevv[v]][preve[v]].cap);\n            }\n        \
    \    for (int v=t;v!=s;v=prevv[v]){\n                auto &e=G[prevv[v]][preve[v]];\n\
    \                e.cap-=d; G[v][e.rev].cap+=d;\n            }\n            f+=d;\
    \ c+=h[t]*d;\n            if (pre==h[t]) res.pop_back();\n            res.emplace_back(f,c);\n\
    \            pre=c;\n        }\n        return res;\n    }\n    E min_cost_flow(int\
    \ s,int t,T f){\n        auto res=slope(s,t,f).back();\n        return res.first==f?res.second:-1;\n\
    \    }\n    pair<T,E> min_cost_max_flow(int s,int t){\n        return slope(s,t,numeric_limits<T>::max()).back();\n\
    \    }\n    vector<pair<T,E>> min_cost_slope(int s,int t){\n        return slope(s,t,numeric_limits<T>::max());\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/PrimalDual.hpp
  requiredBy:
  - test/codeforces/1404_E.cpp
  timestamp: '2020-09-13 20:30:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_B.PrimalDual.test.cpp
documentation_of: flow/PrimalDual.hpp
layout: document
redirect_from:
- /library/flow/PrimalDual.hpp
- /library/flow/PrimalDual.hpp.html
title: Primal Dual
---
## 概要

## 計算量