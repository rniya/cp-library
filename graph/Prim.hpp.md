---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.Prim.test.cpp
    title: test/aoj/GRL_2_A.Prim.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/Prim.md
    document_title: Prim
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/Prim.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Prim\n * @docs docs/graph/Prim.md\n */\n\n#pragma once\n\n\
    #include \"../base.hpp\"\n\ntemplate<typename T>\nstruct Prim{\n    using P=pair<T,int>;\n\
    \    int n;\n    vector<vector<pair<int,T>>> G;\n    vector<bool> used;\n    Prim(int\
    \ n):n(n),G(n),used(n,false){}\n    void add_edge(int u,int v,T c){\n        G[u].emplace_back(v,c);\n\
    \        G[v].emplace_back(u,c);\n    }\n    T build(){\n        T res=0;\n  \
    \      priority_queue<P,vector<P>,greater<P>> pq;\n        pq.emplace(0,0);\n\
    \        while(!pq.empty()){\n            P p=pq.top(); pq.pop();\n          \
    \  if (used[p.second]) continue;\n            used[p.second]=true;\n         \
    \   res+=p.first;\n            for (auto e:G[p.second]){\n                pq.emplace(e.second,e.first);\n\
    \            }\n        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/Prim.hpp
  requiredBy: []
  timestamp: '2020-09-10 12:32:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.Prim.test.cpp
documentation_of: graph/Prim.hpp
layout: document
redirect_from:
- /library/graph/Prim.hpp
- /library/graph/Prim.hpp.html
title: Prim
---
## 概要

## 計算量