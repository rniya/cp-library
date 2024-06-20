---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/binomial.hpp
    title: Binomial Coefficients
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
    title: test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../atcoder/convolution\"\n#include \"math/binomial.hpp\"\
    \n\ntemplate <typename T> T number_of_increasing_sequences_between_two_sequences(std::vector<int>\
    \ a, std::vector<int> b) {\n    assert(a.size() == b.size());\n    int n = a.size();\n\
    \    for (int i = 0; i < n; i++) b[i]--;\n    for (int i = 1; i < n; i++) a[i]\
    \ = std::max(a[i], a[i - 1]);\n    for (int i = n - 2; i >= 0; i--) b[i] = std::min(b[i],\
    \ b[i + 1]);\n    for (int i = 0; i < n; i++) {\n        if (a[i] > b[i]) {\n\
    \            return T(0);\n        }\n    }\n    int m = b[n - 1] + 1;\n    std::vector<int>\
    \ L(n + m, 0), U(n + m, m - 1);\n    U[0] = 0;\n    L[n + m - 1] = m - 1;\n  \
    \  for (int i = 0; i < n; i++) {\n        L[i + a[i]] = std::max(L[i + a[i]],\
    \ a[i]);\n        U[i + b[i] + 1] = std::min(U[i + b[i] + 1], b[i]);\n    }\n\
    \    n = L.size();\n    for (int i = 1; i < n; i++) L[i] = std::max(L[i], L[i\
    \ - 1]);\n    for (int i = n - 2; i >= 0; i--) L[i] = std::max(L[i], L[i + 1]\
    \ - 1);\n    for (int i = n - 2; i >= 0; i--) U[i] = std::min(U[i], U[i + 1]);\n\
    \    for (int i = 1; i < n; i++) U[i] = std::min(U[i], U[i - 1] + 1);\n    Binomial<T>\
    \ binom;\n    auto extract = [](const std::vector<T>& dp, int l, int r = -1) {\n\
    \        int len = dp.size();\n        if (l >= len) return std::vector<T>();\n\
    \        r = (r == -1 ? len : len < r ? len : r);\n        return std::vector<T>(dp.begin()\
    \ + l, dp.begin() + r);\n    };\n    auto go = [&](int l, int r, const std::vector<T>&\
    \ dp) -> std::vector<T> {\n        int len = r - l;\n        std::vector<T> f(len\
    \ + 1);\n        for (int i = 0; i <= len; i++) f[i] = binom.C(len, i);\n    \
    \    return atcoder::convolution(dp, f);\n    };\n    auto dfs_only_L = [&](auto\
    \ self, int l, int r, const std::vector<T>& dp) -> std::vector<T> {\n        if\
    \ (r - l == 1) {\n            auto res = go(l, r, dp);\n            if (L[l] !=\
    \ L[r]) res = extract(res, L[r] - L[l]);\n            return res;\n        }\n\
    \n        int m = (l + r) >> 1;\n        auto M = go(l, m, extract(dp, L[m] -\
    \ L[l]));\n        auto buf = self(self, l, m, extract(dp, 0, L[m] - L[l]));\n\
    \        while (M.size() < buf.size()) M.emplace_back(0);\n        for (int i\
    \ = 0; i < int(buf.size()); i++) M[i] += buf[i];\n\n        auto R = go(m, r,\
    \ extract(M, L[r] - L[m]));\n        buf = self(self, m, r, extract(M, 0, L[r]\
    \ - L[m]));\n        while (R.size() < buf.size()) R.emplace_back(0);\n      \
    \  for (int i = 0; i < int(buf.size()); i++) R[i] += buf[i];\n        return R;\n\
    \    };\n    auto dfs_only_R = [&](auto self, int l, int r, const std::vector<T>&\
    \ dp) -> std::vector<T> {\n        if (r - l == 1) {\n            if (U[l] ==\
    \ U[r]) return std::vector<T>();\n            return extract(go(l, r, dp), 1);\n\
    \        }\n\n        int m = (l + r) >> 1;\n        std::vector<T> M((U[m] -\
    \ U[l]) + (r - m), T(0));\n        auto buf = go(l, m, dp);\n        for (int\
    \ i = m - l; i < std::min(int(buf.size()), r - l); i++) M[i - (m - l)] += buf[i];\n\
    \        buf = self(self, l, m, extract(dp, int(dp.size()) - (m - l)));\n    \
    \    for (int i = 0; i < int(buf.size()); i++) M[i + (r - m)] += buf[i];\n\n \
    \       std::vector<T> R(U[r] - U[l], T(0));\n        buf = go(m, r, M);\n   \
    \     for (int i = r - m; i < std::min(int(buf.size()), ((U[m] - U[l]) + (r -\
    \ m))); i++) R[i - (r - m)] += buf[i];\n        buf = self(self, m, r, extract(M,\
    \ int(M.size()) - (r - m)));\n        for (int i = 0; i < int(buf.size()); i++)\
    \ R[i + (U[m] - U[l])] += buf[i];\n        return R;\n    };\n    auto dfs = [&](auto\
    \ self, int l, int r, const std::vector<T>& dp) -> std::vector<T> {\n        if\
    \ (r - l == 1) {\n            auto res = go(l, r, dp);\n            return extract(res,\
    \ L[r] - L[l], U[r] - L[l] + 1);\n        }\n\n        if (L[r] + (r - l) <= U[l])\
    \ {\n            std::vector<T> res(U[r] - L[r] + 1, T(0));\n            auto\
    \ buf = go(l, r, extract(dp, L[r] - L[l]));\n            for (int i = 0; i < std::min(int(buf.size()),\
    \ U[l] - L[r] + 1); i++) res[i] += buf[i];\n            buf = dfs_only_L(dfs_only_L,\
    \ l, r, extract(dp, 0, L[r] - L[l]));\n            for (int i = 0; i < int(buf.size());\
    \ i++) res[i] += buf[i];\n            buf = dfs_only_R(dfs_only_R, l, r, extract(dp,\
    \ int(dp.size()) - (r - l)));\n            for (int i = 0; i < int(buf.size());\
    \ i++) res[int(res.size()) - 1 - i] += buf[int(buf.size()) - 1 - i];\n       \
    \     return res;\n        }\n\n        int m = (l + r) >> 1;\n        return\
    \ self(self, m, r, self(self, l, m, dp));\n    };\n    std::vector<T> init(1,\
    \ T(1));\n    auto last = dfs(dfs, 0, n - 1, init);\n    return std::accumulate(last.begin(),\
    \ last.end(), T(0));\n}\n"
  dependsOn:
  - src/math/binomial.hpp
  isVerificationFile: false
  path: src/math/number_of_increasing_sequences_between_two_sequences.hpp
  requiredBy: []
  timestamp: '2024-06-21 03:19:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
