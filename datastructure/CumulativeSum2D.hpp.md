---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_5_B.test.cpp
    title: test/aoj/DSL_5_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/CumulativeSum2D.md
    document_title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/CumulativeSum2D.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n * @docs docs/datastructure/CumulativeSum2D.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nstruct\
    \ CumulativeSum2D{\n    vector<vector<T>> dat;\n    CumulativeSum2D(const vector<vector<T>>\
    \ &v){\n        int H=v.size(),W=v[0].size();\n        dat.assign(H+1,vector<T>(W+1,0));\n\
    \        for (int i=0;i<H;++i){\n            for (int j=0;j<W;++j){\n        \
    \        dat[i+1][j+1]=v[i][j];\n                dat[i+1][j+1]+=dat[i+1][j]+dat[i][j+1]-dat[i][j];\n\
    \            }\n        }\n    }\n    T query(int sx,int gx,int sy,int gy){ //\
    \ [sx,gx),[sy,gy)\n        return dat[gx][gy]-dat[sx][gy]-dat[gx][sy]+dat[sx][sy];\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_5_B.test.cpp
documentation_of: datastructure/CumulativeSum2D.hpp
layout: document
redirect_from:
- /library/datastructure/CumulativeSum2D.hpp
- /library/datastructure/CumulativeSum2D.hpp.html
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
## 概要

## 計算量