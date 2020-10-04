---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.test.cpp
    title: test/aoj/DSL_3_D.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/Slide_Min.md
    document_title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/Slide_Min.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n * @docs docs/datastructure/Slide_Min.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<T>\
    \ Slide_Min(const vector<T> &v,int k){\n    deque<int> deq;\n    vector<T> res;\n\
    \    for (int i=0;i<v.size();++i){\n        while(!deq.empty()&&v[deq.back()]>=v[i])\
    \ deq.pop_back();\n        deq.push_back(i);\n        if (i-k+1>=0){\n       \
    \     res.push_back(v[deq.front()]);\n            if (deq.front()==i-k+1) deq.pop_front();\n\
    \        }\n    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/Slide_Min.hpp
  requiredBy: []
  timestamp: '2020-09-09 23:15:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.test.cpp
documentation_of: datastructure/Slide_Min.hpp
layout: document
redirect_from:
- /library/datastructure/Slide_Min.hpp
- /library/datastructure/Slide_Min.hpp.html
title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---
## 概要

## 計算量