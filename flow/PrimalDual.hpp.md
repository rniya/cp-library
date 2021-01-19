---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_6_B.PrimalDual.test.cpp
    title: test/aoj/GRL_6_B.PrimalDual.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1288.test.cpp
    title: test/yukicoder/1288.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1301.test.cpp
    title: test/yukicoder/1301.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/flow/PrimalDual.md
    document_title: Primal Dual
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
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
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_6_B.PrimalDual.test.cpp
  - test/yukicoder/1288.test.cpp
  - test/yukicoder/1301.test.cpp
documentation_of: flow/PrimalDual.hpp
layout: document
redirect_from:
- /library/flow/PrimalDual.hpp
- /library/flow/PrimalDual.hpp.html
title: Primal Dual
---
## 概要
最小費用流を計算する.

- `add_edge(from,to,cap,cost)`：$from$から$to$への容量$cap$, 費用$cost$の辺を追加する.
- `get_edge(i)`：$i$番目に追加した辺の{始点, 終点, 容量, 実際に流れている量, 費用}の情報を返す.
- `edges()`：全ての辺の情報を返す.
- `min_cost_flow(s,t,f)`：始点$s$から終点$t$へ流量$f$を流す際の最小費用を返す.
- `min_cost_max_flow(s,t)`：最大流量, およびそのときの最小費用を返す.
- `min_cost_slope(s,t)`：各流量に対する最小費用は折れ線状のグラフとなるが, そのグラフの各頂点の流量および最小費用を返す.

## 計算量
$O(fE\log V)$