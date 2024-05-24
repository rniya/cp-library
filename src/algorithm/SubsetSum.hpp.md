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
  bundledCode: "#line 2 \"src/algorithm/SubsetSum.hpp\"\n#include <vector>\n\nstd::vector<bool>\
    \ SubsetSum(const std::vector<int>& a, int S) {\n    int n = a.size();\n    std::vector<int>\
    \ dp(S + 1, -1);\n    int m = (S >> 6) + 1;\n    std::vector<unsigned long long>\
    \ A(m, 0), B(m, 0);\n    A[0] = 1;\n\n    for (int i = 0; i < n; i++) {\n    \
    \    int x = a[i] >> 6, y = a[i] & 63;\n        for (int j = 0; j < m; j++) {\n\
    \            if (j + x < m) B[j + x] |= (A[j] << y);\n            if (j + x +\
    \ 1 < m and y) B[j + x + 1] |= (A[j] >> (64 - y));\n        }\n        for (int\
    \ j = 0; j < m; j++) {\n            B[j] &= ~A[j];\n            A[j] |= B[j];\n\
    \            while (B[j]) {\n                int k = __builtin_ctzll(B[j]);\n\
    \                if ((j << 6) + k <= S) dp[(j << 6) + k] = i;\n              \
    \  B[j] &= ~(1ULL << k);\n            }\n        }\n    }\n\n    if (S > 0 and\
    \ dp[S] == -1) return {};\n    std::vector<bool> res(n, false);\n    while (S\
    \ > 0) {\n        res[dp[S]] = true;\n        S -= a[dp[S]];\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include <vector>\n\nstd::vector<bool> SubsetSum(const std::vector<int>&\
    \ a, int S) {\n    int n = a.size();\n    std::vector<int> dp(S + 1, -1);\n  \
    \  int m = (S >> 6) + 1;\n    std::vector<unsigned long long> A(m, 0), B(m, 0);\n\
    \    A[0] = 1;\n\n    for (int i = 0; i < n; i++) {\n        int x = a[i] >> 6,\
    \ y = a[i] & 63;\n        for (int j = 0; j < m; j++) {\n            if (j + x\
    \ < m) B[j + x] |= (A[j] << y);\n            if (j + x + 1 < m and y) B[j + x\
    \ + 1] |= (A[j] >> (64 - y));\n        }\n        for (int j = 0; j < m; j++)\
    \ {\n            B[j] &= ~A[j];\n            A[j] |= B[j];\n            while\
    \ (B[j]) {\n                int k = __builtin_ctzll(B[j]);\n                if\
    \ ((j << 6) + k <= S) dp[(j << 6) + k] = i;\n                B[j] &= ~(1ULL <<\
    \ k);\n            }\n        }\n    }\n\n    if (S > 0 and dp[S] == -1) return\
    \ {};\n    std::vector<bool> res(n, false);\n    while (S > 0) {\n        res[dp[S]]\
    \ = true;\n        S -= a[dp[S]];\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/SubsetSum.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/SubsetSum.hpp
layout: document
title: Subset Sum $\mathrm{O}(NS)$
---

## 概要
$N$ 個の整数 $a_0, a_1, \dots , a_{N - 1}$ と整数 $S$ について，$I \subseteq \{0, 1, \dots, N - 1\}$ で $\sum_{i \in I} a_i = S$ なるものの存在判定及び構成を時間計算量 $O(NS)$ 及び空間計算量 $O(S)$ に 64 倍高速化を施して行う．
$S \sim a_{\max}$ の際に実用的である．

## 問題例
- [Codeforces Round #207 (Div. 1) D. Bags and Coins](https://codeforces.com/contest/356/problem/D)
