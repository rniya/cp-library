---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/526.test.cpp
    title: test/yukicoder/526.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/linearalgebra/Matrix.md
    document_title: Matrix
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"linearalgebra/Matrix.hpp\"\
    \n\n/**\n * @brief Matrix\n * @docs docs/linearalgebra/Matrix.md\n */\ntemplate\
    \ <class T> struct Matrix {\n    vector<vector<T>> A;\n    Matrix(size_t n, size_t\
    \ m) : A(n, vector<T>(m, 0)) {}\n    Matrix(size_t n) : A(n, vector<T>(n, 0))\
    \ {}\n    size_t height() const { return A.size(); }\n    size_t width() const\
    \ { return A[0].size(); }\n    inline const vector<T>& operator[](int i) const\
    \ { return A[i]; }\n    inline vector<T>& operator[](int i) { return A[i]; }\n\
    \    static Matrix I(size_t n) {\n        Matrix res(n);\n        for (int i =\
    \ 0; i < n; i++) res[i][i] = 1;\n        return res;\n    }\n    Matrix operator+(const\
    \ Matrix& B) const { return Matrix(*this) += B; }\n    Matrix operator-(const\
    \ Matrix& B) const { return Matrix(*this) -= B; }\n    Matrix operator*(const\
    \ Matrix& B) const { return Matrix(*this) *= B; }\n    Matrix operator^(const\
    \ long long k) const { return Matrix(*this) ^= k; }\n    Matrix& operator+=(const\
    \ Matrix& B) {\n        size_t n = height(), m = width();\n        assert(n ==\
    \ B.height() && m == B.width());\n        for (int i = 0; i < n; i++) {\n    \
    \        for (int j = 0; j < m; j++) {\n                (*this)[i][j] += B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix& operator-=(const\
    \ Matrix& B) {\n        size_t n = height(), m = width();\n        assert(n ==\
    \ B.height() && m == B.width());\n        for (int i = 0; i < n; i++) {\n    \
    \        for (int j = 0; j < m; j++) {\n                (*this)[i][j] -= B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix& operator*=(const\
    \ Matrix& B) {\n        size_t n = height(), m = B.width(), l = width();\n   \
    \     assert(l == B.height());\n        vector<vector<T>> C(n, vector<T>(m, 0));\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                for (int k = 0; k < l; k++) {\n                    C[i][j]\
    \ += (*this)[i][k] * B[k][j];\n                }\n            }\n        }\n \
    \       A.swap(C);\n        return *this;\n    }\n    Matrix& operator^=(long\
    \ long k) {\n        Matrix res = Matrix::I(height());\n        while (k > 0)\
    \ {\n            if (k & 1) res *= *this;\n            *this *= *this;\n     \
    \       k >>= 1LL;\n        }\n        A.swap(res.A);\n        return *this;\n\
    \    }\n    T determinant() {\n        Matrix B(*this);\n        T res = 1;\n\
    \        for (int i = 0; i < width(); i++) {\n            int pivot = -1;\n  \
    \          for (int j = i; j < height(); j++) {\n                if (B[j][i] !=\
    \ 0) {\n                    pivot = j;\n                }\n            }\n   \
    \         if (pivot < 0) return 0;\n            if (pivot != i) {\n          \
    \      res *= -1;\n                swap(B[i], B[pivot]);\n            }\n    \
    \        res *= B[i][i];\n            T v = T(1) / B[i][i];\n            for (int\
    \ j = 0; j < width(); j++) B[i][j] *= v;\n            for (int j = i + 1; j <\
    \ height(); j++) {\n                T w = B[j][i];\n                for (int k\
    \ = 0; k < width(); k++) {\n                    B[j][k] -= B[i][k] * w;\n    \
    \            }\n            }\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Matrix\n * @docs\
    \ docs/linearalgebra/Matrix.md\n */\ntemplate <class T> struct Matrix {\n    vector<vector<T>>\
    \ A;\n    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}\n    Matrix(size_t\
    \ n) : A(n, vector<T>(n, 0)) {}\n    size_t height() const { return A.size();\
    \ }\n    size_t width() const { return A[0].size(); }\n    inline const vector<T>&\
    \ operator[](int i) const { return A[i]; }\n    inline vector<T>& operator[](int\
    \ i) { return A[i]; }\n    static Matrix I(size_t n) {\n        Matrix res(n);\n\
    \        for (int i = 0; i < n; i++) res[i][i] = 1;\n        return res;\n   \
    \ }\n    Matrix operator+(const Matrix& B) const { return Matrix(*this) += B;\
    \ }\n    Matrix operator-(const Matrix& B) const { return Matrix(*this) -= B;\
    \ }\n    Matrix operator*(const Matrix& B) const { return Matrix(*this) *= B;\
    \ }\n    Matrix operator^(const long long k) const { return Matrix(*this) ^= k;\
    \ }\n    Matrix& operator+=(const Matrix& B) {\n        size_t n = height(), m\
    \ = width();\n        assert(n == B.height() && m == B.width());\n        for\
    \ (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n     \
    \           (*this)[i][j] += B[i][j];\n            }\n        }\n        return\
    \ *this;\n    }\n    Matrix& operator-=(const Matrix& B) {\n        size_t n =\
    \ height(), m = width();\n        assert(n == B.height() && m == B.width());\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                (*this)[i][j] -= B[i][j];\n            }\n        }\n   \
    \     return *this;\n    }\n    Matrix& operator*=(const Matrix& B) {\n      \
    \  size_t n = height(), m = B.width(), l = width();\n        assert(l == B.height());\n\
    \        vector<vector<T>> C(n, vector<T>(m, 0));\n        for (int i = 0; i <\
    \ n; i++) {\n            for (int j = 0; j < m; j++) {\n                for (int\
    \ k = 0; k < l; k++) {\n                    C[i][j] += (*this)[i][k] * B[k][j];\n\
    \                }\n            }\n        }\n        A.swap(C);\n        return\
    \ *this;\n    }\n    Matrix& operator^=(long long k) {\n        Matrix res = Matrix::I(height());\n\
    \        while (k > 0) {\n            if (k & 1) res *= *this;\n            *this\
    \ *= *this;\n            k >>= 1LL;\n        }\n        A.swap(res.A);\n     \
    \   return *this;\n    }\n    T determinant() {\n        Matrix B(*this);\n  \
    \      T res = 1;\n        for (int i = 0; i < width(); i++) {\n            int\
    \ pivot = -1;\n            for (int j = i; j < height(); j++) {\n            \
    \    if (B[j][i] != 0) {\n                    pivot = j;\n                }\n\
    \            }\n            if (pivot < 0) return 0;\n            if (pivot !=\
    \ i) {\n                res *= -1;\n                swap(B[i], B[pivot]);\n  \
    \          }\n            res *= B[i][i];\n            T v = T(1) / B[i][i];\n\
    \            for (int j = 0; j < width(); j++) B[i][j] *= v;\n            for\
    \ (int j = i + 1; j < height(); j++) {\n                T w = B[j][i];\n     \
    \           for (int k = 0; k < width(); k++) {\n                    B[j][k] -=\
    \ B[i][k] * w;\n                }\n            }\n        }\n        return res;\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: linearalgebra/Matrix.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_det.test.cpp
  - test/yukicoder/526.test.cpp
documentation_of: linearalgebra/Matrix.hpp
layout: document
redirect_from:
- /library/linearalgebra/Matrix.hpp
- /library/linearalgebra/Matrix.hpp.html
title: Matrix
---
## 概要

## 計算量