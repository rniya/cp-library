---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/datastructure/SparseTable.md
    document_title: Sparse table
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SparseTable.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Sparse table\n * @docs docs/datastructure/SparseTable.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nstruct\
    \ SparseTable{\n    typedef function<T(T,T)> F;\n    vector<vector<T>> dat;\n\
    \    vector<int> lookup;\n    const F f;\n    SparseTable(F f):f(f){}\n    void\
    \ build(const vector<T> &v){\n        int n=v.size(),h=1;\n        while((1<<h)<=n)\
    \ ++h;\n        dat.assign(h,vector<T>(n));\n        lookup.assign(n+1,0);\n \
    \       for (int i=2;i<=n;++i) lookup[i]=lookup[i>>1]+1;\n        for (int j=0;j<n;++j)\
    \ dat[0][j]=v[j];\n        for (int i=1,mask=1;i<h;++i,mask<<=1){\n          \
    \  for (int j=0;j<n;++j){\n                dat[i][j]=f(dat[i-1][j],dat[i-1][min(j+mask,n-1)]);\n\
    \            }\n        }\n    }\n    T query(int a,int b){\n        int d=lookup[b-a];\n\
    \        return f(dat[d][a],dat[d][b-(1<<d)]);\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2020-09-09 23:15:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: datastructure/SparseTable.hpp
layout: document
redirect_from:
- /library/datastructure/SparseTable.hpp
- /library/datastructure/SparseTable.hpp.html
title: Sparse table
---
## 概要

## 計算量