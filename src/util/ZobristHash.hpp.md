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
  bundledCode: "#line 1 \"src/util/ZobristHash.hpp\"\n#include <random>\n#include\
    \ <vector>\n\nstd::vector<uint64_t> ZobristHash(int n) {\n    std::random_device\
    \ seed_gen;\n    std::mt19937_64 engine(seed_gen());\n    std::vector<uint64_t>\
    \ base(n);\n    for (int i = 0; i < n; i++) base[i] = engine();\n    return base;\n\
    }\n"
  code: "#include <random>\n#include <vector>\n\nstd::vector<uint64_t> ZobristHash(int\
    \ n) {\n    std::random_device seed_gen;\n    std::mt19937_64 engine(seed_gen());\n\
    \    std::vector<uint64_t> base(n);\n    for (int i = 0; i < n; i++) base[i] =\
    \ engine();\n    return base;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/util/ZobristHash.hpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/util/ZobristHash.hpp
layout: document
redirect_from:
- /library/src/util/ZobristHash.hpp
- /library/src/util/ZobristHash.hpp.html
title: src/util/ZobristHash.hpp
---
