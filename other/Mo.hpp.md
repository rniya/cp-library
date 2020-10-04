---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/other/Mo.md
    document_title: Mo's Algorithm
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ other/Mo.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Mo's Algorithm\n * @docs docs/other/Mo.md\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n\nstruct Mo{\n    int sz;\n    vector<int>\
    \ left,right;\n    Mo(int n):sz((int)sqrt(n)){}\n    void insert(int l,int r){\n\
    \        left.emplace_back(l);\n        right.emplace_back(r);\n    }\n    template<typename\
    \ ADDL,typename ADDR,typename DELL,typename DELR,typename REM>\n    void build(const\
    \ ADDL &add_left,const ADDR &add_right,const DELL &del_left,const DELR &del_right,const\
    \ REM &rem){\n        int q=left.size();\n        vector<int> ord(q);\n      \
    \  iota(ord.begin(),ord.end(),0);\n        sort(ord.begin(),ord.end(),[&](int\
    \ a,int b){\n            return (left[a]/sz!=left[b]/sz?left[a]<left[b]:right[a]<right[b]);\n\
    \        });\n        int l=0,r=0;\n        for (int idx:ord){\n            while(l>left[idx])\
    \ add_left(--l);\n            while(r<right[idx]) add_right(r++);\n          \
    \  while(l<left[idx]) del_left(l++);\n            while(r>right[idx]) del_right(--r);\n\
    \            rem(idx);\n        }\n    }\n    template<typename ADD,typename DEL,typename\
    \ REM>\n    void build(const ADD &add,const DEL &del,const REM &rem){\n      \
    \  build(add,add,del,del,rem);\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: other/Mo.hpp
  requiredBy: []
  timestamp: '2020-09-15 13:26:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: other/Mo.hpp
layout: document
redirect_from:
- /library/other/Mo.hpp
- /library/other/Mo.hpp.html
title: Mo's Algorithm
---
## 概要

## 計算量