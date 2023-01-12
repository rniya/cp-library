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
  bundledCode: "#line 2 \"src/string/RollingHash2D.hpp\"\n#include <cassert>\n#include\
    \ <chrono>\n#include <random>\n#include <string>\n#include <vector>\n\nstruct\
    \ RollingHash2D {\n    static inline uint64_t generate_base() {\n        std::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n        std::uniform_int_distribution<uint64_t>\
    \ rand(2, RollingHash2D::mod - 1);\n        return rand(mt);\n    }\n\n    RollingHash2D(uint64_t\
    \ base0 = generate_base(), uint64_t base1 = generate_base()) {\n        basis[0]\
    \ = base0;\n        basis[1] = base1;\n        power[0].assign(1, 1);\n      \
    \  power[1].assign(1, 1);\n    }\n\n    template <typename T> std::vector<std::vector<uint64_t>>\
    \ build(const T& s) const {\n        int n = s.size(), m = s[0].size();\n    \
    \    std::vector<std::vector<uint64_t>> hash(n + 1, std::vector<uint64_t>(m +\
    \ 1, 0));\n        for (int i = 0; i < n; i++) {\n            for (int j = 0;\
    \ j < m; j++) {\n                hash[i + 1][j + 1] = add(sub(add(mul(hash[i][j\
    \ + 1], basis[0]), mul(hash[i + 1][j], basis[1])),\n                         \
    \                    mul(hash[i][j], mul(basis[0], basis[1]))),\n            \
    \                             s[i][j]);\n            }\n        }\n        return\
    \ hash;\n    }\n\n    template <typename T> uint64_t get(const T& s) const {\n\
    \        uint64_t res = 0;\n        for (size_t i = 0; i < s.size(); i++) {\n\
    \            uint64_t sum = 0;\n            for (const auto& x : s[i]) sum = add(mul(sum,\
    \ basis[1]), x);\n            res = add(mul(res, basis[0]), sum);\n        }\n\
    \        return res;\n    }\n\n    uint64_t query(const std::vector<std::vector<uint64_t>>&\
    \ hash, int xl, int xr, int yl, int yr) {\n        assert(0 <= xl and xl <= xr\
    \ and 0 <= yl and yl <= yr);\n        extend(0, xr - xl);\n        extend(1, yr\
    \ - yl);\n        return add(sub(sub(hash[xr][yr], mul(hash[xl][yr], power[0][xr\
    \ - xl])), mul(hash[xr][yl], power[1][yr - yl])),\n                   mul(hash[xl][yl],\
    \ mul(power[0][xr - xl], power[1][yr - yl])));\n    }\n\nprivate:\n    static\
    \ constexpr uint64_t mod = (1ULL << 61) - 1;\n    uint64_t basis[2];\n    std::vector<uint64_t>\
    \ power[2];\n\n    static inline uint64_t add(uint64_t a, uint64_t b) {\n    \
    \    if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static inline\
    \ uint64_t sub(uint64_t a, uint64_t b) { return b == 0 ? a : add(a, mod - b);\
    \ }\n\n    static inline uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t\
    \ c = (__uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n\n  \
    \  inline void extend(int x, size_t len) {\n        if (power[x].size() > len)\
    \ return;\n        size_t pre = power[x].size();\n        power[x].resize(len\
    \ + 1);\n        for (size_t i = pre - 1; i < len; i++) power[x][i + 1] = mul(power[x][i],\
    \ basis[x]);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <chrono>\n#include <random>\n\
    #include <string>\n#include <vector>\n\nstruct RollingHash2D {\n    static inline\
    \ uint64_t generate_base() {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(2, RollingHash2D::mod -\
    \ 1);\n        return rand(mt);\n    }\n\n    RollingHash2D(uint64_t base0 = generate_base(),\
    \ uint64_t base1 = generate_base()) {\n        basis[0] = base0;\n        basis[1]\
    \ = base1;\n        power[0].assign(1, 1);\n        power[1].assign(1, 1);\n \
    \   }\n\n    template <typename T> std::vector<std::vector<uint64_t>> build(const\
    \ T& s) const {\n        int n = s.size(), m = s[0].size();\n        std::vector<std::vector<uint64_t>>\
    \ hash(n + 1, std::vector<uint64_t>(m + 1, 0));\n        for (int i = 0; i < n;\
    \ i++) {\n            for (int j = 0; j < m; j++) {\n                hash[i +\
    \ 1][j + 1] = add(sub(add(mul(hash[i][j + 1], basis[0]), mul(hash[i + 1][j], basis[1])),\n\
    \                                             mul(hash[i][j], mul(basis[0], basis[1]))),\n\
    \                                         s[i][j]);\n            }\n        }\n\
    \        return hash;\n    }\n\n    template <typename T> uint64_t get(const T&\
    \ s) const {\n        uint64_t res = 0;\n        for (size_t i = 0; i < s.size();\
    \ i++) {\n            uint64_t sum = 0;\n            for (const auto& x : s[i])\
    \ sum = add(mul(sum, basis[1]), x);\n            res = add(mul(res, basis[0]),\
    \ sum);\n        }\n        return res;\n    }\n\n    uint64_t query(const std::vector<std::vector<uint64_t>>&\
    \ hash, int xl, int xr, int yl, int yr) {\n        assert(0 <= xl and xl <= xr\
    \ and 0 <= yl and yl <= yr);\n        extend(0, xr - xl);\n        extend(1, yr\
    \ - yl);\n        return add(sub(sub(hash[xr][yr], mul(hash[xl][yr], power[0][xr\
    \ - xl])), mul(hash[xr][yl], power[1][yr - yl])),\n                   mul(hash[xl][yl],\
    \ mul(power[0][xr - xl], power[1][yr - yl])));\n    }\n\nprivate:\n    static\
    \ constexpr uint64_t mod = (1ULL << 61) - 1;\n    uint64_t basis[2];\n    std::vector<uint64_t>\
    \ power[2];\n\n    static inline uint64_t add(uint64_t a, uint64_t b) {\n    \
    \    if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static inline\
    \ uint64_t sub(uint64_t a, uint64_t b) { return b == 0 ? a : add(a, mod - b);\
    \ }\n\n    static inline uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t\
    \ c = (__uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n\n  \
    \  inline void extend(int x, size_t len) {\n        if (power[x].size() > len)\
    \ return;\n        size_t pre = power[x].size();\n        power[x].resize(len\
    \ + 1);\n        for (size_t i = pre - 1; i < len; i++) power[x][i + 1] = mul(power[x][i],\
    \ basis[x]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/RollingHash2D.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/RollingHash2D.hpp
layout: document
title: Rolling Hash 2D
---

## 概要
