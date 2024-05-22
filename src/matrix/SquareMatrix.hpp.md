---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/pow_of_matrix.squarematrix.test.cpp
    title: test/yosupo/pow_of_matrix.squarematrix.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/matrix/SquareMatrix.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#include <utility>\n\ntemplate <typename T, int N> struct SquareMatrix\
    \ {\n    std::array<std::array<T, N>, N> A;\n\n    SquareMatrix() : A() {\n  \
    \      for (int i = 0; i < N; i++) {\n            for (int j = 0; j < N; j++)\
    \ {\n                A[i][j] = T();\n            }\n        }\n    }\n\n    int\
    \ size() const { return N; }\n\n    inline const std::array<T, N>& operator[](int\
    \ k) const { return A[k]; }\n\n    inline std::array<T, N>& operator[](int k)\
    \ { return A[k]; }\n\n    static SquareMatrix identity() {\n        SquareMatrix\
    \ res;\n        for (int i = 0; i < N; i++) res[i][i] = 1;\n        return res;\n\
    \    }\n\n    SquareMatrix& operator+=(const SquareMatrix& B) {\n        for (int\
    \ i = 0; i < N; i++) {\n            for (int j = 0; j < N; j++) {\n          \
    \      (*this)[i][j] += B[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n\n    SquareMatrix& operator-=(const SquareMatrix& B) {\n        for (int\
    \ i = 0; i < N; i++) {\n            for (int j = 0; j < N; j++) {\n          \
    \      (*this)[i][j] -= B[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n\n    SquareMatrix& operator*=(const SquareMatrix& B) {\n        std::array<std::array<T,\
    \ N>, N> C;\n        for (int i = 0; i < N; i++) {\n            for (int k = 0;\
    \ k < N; k++) {\n                for (int j = 0; j < N; j++) {\n             \
    \       C[i][j] += (*this)[i][k] * B[k][j];\n                }\n            }\n\
    \        }\n        std::swap(A, C);\n        return *this;\n    }\n\n    SquareMatrix&\
    \ operator*=(const T& v) {\n        for (int i = 0; i < N; i++) {\n          \
    \  for (int j = 0; j < N; j++) {\n                (*this)[i][j] *= v;\n      \
    \      }\n        }\n        return *this;\n    }\n\n    SquareMatrix& operator/=(const\
    \ T& v) {\n        T inv = T(1) / v;\n        for (int i = 0; i < N; i++) {\n\
    \            for (int j = 0; j < N; j++) {\n                (*this)[i][j] *= inv;\n\
    \            }\n        }\n        return *this;\n    }\n\n    SquareMatrix operator-()\
    \ const {\n        SquareMatrix res;\n        for (int i = 0; i < N; i++) {\n\
    \            for (int j = 0; j < N; j++) {\n                res[i][j] = -(*this)[i][j];\n\
    \            }\n        }\n        return res;\n    }\n\n    SquareMatrix operator+(const\
    \ SquareMatrix& B) const { return SquareMatrix(*this) += B; }\n\n    SquareMatrix\
    \ operator-(const SquareMatrix& B) const { return SquareMatrix(*this) -= B; }\n\
    \n    SquareMatrix operator*(const SquareMatrix& B) const { return SquareMatrix(*this)\
    \ *= B; }\n\n    SquareMatrix operator*(const T& v) const { return SquareMatrix(*this)\
    \ *= v; }\n\n    SquareMatrix operator/(const T& v) const { return SquareMatrix(*this)\
    \ /= v; }\n\n    bool operator==(const SquareMatrix& B) const { return A == B.A;\
    \ }\n\n    bool operator!=(const SquareMatrix& B) const { return A != B.A; }\n\
    \n    SquareMatrix pow(long long n) const {\n        assert(0 <= n);\n       \
    \ SquareMatrix x = *this, r = identity();\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n\n    SquareMatrix transpose() const {\n        SquareMatrix\
    \ res;\n        for (int i = 0; i < N; i++) {\n            for (int j = 0; j <\
    \ N; j++) {\n                res[j][i] = (*this)[i][j];\n            }\n     \
    \   }\n        return res;\n    }\n\n    int rank() const { return Matrix(*this).gauss_jordan().first;\
    \ }\n\n    T det() const { return Matrix(*this).gauss_jordan().second; }\n\n \
    \   SquareMatrix inv() const {\n        SquareMatrix B(*this), C = identity();\n\
    \        for (int j = 0; j < N; j++) {\n            int pivot = -1;\n        \
    \    for (int i = j; i < N; i++) {\n                if (B[i][j] != T(0)) {\n \
    \                   pivot = i;\n                    break;\n                }\n\
    \            }\n            assert(pivot != -1);\n            if (pivot != j)\
    \ {\n                std::swap(B[pivot], B[j]);\n                std::swap(C[pivot],\
    \ C[j]);\n            }\n            {\n                T coef = T(1) / B[j][j];\n\
    \                for (int k = 0; k < N; k++) {\n                    B[j][k] *=\
    \ coef;\n                    C[j][k] *= coef;\n                }\n           \
    \ }\n            for (int i = 0; i < N; i++) {\n                if (i == j) continue;\n\
    \                T coef = B[i][j];\n                if (coef == T(0)) continue;\n\
    \                for (int k = 0; k < N; k++) {\n                    B[i][k] -=\
    \ B[j][k] * coef;\n                    C[i][k] -= C[j][k] * coef;\n          \
    \      }\n            }\n        }\n        return C;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const SquareMatrix& p) {\n        os << \"[(\"\
    \ << N << \" * \" << N << \" Matrix)\";\n        os << \"\\n[columun sums: \"\
    ;\n        for (int j = 0; j < N; j++) {\n            T sum = 0;\n           \
    \ for (int i = 0; i < N; i++) sum += p[i][j];\n            ;\n            os <<\
    \ sum << (j + 1 < N ? \",\" : \"\");\n        }\n        os << \"]\";\n      \
    \  for (int i = 0; i < N; i++) {\n            os << \"\\n[\";\n            for\
    \ (int j = 0; j < N; j++) os << p[i][j] << (j + 1 < N ? \",\" : \"\");\n     \
    \       os << \"]\";\n        }\n        os << \"]\\n\";\n        return os;\n\
    \    }\n\n  private:\n    std::pair<int, T> gauss_jordan() {\n        int rank\
    \ = 0;\n        T det = 1;\n        for (int j = 0; j < N; j++) {\n          \
    \  int pivot = -1;\n            for (int i = rank; i < N; i++) {\n           \
    \     if ((*this)[i][j] != T(0)) {\n                    pivot = i;\n         \
    \           break;\n                }\n            }\n            if (pivot ==\
    \ -1) {\n                det = 0;\n                continue;\n            }\n\
    \            if (pivot != rank) {\n                det = -det;\n             \
    \   std::swap((*this)[pivot], (*this)[rank]);\n            }\n            det\
    \ *= A[rank][j];\n            if (A[rank][j] != T(1)) {\n                T coef\
    \ = T(1) / (*this)[rank][j];\n                for (int k = j; k < N; k++) (*this)[rank][k]\
    \ *= coef;\n            }\n            for (int i = 0; i < N; i++) {\n       \
    \         if (i == rank) continue;\n                T coef = (*this)[i][j];\n\
    \                if (coef == T(0)) continue;\n                for (int k = j;\
    \ k < N; k++) (*this)[i][k] -= (*this)[rank][k] * coef;\n            }\n     \
    \       rank++;\n        }\n        return {rank, det};\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <utility>\n\n\
    template <typename T, int N> struct SquareMatrix {\n    std::array<std::array<T,\
    \ N>, N> A;\n\n    SquareMatrix() : A() {\n        for (int i = 0; i < N; i++)\
    \ {\n            for (int j = 0; j < N; j++) {\n                A[i][j] = T();\n\
    \            }\n        }\n    }\n\n    int size() const { return N; }\n\n   \
    \ inline const std::array<T, N>& operator[](int k) const { return A[k]; }\n\n\
    \    inline std::array<T, N>& operator[](int k) { return A[k]; }\n\n    static\
    \ SquareMatrix identity() {\n        SquareMatrix res;\n        for (int i = 0;\
    \ i < N; i++) res[i][i] = 1;\n        return res;\n    }\n\n    SquareMatrix&\
    \ operator+=(const SquareMatrix& B) {\n        for (int i = 0; i < N; i++) {\n\
    \            for (int j = 0; j < N; j++) {\n                (*this)[i][j] += B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    SquareMatrix& operator-=(const\
    \ SquareMatrix& B) {\n        for (int i = 0; i < N; i++) {\n            for (int\
    \ j = 0; j < N; j++) {\n                (*this)[i][j] -= B[i][j];\n          \
    \  }\n        }\n        return *this;\n    }\n\n    SquareMatrix& operator*=(const\
    \ SquareMatrix& B) {\n        std::array<std::array<T, N>, N> C;\n        for\
    \ (int i = 0; i < N; i++) {\n            for (int k = 0; k < N; k++) {\n     \
    \           for (int j = 0; j < N; j++) {\n                    C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n                }\n            }\n        }\n        std::swap(A,\
    \ C);\n        return *this;\n    }\n\n    SquareMatrix& operator*=(const T& v)\
    \ {\n        for (int i = 0; i < N; i++) {\n            for (int j = 0; j < N;\
    \ j++) {\n                (*this)[i][j] *= v;\n            }\n        }\n    \
    \    return *this;\n    }\n\n    SquareMatrix& operator/=(const T& v) {\n    \
    \    T inv = T(1) / v;\n        for (int i = 0; i < N; i++) {\n            for\
    \ (int j = 0; j < N; j++) {\n                (*this)[i][j] *= inv;\n         \
    \   }\n        }\n        return *this;\n    }\n\n    SquareMatrix operator-()\
    \ const {\n        SquareMatrix res;\n        for (int i = 0; i < N; i++) {\n\
    \            for (int j = 0; j < N; j++) {\n                res[i][j] = -(*this)[i][j];\n\
    \            }\n        }\n        return res;\n    }\n\n    SquareMatrix operator+(const\
    \ SquareMatrix& B) const { return SquareMatrix(*this) += B; }\n\n    SquareMatrix\
    \ operator-(const SquareMatrix& B) const { return SquareMatrix(*this) -= B; }\n\
    \n    SquareMatrix operator*(const SquareMatrix& B) const { return SquareMatrix(*this)\
    \ *= B; }\n\n    SquareMatrix operator*(const T& v) const { return SquareMatrix(*this)\
    \ *= v; }\n\n    SquareMatrix operator/(const T& v) const { return SquareMatrix(*this)\
    \ /= v; }\n\n    bool operator==(const SquareMatrix& B) const { return A == B.A;\
    \ }\n\n    bool operator!=(const SquareMatrix& B) const { return A != B.A; }\n\
    \n    SquareMatrix pow(long long n) const {\n        assert(0 <= n);\n       \
    \ SquareMatrix x = *this, r = identity();\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n\n    SquareMatrix transpose() const {\n        SquareMatrix\
    \ res;\n        for (int i = 0; i < N; i++) {\n            for (int j = 0; j <\
    \ N; j++) {\n                res[j][i] = (*this)[i][j];\n            }\n     \
    \   }\n        return res;\n    }\n\n    int rank() const { return Matrix(*this).gauss_jordan().first;\
    \ }\n\n    T det() const { return Matrix(*this).gauss_jordan().second; }\n\n \
    \   SquareMatrix inv() const {\n        SquareMatrix B(*this), C = identity();\n\
    \        for (int j = 0; j < N; j++) {\n            int pivot = -1;\n        \
    \    for (int i = j; i < N; i++) {\n                if (B[i][j] != T(0)) {\n \
    \                   pivot = i;\n                    break;\n                }\n\
    \            }\n            assert(pivot != -1);\n            if (pivot != j)\
    \ {\n                std::swap(B[pivot], B[j]);\n                std::swap(C[pivot],\
    \ C[j]);\n            }\n            {\n                T coef = T(1) / B[j][j];\n\
    \                for (int k = 0; k < N; k++) {\n                    B[j][k] *=\
    \ coef;\n                    C[j][k] *= coef;\n                }\n           \
    \ }\n            for (int i = 0; i < N; i++) {\n                if (i == j) continue;\n\
    \                T coef = B[i][j];\n                if (coef == T(0)) continue;\n\
    \                for (int k = 0; k < N; k++) {\n                    B[i][k] -=\
    \ B[j][k] * coef;\n                    C[i][k] -= C[j][k] * coef;\n          \
    \      }\n            }\n        }\n        return C;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const SquareMatrix& p) {\n        os << \"[(\"\
    \ << N << \" * \" << N << \" Matrix)\";\n        os << \"\\n[columun sums: \"\
    ;\n        for (int j = 0; j < N; j++) {\n            T sum = 0;\n           \
    \ for (int i = 0; i < N; i++) sum += p[i][j];\n            ;\n            os <<\
    \ sum << (j + 1 < N ? \",\" : \"\");\n        }\n        os << \"]\";\n      \
    \  for (int i = 0; i < N; i++) {\n            os << \"\\n[\";\n            for\
    \ (int j = 0; j < N; j++) os << p[i][j] << (j + 1 < N ? \",\" : \"\");\n     \
    \       os << \"]\";\n        }\n        os << \"]\\n\";\n        return os;\n\
    \    }\n\n  private:\n    std::pair<int, T> gauss_jordan() {\n        int rank\
    \ = 0;\n        T det = 1;\n        for (int j = 0; j < N; j++) {\n          \
    \  int pivot = -1;\n            for (int i = rank; i < N; i++) {\n           \
    \     if ((*this)[i][j] != T(0)) {\n                    pivot = i;\n         \
    \           break;\n                }\n            }\n            if (pivot ==\
    \ -1) {\n                det = 0;\n                continue;\n            }\n\
    \            if (pivot != rank) {\n                det = -det;\n             \
    \   std::swap((*this)[pivot], (*this)[rank]);\n            }\n            det\
    \ *= A[rank][j];\n            if (A[rank][j] != T(1)) {\n                T coef\
    \ = T(1) / (*this)[rank][j];\n                for (int k = j; k < N; k++) (*this)[rank][k]\
    \ *= coef;\n            }\n            for (int i = 0; i < N; i++) {\n       \
    \         if (i == rank) continue;\n                T coef = (*this)[i][j];\n\
    \                if (coef == T(0)) continue;\n                for (int k = j;\
    \ k < N; k++) (*this)[i][k] -= (*this)[rank][k] * coef;\n            }\n     \
    \       rank++;\n        }\n        return {rank, det};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/matrix/SquareMatrix.hpp
  requiredBy: []
  timestamp: '2024-05-23 01:55:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1050.test.cpp
  - test/yosupo/pow_of_matrix.squarematrix.test.cpp
documentation_of: src/matrix/SquareMatrix.hpp
layout: document
title: Square Matrix
---

## 概要
