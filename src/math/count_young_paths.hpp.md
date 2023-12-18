---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/binomial.hpp
    title: binomial
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3335.test.cpp
    title: test/aoj/3335.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution:\
    \ line -1: no such header\n"
  code: "#include \"atcoder/convolution\"\n#include \"math/binomial.hpp\"\n\ntemplate\
    \ <class T>\nstd::vector<T> count_young_paths(const std::vector<int>& h, const\
    \ std::vector<T>& a, Binomial<T>& binom) {\n    assert(h.size() == a.size());\n\
    \    assert(std::is_sorted(begin(h), end(h)));\n    int n = h.size(), m = n >>\
    \ 1;\n    if (n == 0) return {};\n    if (n == 1) return std::vector<T>(h.front(),\
    \ a.front());\n    assert(h[0] >= 0);\n    if (h[0] == 0) {\n        int l = 0;\n\
    \        while (l < n and h[l] == 0) l++;\n        return count_young_paths(std::vector<int>(begin(h)\
    \ + l, end(h)), std::vector<T>(begin(a) + l, end(a)), binom);\n    }\n    int\
    \ x = n - m, y = h[m - 1];\n    auto b = count_young_paths(std::vector<int>(begin(h),\
    \ begin(h) + m), std::vector<T>(begin(a), begin(a) + m), binom);\n    std::vector<T>\
    \ c(x, 0), d(y, 0);\n    // a: down, b: left, c: up, d: right\n    {\n       \
    \ // a -> c\n        std::vector<T> f(x), g(x);\n        for (int i = 0; i < x;\
    \ i++) f[i] = a[m + i];\n        for (int i = 0; i < x; i++) g[i] = binom.C(y\
    \ - 1 + i, i);\n        f = atcoder::convolution(f, g);\n        for (int i =\
    \ 0; i < x; i++) c[i] += f[i];\n    }\n    {\n        // a -> d\n        std::vector<T>\
    \ f(x), g(x + y - 1);\n        for (int i = 0; i < x; i++) f[i] = a[m + i] * binom.finv(x\
    \ - 1 - i);\n        for (int i = 0; i < x + y - 1; i++) g[i] = binom.fac(i);\n\
    \        f = atcoder::convolution(f, g);\n        for (int i = 0; i < y; i++)\
    \ d[i] += f[x - 1 + i] * binom.finv(i);\n    }\n    {\n        // b -> c\n   \
    \     std::vector<T> f(y), g(x + y - 1);\n        for (int i = 0; i < y; i++)\
    \ f[i] = b[i] * binom.finv(y - 1 - i);\n        for (int i = 0; i < x + y - 1;\
    \ i++) g[i] = binom.fac(i);\n        f = atcoder::convolution(f, g);\n       \
    \ for (int i = 0; i < x; i++) c[i] += f[y - 1 + i] * binom.finv(i);\n    }\n \
    \   {\n        // b -> d\n        std::vector<T> f(y), g(y);\n        for (int\
    \ i = 0; i < y; i++) f[i] = b[i];\n        for (int i = 0; i < y; i++) g[i] =\
    \ binom.C(x - 1 + i, i);\n        f = atcoder::convolution(f, g);\n        for\
    \ (int i = 0; i < y; i++) d[i] += f[i];\n    }\n    std::vector<T> res(h.back());\n\
    \    for (int i = 0; i < y; i++) res[i] = d[i];\n    std::vector<int> nh(x);\n\
    \    for (int i = 0; i < x; i++) nh[i] = h[m + i] - y;\n    auto nd = count_young_paths(nh,\
    \ c, binom);\n    for (int i = 0; i < int(nd.size()); i++) res[y + i] = nd[i];\n\
    \    return res;\n}\n"
  dependsOn:
  - src/math/binomial.hpp
  isVerificationFile: false
  path: src/math/count_young_paths.hpp
  requiredBy: []
  timestamp: '2023-05-21 16:36:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/3335.test.cpp
documentation_of: src/math/count_young_paths.hpp
layout: document
title: "Young \u56F3\u5F62\u4E0A\u306E\u6700\u77ED\u7D4C\u8DEF\u306E\u6570\u3048\u4E0A\
  \u3052"
---

## 概要
$(A_1, \dots , A_n)\ (1 \leq A_1 \leq \dots \leq A_n)$ なる分割に対応するヤング図形上の箱 $(1, 1)$ から箱 $(n, i)\ (1 \leq i \leq A_n)$ までの最短経路の総数を数え上げる．

## Links
- https://twitter.com/noshi91/status/1640315787528519680

## 問題例
- [XXI Open Cup, Grand Prix of Tokyo J. Japanese Knowledge](https://codeforces.com/gym/102978/problem/J)
- [The 13th Chinese Northeast Collegiate Programming Contest I. Temperature Survey](https://codeforces.com/gym/102220/problem/I)
- [Good Bye 2022: 2023 is NEAR G. Koxia and Bracket](https://codeforces.com/contest/1770/problem/G)
- [Hokkaido University Competitive Programming Camp 2023 Day 1 L: 01 Swap](https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2023Day1/problems/L)
- [AtCoder Grand Contest 058 B - Adjacent Chmax](https://atcoder.jp/contests/agc058/tasks/agc058_b)