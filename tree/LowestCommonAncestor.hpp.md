---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/arc039_d.cpp
    title: test/atcoder/arc039_d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/LowestCommonAncestor.md
    document_title: Lowest Common Ancestor
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/LowestCommonAncestor.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Lowest Common Ancestor\n * @docs docs/tree/LowestCommonAncestor.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct LowestCommonAncestor{\n\
    \    int n,h;\n    vector<vector<int>> G,par;\n    vector<int> dep;\n    LowestCommonAncestor(int\
    \ n):n(n),G(n),dep(n){\n        h=1;\n        while((1<<h)<=n) ++h;\n        par.assign(h,vector<int>(n,-1));\n\
    \    }\n    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n     \
    \   G[v].emplace_back(u);\n    }\n    void dfs(int v,int p,int d){\n        par[0][v]=p;\n\
    \        dep[v]=d;\n        for (int u:G[v]){\n            if (u!=p) dfs(u,v,d+1);\n\
    \        }\n    }\n    void build(int r=0){\n        dfs(r,-1,0);\n        for\
    \ (int k=0;k<h-1;++k){\n            for (int v=0;v<n;++v){\n                if\
    \ (par[k][v]>=0){\n                    par[k+1][v]=par[k][par[k][v]];\n      \
    \          }\n            }\n        }\n    }\n    int lca(int u,int v){\n   \
    \     if (dep[u]>dep[v]) swap(u,v);\n        for (int k=0;k<h;++k){\n        \
    \    if ((dep[v]-dep[u])&1<<k){\n                v=par[k][v];\n            }\n\
    \        }\n        if (u==v) return u;\n        for (int k=h-1;k>=0;--k){\n \
    \           if (par[k][u]!=par[k][v]){\n                u=par[k][u]; v=par[k][v];\n\
    \            }\n        }\n        return par[0][u];\n    }\n    int distance(int\
    \ u,int v){\n        return dep[u]+dep[v]-dep[lca(u,v)]*2;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/LowestCommonAncestor.hpp
  requiredBy:
  - test/atcoder/arc039_d.cpp
  timestamp: '2020-09-09 23:15:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_C.test.cpp
  - test/yosupo/lca.test.cpp
documentation_of: tree/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/tree/LowestCommonAncestor.hpp
- /library/tree/LowestCommonAncestor.hpp.html
title: Lowest Common Ancestor
---
## 概要

## 計算量