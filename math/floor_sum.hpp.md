---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_floor_of_linear.test.cpp
    title: test/yosupo/sum_of_floor_of_linear.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Sum of Floor of Linear
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/floor_sum.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Sum of Floor of Linear\n * docs docs/math/floor_sum.hpp\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nlong long floor_sum(long long\
    \ n,long long m,long long a,long long b){\n    long long ans=0;\n    if (a>=m){\n\
    \        ans+=(n-1)*n*(a/m)/2;\n        a%=m;\n    }\n    if (b>=m){\n       \
    \ ans+=n*(b/m);\n        b%=m;\n    }\n    long long y_max=(a*n+b)/m,x_max=y_max*m-b;\n\
    \    if (y_max==0) return ans;\n    ans+=(n-(x_max+a-1)/a)*y_max;\n    ans+=floor_sum(y_max,a,m,(a-x_max%a)%a);\n\
    \    return ans;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/floor_sum.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sum_of_floor_of_linear.test.cpp
documentation_of: math/floor_sum.hpp
layout: document
redirect_from:
- /library/math/floor_sum.hpp
- /library/math/floor_sum.hpp.html
title: Sum of Floor of Linear
---
