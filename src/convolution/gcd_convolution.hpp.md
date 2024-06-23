---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/gcd_convolution.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace internal {\n\n// f(k) <- \\sum_{k | i} f(i)\ntemplate\
    \ <typename T> void divisor_transform(std::vector<T>& f) {\n    int n = f.size();\n\
    \    std::vector<bool> sieve(n, true);\n    for (int p = 2; p < n; p++) {\n  \
    \      if (sieve[p]) {\n            for (int k = (n - 1) / p; k > 0; k--) {\n\
    \                sieve[k * p] = false;\n                f[k] += f[k * p];\n  \
    \          }\n        }\n    }\n    for (int i = 1; i < n; i++) f[i] += f[0];\n\
    }\n\n// inverse of divisor transform\ntemplate <typename T> void inverse_divisor_transform(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    std::vector<bool> sieve(n, true);\n    for\
    \ (int i = 1; i < n; i++) f[i] -= f[0];\n    for (int p = 2; p < n; p++) {\n \
    \       if (sieve[p]) {\n            for (int k = 1 / p; k * p < n; k++) {\n \
    \               sieve[k * p] = false;\n                f[k] -= f[k * p];\n   \
    \         }\n        }\n    }\n}\n\n}  // namespace internal\n\ntemplate <typename\
    \ T> std::vector<T> gcd_convolution(std::vector<T> f, std::vector<T> g) {\n  \
    \  assert(f.size() == g.size());\n    internal::divisor_transform(f);\n    internal::divisor_transform(g);\n\
    \    for (int i = 0; i < int(f.size()); i++) f[i] *= g[i];\n    internal::inverse_divisor_transform(f);\n\
    \    return f;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace internal\
    \ {\n\n// f(k) <- \\sum_{k | i} f(i)\ntemplate <typename T> void divisor_transform(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    std::vector<bool> sieve(n, true);\n    for\
    \ (int p = 2; p < n; p++) {\n        if (sieve[p]) {\n            for (int k =\
    \ (n - 1) / p; k > 0; k--) {\n                sieve[k * p] = false;\n        \
    \        f[k] += f[k * p];\n            }\n        }\n    }\n    for (int i =\
    \ 1; i < n; i++) f[i] += f[0];\n}\n\n// inverse of divisor transform\ntemplate\
    \ <typename T> void inverse_divisor_transform(std::vector<T>& f) {\n    int n\
    \ = f.size();\n    std::vector<bool> sieve(n, true);\n    for (int i = 1; i <\
    \ n; i++) f[i] -= f[0];\n    for (int p = 2; p < n; p++) {\n        if (sieve[p])\
    \ {\n            for (int k = 1 / p; k * p < n; k++) {\n                sieve[k\
    \ * p] = false;\n                f[k] -= f[k * p];\n            }\n        }\n\
    \    }\n}\n\n}  // namespace internal\n\ntemplate <typename T> std::vector<T>\
    \ gcd_convolution(std::vector<T> f, std::vector<T> g) {\n    assert(f.size() ==\
    \ g.size());\n    internal::divisor_transform(f);\n    internal::divisor_transform(g);\n\
    \    for (int i = 0; i < int(f.size()); i++) f[i] *= g[i];\n    internal::inverse_divisor_transform(f);\n\
    \    return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2024-06-24 04:02:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/gcd_convolution.test.cpp
documentation_of: src/convolution/gcd_convolution.hpp
layout: document
title: GCD Convolution
---

## 入力

ともに長さ $n$ の数列 $a _ 1, \dots , a _ n$ 及び $b _ 1, \dots , b _ n$．

## 出力

数列 $a$ と $b$ の index の最大公約数についての畳み込み．
すなわち，

$$
c _ k = \sum _ {\gcd(i, j) = k} a _ i b _ j
$$

で定義される長さ $n$ の数列 $c$．

## 計算量

時間計算量 $\mathrm{O}(n \log \log n)$

## 出題例
- [AtCoder Grand Contest 038 C - LCMs](https://atcoder.jp/contests/agc038/tasks/agc038_c)
- [COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred) G. GCD Festival](https://codeforces.com/contest/1575/problem/G)

## Links
- [約数集合でのゼータ変換・メビウス変換的なやつと畳み込み - kazuma8128’s blog](https://kazuma8128.hatenablog.com/entry/2018/07/29/231819)
- [添え字 gcd での畳み込みで AGC038-C を解く - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/09/23/002445)
- [高速ゼータ変換の約数版 $O(N \log(\log(N)))$ - noshi91のメモ](https://noshi91.hatenablog.com/entry/2018/12/27/121649)
