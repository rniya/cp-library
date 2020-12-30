---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/Z_Algorithm.md
    document_title: Z-Algorithm
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/Z_Algorithm.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Z-Algorithm\n * @docs docs/string/Z_Algorithm.md\n */\n\n\
    #pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<int>\
    \ Z_Algorithm(const T &s){\n    int n=s.size();\n    vector<int> z(n);\n    z[0]=n;\n\
    \    for (int i=1,j=0;i<n;){\n        while(i+j<n&&s[j]==s[i+j]) ++j;\n      \
    \  z[i]=j;\n        if (j==0){++i; continue;}\n        int k=1;\n        while(i+k<n&&k+z[k]<j)\
    \ z[i+k]=z[k],++k;\n        i+=k; j-=k;\n    }\n    return z;\n}\n\ntemplate<typename\
    \ T>\nvector<int> LCP(const T &s,const T &t){\n    T u(s);\n    u.insert(u.begin(),t.begin(),t.end());\n\
    \    vector<int> z=Z_Algorithm(u);\n    for (int &i:z) i=min(i,(int)t.size());\n\
    \    return vector<int>(z.begin()+t.size(),z.end());\n}\n"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/Z_Algorithm.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/zalgorithm.test.cpp
documentation_of: string/Z_Algorithm.hpp
layout: document
redirect_from:
- /library/string/Z_Algorithm.hpp
- /library/string/Z_Algorithm.hpp.html
title: Z-Algorithm
---
