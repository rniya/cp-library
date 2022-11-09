---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/ZobristHash.hpp\"\n#include <random>\n#include <vector>\n\
    \nstd::vector<uint64_t> ZobristHash(int n) {\n    std::random_device seed_gen;\n\
    \    std::mt19937_64 engine(seed_gen());\n    std::vector<uint64_t> base(n);\n\
    \    for (int i = 0; i < n; i++) base[i] = engine();\n    return base;\n}\n"
  code: "#include <random>\n#include <vector>\n\nstd::vector<uint64_t> ZobristHash(int\
    \ n) {\n    std::random_device seed_gen;\n    std::mt19937_64 engine(seed_gen());\n\
    \    std::vector<uint64_t> base(n);\n    for (int i = 0; i < n; i++) base[i] =\
    \ engine();\n    return base;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: util/ZobristHash.hpp
  requiredBy: []
  timestamp: '2022-11-10 02:48:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/ZobristHash.hpp
layout: document
redirect_from:
- /library/util/ZobristHash.hpp
- /library/util/ZobristHash.hpp.html
title: util/ZobristHash.hpp
---
