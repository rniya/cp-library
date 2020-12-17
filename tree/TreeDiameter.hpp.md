---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_B.test.cpp
    title: test/aoj/GRL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/TreeDiameter.md
    document_title: Tree Diameter
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/TreeDiameter.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Tree Diameter\n * @docs docs/tree/TreeDiameter.md\n */\n\n\
    #pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nstruct TreeDiameter{\n\
    \    vector<T> dp,par;\n    vector<vector<pair<int,T>>> G;\n    TreeDiameter(int\
    \ n):dp(n),par(n),G(n){}\n    void add_edge(int u,int v,T c){\n        G[u].emplace_back(v,c);\n\
    \        G[v].emplace_back(u,c);\n    }\n    void dfs(int v,int p,int &s){\n \
    \       par[v]=p;\n        if (p<0) dp[v]=T(0);\n        if (dp[s]<dp[v]) s=v;\n\
    \        for (auto e:G[v]){\n            int u=e.first;\n            if (u==p)\
    \ continue;\n            dp[u]=dp[v]+e.second;\n            dfs(u,v,s);\n    \
    \    }\n    }\n    pair<int,int> endPoints(){\n        int s=0;\n        dfs(s,-1,s);\n\
    \        int t=s;\n        dfs(t,-1,t);\n        return make_pair(s,t);\n    }\n\
    \    T build(){\n        int t=endPoints().second;\n        return dp[t];\n  \
    \  }\n    vector<int> restore(){\n        int t=endPoints().second;\n        vector<int>\
    \ res;\n        while(~t){\n            res.emplace_back(t);\n            t=par[t];\n\
    \        }\n        return res;\n    }\n    vector<T> distance(int v){\n     \
    \   dfs(v,-1,v);\n        return dp;\n    }\n    vector<T> farthest(){\n     \
    \   int t=endPoints().second;\n        auto ds=dp;\n        auto dt=distance(t);\n\
    \        for (int i=0;i<ds.size();++i) ds[i]=max(ds[i],dt[i]);\n        return\
    \ ds;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/TreeDiameter.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/tree_diameter.test.cpp
  - test/aoj/GRL_5_B.test.cpp
  - test/aoj/GRL_5_A.test.cpp
documentation_of: tree/TreeDiameter.hpp
layout: document
redirect_from:
- /library/tree/TreeDiameter.hpp
- /library/tree/TreeDiameter.hpp.html
title: Tree Diameter
---
## 概要

## 計算量