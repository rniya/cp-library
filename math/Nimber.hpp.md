---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/nim_product_64.test.cpp
    title: test/yosupo/nim_product_64.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Nimber.hpp\"\n#include <algorithm>\n#include <array>\n\
    \nnamespace Nimber64 {\n\nstruct nim {\n    const static std::array<std::array<unsigned\
    \ char, 256>, 256> small;\n    const static std::array<std::array<std::array<nim,\
    \ 256>, 8>, 8> precalc;\n    unsigned long long v;\n\n    nim() : v(0) {}\n\n\
    \    nim(unsigned long long _v) : v(_v) {}\n\n    nim& operator+=(const nim& rhs)\
    \ {\n        v ^= rhs.v;\n        return *this;\n    }\n\n    nim& operator-=(const\
    \ nim& rhs) {\n        v ^= rhs.v;\n        return *this;\n    }\n\n    nim& operator*=(const\
    \ nim& rhs) {\n        nim res;\n        for (int i = 0; i < 8; i++) {\n     \
    \       for (int j = 0; j < 8; j++) {\n                res += precalc[i][j][small[(v\
    \ >> (8 * i)) & 255][(rhs.v >> (8 * j)) & 255]];\n            }\n        }\n \
    \       return *this = res;\n    }\n\n    const nim operator+(const nim& rhs)\
    \ const { return nim(*this) += rhs; }\n\n    const nim operator-(const nim& rhs)\
    \ const { return nim(*this) -= rhs; }\n\n    const nim operator*(const nim& rhs)\
    \ const { return nim(*this) *= rhs; }\n};\n\nnim mul_naive(nim l, nim r) {\n \
    \   unsigned long long a = l.v, b = r.v;\n    if (a < b) std::swap(a, b);\n  \
    \  if (b == 0) return 0;\n    if (b == 1) return a;\n    int p = 32;\n    while\
    \ (std::max(a, b) < (1ULL << p)) p >>= 1;\n    unsigned long long power = 1ULL\
    \ << p;\n    if (a >= power and b >= power) {\n        nim res;\n        res +=\
    \ mul_naive(a % power, b % power);\n        res += mul_naive(a / power, b % power).v\
    \ * power;\n        res += mul_naive(a % power, b / power).v * power;\n      \
    \  auto x = mul_naive(a / power, b / power);\n        res += x.v * power;\n  \
    \      res += mul_naive(x, power / 2);\n        return res;\n    } else\n    \
    \    return nim(mul_naive(a / power, b).v * power) + mul_naive(a % power, b);\n\
    }\n\nconst std::array<std::array<unsigned char, 256>, 256> nim::small = []() {\n\
    \    std::array<std::array<unsigned char, 256>, 256> small;\n    for (int i =\
    \ 0; i < 256; i++) {\n        for (int j = 0; j < 256; j++) {\n            small[i][j]\
    \ = (unsigned char)(mul_naive(i, j).v);\n        }\n    }\n    return small;\n\
    }();\n\nconst std::array<std::array<std::array<nim, 256>, 8>, 8> nim::precalc\
    \ = []() {\n    std::array<std::array<std::array<nim, 256>, 8>, 8> precalc;\n\
    \    for (int i = 0; i < 8; i++) {\n        for (int j = 0; j < 8; j++) {\n  \
    \          nim tmp = mul_naive(1ULL << (8 * i), 1ULL << (8 * j));\n          \
    \  for (int k = 0; k < 256; k++) precalc[i][j][k] = mul_naive(tmp, k);\n     \
    \   }\n    }\n    return precalc;\n}();\n\n}  // namespace Nimber64\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n\nnamespace Nimber64\
    \ {\n\nstruct nim {\n    const static std::array<std::array<unsigned char, 256>,\
    \ 256> small;\n    const static std::array<std::array<std::array<nim, 256>, 8>,\
    \ 8> precalc;\n    unsigned long long v;\n\n    nim() : v(0) {}\n\n    nim(unsigned\
    \ long long _v) : v(_v) {}\n\n    nim& operator+=(const nim& rhs) {\n        v\
    \ ^= rhs.v;\n        return *this;\n    }\n\n    nim& operator-=(const nim& rhs)\
    \ {\n        v ^= rhs.v;\n        return *this;\n    }\n\n    nim& operator*=(const\
    \ nim& rhs) {\n        nim res;\n        for (int i = 0; i < 8; i++) {\n     \
    \       for (int j = 0; j < 8; j++) {\n                res += precalc[i][j][small[(v\
    \ >> (8 * i)) & 255][(rhs.v >> (8 * j)) & 255]];\n            }\n        }\n \
    \       return *this = res;\n    }\n\n    const nim operator+(const nim& rhs)\
    \ const { return nim(*this) += rhs; }\n\n    const nim operator-(const nim& rhs)\
    \ const { return nim(*this) -= rhs; }\n\n    const nim operator*(const nim& rhs)\
    \ const { return nim(*this) *= rhs; }\n};\n\nnim mul_naive(nim l, nim r) {\n \
    \   unsigned long long a = l.v, b = r.v;\n    if (a < b) std::swap(a, b);\n  \
    \  if (b == 0) return 0;\n    if (b == 1) return a;\n    int p = 32;\n    while\
    \ (std::max(a, b) < (1ULL << p)) p >>= 1;\n    unsigned long long power = 1ULL\
    \ << p;\n    if (a >= power and b >= power) {\n        nim res;\n        res +=\
    \ mul_naive(a % power, b % power);\n        res += mul_naive(a / power, b % power).v\
    \ * power;\n        res += mul_naive(a % power, b / power).v * power;\n      \
    \  auto x = mul_naive(a / power, b / power);\n        res += x.v * power;\n  \
    \      res += mul_naive(x, power / 2);\n        return res;\n    } else\n    \
    \    return nim(mul_naive(a / power, b).v * power) + mul_naive(a % power, b);\n\
    }\n\nconst std::array<std::array<unsigned char, 256>, 256> nim::small = []() {\n\
    \    std::array<std::array<unsigned char, 256>, 256> small;\n    for (int i =\
    \ 0; i < 256; i++) {\n        for (int j = 0; j < 256; j++) {\n            small[i][j]\
    \ = (unsigned char)(mul_naive(i, j).v);\n        }\n    }\n    return small;\n\
    }();\n\nconst std::array<std::array<std::array<nim, 256>, 8>, 8> nim::precalc\
    \ = []() {\n    std::array<std::array<std::array<nim, 256>, 8>, 8> precalc;\n\
    \    for (int i = 0; i < 8; i++) {\n        for (int j = 0; j < 8; j++) {\n  \
    \          nim tmp = mul_naive(1ULL << (8 * i), 1ULL << (8 * j));\n          \
    \  for (int k = 0; k < 256; k++) precalc[i][j][k] = mul_naive(tmp, k);\n     \
    \   }\n    }\n    return precalc;\n}();\n\n}  // namespace Nimber64\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Nimber.hpp
  requiredBy: []
  timestamp: '2022-10-23 23:11:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/nim_product_64.test.cpp
