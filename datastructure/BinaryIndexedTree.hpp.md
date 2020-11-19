---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/BinaryIndexedTree.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/BinaryIndexedTree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Binary Indexed Tree\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nclass\
    \ BinaryIndexedTree{\n    T sum(int i){\n        T res=T();\n        for (;i>0;i-=(i&-i))\
    \ res+=dat[i];\n        return res;\n    }\npublic:\n    int n;\n    vector<T>\
    \ dat;\n    BinaryIndexedTree(int n):n(n+1),dat(n+1,0){}\n    void add(int i,const\
    \ T &x){\n        for (++i;i<=n;i+=(i&-i)) dat[i]+=x;\n    }\n    T query(int\
    \ l,int r){return sum(r)-sum(l);}\n    int lower_bound(T x) const {\n        if\
    \ (x<=0) return 0;\n        int pos=0,k=1;\n        while (k<n) k<<=1;\n     \
    \   for (;k>0;k>>=1){\n            if (pos+k<=n&&dat[pos+k]<x){\n            \
    \    x-=dat[pos+k]; pos+=k;\n            }\n        }\n        return pos;\n \
    \   }\n    int upper_bound(T x) const {return lower_bound(x+1);}\n    T operator[](int\
    \ i){return query(i,i+1);}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1270.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/GRL_5_D.test.cpp
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