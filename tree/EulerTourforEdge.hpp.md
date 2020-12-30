---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/EulerTourforEdge.md
    document_title: "Euler Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/EulerTourforEdge.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Euler Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C\
    )\n * @docs docs/tree/EulerTourforEdge.md\n */\n\n#pragma once\n\n#include \"\
    ../base.hpp\"\n\nclass EulerTourforEdge{\n    vector<int> ds,us,dep,btm;\n   \
    \ void dfs(int v,int p,int d){\n        dep[v]=d;\n        for (int u:G[v]){\n\
    \            if (u==p) continue;\n            ds[u]=btm.size();\n            btm.emplace_back(u);\n\
    \            dfs(u,v,d+1);\n            us[u]=btm.size();\n            btm.emplace_back(u);\n\
    \        }\n    }\n\npublic:\n    vector<vector<int>> G;\n    EulerTourforEdge(int\
    \ n):\n        ds(n),us(n),dep(n),G(n){}\n    void add_edge(int u,int v){\n  \
    \      G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n    void build(int\
    \ r=0){\n        btm.clear();\n        ds[r]=btm.size(); btm.emplace_back(r);\n\
    \        dfs(r,-1,0);\n        us[r]=btm.size(); btm.emplace_back(r);\n    }\n\
    \    int child(int u,int v){\n        return dep[u]<dep[v]?v:u;\n    }\n    int\
    \ bottom(int e){\n        return btm[e];\n    }\n    template<typename T,typename\
    \ F>\n    T query(int v,F f){\n        return f(0,us[v]);\n    }\n    // u or\
    \ v must be lca(u,v)\n    template<typename T,typename F>\n    T query(int u,int\
    \ v,F f){\n        if (dep[u]<dep[v]) swap(u,v);\n        return query<T>(u,f)-query<T>(v,f);\n\
    \    }\n    // v is child of the edge\n    template<typename T,typename G>\n \
    \   void update(int v,T x,G g){\n        g(ds[v],x);\n        g(us[v],-x);\n \
    \   }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/EulerTourforEdge.hpp
  requiredBy: []
  timestamp: '2020-12-17 21:12:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_D.test.cpp
documentation_of: tree/EulerTourforEdge.hpp
layout: document
redirect_from:
- /library/tree/EulerTourforEdge.hpp
- /library/tree/EulerTourforEdge.hpp.html
title: "Euler Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)"
---
## 概要

## 計算量