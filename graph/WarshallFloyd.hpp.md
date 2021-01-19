---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/WarshallFloyd.md
    document_title: Warshall Floyd
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/WarshallFloyd.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Warshall Floyd\n * @docs docs/graph/WarshallFloyd.md\n */\n\
    \n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvoid Warshall_Floyd(vector<vector<T>>\
    \ &d,T id){\n    int n=d.size();\n    for (int k=0;k<n;++k){\n        for (int\
    \ i=0;i<n;++i){\n            for (int j=0;j<n;++j){\n                if (d[i][k]==id||d[k][j]==id)\
    \ continue;\n                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);\n         \
    \   }\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
documentation_of: graph/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/graph/WarshallFloyd.hpp
- /library/graph/WarshallFloyd.hpp.html
title: Warshall Floyd
---
## 概要

## 計算量