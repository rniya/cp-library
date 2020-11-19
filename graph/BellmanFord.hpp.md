---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/abc061_d.cpp
    title: test/atcoder/abc061_d.cpp
  - icon: ':warning:'
    path: test/atcoder/abc137_e.cpp
    title: test/atcoder/abc137_e.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/BellmanFord.md
    document_title: Bellman Ford
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/BellmanFord.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Bellman Ford\n * @docs docs/graph/BellmanFord.md\n */\n\n\
    #pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nstruct BellmanFord{\n\
    \    const T inf=numeric_limits<T>::max();\n    struct edge{\n        int u,v;\
    \ T w;\n        edge(int u,int v,T w):u(u),v(v),w(w){}\n    };\n    int n;\n \
    \   vector<vector<int>> G;\n    vector<int> check,reach;\n    vector<edge> es;\n\
    \    BellmanFord(int n):n(n),G(n),check(n),reach(n,1){}\n    void add_edge(int\
    \ u,int v,T w){\n        es.emplace_back(u,v,w);\n        G[u].emplace_back(v);\n\
    \    }\n    vector<T> build(int s,int &neg_loop){\n        vector<T> d(n,inf);\n\
    \        d[s]=0;\n        for (int i=0;i<n;++i){\n            bool update=false;\n\
    \            for (auto e:es){\n                if (!reach[e.u]||!reach[e.v]||d[e.u]==inf)\
    \ continue;\n                if (d[e.u]+e.w<d[e.v]){\n                    d[e.v]=d[e.u]+e.w;\n\
    \                    update=true;\n                }\n            }\n        \
    \    if (!update) break;\n            if (i==n-1){neg_loop=1; return d;}\n   \
    \     }\n        neg_loop=0; return d;\n    }\n    void dfs(int v){\n        if\
    \ (check[v]) return;\n        check[v]=1;\n        for (int u:G[v]) dfs(u);\n\
    \    }\n    T shortest_path(int s,int t,int &neg_loop){\n        for (int i=0;i<n;++i){\n\
    \            fill(check.begin(),check.end(),0);\n            dfs(i);\n       \
    \     reach[i]=check[t];\n        }\n        return build(s,neg_loop)[t];\n  \
    \  }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/BellmanFord.hpp
  requiredBy:
  - test/atcoder/abc061_d.cpp
  - test/atcoder/abc137_e.cpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
documentation_of: graph/BellmanFord.hpp
layout: document
redirect_from:
- /library/graph/BellmanFord.hpp
- /library/graph/BellmanFord.hpp.html
title: Bellman Ford
---
## 概要

## 計算量