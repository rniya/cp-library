---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/matrix/SquareMatrix.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#include <iostream>\n\ntemplate <typename T, size_t N> struct SquareMatrix\
    \ {\n    std::array<std::array<T, N>, N> A;\n\n    SquareMatrix() : A{{}} {}\n\
    \n    size_t size() const { return N; }\n\n    inline const std::array<T, N>&\
    \ operator[](int k) const { return A[k]; }\n\n    inline std::array<T, N>& operator[](int\
    \ k) { return A[k]; }\n\n    static SquareMatrix I() {\n        SquareMatrix res;\n\
    \        for (size_t i = 0; i < N; i++) res[i][i] = 1;\n        return res;\n\
    \    }\n\n    SquareMatrix& operator+=(const SquareMatrix& B) {\n        for (size_t\
    \ i = 0; i < N; i++) {\n            for (size_t j = 0; j < N; j++) {\n       \
    \         (*this)[i][j] += B[i][j];\n            }\n        }\n        return\
    \ *this;\n    }\n\n    SquareMatrix& operator-=(const SquareMatrix& B) {\n   \
    \     for (size_t i = 0; i < N; i++) {\n            for (size_t j = 0; j < N;\
    \ j++) {\n                (*this)[i][j] -= B[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n\n    SquareMatrix& operator*=(const SquareMatrix&\
    \ B) {\n        std::array<std::array<T, N>, N> C = {};\n        for (size_t i\
    \ = 0; i < N; i++) {\n            for (size_t k = 0; k < N; k++) {\n         \
    \       for (size_t j = 0; j < N; j++) {\n                    C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n                }\n            }\n        }\n        A.swap(C);\n\
    \        return *this;\n    }\n\n    SquareMatrix& operator*=(const T& v) {\n\
    \        for (size_t i = 0; i < N; i++) {\n            for (size_t j = 0; j <\
    \ N; j++) {\n                (*this)[i][j] *= v;\n            }\n        }\n \
    \       return *this;\n    }\n\n    SquareMatrix& operator/=(const T& v) {\n \
    \       T inv = T(1) / v;\n        for (size_t i = 0; i < N; i++) {\n        \
    \    for (size_t j = 0; j < N; j++) {\n                (*this)[i][j] *= inv;\n\
    \            }\n        }\n        return *this;\n    }\n\n    SquareMatrix& operator^=(long\
    \ long k) {\n        assert(0 <= k);\n        SquareMatrix B = SquareMatrix::I();\n\
    \        while (k > 0) {\n            if (k & 1) B *= *this;\n            *this\
    \ *= *this;\n            k >>= 1;\n        }\n        A.swap(B.A);\n        return\
    \ *this;\n    }\n\n    SquareMatrix operator-() const {\n        SquareMatrix\
    \ res;\n        for (size_t i = 0; i < N; i++) {\n            for (size_t j =\
    \ 0; j < N; j++) {\n                res[i][j] = -(*this)[i][j];\n            }\n\
    \        }\n        return res;\n    }\n\n    SquareMatrix operator+(const SquareMatrix&\
    \ B) const { return SquareMatrix(*this) += B; }\n\n    SquareMatrix operator-(const\
    \ SquareMatrix& B) const { return SquareMatrix(*this) -= B; }\n\n    SquareMatrix\
    \ operator*(const SquareMatrix& B) const { return SquareMatrix(*this) *= B; }\n\
    \n    SquareMatrix operator*(const T& v) const { return SquareMatrix(*this) *=\
    \ v; }\n\n    SquareMatrix operator/(const T& v) const { return SquareMatrix(*this)\
    \ /= v; }\n\n    SquareMatrix operator^(const long long k) const { return SquareMatrix(*this)\
    \ ^= k; }\n\n    bool operator==(const SquareMatrix& B) const { return A == B.A;\
    \ }\n\n    bool operator!=(const SquareMatrix& B) const { return A != B.A; }\n\
    \n    SquareMatrix transpose() const {\n        SquareMatrix res;\n        for\
    \ (size_t i = 0; i < N; i++) {\n            for (size_t j = 0; j < N; j++) {\n\
    \                res[j][i] = (*this)[i][j];\n            }\n        }\n      \
    \  return res;\n    }\n\n    T determinant() const {\n        SquareMatrix B(*this);\n\
    \        T res = 1;\n        for (size_t i = 0; i < N; i++) {\n            int\
    \ pivot = -1;\n            for (size_t j = i; j < N; j++) {\n                if\
    \ (B[j][i] != 0) {\n                    pivot = j;\n                    break;\n\
    \                }\n            }\n            if (pivot == -1) return 0;\n  \
    \          if (pivot != (int)i) {\n                res *= -1;\n              \
    \  std::swap(B[i], B[pivot]);\n            }\n            res *= B[i][i];\n  \
    \          T inv = T(1) / B[i][i];\n            for (size_t j = 0; j < N; j++)\
    \ B[i][j] *= inv;\n            for (size_t j = i + 1; j < N; j++) {\n        \
    \        T a = B[j][i];\n                for (size_t k = 0; k < N; k++) {\n  \
    \                  B[j][k] -= B[i][k] * a;\n                }\n            }\n\
    \        }\n        return res;\n    }\n\n    SquareMatrix inv() const {\n   \
    \     SquareMatrix B(*this), C = SquareMatrix::I();\n        for (size_t i = 0;\
    \ i < N; i++) {\n            int pivot = -1;\n            for (size_t j = i; j\
    \ < N; j++) {\n                if (B[j][i] != 0) {\n                    pivot\
    \ = j;\n                    break;\n                }\n            }\n       \
    \     if (pivot == -1) return {};\n            if (pivot != (int)i) {\n      \
    \          std::swap(B[i], B[pivot]);\n                std::swap(C[i], C[pivot]);\n\
    \            }\n            T inv = T(1) / B[i][i];\n            for (size_t j\
    \ = 0; j < N; j++) {\n                B[i][j] *= inv;\n                C[i][j]\
    \ *= inv;\n            }\n            for (size_t j = 0; j < N; j++) {\n     \
    \           if (j == i) continue;\n                T a = B[j][i];\n          \
    \      for (size_t k = 0; k < N; k++) {\n                    B[j][k] -= B[i][k]\
    \ * a;\n                    C[j][k] -= C[i][k] * a;\n                }\n     \
    \       }\n        }\n        return C;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const SquareMatrix& p) {\n        os << \"[(\" << N << \" * \" << N << \"\
    \ Matrix)\";\n        os << \"\\n[columun sums: \";\n        for (size_t j = 0;\
    \ j < N; j++) {\n            T sum = 0;\n            for (size_t i = 0; i < N;\
    \ i++) sum += p[i][j];\n            ;\n            os << sum << (j + 1 < N ? \"\
    ,\" : \"\");\n        }\n        os << \"]\";\n        for (size_t i = 0; i <\
    \ N; i++) {\n            os << \"\\n[\";\n            for (size_t j = 0; j < N;\
    \ j++) os << p[i][j] << (j + 1 < N ? \",\" : \"\");\n            os << \"]\";\n\
    \        }\n        os << \"]\\n\";\n        return os;\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <iostream>\n\
    \ntemplate <typename T, size_t N> struct SquareMatrix {\n    std::array<std::array<T,\
    \ N>, N> A;\n\n    SquareMatrix() : A{{}} {}\n\n    size_t size() const { return\
    \ N; }\n\n    inline const std::array<T, N>& operator[](int k) const { return\
    \ A[k]; }\n\n    inline std::array<T, N>& operator[](int k) { return A[k]; }\n\
    \n    static SquareMatrix I() {\n        SquareMatrix res;\n        for (size_t\
    \ i = 0; i < N; i++) res[i][i] = 1;\n        return res;\n    }\n\n    SquareMatrix&\
    \ operator+=(const SquareMatrix& B) {\n        for (size_t i = 0; i < N; i++)\
    \ {\n            for (size_t j = 0; j < N; j++) {\n                (*this)[i][j]\
    \ += B[i][j];\n            }\n        }\n        return *this;\n    }\n\n    SquareMatrix&\
    \ operator-=(const SquareMatrix& B) {\n        for (size_t i = 0; i < N; i++)\
    \ {\n            for (size_t j = 0; j < N; j++) {\n                (*this)[i][j]\
    \ -= B[i][j];\n            }\n        }\n        return *this;\n    }\n\n    SquareMatrix&\
    \ operator*=(const SquareMatrix& B) {\n        std::array<std::array<T, N>, N>\
    \ C = {};\n        for (size_t i = 0; i < N; i++) {\n            for (size_t k\
    \ = 0; k < N; k++) {\n                for (size_t j = 0; j < N; j++) {\n     \
    \               C[i][j] += (*this)[i][k] * B[k][j];\n                }\n     \
    \       }\n        }\n        A.swap(C);\n        return *this;\n    }\n\n   \
    \ SquareMatrix& operator*=(const T& v) {\n        for (size_t i = 0; i < N; i++)\
    \ {\n            for (size_t j = 0; j < N; j++) {\n                (*this)[i][j]\
    \ *= v;\n            }\n        }\n        return *this;\n    }\n\n    SquareMatrix&\
    \ operator/=(const T& v) {\n        T inv = T(1) / v;\n        for (size_t i =\
    \ 0; i < N; i++) {\n            for (size_t j = 0; j < N; j++) {\n           \
    \     (*this)[i][j] *= inv;\n            }\n        }\n        return *this;\n\
    \    }\n\n    SquareMatrix& operator^=(long long k) {\n        assert(0 <= k);\n\
    \        SquareMatrix B = SquareMatrix::I();\n        while (k > 0) {\n      \
    \      if (k & 1) B *= *this;\n            *this *= *this;\n            k >>=\
    \ 1;\n        }\n        A.swap(B.A);\n        return *this;\n    }\n\n    SquareMatrix\
    \ operator-() const {\n        SquareMatrix res;\n        for (size_t i = 0; i\
    \ < N; i++) {\n            for (size_t j = 0; j < N; j++) {\n                res[i][j]\
    \ = -(*this)[i][j];\n            }\n        }\n        return res;\n    }\n\n\
    \    SquareMatrix operator+(const SquareMatrix& B) const { return SquareMatrix(*this)\
    \ += B; }\n\n    SquareMatrix operator-(const SquareMatrix& B) const { return\
    \ SquareMatrix(*this) -= B; }\n\n    SquareMatrix operator*(const SquareMatrix&\
    \ B) const { return SquareMatrix(*this) *= B; }\n\n    SquareMatrix operator*(const\
    \ T& v) const { return SquareMatrix(*this) *= v; }\n\n    SquareMatrix operator/(const\
    \ T& v) const { return SquareMatrix(*this) /= v; }\n\n    SquareMatrix operator^(const\
    \ long long k) const { return SquareMatrix(*this) ^= k; }\n\n    bool operator==(const\
    \ SquareMatrix& B) const { return A == B.A; }\n\n    bool operator!=(const SquareMatrix&\
    \ B) const { return A != B.A; }\n\n    SquareMatrix transpose() const {\n    \
    \    SquareMatrix res;\n        for (size_t i = 0; i < N; i++) {\n           \
    \ for (size_t j = 0; j < N; j++) {\n                res[j][i] = (*this)[i][j];\n\
    \            }\n        }\n        return res;\n    }\n\n    T determinant() const\
    \ {\n        SquareMatrix B(*this);\n        T res = 1;\n        for (size_t i\
    \ = 0; i < N; i++) {\n            int pivot = -1;\n            for (size_t j =\
    \ i; j < N; j++) {\n                if (B[j][i] != 0) {\n                    pivot\
    \ = j;\n                    break;\n                }\n            }\n       \
    \     if (pivot == -1) return 0;\n            if (pivot != (int)i) {\n       \
    \         res *= -1;\n                std::swap(B[i], B[pivot]);\n           \
    \ }\n            res *= B[i][i];\n            T inv = T(1) / B[i][i];\n      \
    \      for (size_t j = 0; j < N; j++) B[i][j] *= inv;\n            for (size_t\
    \ j = i + 1; j < N; j++) {\n                T a = B[j][i];\n                for\
    \ (size_t k = 0; k < N; k++) {\n                    B[j][k] -= B[i][k] * a;\n\
    \                }\n            }\n        }\n        return res;\n    }\n\n \
    \   SquareMatrix inv() const {\n        SquareMatrix B(*this), C = SquareMatrix::I();\n\
    \        for (size_t i = 0; i < N; i++) {\n            int pivot = -1;\n     \
    \       for (size_t j = i; j < N; j++) {\n                if (B[j][i] != 0) {\n\
    \                    pivot = j;\n                    break;\n                }\n\
    \            }\n            if (pivot == -1) return {};\n            if (pivot\
    \ != (int)i) {\n                std::swap(B[i], B[pivot]);\n                std::swap(C[i],\
    \ C[pivot]);\n            }\n            T inv = T(1) / B[i][i];\n           \
    \ for (size_t j = 0; j < N; j++) {\n                B[i][j] *= inv;\n        \
    \        C[i][j] *= inv;\n            }\n            for (size_t j = 0; j < N;\
    \ j++) {\n                if (j == i) continue;\n                T a = B[j][i];\n\
    \                for (size_t k = 0; k < N; k++) {\n                    B[j][k]\
    \ -= B[i][k] * a;\n                    C[j][k] -= C[i][k] * a;\n             \
    \   }\n            }\n        }\n        return C;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const SquareMatrix& p) {\n        os << \"[(\"\
    \ << N << \" * \" << N << \" Matrix)\";\n        os << \"\\n[columun sums: \"\
    ;\n        for (size_t j = 0; j < N; j++) {\n            T sum = 0;\n        \
    \    for (size_t i = 0; i < N; i++) sum += p[i][j];\n            ;\n         \
    \   os << sum << (j + 1 < N ? \",\" : \"\");\n        }\n        os << \"]\";\n\
    \        for (size_t i = 0; i < N; i++) {\n            os << \"\\n[\";\n     \
    \       for (size_t j = 0; j < N; j++) os << p[i][j] << (j + 1 < N ? \",\" : \"\
    \");\n            os << \"]\";\n        }\n        os << \"]\\n\";\n        return\
    \ os;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/matrix/SquareMatrix.hpp
  requiredBy: []
  timestamp: '2024-05-21 23:41:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1050.test.cpp
documentation_of: src/matrix/SquareMatrix.hpp
layout: document
title: "\u6B63\u65B9\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
---

## 概要
