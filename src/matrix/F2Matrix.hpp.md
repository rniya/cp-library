---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inverse_matrix_mod_2.test.cpp
    title: test/yosupo/inverse_matrix_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det_mod_2.test.cpp
    title: test/yosupo/matrix_det_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_product_mod_2.test.cpp
    title: test/yosupo/matrix_product_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/system_of_linear_equations_mod_2.test.cpp
    title: test/yosupo/system_of_linear_equations_mod_2.test.cpp
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
    \ == W);\n        return rank() == H ? 1 : 0;\n    }\n\n    F2Matrix inv() const\
    \ {\n        assert(height() == width());\n        int n = height();\n       \
    \ F2Matrix B(*this), C = identity(n);\n        for (int j = 0; j < n; j++) {\n\
    \            int pivot = -1;\n            for (int i = j; i < n; i++) {\n    \
    \            if (B[i][j]) {\n                    pivot = i;\n                \
    \    break;\n                }\n            }\n            assert(pivot != -1);\n\
    \            if (pivot != j) {\n                std::swap(B[pivot], B[j]);\n \
    \               std::swap(C[pivot], C[j]);\n            }\n            for (int\
    \ i = 0; i < n; i++) {\n                if (i != j and B[i][j]) {\n          \
    \          B[i] ^= B[j];\n                    C[i] ^= C[j];\n                }\n\
    \            }\n        }\n        return C;\n    }\n\n    std::vector<std::bitset<MAX_W>>\
    \ system_of_linear_equations(const std::vector<bool>& b) {\n        assert(W +\
    \ 1 <= MAX_W);\n        assert(int(b.size()) == H);\n        F2Matrix B(*this);\n\
    \        for (int i = 0; i < H; i++) B[i][W] = b[i];\n        int rank = B.gauss_jordan(W);\n\
    \        for (int i = rank; i < H; i++) {\n            if (B[i][W]) {\n      \
    \          return {};\n            }\n        }\n        std::vector<std::bitset<MAX_W>>\
    \ res(1);\n        std::vector<int> pivot(W, -1);\n        for (int i = 0, j =\
    \ 0; i < rank; i++) {\n            while (not B[i][j]) j++;\n            res[0][j]\
    \ = B[i][W];\n            pivot[j] = i;\n        }\n        for (int j = 0; j\
    \ < W; j++) {\n            if (pivot[j] != -1) continue;\n            std::bitset<MAX_W>\
    \ x;\n            x[j] = 1;\n            for (int k = 0; k < j; k++) {\n     \
    \           if (pivot[k] != -1) {\n                    x[k] = B[pivot[k]][j];\n\
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
    \ == W);\n        return rank() == H ? 1 : 0;\n    }\n\n    F2Matrix inv() const\
    \ {\n        assert(height() == width());\n        int n = height();\n       \
    \ F2Matrix B(*this), C = identity(n);\n        for (int j = 0; j < n; j++) {\n\
    \            int pivot = -1;\n            for (int i = j; i < n; i++) {\n    \
    \            if (B[i][j]) {\n                    pivot = i;\n                \
    \    break;\n                }\n            }\n            assert(pivot != -1);\n\
    \            if (pivot != j) {\n                std::swap(B[pivot], B[j]);\n \
    \               std::swap(C[pivot], C[j]);\n            }\n            for (int\
    \ i = 0; i < n; i++) {\n                if (i != j and B[i][j]) {\n          \
    \          B[i] ^= B[j];\n                    C[i] ^= C[j];\n                }\n\
    \            }\n        }\n        return C;\n    }\n\n    std::vector<std::bitset<MAX_W>>\
    \ system_of_linear_equations(const std::vector<bool>& b) {\n        assert(W +\
    \ 1 <= MAX_W);\n        assert(int(b.size()) == H);\n        F2Matrix B(*this);\n\
    \        for (int i = 0; i < H; i++) B[i][W] = b[i];\n        int rank = B.gauss_jordan(W);\n\
    \        for (int i = rank; i < H; i++) {\n            if (B[i][W]) {\n      \
    \          return {};\n            }\n        }\n        std::vector<std::bitset<MAX_W>>\
    \ res(1);\n        std::vector<int> pivot(W, -1);\n        for (int i = 0, j =\
    \ 0; i < rank; i++) {\n            while (not B[i][j]) j++;\n            res[0][j]\
    \ = B[i][W];\n            pivot[j] = i;\n        }\n        for (int j = 0; j\
    \ < W; j++) {\n            if (pivot[j] != -1) continue;\n            std::bitset<MAX_W>\
    \ x;\n            x[j] = 1;\n            for (int k = 0; k < j; k++) {\n     \
    \           if (pivot[k] != -1) {\n                    x[k] = B[pivot[k]][j];\n\
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
  timestamp: '2024-10-28 16:18:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/system_of_linear_equations_mod_2.test.cpp
  - test/yosupo/matrix_product_mod_2.test.cpp
  - test/yosupo/matrix_det_mod_2.test.cpp
  - test/yosupo/inverse_matrix_mod_2.test.cpp
documentation_of: src/matrix/F2Matrix.hpp
layout: document
title: Matrix on $\mathbb{F}_2$
---

## 概要
`std::bitset<>` を利用して $\mathbb{F}_2$ 上での各種行列処理を高速化したライブラリ。
固定長の都合上、列数以上の値を引数 `MAX_W` として渡す必要がある。

下表ではワードサイズを $w = 64$ とする。

| メンバ関数                      | 効果                                                                                                                                                                                                                                   | 時間計算量                                       |
| ------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------ |
| `empty()`                       | 行列が空か否かを返す．                                                                                                                                                                                                                 | $\mathrm{O}(1)$                                  |
| `size()`                        | 行数を返す．                                                                                                                                                                                                                           | $\mathrm{O}(1)$                                  |
| `height()`                      | 行数を返す．                                                                                                                                                                                                                           | $\mathrm{O}(1)$                                  |
| `width()`                       | 列数を返す．                                                                                                                                                                                                                           | $\mathrm{O}(1)$                                  |
| `identity(N)`                   | $N \times N$ 単位行列を返す．                                                                                                                                                                                                          | $\mathrm{O} \left( \frac{N^2}{w} \right)$        |
| 加算                            | $N \times M$ 行列 $A$ に $B$ を加算する．                                                                                                                                                                                              | $\mathrm{O} \left( \frac{N M}{w} \right)$        |
| 減算                            | $N \times M$ 行列 $A$ に $B$ を減算する．                                                                                                                                                                                              | $\mathrm{O} \left( \frac{N M}{w} \right)$        |
| 乗算                            | $N \times M$ 行列 $A$ に $M \times L$ 行列 $B$ を減算する．                                                                                                                                                                            | $\mathrm{O} \left( \frac{N M L}{w} \right)$      |
| `pow(n)`                        | $N \times N$ 正方行列 $A$ を $n$ 乗した行列を返す．                                                                                                                                                                                    | $\mathrm{O} \left( \frac{N^3 \log n}{w} \right)$ |
| `rank()`                        | $N \times M$ 行列 $A$ の rank を返す．                                                                                                                                                                                                 | $\mathrm{O} \left( \frac{N M^2}{w} \right)$      |
| `det()`                         | $N \times N$ 正方行列 $A$ の determinant を返す．                                                                                                                                                                                      | $\mathrm{O} \left( \frac{N^3}{w} \right)$        |
| `inv()`                         | $N \times N$ 正方行列 $A$ の逆行列を返す（行列が正則である必要がある）．                                                                                                                                                               | $\mathrm{O} \left( \frac{N^3}{w} \right)$        |
| `system_of_linear_equations(b)` | $N \times M$ 行列 $A$ と長さ $N$ のｔ縦ベクトル $b$ について $A x = b$ という線形方程式系を考える．この方程式系に解が存在しない場合は空配列を返し，存在する場合は解のうちの 1 つ及び解空間の基底ベクトルをこの順にまとめた配列を返す． | $\mathrm{O} \left( \frac{N M^2}{w} \right)$      |


## 出題例
- [yukicoder No.803 Very Limited Xor Subset](https://yukicoder.me/problems/no/803)
- [AtCoder Beginner Contest 276 Ex - Construct a Matrix](https://atcoder.jp/contests/abc276/tasks/abc276_h)