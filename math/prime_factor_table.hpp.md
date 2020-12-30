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
    _deprecated_at_docs: docs/math/prime_factor_table.md
    document_title: "osa_k\u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/prime_factor_table.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief osa_k\u6CD5\n * @docs docs/math/prime_factor_table.md\n */\n\
    \n#pragma once\n\n#include \"../base.hpp\"\n\nvector<int> prime_factor_table(int\
    \ n){\n    vector<int> res(n+1,0);\n    for (int i=2;i<=n;++i) if (!res[i]){\n\
    \        for (int j=i;j<=n;j+=i){\n            if (!res[j]) res[j]=i;\n      \
    \  }\n    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/prime_factor_table.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factor_table.hpp
layout: document
redirect_from:
- /library/math/prime_factor_table.hpp
- /library/math/prime_factor_table.hpp.html
title: "osa_k\u6CD5"
---
## 概要

## 計算量