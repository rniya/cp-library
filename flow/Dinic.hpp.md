---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.DInic.test.cpp
    title: test/aoj/GRL_6_A.DInic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.test.cpp
    title: test/aoj/2313.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/flow/Dinic.md
    document_title: Dinic
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/Dinic.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Dinic\n * @docs docs/flow/Dinic.md\n */\n\n#pragma once\n\n\
    #include \"../base.hpp\"\n\ntemplate<typename T,bool directed>\nstruct Dinic{\n\
    \    struct edge{\n        int to,rev; T cap;\n        edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}\n\
    \    };\n    vector<vector<edge>> G;\n    vector<pair<int,int>> pos;\n    vector<int>\
    \ level,iter;\n    Dinic(int n):G(n),level(n),iter(n){}\n    int add_edge(int\
    \ from,int to,T cap){\n        pos.emplace_back(from,G[from].size());\n      \
    \  G[from].emplace_back(to,cap,G[to].size());\n        G[to].emplace_back(from,directed?0:cap,G[from].size()-1);\n\
    \        return pos.size()-1;\n    }\n    int add_vertex(){\n        G.emplace_back();\n\
    \        level.emplace_back();\n        iter.emplace_back();\n        return G.size()-1;\n\
    \    }\n    tuple<int,int,int,int> get_edge(int i){\n        auto e=G[pos[i].first][pos[i].second];\n\
    \        auto re=G[e.to][e.rev];\n        return {pos[i].first,e.to,e.cap+re.cap,re.cap};\n\
    \    }\n    vector<tuple<int,int,int,int>> edges(){\n        vector<tuple<int,int,int,int>>\
    \ res;\n        for (int i=0;i<pos.size();++i){\n            res.emplace_back(get_edge(i));\n\
    \        }\n        return res;\n    }\n    void change_edge(int i,T new_cap,T\
    \ new_flow){\n        auto &e=G[pos[i].first][pos[i].second];\n        auto &re=G[e.to][e.rev];\n\
    \        e.cap=new_cap-new_flow;\n        re.cap=(directed?new_flow:new_cap+new_flow);\n\
    \    }\n    void bfs(int s){\n        fill(level.begin(),level.end(),-1);\n  \
    \      queue<int> que;\n        level[s]=0; que.emplace(s);\n        while(!que.empty()){\n\
    \            int v=que.front(); que.pop();\n            for (auto &e:G[v]){\n\
    \                if (e.cap>0&&level[e.to]<0){\n                    level[e.to]=level[v]+1;\n\
    \                    que.emplace(e.to);\n                }\n            }\n  \
    \      }\n    }\n    T dfs(int v,int t,T f){\n        if (v==t) return f;\n  \
    \      for (int &i=iter[v];i<G[v].size();++i){\n            auto &e=G[v][i];\n\
    \            if (e.cap>0&&level[v]<level[e.to]){\n                T d=dfs(e.to,t,min(f,e.cap));\n\
    \                if (d<=0) continue;\n                e.cap-=d;\n            \
    \    G[e.to][e.rev].cap+=d;\n                return d;\n            }\n      \
    \  }\n        return 0;\n    }\n    T max_flow(int s,int t,T lim){\n        T\
    \ flow=0;\n        while(lim>0){\n            bfs(s);\n            if (level[t]<0)\
    \ break;\n            fill(iter.begin(),iter.end(),0);\n            while(lim>0){\n\
    \                T f=dfs(s,t,lim);\n                if (f==0) break;\n       \
    \         flow+=f; lim-=f;\n            }\n        }\n        return flow;\n \
    \   }\n    T max_flow(int s,int t){\n        return max_flow(s,t,numeric_limits<T>::max());\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/Dinic.hpp
  requiredBy: []
  timestamp: '2020-09-19 17:20:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.DInic.test.cpp
  - test/aoj/2313.test.cpp
documentation_of: flow/Dinic.hpp
layout: document
redirect_from:
- /library/flow/Dinic.hpp
- /library/flow/Dinic.hpp.html
title: Dinic
---
## 概要

## 計算量