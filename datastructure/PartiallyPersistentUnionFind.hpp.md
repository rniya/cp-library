---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/agc002_d.cpp
    title: test/atcoder/agc002_d.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/datastructure/PartiallyPersistentUnionFind.md
    document_title: Partially Persistent UnionFind
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/PartiallyPersistentUnionFind.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\n * @brief Partially Persistent UnionFind\n * @docs docs/datastructure/PartiallyPersistentUnionFind.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct PartiallyPersistentUnionFind{\n\
    \    const int inf=numeric_limits<int>::max()/2;\n    int now,num;\n    vector<int>\
    \ par,time;\n    vector<vector<pair<int,int>>> Size;\n    PartiallyPersistentUnionFind(int\
    \ n):\n        now(0),num(n),par(n,-1),Size(n),time(n,inf){\n        for (int\
    \ i=0;i<n;++i) Size[i].emplace_back(0,-1);\n    }\n    int root(int t,int x){\n\
    \        if (t<time[x]) return x;\n        return root(t,par[x]);\n    }\n   \
    \ int merge(int x,int y){\n        ++now;\n        x=root(now,x),y=root(now,y);\n\
    \        if (x==y) return 0;\n        if (par[x]>par[y]) swap(x,y);\n        par[x]+=par[y];\n\
    \        par[y]=x;\n        time[y]=now;\n        Size[x].emplace_back(now,par[x]);\n\
    \        --num;\n        return now;\n    }\n    bool same(int t,int x,int y){return\
    \ root(t,x)==root(t,y);}\n    int size(int t,int x){\n        x=root(t,x);\n \
    \       return -prev(lower_bound(Size[x].begin(),Size[x].end(),make_pair(t,0)))->second;\n\
    \    }\n    int count(){return num;}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/PartiallyPersistentUnionFind.hpp
  requiredBy:
  - test/atcoder/agc002_d.cpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/PartiallyPersistentUnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/PartiallyPersistentUnionFind.hpp
- /library/datastructure/PartiallyPersistentUnionFind.hpp.html
title: Partially Persistent UnionFind
---
## 概要

## 計算量