documentation_of: math/Nimber.hpp
layout: document
title: Nimber
---

## 概要
排他的論理和 (XOR) $\oplus$ を加法，Nim product $\otimes$ を乗法とすると $2^{2^n}$ 未満の非負整数の上に体を成す．

Nim product については $n \otimes 2^{2^k} = n 2^{2^k}\ (n < 2^{2^k})$ 及び $2^{2^k} \otimes 2^{2^k} = (3 / 2) 2^{2^k}$ が成立することから，$a \oplus b$ について $a = a_u 2^{32} + a_l,\ b = b_u 2^{32} + b_l$ とすると，

$$
\begin{aligned}
  &&& a \otimes b
  &=&& (a_u 2^{32} + a_l) \otimes (b_u 2^{32} + b_l) \\
  &=&& (a_u \otimes 2^{32} \oplus a_l) \otimes (b_u \otimes 2^{32} \oplus b_l) \quad (\because n 2^{2^k} = n \otimes 2^{2^k}) \\
  &=&& (a_u \otimes 2^{32} \otimes b_u \otimes 2^{32}) \oplus (a_u \otimes 2^{32} \otimes b_l) \oplus (a_l \otimes b_u \otimes 2^{32}) \oplus (a_l \otimes b_l) \\
  &=&& (a_u \otimes b_u \otimes (2^{32} + 2^{31})) \oplus ((a_u \otimes b_l \oplus a_l \otimes b_u) \otimes 2^{32}) \oplus (a_l \otimes b_l) \quad (\because 2^{2^k} \otimes 2^{2^k} = (3 / 2) 2^{2^k}) \\
  &=&& (a_u \otimes b_u \otimes (2^{32} \oplus 2^{31})) \oplus ((a_u \otimes b_l \oplus a_l \otimes b_u) \otimes 2^{32}) \oplus (a_l \otimes b_l) \\
  &=&& ((a_u \otimes b_u \oplus a_u \otimes b_l \oplus a_l \otimes b_u) \otimes 2^{32}) \oplus (a_u \otimes b_u \otimes 2^{31}) \oplus (a_l \otimes b_l) \\
  &=&& ((a_u \otimes b_u \oplus a_u \otimes b_l \oplus a_l \otimes b_u) \times 2^{32}) \oplus (a_u \otimes b_u \otimes 2^{31}) \oplus (a_l \otimes b_l) \\
\end{aligned}
$$

が成立するから再帰的に計算可能である．

## 問題例
- [AtCoder Beginner Contest 274 Ex - XOR Sum of Arrays](https://atcoder.jp/contests/abc274/tasks/abc274_h)

## Links
- [Nim product - kyopro_friends’ diary](https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850)
  - 代数的性質の証明について詳しい．
