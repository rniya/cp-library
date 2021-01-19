---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ukuku09_d.cpp
    title: test/atcoder/ukuku09_d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_palindromes.test.cpp
    title: test/yosupo/enumerate_palindromes.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/Manacher.md
    document_title: Manacher
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/Manacher.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Manacher\n * @docs docs/string/Manacher.md\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n\nvector<int> Manacher(const string &s){\n\
    \    int n=s.size();\n    vector<int> res(n);\n    for (int i=0,j=0;i<n;){\n \
    \       while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) ++j;\n        res[i]=j;\n       \
    \ int k=1;\n        while(i-k>=0&&i+k<n&&k+res[i-k]<j) res[i+k]=res[i-k],++k;\n\
    \        i+=k,j-=k;\n    }\n    return res;\n}\n\nvector<int> PalindromeTable(const\
    \ string &s){\n    int n=s.size();\n    string t(n*2+1,'$');\n    for (int i=0;i<n;++i)\
    \ t[i*2+1]=s[i];\n    vector<int> v=Manacher(t),res;\n    for (int i=1;i<n*2;++i)\
    \ res.emplace_back(v[i]-1);\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/Manacher.hpp
  requiredBy:
  - test/atcoder/ukuku09_d.cpp
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_palindromes.test.cpp
documentation_of: string/Manacher.hpp
layout: document
redirect_from:
- /library/string/Manacher.hpp
- /library/string/Manacher.hpp.html
title: Manacher
---
## 概要

## 計算量