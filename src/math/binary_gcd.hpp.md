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
  bundledCode: "#line 2 \"src/math/binary_gcd.hpp\"\n\ntemplate <typename T> T binary_gcd(T\
    \ x_, T y_) {\n    unsigned long long x = x_ < 0 ? -x_ : x_, y = y_ < 0 ? -y_\
    \ : y_;\n    if (!x or !y) return x + y;\n    int n = __builtin_ctzll(x), m =\
    \ __builtin_ctzll(y);\n    x >>= n, y >>= m;\n    while (x != y) {\n        if\
    \ (x > y)\n            x = (x - y) >> __builtin_ctzll(x - y);\n        else\n\
    \            y = (y - x) >> __builtin_ctzll(y - x);\n    }\n    return x << (n\
    \ > m ? m : n);\n}\n"
  code: "#pragma once\n\ntemplate <typename T> T binary_gcd(T x_, T y_) {\n    unsigned\
    \ long long x = x_ < 0 ? -x_ : x_, y = y_ < 0 ? -y_ : y_;\n    if (!x or !y) return\
    \ x + y;\n    int n = __builtin_ctzll(x), m = __builtin_ctzll(y);\n    x >>= n,\
    \ y >>= m;\n    while (x != y) {\n        if (x > y)\n            x = (x - y)\
    \ >> __builtin_ctzll(x - y);\n        else\n            y = (y - x) >> __builtin_ctzll(y\
    \ - x);\n    }\n    return x << (n > m ? m : n);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/binary_gcd.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/binary_gcd.hpp
layout: document
title: binary gcd
---

## 概要
2 数の最大公約数を求める．
一般的な Euclid の互除法による実装と異なり，非再帰かつ除算が 2 で割るものしか登場しないので bit shift で済み，約 3 から 4 倍程度高速である．

### 補題
- $\gcd(0, x) = \gcd(x, x) = x$
- $\gcd(2x, 2y) = 2\gcd(x, y)$
- $\gcd(2x, y) = \gcd(x, y)$ if $y$ is odd
- $\gcd(x, y) = \gcd(x - y, y)$ if $x > y$

どれも理解及び証明は容易で，原理は実際にソースコードを見るのがわかりやすい．
特に $x, y$ が共に奇数ならば $x - y$ は偶数であるから効率的に計算することが可能である．
