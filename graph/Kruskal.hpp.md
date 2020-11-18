---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/Kruskal.md
    document_title: Kruskal
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/Kruskal.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Kruskal\n * @docs docs/graph/Kruskal.md\n */\n\n#pragma once\n\
    \n#include \"../base.hpp\"\n\ntemplate<typename T>\nstruct Kruskal{\nprivate:\n\
    \    struct edge{\n        int from,to,used,id; T cost;\n        edge(int from,int\
    \ to,T cost,int id):\n            from(from),to(to),cost(cost),id(id),used(0){}\n\
    \        bool operator<(const edge &e) const{\n            if (cost!=e.cost) return\
    \ cost<e.cost;\n            else if (from!=e.from) return from<e.from;\n     \
    \       else return to<e.to;\n        }\n    };\n    vector<edge> es;\n    vector<int>\
    \ par,rank;\n    int root(int x){\n        if (par[x]==x) return x;\n        return\
    \ par[x]=root(par[x]);\n    }\n    bool merge(int x, int y){\n        x=root(x),y=root(y);\n\
    \        if (x==y) return false;\n        if (rank[x]<rank[y]) swap(x,y);\n  \
    \      par[y]=x;\n        rank[x]+=rank[y];\n        return true;\n    }\n   \
    \ bool same(int x, int y){return root(x)==root(y);}\n    int size(int x){return\
    \ rank[root(x)];}\npublic:\n    Kruskal(int n):par(n),rank(n,1){\n        iota(par.begin(),par.end(),0);\n\
    \    }\n    void add_edge(int u,int v,T c,int id=0){\n        es.emplace_back(u,v,c,id);\n\
    \    }\n    T build(){\n        sort(es.begin(),es.end());\n        T res=0;\n\
    \        for (auto &e:es){\n            if (!same(e.from,e.to)){\n           \
    \     res+=e.cost; e.used=1;\n                merge(e.from,e.to);\n          \
    \  }\n        }\n        return res;\n    }\n    vector<int> restore(T &c){\n\
    \        int m=es.size();\n        vector<int> res(m);\n        for (int i=0;i<m;++i)\
    \ res[es[i].id]=es[i].used;\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
documentation_of: graph/Kruskal.hpp
layout: document
redirect_from:
- /library/graph/Kruskal.hpp
- /library/graph/Kruskal.hpp.html
title: Kruskal
---
## 概要

## 計算量