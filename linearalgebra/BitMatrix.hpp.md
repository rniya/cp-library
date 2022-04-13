---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linearalgebra/BitMatrix.hpp\"\n#include <bitset>\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <size_t MAX_COL> struct BitMatrix {\n\
    \    size_t n, m;\n    std::vector<std::bitset<MAX_COL>> A;\n\n    BitMatrix(size_t\
    \ n, size_t m) : n(n), m(m), A(n) { assert(m <= MAX_COL); }\n\n    size_t size()\
    \ const { return n; };\n\n    size_t height() const { return n; }\n\n    size_t\
    \ width() const { return m; }\n\n    inline const std::bitset<MAX_COL>& operator[](int\
    \ k) const { return A[k]; }\n\n    inline std::bitset<MAX_COL>& operator[](int\
    \ k) { return A[k]; }\n\n    static BitMatrix I(size_t n) {\n        BitMatrix\
    \ res(n, n);\n        for (size_t i = 0; i < n; i++) res[i][i] = true;\n     \
    \   return res;\n    }\n\n    BitMatrix& operator*=(const BitMatrix& B) {\n  \
    \      assert(m == B.height());\n        BitMatrix C(n, B.width());\n        for\
    \ (size_t i = 0; i < n; i++) {\n            for (size_t j = 0; j < m; j++) {\n\
    \                if (A[i][j]) {\n                    C[i] |= B[j];\n         \
    \       }\n            }\n        }\n        std::swap(A, C.A);\n        return\
    \ *this;\n    }\n\n    BitMatrix& operator^=(long long k) {\n        assert(0\
    \ <= k);\n        BitMatrix B = BitMatrix::I(n);\n        while (k > 0) {\n  \
    \          if (k & 1) B *= *this;\n            *this *= *this;\n            k\
    \ >>= 1;\n        }\n        std::swap(A, B.A);\n        return *this;\n    }\n\
    \n    BitMatrix operator*(const BitMatrix& B) const { return BitMatrix(*this)\
    \ *= B; }\n\n    BitMatrix operator^(const long long k) const { return BitMatrix(*this)\
    \ ^= k; }\n\n    size_t gauss_jordan() {\n        size_t rank = 0;\n        for\
    \ (size_t j = 0; j < m; j++) {\n            int pivot = -1;\n            for (size_t\
    \ i = rank; i < n; i++) {\n                if (A[i][j]) {\n                  \
    \  pivot = i;\n                    break;\n                }\n            }\n\
    \            if (pivot == -1) continue;\n            std::swap(A[pivot], A[rank]);\n\
    \            for (size_t i = 0; i < n; i++) {\n                if (i != rank and\
    \ A[i][j]) {\n                    A[i] ^= A[rank];\n                }\n      \
    \      }\n            rank++;\n        }\n        return rank;\n    }\n\n    std::pair<int,\
    \ std::bitset<MAX_COL>> system_of_linear_equations(const std::vector<bool>& b)\
    \ {\n        assert(m + 1 <= MAX_COL);\n        BitMatrix B(*this);\n        for\
    \ (size_t i = 0; i < n; i++) B[i][m] = b[i];\n        size_t rank = B.gauss_jordan();\n\
    \        for (size_t i = rank; i < n; i++) {\n            if (B[i][m]) {\n   \
    \             return {-1, std::bitset<MAX_COL>()};\n            }\n        }\n\
    \        std::bitset<MAX_COL> res;\n        for (size_t i = 0; i < rank; i++)\
    \ res[i] = B[i][m];\n        return {rank, res};\n    }\n};\n"
  code: "#pragma once\n#include <bitset>\n#include <cassert>\n#include <vector>\n\n\
    template <size_t MAX_COL> struct BitMatrix {\n    size_t n, m;\n    std::vector<std::bitset<MAX_COL>>\
    \ A;\n\n    BitMatrix(size_t n, size_t m) : n(n), m(m), A(n) { assert(m <= MAX_COL);\
    \ }\n\n    size_t size() const { return n; };\n\n    size_t height() const { return\
    \ n; }\n\n    size_t width() const { return m; }\n\n    inline const std::bitset<MAX_COL>&\
    \ operator[](int k) const { return A[k]; }\n\n    inline std::bitset<MAX_COL>&\
    \ operator[](int k) { return A[k]; }\n\n    static BitMatrix I(size_t n) {\n \
    \       BitMatrix res(n, n);\n        for (size_t i = 0; i < n; i++) res[i][i]\
    \ = true;\n        return res;\n    }\n\n    BitMatrix& operator*=(const BitMatrix&\
    \ B) {\n        assert(m == B.height());\n        BitMatrix C(n, B.width());\n\
    \        for (size_t i = 0; i < n; i++) {\n            for (size_t j = 0; j <\
    \ m; j++) {\n                if (A[i][j]) {\n                    C[i] |= B[j];\n\
    \                }\n            }\n        }\n        std::swap(A, C.A);\n   \
    \     return *this;\n    }\n\n    BitMatrix& operator^=(long long k) {\n     \
    \   assert(0 <= k);\n        BitMatrix B = BitMatrix::I(n);\n        while (k\
    \ > 0) {\n            if (k & 1) B *= *this;\n            *this *= *this;\n  \
    \          k >>= 1;\n        }\n        std::swap(A, B.A);\n        return *this;\n\
    \    }\n\n    BitMatrix operator*(const BitMatrix& B) const { return BitMatrix(*this)\
    \ *= B; }\n\n    BitMatrix operator^(const long long k) const { return BitMatrix(*this)\
    \ ^= k; }\n\n    size_t gauss_jordan() {\n        size_t rank = 0;\n        for\
    \ (size_t j = 0; j < m; j++) {\n            int pivot = -1;\n            for (size_t\
    \ i = rank; i < n; i++) {\n                if (A[i][j]) {\n                  \
    \  pivot = i;\n                    break;\n                }\n            }\n\
    \            if (pivot == -1) continue;\n            std::swap(A[pivot], A[rank]);\n\
    \            for (size_t i = 0; i < n; i++) {\n                if (i != rank and\
    \ A[i][j]) {\n                    A[i] ^= A[rank];\n                }\n      \
    \      }\n            rank++;\n        }\n        return rank;\n    }\n\n    std::pair<int,\
    \ std::bitset<MAX_COL>> system_of_linear_equations(const std::vector<bool>& b)\
    \ {\n        assert(m + 1 <= MAX_COL);\n        BitMatrix B(*this);\n        for\
    \ (size_t i = 0; i < n; i++) B[i][m] = b[i];\n        size_t rank = B.gauss_jordan();\n\
    \        for (size_t i = rank; i < n; i++) {\n            if (B[i][m]) {\n   \
    \             return {-1, std::bitset<MAX_COL>()};\n            }\n        }\n\
    \        std::bitset<MAX_COL> res;\n        for (size_t i = 0; i < rank; i++)\
    \ res[i] = B[i][m];\n        return {rank, res};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linearalgebra/BitMatrix.hpp
  requiredBy: []
  timestamp: '2022-04-14 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/803.test.cpp
documentation_of: linearalgebra/BitMatrix.hpp
layout: document
title: Bit Matrix
---

## 概要
$\mathbb{F}_2$ 上での掃き出し法を行うためのライブラリ. $\mathbb{F}_2$ に特化させるために内部では `bitset` でデータを保持している.
- `gauss_jordan(extended)` : 掃き出し法を行い, その結果得られた $\operatorname{rank}$ を返す. `extended` は `linear_equtation(b)` などで最後の行を除外して掃き出す機会があるのでそのための変数.
- `linear_equation(b)` : $\forall i,\ \otimes_{j=1}^m a_{ij}x_j = b_i$ を満たすような数列 $\{x_j\}_{j=1}^m$ を求める. 解を構成することが不可能な場合には -1 を返す. 行列 $A$ の列方向のサイズには 1 だけ余分をもたせておく必要があることに注意.

## 計算量
$O\left(\dfrac{n^2m}{64}\right)$

## 問題例
[yukicoder No.803 Very Limited Xor Subset](https://yukicoder.me/problems/no/803)
