---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det_mod_2.test.cpp
    title: test/yosupo/matrix_det_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_product_mod_2.test.cpp
    title: test/yosupo/matrix_product_mod_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/matrix/F2Matrix.hpp\"\n#include <bitset>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\ntemplate <int MAX_W> struct F2Matrix\
    \ {\n    int H, W;\n\n    std::vector<std::bitset<MAX_W>> A;\n\n    F2Matrix(int\
    \ H, int W) : H(H), W(W), A(H) {\n        assert(W <= MAX_W);\n        for (int\
    \ i = 0; i < H; i++) A[i].reset();\n    }\n\n    bool empty() const { return A.empty();\
    \ }\n\n    int size() const { return H; }\n\n    int height() const { return H;\
    \ }\n\n    int width() const { return W; }\n\n    inline const std::bitset<MAX_W>&\
    \ operator[](int i) const { return A[i]; }\n\n    inline std::bitset<MAX_W>& operator[](int\
    \ i) { return A[i]; }\n\n    static F2Matrix identity(int n) {\n        F2Matrix\
    \ res(n, n);\n        for (int i = 0; i < n; i++) res[i][i] = 1;\n        return\
    \ res;\n    }\n\n    F2Matrix& operator+=(const F2Matrix& B) {\n        assert(H\
    \ == B.height() and W == B.width());\n        for (int i = 0; i < H; i++) (*this)[i]\
    \ ^= B[i];\n        return *this;\n    }\n\n    F2Matrix& operator-=(const F2Matrix&\
    \ B) { return *this += B; }\n\n    F2Matrix& operator*=(const F2Matrix& B) {\n\
    \        assert(W == B.height());\n        F2Matrix C(H, B.width());\n       \
    \ for (int i = 0; i < H; i++) {\n            for (int j = 0; j < W; j++) {\n \
    \               if (A[i][j]) {\n                    C[i] ^= B[j];\n          \
    \      }\n            }\n        }\n        std::swap(A, C.A);\n        return\
    \ *this;\n    }\n\n    F2Matrix operator+(const F2Matrix& B) const { return F2Matrix(*this)\
    \ += B; }\n\n    F2Matrix operator-(const F2Matrix& B) const { return F2Matrix(*this)\
    \ -= B; }\n\n    F2Matrix operator*(const F2Matrix& B) const { return F2Matrix(*this)\
    \ *= B; }\n\n    F2Matrix pow(long long n) const {\n        assert(H == W);\n\
    \        assert(0 <= n);\n        F2Matrix x = *this, r = identity(H);\n     \
    \   while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n       \
    \     n >>= 1;\n        }\n        return r;\n    }\n\n    int rank() const {\
    \ return F2Matrix(*this).gauss_jordan(); }\n\n    int det() const {\n        assert(H\
    \ == W);\n        return rank() == H ? 1 : 0;\n    }\n\n    std::vector<std::bitset<MAX_W>>\
    \ system_of_linear_equations(const std::vector<bool>& b) {\n        assert(W +\
    \ 1 <= MAX_W);\n        assert(int(b.size()) == H);\n        F2Matrix B(*this);\n\
    \        for (int i = 0; i < H; i++) B[i][W] = b[i];\n        int rank = B.gauss_jordan(W);\n\
    \        for (int i = rank; i < H; i++) {\n            if (B[i][W]) {\n      \
    \          return {};\n            }\n        }\n        std::vector<std::bitset<MAX_W>>\
    \ res(1);\n        std::vector<int> pivot(W, -1);\n        for (int i = 0, j =\
    \ 0; i < rank; i++) {\n            while (not B[i][j]) j++;\n            res[0][j]\
    \ = B[i][W];\n            pivot[j] = i;\n        }\n        for (int j = 0; j\
    \ < W; j++) {\n            if (pivot[j] != -1) continue;\n            std::bitset<MAX_W>\
    \ x(W);\n            x[j] = 1;\n            for (int k = 0; k < j; k++) {\n  \
    \              if (pivot[k] != -1) {\n                    x[k] = B[pivot[k]][j];\n\
    \                }\n            }\n            res.emplace_back(x);\n        }\n\
    \        return res;\n    }\n\n  private:\n    int gauss_jordan(int pivot_end\
    \ = -1) {\n        if (empty()) return 0;\n        if (pivot_end == -1) pivot_end\
    \ = W;\n        assert(pivot_end <= MAX_W);\n        int rank = 0;\n        for\
    \ (int j = 0; j < pivot_end; j++) {\n            int pivot = -1;\n           \
    \ for (int i = rank; i < H; i++) {\n                if ((*this)[i][j]) {\n   \
    \                 pivot = i;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) continue;\n            if (pivot\
    \ != rank) std::swap((*this)[pivot], (*this)[rank]);\n            for (int i =\
    \ 0; i < H; i++) {\n                if (i != rank and (*this)[i][j]) {\n     \
    \               (*this)[i] ^= (*this)[rank];\n                }\n            }\n\
    \            rank++;\n        }\n        return rank;\n    }\n};\n"
  code: "#pragma once\n#include <bitset>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\ntemplate <int MAX_W> struct F2Matrix {\n    int H, W;\n\n\
    \    std::vector<std::bitset<MAX_W>> A;\n\n    F2Matrix(int H, int W) : H(H),\
    \ W(W), A(H) {\n        assert(W <= MAX_W);\n        for (int i = 0; i < H; i++)\
    \ A[i].reset();\n    }\n\n    bool empty() const { return A.empty(); }\n\n   \
    \ int size() const { return H; }\n\n    int height() const { return H; }\n\n \
    \   int width() const { return W; }\n\n    inline const std::bitset<MAX_W>& operator[](int\
    \ i) const { return A[i]; }\n\n    inline std::bitset<MAX_W>& operator[](int i)\
    \ { return A[i]; }\n\n    static F2Matrix identity(int n) {\n        F2Matrix\
    \ res(n, n);\n        for (int i = 0; i < n; i++) res[i][i] = 1;\n        return\
    \ res;\n    }\n\n    F2Matrix& operator+=(const F2Matrix& B) {\n        assert(H\
    \ == B.height() and W == B.width());\n        for (int i = 0; i < H; i++) (*this)[i]\
    \ ^= B[i];\n        return *this;\n    }\n\n    F2Matrix& operator-=(const F2Matrix&\
    \ B) { return *this += B; }\n\n    F2Matrix& operator*=(const F2Matrix& B) {\n\
    \        assert(W == B.height());\n        F2Matrix C(H, B.width());\n       \
    \ for (int i = 0; i < H; i++) {\n            for (int j = 0; j < W; j++) {\n \
    \               if (A[i][j]) {\n                    C[i] ^= B[j];\n          \
    \      }\n            }\n        }\n        std::swap(A, C.A);\n        return\
    \ *this;\n    }\n\n    F2Matrix operator+(const F2Matrix& B) const { return F2Matrix(*this)\
    \ += B; }\n\n    F2Matrix operator-(const F2Matrix& B) const { return F2Matrix(*this)\
    \ -= B; }\n\n    F2Matrix operator*(const F2Matrix& B) const { return F2Matrix(*this)\
    \ *= B; }\n\n    F2Matrix pow(long long n) const {\n        assert(H == W);\n\
    \        assert(0 <= n);\n        F2Matrix x = *this, r = identity(H);\n     \
    \   while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n       \
    \     n >>= 1;\n        }\n        return r;\n    }\n\n    int rank() const {\
    \ return F2Matrix(*this).gauss_jordan(); }\n\n    int det() const {\n        assert(H\
    \ == W);\n        return rank() == H ? 1 : 0;\n    }\n\n    std::vector<std::bitset<MAX_W>>\
    \ system_of_linear_equations(const std::vector<bool>& b) {\n        assert(W +\
    \ 1 <= MAX_W);\n        assert(int(b.size()) == H);\n        F2Matrix B(*this);\n\
    \        for (int i = 0; i < H; i++) B[i][W] = b[i];\n        int rank = B.gauss_jordan(W);\n\
    \        for (int i = rank; i < H; i++) {\n            if (B[i][W]) {\n      \
    \          return {};\n            }\n        }\n        std::vector<std::bitset<MAX_W>>\
    \ res(1);\n        std::vector<int> pivot(W, -1);\n        for (int i = 0, j =\
    \ 0; i < rank; i++) {\n            while (not B[i][j]) j++;\n            res[0][j]\
    \ = B[i][W];\n            pivot[j] = i;\n        }\n        for (int j = 0; j\
    \ < W; j++) {\n            if (pivot[j] != -1) continue;\n            std::bitset<MAX_W>\
    \ x(W);\n            x[j] = 1;\n            for (int k = 0; k < j; k++) {\n  \
    \              if (pivot[k] != -1) {\n                    x[k] = B[pivot[k]][j];\n\
    \                }\n            }\n            res.emplace_back(x);\n        }\n\
    \        return res;\n    }\n\n  private:\n    int gauss_jordan(int pivot_end\
    \ = -1) {\n        if (empty()) return 0;\n        if (pivot_end == -1) pivot_end\
    \ = W;\n        assert(pivot_end <= MAX_W);\n        int rank = 0;\n        for\
    \ (int j = 0; j < pivot_end; j++) {\n            int pivot = -1;\n           \
    \ for (int i = rank; i < H; i++) {\n                if ((*this)[i][j]) {\n   \
    \                 pivot = i;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) continue;\n            if (pivot\
    \ != rank) std::swap((*this)[pivot], (*this)[rank]);\n            for (int i =\
    \ 0; i < H; i++) {\n                if (i != rank and (*this)[i][j]) {\n     \
    \               (*this)[i] ^= (*this)[rank];\n                }\n            }\n\
    \            rank++;\n        }\n        return rank;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/matrix/F2Matrix.hpp
  requiredBy: []
  timestamp: '2024-05-24 00:56:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_product_mod_2.test.cpp
  - test/yosupo/matrix_det_mod_2.test.cpp
documentation_of: src/matrix/F2Matrix.hpp
layout: document
title: Matrix on $\mathbb{F}_2$
---

## 概要
$\mathbb{F}_2$ 上での掃き出し法を行うためのライブラリ。$\mathbb{F}_2$ に特化させるために内部では `bitset` でデータを保持している。
- `gauss_jordan(extended)` : 掃き出し法を行い、その結果得られた $\operatorname{rank}$ を返す. `extended` は `linear_equtation(b)` などで最後の行を除外して掃き出す機会があるのでそのための変数。
- `linear_equation(b)` : $\forall i,\ \otimes_{j=1}^m a_{ij}x_j = b_i$ を満たすような数列 $\{x_j\}_{j=1}^m$ を求める。解を構成することが不可能な場合には -1 を返す. 行列 $A$ の列方向のサイズには 1 だけ余分をもたせておく必要があることに注意.

## 計算量
$O\left(\dfrac{n^2m}{64}\right)$

## 問題例
[yukicoder No.803 Very Limited Xor Subset](https://yukicoder.me/problems/no/803)
