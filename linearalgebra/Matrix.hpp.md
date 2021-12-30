---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linearalgebra/Matrix.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#include <vector>\n\ntemplate <typename T> struct Matrix {\n   \
    \ std::vector<std::vector<T>> A;\n\n    Matrix(size_t n, size_t m) : A(n, std::vector<T>(m,\
    \ 0)) {}\n\n    Matrix(size_t n) : A(n, std::vector<T>(n, 0)) {}\n\n    size_t\
    \ size() const { return A.size(); }\n\n    size_t height() const { return A.size();\
    \ }\n\n    size_t width() const { return A[0].size(); }\n\n    inline const std::vector<T>&\
    \ operator[](int k) const { return A[k]; }\n\n    inline std::vector<T>& operator[](int\
    \ k) { return A[k]; }\n\n    static Matrix I(size_t n) {\n        Matrix res(n);\n\
    \        for (size_t i = 0; i < n; i++) res[i][i] = 1;\n        return res;\n\
    \    }\n\n    Matrix& operator+=(const Matrix& B) {\n        size_t n = height(),\
    \ m = width();\n        assert(n == B.height() && m == B.width());\n        for\
    \ (size_t i = 0; i < n; i++) {\n            for (size_t j = 0; j < m; j++) {\n\
    \                (*this)[i][j] += B[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n\n    Matrix& operator-=(const Matrix& B) {\n        size_t\
    \ n = height(), m = width();\n        assert(n == B.height() && m == B.width());\n\
    \        for (size_t i = 0; i < n; i++) {\n            for (size_t j = 0; j <\
    \ m; j++) {\n                (*this)[i][j] -= B[i][j];\n            }\n      \
    \  }\n        return *this;\n    }\n\n    Matrix& operator*=(const Matrix& B)\
    \ {\n        size_t n = height(), m = B.width(), p = width();\n        assert(p\
    \ == B.height());\n        std::vector<std::vector<T>> C(n, std::vector<T>(m,\
    \ 0));\n        for (size_t i = 0; i < n; i++) {\n            for (size_t k =\
    \ 0; k < p; k++) {\n                for (size_t j = 0; j < m; j++) {\n       \
    \             C[i][j] += (*this)[i][k] * B[k][j];\n                }\n       \
    \     }\n        }\n        A.swap(C);\n        return *this;\n    }\n\n    Matrix&\
    \ operator*=(const T& v) {\n        for (size_t i = 0; i < height(); i++) {\n\
    \            for (size_t j = 0; j < width(); j++) {\n                (*this)[i][j]\
    \ *= v;\n            }\n        }\n        return *this;\n    }\n\n    Matrix&\
    \ operator/=(const T& v) {\n        T inv = T(1) / v;\n        for (size_t i =\
    \ 0; i < height(); i++) {\n            for (size_t j = 0; j < width(); j++) {\n\
    \                (*this)[i][j] *= inv;\n            }\n        }\n        return\
    \ *this;\n    }\n\n    Matrix& operator^=(long long k) {\n        assert(0 <=\
    \ k);\n        Matrix B = Matrix::I(size());\n        while (k > 0) {\n      \
    \      if (k & 1) B *= *this;\n            *this *= *this;\n            k >>=\
    \ 1;\n        }\n        A.swap(B.A);\n        return *this;\n    }\n\n    Matrix\
    \ operator-() const {\n        Matrix res(height(), width());\n        for (size_t\
    \ i = 0; i < height(); i++) {\n            for (size_t j = 0; j < width(); j++)\
    \ {\n                res[i][j] = -(*this)[i][j];\n            }\n        }\n \
    \       return res;\n    }\n\n    Matrix operator+(const Matrix& B) const { return\
    \ Matrix(*this) += B; }\n\n    Matrix operator-(const Matrix& B) const { return\
    \ Matrix(*this) -= B; }\n\n    Matrix operator*(const Matrix& B) const { return\
    \ Matrix(*this) *= B; }\n\n    Matrix operator*(const T& v) const { return Matrix(*this)\
    \ *= v; }\n\n    Matrix operator/(const T& v) const { return Matrix(*this) /=\
    \ v; }\n\n    Matrix operator^(const long long k) const { return Matrix(*this)\
    \ ^= k; }\n\n    bool operator==(const Matrix& B) const {\n        assert(height()\
    \ == B.height() && width() == B.width());\n        return A == B.A;\n    }\n\n\
    \    bool operator!=(const Matrix& B) const {\n        assert(height() == B.height()\
    \ && width() == B.width());\n        return A != B.A;\n    }\n\n    Matrix transpose()\
    \ const {\n        Matrix res(width(), height());\n        for (size_t i = 0;\
    \ i < height(); i++) {\n            for (size_t j = 0; j < width(); j++) {\n \
    \               res[j][i] = (*this)[i][j];\n            }\n        }\n       \
    \ return res;\n    }\n\n    T determinant() const {\n        assert(height() ==\
    \ width());\n        Matrix B(*this);\n        T res = 1;\n        for (size_t\
    \ i = 0; i < height(); i++) {\n            int pivot = -1;\n            for (size_t\
    \ j = i; j < height(); j++) {\n                if (B[j][i] != 0) {\n         \
    \           pivot = j;\n                    break;\n                }\n      \
    \      }\n            if (pivot == -1) return 0;\n            if (pivot != (int)i)\
    \ {\n                res *= -1;\n                std::swap(B[i], B[pivot]);\n\
    \            }\n            res *= B[i][i];\n            T inv = T(1) / B[i][i];\n\
    \            for (size_t j = 0; j < width(); j++) B[i][j] *= inv;\n          \
    \  for (size_t j = i + 1; j < height(); j++) {\n                T a = B[j][i];\n\
    \                for (size_t k = 0; k < width(); k++) {\n                    B[j][k]\
    \ -= B[i][k] * a;\n                }\n            }\n        }\n        return\
    \ res;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const Matrix&\
    \ p) {\n        size_t n = p.height(), m = p.width();\n        os << \"[(\" <<\
    \ n << \" * \" << m << \" Matrix)\";\n        os << \"\\n[columun sums: \";\n\
    \        for (size_t j = 0; j < m; j++) {\n            T sum = 0;\n          \
    \  for (size_t i = 0; i < n; i++) sum += p[i][j];\n            ;\n           \
    \ os << sum << (j + 1 < m ? \",\" : \"\");\n        }\n        os << \"]\";\n\
    \        for (size_t i = 0; i < n; i++) {\n            os << \"\\n[\";\n     \
    \       for (size_t j = 0; j < m; j++) os << p[i][j] << (j + 1 < m ? \",\" : \"\
    \");\n            os << \"]\";\n        }\n        os << \"]\\n\";\n        return\
    \ os;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    \ntemplate <typename T> struct Matrix {\n    std::vector<std::vector<T>> A;\n\n\
    \    Matrix(size_t n, size_t m) : A(n, std::vector<T>(m, 0)) {}\n\n    Matrix(size_t\
    \ n) : A(n, std::vector<T>(n, 0)) {}\n\n    size_t size() const { return A.size();\
    \ }\n\n    size_t height() const { return A.size(); }\n\n    size_t width() const\
    \ { return A[0].size(); }\n\n    inline const std::vector<T>& operator[](int k)\
    \ const { return A[k]; }\n\n    inline std::vector<T>& operator[](int k) { return\
    \ A[k]; }\n\n    static Matrix I(size_t n) {\n        Matrix res(n);\n       \
    \ for (size_t i = 0; i < n; i++) res[i][i] = 1;\n        return res;\n    }\n\n\
    \    Matrix& operator+=(const Matrix& B) {\n        size_t n = height(), m = width();\n\
    \        assert(n == B.height() && m == B.width());\n        for (size_t i = 0;\
    \ i < n; i++) {\n            for (size_t j = 0; j < m; j++) {\n              \
    \  (*this)[i][j] += B[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n\n    Matrix& operator-=(const Matrix& B) {\n        size_t n = height(),\
    \ m = width();\n        assert(n == B.height() && m == B.width());\n        for\
    \ (size_t i = 0; i < n; i++) {\n            for (size_t j = 0; j < m; j++) {\n\
    \                (*this)[i][j] -= B[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n\n    Matrix& operator*=(const Matrix& B) {\n        size_t\
    \ n = height(), m = B.width(), p = width();\n        assert(p == B.height());\n\
    \        std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));\n        for\
    \ (size_t i = 0; i < n; i++) {\n            for (size_t k = 0; k < p; k++) {\n\
    \                for (size_t j = 0; j < m; j++) {\n                    C[i][j]\
    \ += (*this)[i][k] * B[k][j];\n                }\n            }\n        }\n \
    \       A.swap(C);\n        return *this;\n    }\n\n    Matrix& operator*=(const\
    \ T& v) {\n        for (size_t i = 0; i < height(); i++) {\n            for (size_t\
    \ j = 0; j < width(); j++) {\n                (*this)[i][j] *= v;\n          \
    \  }\n        }\n        return *this;\n    }\n\n    Matrix& operator/=(const\
    \ T& v) {\n        T inv = T(1) / v;\n        for (size_t i = 0; i < height();\
    \ i++) {\n            for (size_t j = 0; j < width(); j++) {\n               \
    \ (*this)[i][j] *= inv;\n            }\n        }\n        return *this;\n   \
    \ }\n\n    Matrix& operator^=(long long k) {\n        assert(0 <= k);\n      \
    \  Matrix B = Matrix::I(size());\n        while (k > 0) {\n            if (k &\
    \ 1) B *= *this;\n            *this *= *this;\n            k >>= 1;\n        }\n\
    \        A.swap(B.A);\n        return *this;\n    }\n\n    Matrix operator-()\
    \ const {\n        Matrix res(height(), width());\n        for (size_t i = 0;\
    \ i < height(); i++) {\n            for (size_t j = 0; j < width(); j++) {\n \
    \               res[i][j] = -(*this)[i][j];\n            }\n        }\n      \
    \  return res;\n    }\n\n    Matrix operator+(const Matrix& B) const { return\
    \ Matrix(*this) += B; }\n\n    Matrix operator-(const Matrix& B) const { return\
    \ Matrix(*this) -= B; }\n\n    Matrix operator*(const Matrix& B) const { return\
    \ Matrix(*this) *= B; }\n\n    Matrix operator*(const T& v) const { return Matrix(*this)\
    \ *= v; }\n\n    Matrix operator/(const T& v) const { return Matrix(*this) /=\
    \ v; }\n\n    Matrix operator^(const long long k) const { return Matrix(*this)\
    \ ^= k; }\n\n    bool operator==(const Matrix& B) const {\n        assert(height()\
    \ == B.height() && width() == B.width());\n        return A == B.A;\n    }\n\n\
    \    bool operator!=(const Matrix& B) const {\n        assert(height() == B.height()\
    \ && width() == B.width());\n        return A != B.A;\n    }\n\n    Matrix transpose()\
    \ const {\n        Matrix res(width(), height());\n        for (size_t i = 0;\
    \ i < height(); i++) {\n            for (size_t j = 0; j < width(); j++) {\n \
    \               res[j][i] = (*this)[i][j];\n            }\n        }\n       \
    \ return res;\n    }\n\n    T determinant() const {\n        assert(height() ==\
    \ width());\n        Matrix B(*this);\n        T res = 1;\n        for (size_t\
    \ i = 0; i < height(); i++) {\n            int pivot = -1;\n            for (size_t\
    \ j = i; j < height(); j++) {\n                if (B[j][i] != 0) {\n         \
    \           pivot = j;\n                    break;\n                }\n      \
    \      }\n            if (pivot == -1) return 0;\n            if (pivot != (int)i)\
    \ {\n                res *= -1;\n                std::swap(B[i], B[pivot]);\n\
    \            }\n            res *= B[i][i];\n            T inv = T(1) / B[i][i];\n\
    \            for (size_t j = 0; j < width(); j++) B[i][j] *= inv;\n          \
    \  for (size_t j = i + 1; j < height(); j++) {\n                T a = B[j][i];\n\
    \                for (size_t k = 0; k < width(); k++) {\n                    B[j][k]\
    \ -= B[i][k] * a;\n                }\n            }\n        }\n        return\
    \ res;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const Matrix&\
    \ p) {\n        size_t n = p.height(), m = p.width();\n        os << \"[(\" <<\
    \ n << \" * \" << m << \" Matrix)\";\n        os << \"\\n[columun sums: \";\n\
    \        for (size_t j = 0; j < m; j++) {\n            T sum = 0;\n          \
    \  for (size_t i = 0; i < n; i++) sum += p[i][j];\n            ;\n           \
    \ os << sum << (j + 1 < m ? \",\" : \"\");\n        }\n        os << \"]\";\n\
    \        for (size_t i = 0; i < n; i++) {\n            os << \"\\n[\";\n     \
    \       for (size_t j = 0; j < m; j++) os << p[i][j] << (j + 1 < m ? \",\" : \"\
    \");\n            os << \"]\";\n        }\n        os << \"]\\n\";\n        return\
    \ os;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linearalgebra/Matrix.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:27:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_det.test.cpp
documentation_of: linearalgebra/Matrix.hpp
layout: document
title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
---

## 概要
基本的な行列演算を搭載したライブラリ. 行列式も `determinant()` で $O(n^3)$ で求めることができる.
