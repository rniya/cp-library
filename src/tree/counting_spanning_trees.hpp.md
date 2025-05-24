---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/matrix/Matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/counting_spanning_tree_directed.test.cpp
    title: test/yosupo/counting_spanning_tree_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/counting_spanning_tree_undirected.test.cpp
    title: test/yosupo/counting_spanning_tree_undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/matrix/Matrix.hpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename T> struct Matrix {\n\
    \    std::vector<std::vector<T>> A;\n\n    Matrix() = default;\n\n    Matrix(int\
    \ n, int m) : A(n, std::vector<T>(m, 0)) {}\n\n    Matrix(int n) : A(n, std::vector<T>(n,\
    \ 0)) {}\n\n    bool empty() const { return A.empty(); }\n\n    int size() const\
    \ { return A.size(); }\n\n    int height() const { return A.size(); }\n\n    int\
    \ width() const {\n        assert(not A.empty());\n        return A[0].size();\n\
    \    }\n\n    inline const std::vector<T>& operator[](int i) const { return A[i];\
    \ }\n\n    inline std::vector<T>& operator[](int i) { return A[i]; }\n\n    static\
    \ Matrix identity(int n) {\n        Matrix res(n);\n        for (int i = 0; i\
    \ < n; i++) res[i][i] = 1;\n        return res;\n    }\n\n    Matrix& operator+=(const\
    \ Matrix& B) {\n        int n = height(), m = width();\n        assert(n == B.height()\
    \ and m == B.width());\n        for (int i = 0; i < n; i++) {\n            for\
    \ (int j = 0; j < m; j++) {\n                (*this)[i][j] += B[i][j];\n     \
    \       }\n        }\n        return *this;\n    }\n\n    Matrix& operator-=(const\
    \ Matrix& B) {\n        int n = height(), m = width();\n        assert(n == B.height()\
    \ and m == B.width());\n        for (int i = 0; i < n; i++) {\n            for\
    \ (int j = 0; j < m; j++) {\n                (*this)[i][j] -= B[i][j];\n     \
    \       }\n        }\n        return *this;\n    }\n\n    Matrix& operator*=(const\
    \ Matrix& B) {\n        int n = height(), m = B.width(), p = width();\n      \
    \  assert(p == B.height());\n        std::vector<std::vector<T>> C(n, std::vector<T>(m,\
    \ 0));\n        for (int i = 0; i < n; i++) {\n            for (int k = 0; k <\
    \ p; k++) {\n                for (int j = 0; j < m; j++) {\n                 \
    \   C[i][j] += (*this)[i][k] * B[k][j];\n                }\n            }\n  \
    \      }\n        std::swap(A, C);\n        return *this;\n    }\n\n    Matrix&\
    \ operator*=(const T& v) {\n        for (int i = 0; i < height(); i++) {\n   \
    \         for (int j = 0; j < width(); j++) {\n                (*this)[i][j] *=\
    \ v;\n            }\n        }\n        return *this;\n    }\n\n    Matrix& operator/=(const\
    \ T& v) {\n        T inv = T(1) / v;\n        for (int i = 0; i < height(); i++)\
    \ {\n            for (int j = 0; j < width(); j++) {\n                (*this)[i][j]\
    \ *= inv;\n            }\n        }\n        return *this;\n    }\n\n    Matrix\
    \ operator-() const {\n        Matrix res(height(), width());\n        for (int\
    \ i = 0; i < height(); i++) {\n            for (int j = 0; j < width(); j++) {\n\
    \                res[i][j] = -(*this)[i][j];\n            }\n        }\n     \
    \   return res;\n    }\n\n    Matrix operator+(const Matrix& B) const { return\
    \ Matrix(*this) += B; }\n\n    Matrix operator-(const Matrix& B) const { return\
    \ Matrix(*this) -= B; }\n\n    Matrix operator*(const Matrix& B) const { return\
    \ Matrix(*this) *= B; }\n\n    Matrix operator*(const T& v) const { return Matrix(*this)\
    \ *= v; }\n\n    Matrix operator/(const T& v) const { return Matrix(*this) /=\
    \ v; }\n\n    bool operator==(const Matrix& B) const {\n        assert(height()\
    \ == B.height() && width() == B.width());\n        return A == B.A;\n    }\n\n\
    \    bool operator!=(const Matrix& B) const {\n        assert(height() == B.height()\
    \ && width() == B.width());\n        return A != B.A;\n    }\n\n    Matrix pow(long\
    \ long n) const {\n        assert(0 <= n);\n        Matrix x = *this, r = identity(size());\n\
    \        while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n  \
    \          n >>= 1;\n        }\n        return r;\n    }\n\n    Matrix transpose()\
    \ const {\n        Matrix res(width(), height());\n        for (int i = 0; i <\
    \ height(); i++) {\n            for (int j = 0; j < width(); j++) {\n        \
    \        res[j][i] = (*this)[i][j];\n            }\n        }\n        return\
    \ res;\n    }\n\n    int rank() const { return Matrix(*this).gauss_jordan().first;\
    \ }\n\n    T det() const { return Matrix(*this).gauss_jordan().second; }\n\n \
    \   Matrix inv() const {\n        assert(height() == width());\n        int n\
    \ = height();\n        Matrix B(*this);\n        for (int i = 0; i < n; i++) {\n\
    \            B[i].resize(2 * n, T(0));\n            B[i][n + i] = T(1);\n    \
    \    }\n        int rank = B.gauss_jordan(n).first;\n        if (rank != n) return\
    \ {};\n        for (int i = 0; i < n; i++) {\n            B[i].erase(B[i].begin(),\
    \ B[i].begin() + n);\n        }\n        return B;\n    }\n\n    std::vector<std::vector<T>>\
    \ system_of_linear_equations(const std::vector<T>& b) const {\n        assert(height()\
    \ == int(b.size()));\n        int n = height(), m = width();\n        Matrix B(*this);\n\
    \        for (int i = 0; i < n; i++) B[i].emplace_back(b[i]);\n        int rank\
    \ = B.gauss_jordan(m).first;\n        for (int i = rank; i < n; i++) {\n     \
    \       if (B[i][m] != T(0)) {\n                return {};\n            }\n  \
    \      }\n        std::vector<std::vector<T>> res(1, std::vector<T>(m, 0));\n\
    \        std::vector<int> pivot(m, -1);\n        for (int i = 0, j = 0; i < rank;\
    \ i++) {\n            while (B[i][j] == T(0)) j++;\n            res[0][j] = B[i][m];\n\
    \            pivot[j] = i;\n        }\n        for (int j = 0; j < m; j++) {\n\
    \            if (pivot[j] != -1) continue;\n            std::vector<T> x(m, 0);\n\
    \            x[j] = 1;\n            for (int k = 0; k < j; k++) {\n          \
    \      if (pivot[k] != -1) {\n                    x[k] = -B[pivot[k]][j];\n  \
    \              }\n            }\n            res.emplace_back(x);\n        }\n\
    \        return res;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Matrix& p) {\n        int n = p.height(), m = p.width();\n       \
    \ os << \"[(\" << n << \" * \" << m << \" Matrix)\";\n        os << \"\\n[columun\
    \ sums: \";\n        for (int j = 0; j < m; j++) {\n            T sum = 0;\n \
    \           for (int i = 0; i < n; i++) sum += p[i][j];\n            os << sum\
    \ << (j + 1 < m ? \",\" : \"\");\n        }\n        os << \"]\";\n        for\
    \ (int i = 0; i < n; i++) {\n            os << \"\\n[\";\n            for (int\
    \ j = 0; j < m; j++) os << p[i][j] << (j + 1 < m ? \",\" : \"\");\n          \
    \  os << \"]\";\n        }\n        os << \"]\\n\";\n        return os;\n    }\n\
    \n  private:\n    std::pair<int, T> gauss_jordan(int pivot_end = -1) {\n     \
    \   if (empty()) return {0, T(1)};\n        if (pivot_end == -1) pivot_end = width();\n\
    \        int rank = 0;\n        T det = 1;\n        for (int j = 0; j < pivot_end;\
    \ j++) {\n            int pivot = -1;\n            for (int i = rank; i < height();\
    \ i++) {\n                if ((*this)[i][j] != T(0)) {\n                    pivot\
    \ = i;\n                    break;\n                }\n            }\n       \
    \     if (pivot == -1) {\n                det = 0;\n                continue;\n\
    \            }\n            if (pivot != rank) {\n                det = -det;\n\
    \                std::swap((*this)[pivot], (*this)[rank]);\n            }\n  \
    \          det *= A[rank][j];\n            if (A[rank][j] != T(1)) {\n       \
    \         T coef = T(1) / (*this)[rank][j];\n                for (int k = j; k\
    \ < width(); k++) (*this)[rank][k] *= coef;\n            }\n            for (int\
    \ i = 0; i < height(); i++) {\n                if (i == rank) continue;\n    \
    \            T coef = (*this)[i][j];\n                if (coef == T(0)) continue;\n\
    \                for (int k = j; k < width(); k++) (*this)[i][k] -= (*this)[rank][k]\
    \ * coef;\n            }\n            rank++;\n        }\n        return {rank,\
    \ det};\n    }\n};\n#line 3 \"src/tree/counting_spanning_trees.hpp\"\n\ntemplate\
    \ <typename T> T counting_spanning_trees_directed(std::vector<std::vector<T>>\
    \ G, int r) {\n    int n = G.size();\n    assert(0 <= r and r < n);\n    if (n\
    \ <= 1) return T(1);\n    for (int i = 0; i < n; i++) {\n        G[i][i] = 0;\n\
    \        for (int j = 0; j < n; j++) {\n            if (j != i) {\n          \
    \      G[i][i] += G[i][j];\n                G[i][j] = -G[i][j];\n            }\n\
    \        }\n    }\n    Matrix<T> L(n - 1);\n    for (int i = 0; i < n; i++) {\n\
    \        for (int j = 0; j < n; j++) {\n            if (i != r and j != r) {\n\
    \                L[i - (i > r)][j - (j > r)] = G[i][j];\n            }\n     \
    \   }\n    }\n    return L.det();\n}\n\ntemplate <typename T> T counting_spanning_trees_undirected(std::vector<std::vector<T>>\
    \ G) {\n    return counting_spanning_trees_directed(G, 0);\n}\n"
  code: "#pragma once\n#include \"../matrix/Matrix.hpp\"\n\ntemplate <typename T>\
    \ T counting_spanning_trees_directed(std::vector<std::vector<T>> G, int r) {\n\
    \    int n = G.size();\n    assert(0 <= r and r < n);\n    if (n <= 1) return\
    \ T(1);\n    for (int i = 0; i < n; i++) {\n        G[i][i] = 0;\n        for\
    \ (int j = 0; j < n; j++) {\n            if (j != i) {\n                G[i][i]\
    \ += G[i][j];\n                G[i][j] = -G[i][j];\n            }\n        }\n\
    \    }\n    Matrix<T> L(n - 1);\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int j = 0; j < n; j++) {\n            if (i != r and j != r) {\n          \
    \      L[i - (i > r)][j - (j > r)] = G[i][j];\n            }\n        }\n    }\n\
    \    return L.det();\n}\n\ntemplate <typename T> T counting_spanning_trees_undirected(std::vector<std::vector<T>>\
    \ G) {\n    return counting_spanning_trees_directed(G, 0);\n}"
  dependsOn:
  - src/matrix/Matrix.hpp
  isVerificationFile: false
  path: src/tree/counting_spanning_trees.hpp
  requiredBy: []
  timestamp: '2024-10-28 16:18:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/counting_spanning_tree_undirected.test.cpp
  - test/yosupo/counting_spanning_tree_directed.test.cpp
documentation_of: src/tree/counting_spanning_trees.hpp
layout: document
title: Counting Spanning Trees
---

## `counting_spanning_trees_undirected`

### 入力

$n$ 頂点の無向グラフ $G$ に対する隣接行列（すなわち，第 $(i, j)$ 成分が頂点 $i, j$ を結ぶ辺の本数に等しいような行列）．

### 出力

グラフの全域木の個数．

### 計算量

$\mathrm{O}(n ^ 3)$

## `counting_spanning_trees_directed`

### 入力

$n$ 頂点の有向グラフ $G$ に対する隣接行列（すなわち，第 $(i, j)$ 成分が頂点 $i$ から $j$ に向かう辺の本数に等しいような行列）及び頂点 $r$．

### 出力

根を $r$ とする（全ての頂点から根に到達できる）有向全域木の個数．

### 計算量

$\mathrm{O}(n ^ 3)$

## 概要

行列木定理より，ラプラシアン行列の行列式計算に帰着される．

## Links
- [行列木定理の証明 - blogoid](https://mizuwater0.hatenablog.com/entry/2018/11/25/233547)

## 出題例
- [AtCoder Beginner Contest 323 G - Inversion of Tree](https://atcoder.jp/contests/abc323/tasks/abc323_g)
- [AtCoder Beginner Contest 336 G - 16 Integers](https://atcoder.jp/contests/abc336/tasks/abc336_g)
  - BEST Theorem の中で有向全域木の個数を求める必要が生じる．