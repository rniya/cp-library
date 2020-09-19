---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/datastructure/BinaryIndexedTree.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/BinaryIndexedTree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Binary Indexed Tree\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nstruct\
    \ BinaryIndexedTree{\n    int n;\n    vector<T> dat;\n    BinaryIndexedTree(int\
    \ n):n(n),dat(n+1,0){}\n    void add(int i,T x){\n        if (i==0) return;\n\
    \        for (;i<=dat.size();i+=(i&-i)) dat[i]+=x;\n    }\n    T sum(int i){ //[1,i]\n\
    \        T res=0;\n        for (;i>0;i-=(i&-i)) res+=dat[i];\n        return res;\n\
    \    }\n    T query(int l,int r){ //[l,r)\n        return sum(r-1)-sum(l-1);\n\
    \    }\n    int lower_bound(T x){\n        if (x<=0) return 0;\n        int lb=0,r=1;\n\
    \        while(r<n) r<<=1;\n        for (;r>0;r>>=1){\n            if (lb+r<=n&&dat[lb+r]<x){\n\
    \                x-=dat[lb+r]; lb+=r;\n            }\n        }\n        return\
    \ lb+1;\n    }\n    void add0(int i,T x){add(i+1,x);}\n    T sum0(int i){return\
    \ sum(i+1);}\n    T query0(int l,int r){return sum(r)-sum(l);}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2020-09-09 23:15:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_D.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: datastructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/datastructure/BinaryIndexedTree.hpp
- /library/datastructure/BinaryIndexedTree.hpp.html
title: Binary Indexed Tree
---
## 概要

## 計算量