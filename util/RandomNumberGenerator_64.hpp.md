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
  bundledCode: "#line 1 \"util/RandomNumberGenerator_64.hpp\"\n#include <chrono>\n\
    #include <random>\n\nstruct RandomNumberGenerator {\n    std::mt19937_64 mt;\n\
    \    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    uint64_t operator()(uint64_t a, uint64_t b) {\n        std::uniform_int_distribution<uint64_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    uint64_t operator()(uint64_t\
    \ b) { return (*this)(0, b); }\n};\n"
  code: "#include <chrono>\n#include <random>\n\nstruct RandomNumberGenerator {\n\
    \    std::mt19937_64 mt;\n    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    uint64_t operator()(uint64_t a, uint64_t b) {\n        std::uniform_int_distribution<uint64_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    uint64_t operator()(uint64_t\
    \ b) { return (*this)(0, b); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/RandomNumberGenerator_64.hpp
  requiredBy: []
  timestamp: '2022-11-10 02:48:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/RandomNumberGenerator_64.hpp
layout: document
redirect_from:
- /library/util/RandomNumberGenerator_64.hpp
- /library/util/RandomNumberGenerator_64.hpp.html
title: util/RandomNumberGenerator_64.hpp
---
