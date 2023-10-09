---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/subset_convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_set_power_series.test.cpp
    title: test/yosupo/exp_of_set_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/exp_of_set_power_series.hpp\"\n#include <algorithm>\n\
    #line 1 \"src/math/subset_convolution.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <vector>\n\nnamespace internal {\n\ntemplate <typename T, int LIM> std::vector<std::array<T,\
    \ LIM + 1>> ranked_zeta(const std::vector<T>& a) {\n    int n = a.size(), len\
    \ = __builtin_ctz(n);\n    assert((n & (n - 1)) == 0);\n    std::vector<std::array<T,\
    \ LIM + 1>> res(n);\n    for (int i = 0; i < n; i++) res[i][__builtin_popcount(i)]\
    \ = a[i];\n    for (int step = 1; step < n; step <<= 1) {\n        for (int start\
    \ = 0; start < n; start += 2 * step) {\n            for (int i = start; i < start\
    \ + step; i++) {\n                for (int j = 0; j <= len; j++) {\n         \
    \           res[i | step][j] += res[i][j];\n                }\n            }\n\
    \        }\n    }\n    return res;\n}\n\ntemplate <typename T, int LIM> std::vector<T>\
    \ ranked_mobius(std::vector<std::array<T, LIM + 1>>& ranked) {\n    int n = ranked.size(),\
    \ len = __builtin_ctz(n);\n    assert((n & (n - 1)) == 0);\n    for (int step\
    \ = 1; step < n; step <<= 1) {\n        for (int start = 0; start < n; start +=\
    \ 2 * step) {\n            for (int i = start; i < start + step; i++) {\n    \
    \            for (int j = 0; j <= len; j++) {\n                    ranked[i |\
    \ step][j] -= ranked[i][j];\n                }\n            }\n        }\n   \
    \ }\n    std::vector<T> res(n);\n    for (int i = 0; i < n; i++) res[i] = ranked[i][__builtin_popcount(i)];\n\
    \    return res;\n}\n\n}  // namespace internal\n\ntemplate <typename T, int LIM\
    \ = 20>\nstd::vector<T> subset_convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    auto ra = internal::ranked_zeta<T, LIM>(a);\n    auto rb = internal::ranked_zeta<T,\
    \ LIM>(b);\n    int n = ra.size(), len = __builtin_ctz(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        auto &f = ra[i], &g = rb[i];\n        for (int j = len;\
    \ j >= 0; j--) {\n            T sum = 0;\n            for (int k = 0; k <= j;\
    \ k++) sum += f[k] * g[j - k];\n            f[j] = sum;\n        }\n    }\n  \
    \  return internal::ranked_mobius<T, LIM>(ra);\n}\n#line 3 \"src/math/exp_of_set_power_series.hpp\"\
    \n\ntemplate <typename T, int LIM = 20> std::vector<T> exp_of_set_power_series(std::vector<T>&\
    \ a) {\n    int n = __builtin_ctz(a.size());\n    assert(int(a.size()) == 1 <<\
    \ n and a[0] == T(0));\n    std::vector<T> res(1 << n);\n    res[0] = T(1);\n\
    \    for (int i = 0; i < n; i++) {\n        std::vector<T> f(begin(a) + (1 <<\
    \ i), begin(a) + (2 << i));\n        std::vector<T> g(begin(res), begin(res) +\
    \ (1 << i));\n        auto h = subset_convolution<T, LIM>(f, g);\n        std::copy(begin(h),\
    \ end(h), begin(res) + (1 << i));\n    }\n    return res;\n}\n"
  code: "#include <algorithm>\n#include \"subset_convolution.hpp\"\n\ntemplate <typename\
    \ T, int LIM = 20> std::vector<T> exp_of_set_power_series(std::vector<T>& a) {\n\
    \    int n = __builtin_ctz(a.size());\n    assert(int(a.size()) == 1 << n and\
    \ a[0] == T(0));\n    std::vector<T> res(1 << n);\n    res[0] = T(1);\n    for\
    \ (int i = 0; i < n; i++) {\n        std::vector<T> f(begin(a) + (1 << i), begin(a)\
    \ + (2 << i));\n        std::vector<T> g(begin(res), begin(res) + (1 << i));\n\
    \        auto h = subset_convolution<T, LIM>(f, g);\n        std::copy(begin(h),\
    \ end(h), begin(res) + (1 << i));\n    }\n    return res;\n}"
  dependsOn:
  - src/math/subset_convolution.hpp
  isVerificationFile: false
  path: src/math/exp_of_set_power_series.hpp
  requiredBy: []
  timestamp: '2023-10-09 19:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/exp_of_set_power_series.test.cpp
documentation_of: src/math/exp_of_set_power_series.hpp
layout: document
title: Exp of Set Power Series
---

## 概要

## 問題例
