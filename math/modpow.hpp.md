---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u7E70\u308A\u8FD4\u30572\u4E57\u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/modpow.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u7E70\u308A\u8FD4\u30572\u4E57\u6CD5\n */\n\n#pragma once\n\
    \n#include \"../base.hpp\"\n\nlong long modpow(long long x,long long n,long long\
    \ mod){\n    long long res=1;\n    while (n>0){\n        if (n&1LL) res=res*x%mod;\n\
    \        x=x*x%mod; n>>=1LL;\n    }\n    return res;\n}\nlong long modinv(long\
    \ long x,long long p){\n    return modpow(x,p-2,p);\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/modpow.hpp
  requiredBy: []
  timestamp: '2020-09-13 02:46:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_B.test.cpp
documentation_of: math/modpow.hpp
layout: document
redirect_from:
- /library/math/modpow.hpp
- /library/math/modpow.hpp.html
title: "\u7E70\u308A\u8FD4\u30572\u4E57\u6CD5"
---
