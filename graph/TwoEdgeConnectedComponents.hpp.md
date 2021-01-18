---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/arc039_d.cpp
    title: test/atcoder/arc039_d.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/StronglyConnectedComponents.md
    document_title: Two Edge Connected Components
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/TwoEdgeConnectedComponents.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Two Edge Connected Components\n * @docs docs/graph/StronglyConnectedComponents.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct TwoEdgeConnectedComponents{\n\
    \    int time,k;\n    vector<int> ord,low,cmp;\n    vector<vector<int>> G,C,T;\n\
    \    vector<pair<int,int>> bridge;\n    TwoEdgeConnectedComponents(int n):\n \
    \       time(0),k(0),ord(n,-1),low(n),cmp(n,-1),G(n){}\n    void add_edge(int\
    \ u,int v){\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n  \
    \  }\n    bool is_bridge(int u,int v){\n        if (ord[u]>ord[v]) swap(u,v);\n\
    \        return ord[u]<low[v];\n    }\n    void dfs(int v,int p){\n        ord[v]=low[v]=time++;\n\
    \        int bic=0;\n        for (int u:G[v]){\n            if (u==p&&!bic){bic=1;\
    \ continue;}\n            if (~ord[u]){\n                low[v]=min(low[v],ord[u]);\n\
    \                continue;\n            }\n            dfs(u,v);\n           \
    \ low[v]=min(low[v],low[u]);\n            if (is_bridge(v,u)) bridge.emplace_back(v,u);\n\
    \        }\n    }\n    void fill_component(int v){\n        C[cmp[v]].emplace_back(v);\n\
    \        for (int u:G[v]){\n            if (~cmp[u]||is_bridge(u,v)) continue;\n\
    \            cmp[u]=cmp[v];\n            fill_component(u);\n        }\n    }\n\
    \    void add_component(int v){\n        if (~cmp[v]) return;\n        cmp[v]=k++;\n\
    \        C.emplace_back();\n        fill_component(v);\n    }\n    int build(){\n\
    \        int n=G.size();\n        for (int v=0;v<n;++v){\n            if (ord[v]<0)\
    \ dfs(v,-1);\n        }\n        for (int v=0;v<n;++v) add_component(v);\n   \
    \     T.resize(k);\n        for (auto e:bridge){\n            int u=cmp[e.first],v=cmp[e.second];\n\
    \            T[u].emplace_back(v);\n            T[v].emplace_back(u);\n      \
    \  }\n        return k;\n    }\n    int operator[](int i) const{return cmp[i];}\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/TwoEdgeConnectedComponents.hpp
  requiredBy:
  - test/atcoder/arc039_d.cpp
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: graph/TwoEdgeConnectedComponents.hpp
layout: document
redirect_from:
- /library/graph/TwoEdgeConnectedComponents.hpp
- /library/graph/TwoEdgeConnectedComponents.hpp.html
title: Two Edge Connected Components
---
## 概要

## 計算量