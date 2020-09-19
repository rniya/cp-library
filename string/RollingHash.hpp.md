---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/string/RollingHash.md
    document_title: Rolling Hash
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/RollingHash.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Rolling Hash\n * @docs docs/string/RollingHash.md\n */\n\n\
    #pragma once\n\n#include \"../base.hpp\"\n\nstruct RollingHash{\n    static const\
    \ int B1=1007,B2=2009;\n    static const int mod1=1000000007,mod2=1000000009;\n\
    \    vector<long long> hash1,hash2,po1,po2;\n    RollingHash(const vector<long\
    \ long> &vs){init(vs);}\n    RollingHash(const string &S){\n        vector<long\
    \ long> vs;\n        for (char c:S) vs.emplace_back(c);\n        init(vs);\n \
    \   }\n    void init(vector<long long> vs){\n        int n=vs.size();\n      \
    \  hash1.assign(n+1,0);\n        hash2.assign(n+1,0);\n        po1.assign(n+1,1);\n\
    \        po2.assign(n+1,1);\n        for (int i=0;i<n;++i){\n            hash1[i+1]=(hash1[i]*B1+vs[i])%mod1;\n\
    \            hash2[i+1]=(hash2[i]*B2+vs[i])%mod2;\n            po1[i+1]=po1[i]*B1%mod1;\n\
    \            po2[i+1]=po2[i]*B2%mod2;\n        }\n    }\n    inline pair<long\
    \ long,long long> get(int l,int r) const {\n        long long res1=hash1[r]+mod1-hash1[l]*po1[r-l]%mod1\n\
    \                ,res2=hash2[r]+mod2-hash2[l]*po2[r-l]%mod2;\n        return {res1>=mod1?res1-mod1:res1,res2>=mod2?res2-mod2:res2};\n\
    \    }\n    inline int lcp(int a,int b) const {\n        int len=min((int)hash1.size()-a,(int)hash1.size()-b);\n\
    \        int lb=0,ub=len;\n        while(ub-lb>1){\n            int mid=(lb+ub)>>1;\n\
    \            (get(a,a+mid)==get(b,b+mid)?lb:ub)=mid;\n        }\n        return\
    \ lb;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2020-09-11 16:00:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.test.cpp
documentation_of: string/RollingHash.hpp
layout: document
redirect_from:
- /library/string/RollingHash.hpp
- /library/string/RollingHash.hpp.html
title: Rolling Hash
---
## 概要

## 計算量