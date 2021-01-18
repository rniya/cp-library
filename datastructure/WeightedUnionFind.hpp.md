---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/WeightedUnionFind.md
    document_title: Weighted UnionFind
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/WeightedUnionFind.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Weighted UnionFind\n * @docs docs/datastructure/WeightedUnionFind.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename Abel>\n\
    struct WeightedUnionFind{\n    int num;\n    vector<int> par,rank;\n    vector<Abel>\
    \ diff_weight;\n    WeightedUnionFind(int n,Abel id=0):\n        num(n),par(n),rank(n,1),diff_weight(n,Abel(0)){\n\
    \        iota(par.begin(),par.end(),0);\n    }\n    int root(int x){\n       \
    \ if (x==par[x]) return x;\n        int t=root(par[x]);\n        diff_weight[x]+=diff_weight[par[x]];\n\
    \        return par[x]=t;\n    }\n    bool merge(int x,int y,Abel w){\n      \
    \  w+=weight(x),w-=weight(y);\n        x=root(x),y=root(y);\n        if (x==y)\
    \ return false;\n        if (rank[x]<rank[y]) swap(x,y),w=-w;\n        par[y]=x;\n\
    \        rank[x]+=rank[y];\n        diff_weight[y]=w;\n        --num;\n      \
    \  return true;\n    }\n    Abel weight(int x){\n        root(x);\n        return\
    \ diff_weight[x];\n    }\n    Abel diff(int x,int y){return weight(y)-weight(x);}\n\
    \    bool same(int x,int y){return root(x)==root(y);}\n    int size(int x){return\
    \ rank[root(x)];}\n    int count(){return num;}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_1_B.test.cpp
documentation_of: datastructure/WeightedUnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/WeightedUnionFind.hpp
- /library/datastructure/WeightedUnionFind.hpp.html
title: Weighted UnionFind
---
## 概要

## 計算量