---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/LowLink.md
    document_title: "Low Link (\u6A4B/\u95A2\u7BC0\u70B9)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/LowLink.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Low Link (\u6A4B/\u95A2\u7BC0\u70B9)\n * @docs docs/graph/LowLink.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct LowLink{\n    int n,time;\n\
    \    vector<int> ord,low;\n    vector<vector<int>> G;\n    vector<int> articulation;\n\
    \    vector<pair<int,int>> bridge;\n    LowLink(int n):n(n),time(0),ord(n,-1),low(n),G(n){}\n\
    \    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    bool is_bridge(int u,int v){\n        if (ord[u]>ord[v]) swap(u,v);\n\
    \        return ord[u]<low[v];\n    }\n    void dfs(int v,int p){\n        ord[v]=low[v]=time++;\n\
    \        bool is_articulation=false;\n        int cnt=0;\n        for (int u:G[v]){\n\
    \            if (u==p) continue;\n            if (~ord[u]){\n                low[v]=min(low[v],ord[u]);\n\
    \                continue;\n            }\n            ++cnt;\n            dfs(u,v);\n\
    \            low[v]=min(low[v],low[u]);\n            is_articulation|=(~p&&ord[v]<=low[u]);\n\
    \            if (is_bridge(v,u)) bridge.emplace_back(v,u);\n        }\n      \
    \  is_articulation|=(p<0&&cnt>1);\n        if (is_articulation) articulation.emplace_back(v);\n\
    \    }\n    void build(){\n        for (int v=0;v<n;++v){\n            if (ord[v]<0)\
    \ dfs(v,-1);\n        }\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/LowLink.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/GRL_3_A.test.cpp
documentation_of: graph/LowLink.hpp
layout: document
redirect_from:
- /library/graph/LowLink.hpp
- /library/graph/LowLink.hpp.html
title: "Low Link (\u6A4B/\u95A2\u7BC0\u70B9)"
---
## 概要

## 計算量