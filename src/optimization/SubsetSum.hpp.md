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
  bundledCode: "#line 2 \"src/optimization/SubsetSum.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <vector>\n\nstd::vector<bool> SubsetSum1(const std::vector<int>&\
    \ a, int S) {  // O(N * S)\n    int n = a.size();\n    std::vector<int> dp(S +\
    \ 1, -1);\n    int m = (S >> 6) + 1;\n    std::vector<unsigned long long> A(m,\
    \ 0), B(m, 0);\n    A[0] = 1;\n\n    for (int i = 0; i < n; i++) {\n        int\
    \ x = a[i] >> 6, y = a[i] & 63;\n        for (int j = 0; j < m; j++) {\n     \
    \       if (j + x < m) B[j + x] |= (A[j] << y);\n            if (j + x + 1 < m\
    \ and y) B[j + x + 1] |= (A[j] >> (64 - y));\n        }\n        for (int j =\
    \ 0; j < m; j++) {\n            B[j] &= ~A[j];\n            A[j] |= B[j];\n  \
    \          while (B[j]) {\n                int k = __builtin_ctzll(B[j]);\n  \
    \              if ((j << 6) + k <= S) dp[(j << 6) + k] = i;\n                B[j]\
    \ &= ~(1ULL << k);\n            }\n        }\n    }\n\n    if (S > 0 and dp[S]\
    \ == -1) return {};\n    std::vector<bool> res(n, false);\n    while (S > 0) {\n\
    \        res[dp[S]] = true;\n        S -= a[dp[S]];\n    }\n    return res;\n\
    }\n\nstd::vector<int> SubsetSum2(const std::vector<int>& a, int S) {  // O(N *\
    \ max(a))\n    int n = a.size(), sum = std::accumulate(a.begin(), a.end(), 0);\n\
    \    if (S < 0 or sum < S) return {};\n    bool flip = (S * 2 < sum);\n    if\
    \ (flip) S = sum - S;\n\n    int l = 0;\n    while (l < n and S > 0) S -= a[l++];\n\
    \    int a_max = *std::max_element(a.begin(), a.end()), m = a_max * 2 + 1;\n \
    \   const int inf = 1 << 30;\n    std::vector<std::vector<int>> dp(n + 1);\n \
    \   for (int i = l; i <= n; i++) dp[i].assign(m, inf);\n    dp[l][a_max - S] =\
    \ 0;\n\n    for (int i = l; i <= n; i++) {\n        for (int k = m - 1; k >= 0;\
    \ k--) {\n            if (k > a_max) {\n                int r = l;\n         \
    \       if (i > l) r = std::min(r, dp[i - 1][k]);\n                for (int j\
    \ = dp[i][k]; j < r; j++) dp[i][k - a[j]] = std::min(dp[i][k - a[j]], j + 1);\n\
    \            }\n            if (i < n) {\n                dp[i + 1][k] = std::min(dp[i\
    \ + 1][k], dp[i][k]);\n                if (k < a_max) dp[i + 1][k + a[i]] = std::min(dp[i\
    \ + 1][k + a[i]], dp[i][k]);\n            }\n        }\n        if (dp[i][a_max]\
    \ == inf) continue;\n        std::vector<int> res(n);\n        std::fill(res.begin(),\
    \ res.begin() + l, 1);\n        for (int k = a_max;;) {\n            int j = dp[i][k];\n\
    \            if (j == 0 and i == l) break;\n            if (j != inf and j !=\
    \ 0 and k + a[j - 1] < m and dp[i][k + a[j - 1]] < j) {\n                k +=\
    \ a[j - 1];\n                res[j - 1] = 0;\n                continue;\n    \
    \        }\n            i--;\n            if (dp[i][k] != j) {\n             \
    \   k -= a[i];\n                res[i] = 1;\n            }\n        }\n\n    \
    \    if (flip) {\n            for (int& x : res) {\n                x ^= 1;\n\
    \            }\n        }\n        return res;\n    }\n    return {};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    \nstd::vector<bool> SubsetSum1(const std::vector<int>& a, int S) {  // O(N * S)\n\
    \    int n = a.size();\n    std::vector<int> dp(S + 1, -1);\n    int m = (S >>\
    \ 6) + 1;\n    std::vector<unsigned long long> A(m, 0), B(m, 0);\n    A[0] = 1;\n\
    \n    for (int i = 0; i < n; i++) {\n        int x = a[i] >> 6, y = a[i] & 63;\n\
    \        for (int j = 0; j < m; j++) {\n            if (j + x < m) B[j + x] |=\
    \ (A[j] << y);\n            if (j + x + 1 < m and y) B[j + x + 1] |= (A[j] >>\
    \ (64 - y));\n        }\n        for (int j = 0; j < m; j++) {\n            B[j]\
    \ &= ~A[j];\n            A[j] |= B[j];\n            while (B[j]) {\n         \
    \       int k = __builtin_ctzll(B[j]);\n                if ((j << 6) + k <= S)\
    \ dp[(j << 6) + k] = i;\n                B[j] &= ~(1ULL << k);\n            }\n\
    \        }\n    }\n\n    if (S > 0 and dp[S] == -1) return {};\n    std::vector<bool>\
    \ res(n, false);\n    while (S > 0) {\n        res[dp[S]] = true;\n        S -=\
    \ a[dp[S]];\n    }\n    return res;\n}\n\nstd::vector<int> SubsetSum2(const std::vector<int>&\
    \ a, int S) {  // O(N * max(a))\n    int n = a.size(), sum = std::accumulate(a.begin(),\
    \ a.end(), 0);\n    if (S < 0 or sum < S) return {};\n    bool flip = (S * 2 <\
    \ sum);\n    if (flip) S = sum - S;\n\n    int l = 0;\n    while (l < n and S\
    \ > 0) S -= a[l++];\n    int a_max = *std::max_element(a.begin(), a.end()), m\
    \ = a_max * 2 + 1;\n    const int inf = 1 << 30;\n    std::vector<std::vector<int>>\
    \ dp(n + 1);\n    for (int i = l; i <= n; i++) dp[i].assign(m, inf);\n    dp[l][a_max\
    \ - S] = 0;\n\n    for (int i = l; i <= n; i++) {\n        for (int k = m - 1;\
    \ k >= 0; k--) {\n            if (k > a_max) {\n                int r = l;\n \
    \               if (i > l) r = std::min(r, dp[i - 1][k]);\n                for\
    \ (int j = dp[i][k]; j < r; j++) dp[i][k - a[j]] = std::min(dp[i][k - a[j]], j\
    \ + 1);\n            }\n            if (i < n) {\n                dp[i + 1][k]\
    \ = std::min(dp[i + 1][k], dp[i][k]);\n                if (k < a_max) dp[i + 1][k\
    \ + a[i]] = std::min(dp[i + 1][k + a[i]], dp[i][k]);\n            }\n        }\n\
    \        if (dp[i][a_max] == inf) continue;\n        std::vector<int> res(n);\n\
    \        std::fill(res.begin(), res.begin() + l, 1);\n        for (int k = a_max;;)\
    \ {\n            int j = dp[i][k];\n            if (j == 0 and i == l) break;\n\
    \            if (j != inf and j != 0 and k + a[j - 1] < m and dp[i][k + a[j -\
    \ 1]] < j) {\n                k += a[j - 1];\n                res[j - 1] = 0;\n\
    \                continue;\n            }\n            i--;\n            if (dp[i][k]\
    \ != j) {\n                k -= a[i];\n                res[i] = 1;\n         \
    \   }\n        }\n\n        if (flip) {\n            for (int& x : res) {\n  \
    \              x ^= 1;\n            }\n        }\n        return res;\n    }\n\
    \    return {};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/optimization/SubsetSum.hpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/optimization/SubsetSum.hpp
layout: document
title: Subset Sum $\mathrm{O}(NS)$
---

## 概要
$N$ 個の整数 $a_0, a_1, \dots , a_{N - 1}$ と整数 $S$ について，$I \subseteq \{0, 1, \dots, N - 1\}$ で $\sum_{i \in I} a_i = S$ なるものの存在判定及び構成を

- 時間計算量 $O(NS)$ 及び空間計算量 $O(S)$ に 64 倍高速化を施して
- 時間・空間計算量 $O(N a_{\max})$

で行う．
前者は $S \sim a_{\max}$、後者は $S \sim Na_{\max}$ の際に実用的である．

## 出題例
- [Codeforces Round #207 (Div. 1) D. Bags and Coins](https://codeforces.com/contest/356/problem/D)
- [AtCoder Beginner Contest 221 G - Jumping sequence](https://atcoder.jp/contests/abc221/tasks/abc221_g)
