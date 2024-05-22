---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_product.test.cpp
    title: test/yosupo/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_matrix.test.cpp
    title: test/yosupo/pow_of_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/matrix/Matrix.hpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename T> struct Matrix {\n\
    \    std::vector<std::vector<T>> A;\n\n    Matrix() = default;\n\n    Matrix(int\
    \ n, int m) : A(n, std::vector<T>(m, 0)) {}\n\n    Matrix(int n) : A(n, std::vector<T>(n,\
    \ 0)) {}\n\n    int size() const { return A.size(); }\n\n    int height() const\
    \ { return A.size(); }\n\n    int width() const { return A[0].size(); }\n\n  \
    \  inline const std::vector<T>& operator[](int k) const { return A[k]; }\n   \
    \ inline std::vector<T>& operator[](int k) { return A[k]; }\n\n    static Matrix\
    \ identity(int n) {\n        Matrix res(n);\n        for (int i = 0; i < n; i++)\
    \ res[i][i] = 1;\n        return res;\n    }\n\n    Matrix& operator+=(const Matrix&\
    \ B) {\n        int n = height(), m = width();\n        assert(n == B.height()\
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
    \ res;\n    }\n\n    T determinant() const {\n        assert(height() == width());\n\
    \        Matrix B(*this);\n        T res = 1;\n        for (int i = 0; i < height();\
    \ i++) {\n            int pivot = -1;\n            for (int j = i; j < height();\
    \ j++) {\n                if (B[j][i] != 0) {\n                    pivot = j;\n\
    \                    break;\n                }\n            }\n            if\
    \ (pivot == -1) return 0;\n            if (pivot != (int)i) {\n              \
    \  res *= -1;\n                std::swap(B[i], B[pivot]);\n            }\n   \
    \         res *= B[i][i];\n            T inv = T(1) / B[i][i];\n            for\
    \ (int j = 0; j < width(); j++) B[i][j] *= inv;\n            for (int j = i +\
    \ 1; j < height(); j++) {\n                T a = B[j][i];\n                for\
    \ (int k = 0; k < width(); k++) {\n                    B[j][k] -= B[i][k] * a;\n\
    \                }\n            }\n        }\n        return res;\n    }\n\n \
    \   std::pair<int, T> gauss_jordan() {}\n\n    int rank() const {}\n\n    T det()\
    \ const {}\n\n    Matrix inv() const {}\n\n    std::vector<std::vector<T>> system_of_linear_equations(const\
    \ std::vector<T>& b) const {}\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Matrix& p) {\n        int n = p.height(), m = p.width();\n       \
    \ os << \"[(\" << n << \" * \" << m << \" Matrix)\";\n        os << \"\\n[columun\
    \ sums: \";\n        for (int j = 0; j < m; j++) {\n            T sum = 0;\n \
    \           for (int i = 0; i < n; i++) sum += p[i][j];\n            os << sum\
    \ << (j + 1 < m ? \",\" : \"\");\n        }\n        os << \"]\";\n        for\
    \ (int i = 0; i < n; i++) {\n            os << \"\\n[\";\n            for (int\
    \ j = 0; j < m; j++) os << p[i][j] << (j + 1 < m ? \",\" : \"\");\n          \
    \  os << \"]\";\n        }\n        os << \"]\\n\";\n        return os;\n    }\n\
    };\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T> struct Matrix {\n    std::vector<std::vector<T>>\
    \ A;\n\n    Matrix() = default;\n\n    Matrix(int n, int m) : A(n, std::vector<T>(m,\
    \ 0)) {}\n\n    Matrix(int n) : A(n, std::vector<T>(n, 0)) {}\n\n    int size()\
    \ const { return A.size(); }\n\n    int height() const { return A.size(); }\n\n\
    \    int width() const { return A[0].size(); }\n\n    inline const std::vector<T>&\
    \ operator[](int k) const { return A[k]; }\n    inline std::vector<T>& operator[](int\
    \ k) { return A[k]; }\n\n    static Matrix identity(int n) {\n        Matrix res(n);\n\
    \        for (int i = 0; i < n; i++) res[i][i] = 1;\n        return res;\n   \
    \ }\n\n    Matrix& operator+=(const Matrix& B) {\n        int n = height(), m\
    \ = width();\n        assert(n == B.height() and m == B.width());\n        for\
    \ (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n     \
    \           (*this)[i][j] += B[i][j];\n            }\n        }\n        return\
    \ *this;\n    }\n\n    Matrix& operator-=(const Matrix& B) {\n        int n =\
    \ height(), m = width();\n        assert(n == B.height() and m == B.width());\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                (*this)[i][j] -= B[i][j];\n            }\n        }\n   \
    \     return *this;\n    }\n\n    Matrix& operator*=(const Matrix& B) {\n    \
    \    int n = height(), m = B.width(), p = width();\n        assert(p == B.height());\n\
    \        std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));\n        for\
    \ (int i = 0; i < n; i++) {\n            for (int k = 0; k < p; k++) {\n     \
    \           for (int j = 0; j < m; j++) {\n                    C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n                }\n            }\n        }\n        std::swap(A,\
    \ C);\n        return *this;\n    }\n\n    Matrix& operator*=(const T& v) {\n\
    \        for (int i = 0; i < height(); i++) {\n            for (int j = 0; j <\
    \ width(); j++) {\n                (*this)[i][j] *= v;\n            }\n      \
    \  }\n        return *this;\n    }\n\n    Matrix& operator/=(const T& v) {\n \
    \       T inv = T(1) / v;\n        for (int i = 0; i < height(); i++) {\n    \
    \        for (int j = 0; j < width(); j++) {\n                (*this)[i][j] *=\
    \ inv;\n            }\n        }\n        return *this;\n    }\n\n    Matrix operator-()\
    \ const {\n        Matrix res(height(), width());\n        for (int i = 0; i <\
    \ height(); i++) {\n            for (int j = 0; j < width(); j++) {\n        \
    \        res[i][j] = -(*this)[i][j];\n            }\n        }\n        return\
    \ res;\n    }\n\n    Matrix operator+(const Matrix& B) const { return Matrix(*this)\
    \ += B; }\n\n    Matrix operator-(const Matrix& B) const { return Matrix(*this)\
    \ -= B; }\n\n    Matrix operator*(const Matrix& B) const { return Matrix(*this)\
    \ *= B; }\n\n    Matrix operator*(const T& v) const { return Matrix(*this) *=\
    \ v; }\n\n    Matrix operator/(const T& v) const { return Matrix(*this) /= v;\
    \ }\n\n    bool operator==(const Matrix& B) const {\n        assert(height() ==\
    \ B.height() && width() == B.width());\n        return A == B.A;\n    }\n\n  \
    \  bool operator!=(const Matrix& B) const {\n        assert(height() == B.height()\
    \ && width() == B.width());\n        return A != B.A;\n    }\n\n    Matrix pow(long\
    \ long n) const {\n        assert(0 <= n);\n        Matrix x = *this, r = identity(size());\n\
    \        while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n  \
    \          n >>= 1;\n        }\n        return r;\n    }\n\n    Matrix transpose()\
    \ const {\n        Matrix res(width(), height());\n        for (int i = 0; i <\
    \ height(); i++) {\n            for (int j = 0; j < width(); j++) {\n        \
    \        res[j][i] = (*this)[i][j];\n            }\n        }\n        return\
    \ res;\n    }\n\n    T determinant() const {\n        assert(height() == width());\n\
    \        Matrix B(*this);\n        T res = 1;\n        for (int i = 0; i < height();\
    \ i++) {\n            int pivot = -1;\n            for (int j = i; j < height();\
    \ j++) {\n                if (B[j][i] != 0) {\n                    pivot = j;\n\
    \                    break;\n                }\n            }\n            if\
    \ (pivot == -1) return 0;\n            if (pivot != (int)i) {\n              \
    \  res *= -1;\n                std::swap(B[i], B[pivot]);\n            }\n   \
    \         res *= B[i][i];\n            T inv = T(1) / B[i][i];\n            for\
    \ (int j = 0; j < width(); j++) B[i][j] *= inv;\n            for (int j = i +\
    \ 1; j < height(); j++) {\n                T a = B[j][i];\n                for\
    \ (int k = 0; k < width(); k++) {\n                    B[j][k] -= B[i][k] * a;\n\
    \                }\n            }\n        }\n        return res;\n    }\n\n \
    \   std::pair<int, T> gauss_jordan() {}\n\n    int rank() const {}\n\n    T det()\
    \ const {}\n\n    Matrix inv() const {}\n\n    std::vector<std::vector<T>> system_of_linear_equations(const\
    \ std::vector<T>& b) const {}\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Matrix& p) {\n        int n = p.height(), m = p.width();\n       \
    \ os << \"[(\" << n << \" * \" << m << \" Matrix)\";\n        os << \"\\n[columun\
    \ sums: \";\n        for (int j = 0; j < m; j++) {\n            T sum = 0;\n \
    \           for (int i = 0; i < n; i++) sum += p[i][j];\n            os << sum\
    \ << (j + 1 < m ? \",\" : \"\");\n        }\n        os << \"]\";\n        for\
    \ (int i = 0; i < n; i++) {\n            os << \"\\n[\";\n            for (int\
    \ j = 0; j < m; j++) os << p[i][j] << (j + 1 < m ? \",\" : \"\");\n          \
    \  os << \"]\";\n        }\n        os << \"]\\n\";\n        return os;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/matrix/Matrix.hpp
  requiredBy: []
  timestamp: '2024-05-22 22:29:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_product.test.cpp
  - test/yosupo/pow_of_matrix.test.cpp
  - test/yosupo/matrix_det.test.cpp
documentation_of: src/matrix/Matrix.hpp
layout: document
title: Matrix
---

## 概要
基本的な行列演算を搭載したライブラリ．行列式も `determinant()` で $O(n^3)$ で求めることができる．
