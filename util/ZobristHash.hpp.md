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
    document_title: Zobrist Hash
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ util/ZobristHash.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Zobrist Hash\n */\n\n#pragma once\n\n#include \"../base.hpp\"\
    \n\nvector<uint64_t> ZobristHash(int n){\n    random_device seed_gen;\n    mt19937_64\
    \ engine(seed_gen());\n    vector<uint64_t> base(n);\n    for (int i=0;i<n;++i)\
    \ base[i]=engine();\n    return base;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: util/ZobristHash.hpp
  requiredBy: []
  timestamp: '2020-09-22 22:16:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/ZobristHash.hpp
layout: document
redirect_from:
- /library/util/ZobristHash.hpp
- /library/util/ZobristHash.hpp.html
title: Zobrist Hash
---
