---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: '@docs/combinatorics/combination.md'
    document_title: combination
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/combination.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief combination\n * @docs @docs/combinatorics/combination.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<class M>\nstruct\
    \ Combination{\n    vector<M> _fac,_inv,_finv;\n    Combination(int n):_fac(n+1),_inv(n+1),_finv(n+1){\n\
    \        _fac[0]=_finv[n]=_inv[0]=1;\n        for (int i=1;i<=n;++i) _fac[i]=_fac[i-1]*i;\n\
    \        _finv[n]/=_fac[n];\n        for (int i=n-1;i>=0;--i) _finv[i]=_finv[i+1]*(i+1);\n\
    \        for (int i=1;i<=n;++i) _inv[i]=_finv[i]*_finv[i-1];\n    }\n    M fac(int\
    \ k) const {return _fac[k];}\n    M finv(int k) const {return _finv[k];}\n   \
    \ M inv(int k) const {return _inv[k];}\n    M P(int n,int r) const {\n       \
    \ if (n<0||r<0||n<r) return 0;\n        return _fac[n]*_finv[n-r];\n    }\n  \
    \  M C(int n,int r) const {\n        if (n<0||r<0||n<r) return 0;\n        return\
    \ _fac[n]*_finv[r]*_finv[n-r];\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: combinatorics/combination.hpp
  requiredBy: []
  timestamp: '2020-09-10 15:03:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: combinatorics/combination.hpp
layout: document
redirect_from:
- /library/combinatorics/combination.hpp
- /library/combinatorics/combination.hpp.html
title: combination
---
