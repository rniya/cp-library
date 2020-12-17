---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/UnionFind.md
    document_title: UnionFind
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/UnionFind.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief UnionFind\n * @docs docs/datastructure/UnionFind.md\n */\n\
    \n#pragma once\n#include \"../base.hpp\"\n\nstruct UnionFind{\n    int num;\n\
    \    vector<int> par,rank;\n    UnionFind(int n):num(n),par(n),rank(n,1){\n  \
    \      iota(par.begin(),par.end(),0);\n    }\n    int root(int x){\n        return\
    \ (par[x]==x?x:par[x]=root(par[x]));\n    }\n    bool merge(int x, int y){\n \
    \       x=root(x); y=root(y);\n        if (x==y) return false;\n        if (rank[x]<rank[y])\
    \ swap(x,y);\n        par[y]=x;\n        rank[x]+=rank[y];\n        --num;\n \
    \       return true;\n    }\n    bool same(int x, int y){return root(x)==root(y);}\n\
    \    int size(int x){return rank[root(x)];}\n    int count(){return num;}\n  \
    \  int operator[](int x){return root(x);}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2020-11-27 23:15:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind.test.cpp
  - test/aoj/DSL_1_A.test.cpp
documentation_of: datastructure/UnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/UnionFind.hpp
- /library/datastructure/UnionFind.hpp.html
title: UnionFind
---
## 概要

## 計算量