---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/is_prime.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u7D20\u6570\u5224\u5B9A\n */\n\n#pragma once\n\n#include\
    \ \"../base.hpp\"\n\ntemplate<typename T> bool is_prime(T n){\n    for (T i=2;i*i<=n;++i){\n\
    \        if (n%i==0) return false;\n    }\n    return 1<n;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy: []
  timestamp: '2020-09-10 15:03:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: "\u7D20\u6570\u5224\u5B9A"
---
