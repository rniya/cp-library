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
    document_title: Zobrist Hash
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
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
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/ZobristHash.hpp
layout: document
redirect_from:
- /library/util/ZobristHash.hpp
- /library/util/ZobristHash.hpp.html
title: Zobrist Hash
---
