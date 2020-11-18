---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':x:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':x:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/graph/StronglyConnectedComponents.md
    document_title: Strongly Connected Components
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/StronglyConnectedComponents.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Strongly Connected Components\n * @docs docs/graph/StronglyConnectedComponents.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct StronglyConnectedComponents{\n\
    \    vector<vector<int>> G,rG,C,T;\n    vector<int> vs,cmp,used;\n    StronglyConnectedComponents(int\
    \ n):G(n),rG(n),cmp(n),used(n){}\n    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n\
    \        rG[v].emplace_back(u);\n    }\n    void dfs(int v){\n        used[v]=1;\n\
    \        for (int u:G[v]) if(!used[u]) dfs(u);\n        vs.emplace_back(v);\n\
    \    }\n    void rdfs(int v,int k){\n        used[v]=1;\n        cmp[v]=k;\n \
    \       C[k].emplace_back(v);\n        for (int u:rG[v]) if (!used[u]) rdfs(u,k);\n\
    \    }\n    int build(){\n        int n=G.size();\n        for (int i=0;i<n;++i)\
    \ if (!used[i]) dfs(i);\n        fill(used.begin(),used.end(),0);\n        int\
    \ k=0;\n        for (int i=n-1;i>=0;--i){\n            if (!used[vs[i]]){\n  \
    \              C.emplace_back(),T.emplace_back();\n                rdfs(vs[i],k++);\n\
    \            }\n        }\n        for (int v=0;v<n;++v){\n            for (int\
    \ u:G[v]){\n                if (cmp[v]!=cmp[u]){\n                    T[cmp[v]].emplace_back(cmp[u]);\n\
    \                }\n            }\n        }\n        for (int i=0;i<k;++i){\n\
    \            sort(T[i].begin(),T[i].end());\n            T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());\n\
    \        }\n        return k;\n    }\n    int operator[](int i) const{return cmp[i];}\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/StronglyConnectedComponents.hpp
  requiredBy:
  - graph/TwoSatisfiability.hpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_3_C.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
documentation_of: graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/graph/StronglyConnectedComponents.hpp
- /library/graph/StronglyConnectedComponents.hpp.html
title: Strongly Connected Components
---
## 概要

## 計算量