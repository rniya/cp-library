---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.test.cpp
    title: test/aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
    title: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
    title: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Heavy Light Decomposition
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/HeavyLightDecomposition.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Heavy Light Decomposition\n * @docsdocs/tree/HeavyLightDecomposition.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nclass HeavyLightDecomposition{\n\
    \    void dfs_sz(int v){\n        if (G[v].size()&&G[v][0]==par[v]) swap(G[v][0],G[v].back());\n\
    \        for (int &u:G[v]){\n            if (u==par[v]) continue;\n          \
    \  par[u]=v; dep[u]=dep[v]+1;\n            dfs_sz(u);\n            sub[v]+=sub[u];\n\
    \            if (sub[u]>sub[G[v][0]]) swap(u,G[v][0]);\n        }\n    }\n   \
    \ void dfs_hld(int v,int c,int &times){\n        vid[v]=times++; type[v]=c;\n\
    \        for (int u:G[v]){\n            if (u==par[v]) continue;\n           \
    \ head[u]=(u==G[v][0]?head[v]:u);\n            dfs_hld(u,c,times);\n        }\n\
    \    }\npublic:\n    vector<vector<int>> G;\n    vector<int> vid,head,sub,par,dep,type;\n\
    \    HeavyLightDecomposition(int n):\n        G(n),vid(n,-1),head(n),sub(n,1),par(n,-1),dep(n,0),type(n){}\n\
    \    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    void build(vector<int> rs={0}){\n        int c=0,times=0;\n      \
    \  for (int r:rs){\n            dfs_sz(r);\n            head[r]=r;\n         \
    \   dfs_hld(r,c++,times);\n        }\n    }\n    int lca(int u,int v){\n     \
    \   for (;;v=par[head[v]]){\n            if (vid[u]>vid[v]) swap(u,v);\n     \
    \       if (head[u]==head[v]) return u;\n        }\n    }\n    int distance(int\
    \ u,int v){\n        return dep[u]+dep[v]-2*dep[lca(u,v)];\n    }\n    template<typename\
    \ F>\n    void update_path(int u,int v,const F &f,bool edge=false){\n        for\
    \ (;;v=par[head[v]]){\n            if (vid[u]>vid[v]) swap(u,v);\n           \
    \ if (head[u]==head[v]) break;\n            f(vid[head[v]],vid[v]+1);\n      \
    \  }\n        f(vid[u]+edge,vid[v]+1);\n    }\n    template<typename F>\n    void\
    \ update_sub(int u,const F &f,bool edge=false){\n        f(vid[u]+edge,vid[u]+sub[u]);\n\
    \    }\n    template<typename T,typename Q,typename F>\n    T query(int u,int\
    \ v,const T &id,const Q &q,const F &f,bool edge=false){\n        T l=id,r=id;\n\
    \        for (;;v=par[head[v]]){\n            if (vid[u]>vid[v]) swap(u,v),swap(l,r);\n\
    \            if (head[u]==head[v]) break;\n            l=f(l,q(vid[head[v]],vid[v]+1));\n\
    \        }\n        return f(r,f(l,q(vid[u]+edge,vid[v]+1)));\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2667.test.cpp
  - test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  - test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
documentation_of: tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/tree/HeavyLightDecomposition.hpp
- /library/tree/HeavyLightDecomposition.hpp.html
title: Heavy Light Decomposition
---
