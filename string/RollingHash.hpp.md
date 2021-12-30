---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/RollingHash.hpp\"\n#include <cassert>\n#include <chrono>\n\
    #include <random>\n#include <string>\n#include <vector>\n\nstruct RollingHash\
    \ {\n    static inline uint64_t generate_base() {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(2, RollingHash::mod - 1);\n\
    \        return rand(mt);\n    }\n\n    RollingHash(uint64_t base = generate_base())\
    \ : base(base), power{1} {}\n\n    template <typename T> std::vector<uint64_t>\
    \ build(const T& s) const {\n        int n = s.size();\n        std::vector<uint64_t>\
    \ hash(n + 1);\n        hash[0] = 0;\n        for (int i = 0; i < n; i++) hash[i\
    \ + 1] = add(mul(hash[i], base), s[i]);\n        return hash;\n    }\n\n    template\
    \ <typename T> uint64_t get(const T& s) const {\n        uint64_t res = 0;\n \
    \       for (const auto& x : s) res = add(mul(res, base), x);\n        return\
    \ res;\n    }\n\n    uint64_t query(const std::vector<uint64_t>& hash, int l,\
    \ int r) {\n        assert(0 <= l && l <= r);\n        extend(r - l);\n      \
    \  return add(hash[r], mod - mul(hash[l], power[r - l]));\n    }\n\n    uint64_t\
    \ combine(uint64_t h1, uint64_t h2, size_t h2_len) {\n        extend(h2_len);\n\
    \        return add(mul(h1, power[h2_len]), h2);\n    }\n\n    int lcp(const std::vector<uint64_t>&\
    \ a, int l1, int r1, const std::vector<uint64_t>& b, int l2, int r2) {\n     \
    \   int len = std::min(r1 - l1, r2 - l2);\n        int lb = 0, ub = len + 1;\n\
    \        while (ub - lb > 1) {\n            int mid = (lb + ub) >> 1;\n      \
    \      (query(a, l1, l1 + mid) == query(b, l2, l2 + mid) ? lb : ub) = mid;\n \
    \       }\n        return lb;\n    }\n\nprivate:\n    static constexpr uint64_t\
    \ mod = (1ULL << 61) - 1;\n    const uint64_t base;\n    std::vector<uint64_t>\
    \ power;\n\n    static inline uint64_t add(uint64_t a, uint64_t b) {\n       \
    \ if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static inline\
    \ uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t c = (__uint128_t)a\
    \ * b;\n        return add(c >> 61, c & mod);\n    }\n\n    inline void extend(size_t\
    \ len) {\n        if (power.size() > len) return;\n        size_t pre = power.size();\n\
    \        power.resize(len + 1);\n        for (size_t i = pre - 1; i < len; i++)\
    \ power[i + 1] = mul(power[i], base);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <chrono>\n#include <random>\n\
    #include <string>\n#include <vector>\n\nstruct RollingHash {\n    static inline\
    \ uint64_t generate_base() {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(2, RollingHash::mod - 1);\n\
    \        return rand(mt);\n    }\n\n    RollingHash(uint64_t base = generate_base())\
    \ : base(base), power{1} {}\n\n    template <typename T> std::vector<uint64_t>\
    \ build(const T& s) const {\n        int n = s.size();\n        std::vector<uint64_t>\
    \ hash(n + 1);\n        hash[0] = 0;\n        for (int i = 0; i < n; i++) hash[i\
    \ + 1] = add(mul(hash[i], base), s[i]);\n        return hash;\n    }\n\n    template\
    \ <typename T> uint64_t get(const T& s) const {\n        uint64_t res = 0;\n \
    \       for (const auto& x : s) res = add(mul(res, base), x);\n        return\
    \ res;\n    }\n\n    uint64_t query(const std::vector<uint64_t>& hash, int l,\
    \ int r) {\n        assert(0 <= l && l <= r);\n        extend(r - l);\n      \
    \  return add(hash[r], mod - mul(hash[l], power[r - l]));\n    }\n\n    uint64_t\
    \ combine(uint64_t h1, uint64_t h2, size_t h2_len) {\n        extend(h2_len);\n\
    \        return add(mul(h1, power[h2_len]), h2);\n    }\n\n    int lcp(const std::vector<uint64_t>&\
    \ a, int l1, int r1, const std::vector<uint64_t>& b, int l2, int r2) {\n     \
    \   int len = std::min(r1 - l1, r2 - l2);\n        int lb = 0, ub = len + 1;\n\
    \        while (ub - lb > 1) {\n            int mid = (lb + ub) >> 1;\n      \
    \      (query(a, l1, l1 + mid) == query(b, l2, l2 + mid) ? lb : ub) = mid;\n \
    \       }\n        return lb;\n    }\n\nprivate:\n    static constexpr uint64_t\
    \ mod = (1ULL << 61) - 1;\n    const uint64_t base;\n    std::vector<uint64_t>\
    \ power;\n\n    static inline uint64_t add(uint64_t a, uint64_t b) {\n       \
    \ if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static inline\
    \ uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t c = (__uint128_t)a\
    \ * b;\n        return add(c >> 61, c & mod);\n    }\n\n    inline void extend(size_t\
    \ len) {\n        if (power.size() > len) return;\n        size_t pre = power.size();\n\
    \        power.resize(len + 1);\n        for (size_t i = pre - 1; i < len; i++)\
    \ power[i + 1] = mul(power[i], base);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:27:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.test.cpp
  - test/yukicoder/430.test.cpp
documentation_of: string/RollingHash.hpp
layout: document
redirect_from:
- /library/string/RollingHash.hpp
- /library/string/RollingHash.hpp.html
title: string/RollingHash.hpp
---