documentation_of: src/math/number_of_increasing_sequences_between_two_sequences.hpp
layout: document
title: Number of Increasing Sequences Between Two Sequences
---

## 入力

長さ $n$ の数列 $a, b$

## 出力

任意の $i\ (0 \le i \lt n)$ について $a _ i \le x _ i \lt b _ i$ を満たす長さ $n$ の数列 $x$ の個数

## 計算量

$m \coloneqq \max _ i b _ i - \min _ i a _ i$ として時間計算量 $\mathrm{O}(n + m) \log ^ 2 (n + m)$

## Links
- [上限付き単調増加列の数え上げ - noshi91のメモ](https://noshi91.hatenablog.com/entry/2023/07/21/235339)

## 出題例
- [XXI Open Cup, Grand Prix of Tokyo J. Japanese Knowledge](https://codeforces.com/gym/102978/problem/J)
- [The 13th Chinese Northeast Collegiate Programming Contest I. Temperature Survey](https://codeforces.com/gym/102220/problem/I)
- [Good Bye 2022: 2023 is NEAR G. Koxia and Bracket](https://codeforces.com/contest/1770/problem/G)
- [Hokkaido University Competitive Programming Camp 2023 Day 1 L: 01 Swap](https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2023Day1/problems/L)
- [AtCoder Grand Contest 058 B - Adjacent Chmax](https://atcoder.jp/contests/agc058/tasks/agc058_b)
- [Codeforces Round 942 (Div. 1) E1. Again Counting Arrays (Easy Version)](https://codeforces.com/contest/1967/problem/E1)
- [The 2nd Universal Cup. Stage 7: Two Capitals C. Cards](https://qoj.ac/contest/1399/problem/7634)
- [AtCoder Beginner Contest 357 G - Stair-like Grid](https://atcoder.jp/contests/abc357/tasks/abc357_g)