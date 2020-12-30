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
    _deprecated_at_docs: docs/util/RandomNumberGenerator.md
    document_title: "\u4E71\u6570\u751F\u6210\u5668(64bit)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ util/RandomNumberGenerator_64.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief \u4E71\u6570\u751F\u6210\u5668(64bit)\n * @docs docs/util/RandomNumberGenerator.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct RandomNumberGenerator{\n\
    \    mt19937_64 mt;\n    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    uint64_t operator()(uint64_t a,uint64_t b){\n        uniform_int_distribution<uint64_t>\
    \ dist(a,b-1);\n        return dist(mt);\n    }\n    uint64_t operator()(uint64_t\
    \ b){\n        return (*this)(0,b);\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: util/RandomNumberGenerator_64.hpp
  requiredBy: []
  timestamp: '2020-12-09 21:28:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/RandomNumberGenerator_64.hpp
layout: document
redirect_from:
- /library/util/RandomNumberGenerator_64.hpp
- /library/util/RandomNumberGenerator_64.hpp.html
title: "\u4E71\u6570\u751F\u6210\u5668(64bit)"
---
## 概要
一様乱数を生成する.

## 計算量
$O(1)$

## 参照
[Don't use rand(): a guide to random number generators in C++ - Codeforces](https://codeforces.com/blog/entry/61587)