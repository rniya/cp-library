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
  bundledCode: "#line 2 \"src/util/RandomNumberGenerator.hpp\"\n#include <chrono>\n\
    #include <random>\n#include <utility>\n#include <vector>\n\nstruct RandomNumberGenerator\
    \ {\n    std::mt19937 mt;\n\n    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    uint32_t operator()(uint32_t a, uint32_t b) {\n        std::uniform_int_distribution<uint32_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n\n    uint32_t operator()(uint32_t\
    \ b) { return (*this)(0, b); }\n\n    template <typename T> void shuffle(std::vector<T>&\
    \ v) {\n        for (int i = 0; i < int(v.size()); i++) std::swap(v[i], v[(*this)(0,\
    \ i + 1)]);\n    }\n};\n\nstruct RandomNumberGenerator64 {\n    std::mt19937_64\
    \ mt;\n\n    RandomNumberGenerator64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    uint64_t operator()(uint64_t a, uint64_t b) {\n        std::uniform_int_distribution<uint64_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n\n    uint64_t operator()(uint64_t\
    \ b) { return (*this)(0, b); }\n\n    template <typename T> void shuffle(std::vector<T>&\
    \ v) {\n        for (int i = 0; i < int(v.size()); i++) std::swap(v[i], v[(*this)(0,\
    \ i + 1)]);\n    }\n};\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\n#include <utility>\n\
    #include <vector>\n\nstruct RandomNumberGenerator {\n    std::mt19937 mt;\n\n\
    \    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    uint32_t operator()(uint32_t a, uint32_t b) {\n        std::uniform_int_distribution<uint32_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n\n    uint32_t operator()(uint32_t\
    \ b) { return (*this)(0, b); }\n\n    template <typename T> void shuffle(std::vector<T>&\
    \ v) {\n        for (int i = 0; i < int(v.size()); i++) std::swap(v[i], v[(*this)(0,\
    \ i + 1)]);\n    }\n};\n\nstruct RandomNumberGenerator64 {\n    std::mt19937_64\
    \ mt;\n\n    RandomNumberGenerator64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    uint64_t operator()(uint64_t a, uint64_t b) {\n        std::uniform_int_distribution<uint64_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n\n    uint64_t operator()(uint64_t\
    \ b) { return (*this)(0, b); }\n\n    template <typename T> void shuffle(std::vector<T>&\
    \ v) {\n        for (int i = 0; i < int(v.size()); i++) std::swap(v[i], v[(*this)(0,\
    \ i + 1)]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/util/RandomNumberGenerator.hpp
  requiredBy: []
  timestamp: '2023-12-18 21:46:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/util/RandomNumberGenerator.hpp
layout: document
title: Random Number Generator
---

## 概要
一様乱数を生成する.

## 参照
[Don't use rand(): a guide to random number generators in C++ - Codeforces](https://codeforces.com/blog/entry/61587)
