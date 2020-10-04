---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/tdpc_fibonacci.cpp
    title: test/atcoder/tdpc_fibonacci.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/polynomial/Kitamasa.md
    document_title: Kitamasa
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ polynomial/Kitamasa.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Kitamasa\n * @docs docs/polynomial/Kitamasa.md\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n\ntemplate<typename K>\nstruct Kitamasa{\n\
    \    int k;\n    vector<K> cs;\n    vector<vector<K>> pcs;\n    Kitamasa(const\
    \ vector<K> &C):cs(C),pcs(1),k(C.size()){\n        pcs[0].assign(2*k+1,K(0));\n\
    \        pcs[0][1]=K(1);\n    }\n    vector<K> merge(const vector<K> &xs,const\
    \ vector<K> &ys){\n        vector<K> zs(2*k+1,K(0));\n        for (int i=1;i<=k;++i)\n\
    \            for (int j=1;j<=k;++j)\n                zs[i+j]+=xs[i]*ys[j];\n \
    \       for (int i=2*k;i>k;zs[i--]=K(0))\n            for (int j=1;j<=k;++j)\n\
    \                zs[i-j]+=cs[k-j]*zs[i];\n        return zs;\n    }\n    //Be\
    \ careful n is 0-indexed\n    K calc(const vector<K> &A,long long n){\n      \
    \  vector<K> res(pcs[0]);\n        for (int i=0;n;++i,n>>=1){\n            if\
    \ ((int)pcs.size()<=i)\n                pcs.emplace_back(merge(pcs[i-1],pcs[i-1]));\n\
    \            if (~n&1) continue;\n            res=merge(res,pcs[i]);\n       \
    \ }\n        K ans=K(0);\n        for (int i=1;i<=k;++i) ans+=res[i]*A[i-1];\n\
    \        return ans;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: polynomial/Kitamasa.hpp
  requiredBy:
  - test/atcoder/tdpc_fibonacci.cpp
  timestamp: '2020-09-20 00:58:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: polynomial/Kitamasa.hpp
layout: document
redirect_from:
- /library/polynomial/Kitamasa.hpp
- /library/polynomial/Kitamasa.hpp.html
title: Kitamasa
---
## 概要

## 計算量