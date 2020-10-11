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
    document_title: "\u7D04\u6570\u5217\u6319"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/divisor.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u7D04\u6570\u5217\u6319\n */\n\n#pragma once\n\n#include\
    \ \"../base.hpp\"\n\ntemplate<typename T> vector<T> divisor(T n){\n    vector<T>\
    \ res;\n    for (T i=1;i*i<=n;++i) if (n%i==0){\n        res.emplace_back(i);\n\
    \        if (i!=n/i) res.emplace_back(n/i);\n    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2020-09-10 15:03:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.hpp
layout: document
redirect_from:
- /library/math/divisor.hpp
- /library/math/divisor.hpp.html
title: "\u7D04\u6570\u5217\u6319"
---
