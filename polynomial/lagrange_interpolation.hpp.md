---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/polynomial/lagrange_interpolation.md
    document_title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ polynomial/lagrange_interpolation.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\n * @docs\
    \ docs/polynomial/lagrange_interpolation.md\n */\n\n#pragma once\n\n#include \"\
    ../base.hpp\"\n\ntemplate<typename M>\nM lagrange_interpolation(vector<M> x,vector<M>\
    \ y,M T){\n    int n=x.size()-1;\n    M res=0;\n    for (int i=0;i<=n;++i){\n\
    \        M c=1;\n        for (int j=0;j<=n;++j){\n            if (i==j) continue;\n\
    \            (c*=T-x[j])/=x[i]-x[j];\n        }\n        res+=c*y[i];\n    }\n\
    \    return res;\n}\n\ntemplate<typename M>\nM lagrange_interpolation_arithmetic(vector<M>\
    \ &y,M T){\n    int n=y.size()-1;\n    if (T.v<=n) return y[T.v];\n    vector<M>\
    \ left(n+1,1),right(n+1,1),fac(n+1,1),finv(n+1,1);\n    for (int i=0;i<n;++i)\
    \ left[i+1]=left[i]*(T-i);\n    for (int i=n-1;i>=0;--i) right[i]=right[i+1]*(T-(i+1));\n\
    \    for (int i=1;i<=n;++i) fac[i]=fac[i-1]*i;\n    finv[n]=(M)1/fac[n];\n   \
    \ for (int i=n;i>0;--i) finv[i-1]=finv[i]*i;\n    M res=0;\n    for (int i=0;i<=n;++i){\n\
    \        M add=y[i]*left[i]*right[i]*finv[i]*finv[n-i];\n        if ((n-i)&1)\
    \ res-=add;\n        else res+=add;\n    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: polynomial/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/665.test.cpp
documentation_of: polynomial/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/polynomial/lagrange_interpolation.hpp
- /library/polynomial/lagrange_interpolation.hpp.html
title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
---
## 概要

## 計算量