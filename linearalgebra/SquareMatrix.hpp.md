---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/linearalgebra/SquareMatrix.md
    document_title: Square Matrix
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    const long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int\
    \ INF = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
    \ = {0, 1, 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n      \
    \  os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \ i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \" \"\
    );\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate\
    \ <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n\
    \    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"linearalgebra/SquareMatrix.hpp\"\
    \n\n/**\n * @brief Square Matrix\n * @docs docs/linearalgebra/SquareMatrix.md\n\
    \ */\ntemplate <class T, size_t N> struct SquareMatrix {\n    array<array<T, N>,\
    \ N> A;\n    SquareMatrix() = default;\n    size_t size() { return N; }\n    inline\
    \ const array<T, N>& operator[](int i) const { return A[i]; }\n    inline array<T,\
    \ N>& operator[](int i) { return A[i]; }\n    static SquareMatrix add_identity()\
    \ { return SquareMatrix(); }\n    static SquareMatrix mul_identity() {\n     \
    \   SquareMatrix res;\n        for (size_t i = 0; i < N; i++) res[i][i] = 1;\n\
    \        return res;\n    }\n    SquareMatrix operator+(const SquareMatrix& B)\
    \ const { return SquareMatrix(*this) += B; }\n    SquareMatrix operator-(const\
    \ SquareMatrix& B) const { return SquareMatrix(*this) -= B; }\n    SquareMatrix\
    \ operator*(const SquareMatrix& B) const { return SquareMatrix(*this) *= B; }\n\
    \    SquareMatrix operator^(const long long& k) const { return SquareMatrix(*this)\
    \ ^= k; }\n    SquareMatrix& operator+=(const SquareMatrix& B) {\n        for\
    \ (size_t i = 0; i < N; i++) {\n            for (size_t j = 0; j < N; j++) {\n\
    \                (*this)[i][j] += B[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n    SquareMatrix& operator-=(const SquareMatrix& B) {\n\
    \        for (size_t i = 0; i < N; i++) {\n            for (size_t j = 0; j <\
    \ N; j++) {\n                (*this)[i][j] -= B[i][j];\n            }\n      \
    \  }\n        return *this;\n    }\n    SquareMatrix& operator*=(const SquareMatrix&\
    \ B) {\n        array<array<T, N>, N> C;\n        for (size_t i = 0; i < N; i++)\
    \ {\n            for (size_t j = 0; j < N; j++) {\n                for (size_t\
    \ k = 0; k < N; k++) {\n                    C[i][j] += (*this)[i][k] * B[k][j];\n\
    \                }\n            }\n        }\n        A.swap(C);\n        return\
    \ *this;\n    }\n    SquareMatrix& operator^=(long long k) {\n        SquareMatrix\
    \ res = SquareMatrix::mul_identity();\n        while (k > 0) {\n            if\
    \ (k & 1) res *= *this;\n            *this *= *this;\n            k >>= 1LL;\n\
    \        }\n        A.swap(res.A);\n        return *this;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Square Matrix\n\
    \ * @docs docs/linearalgebra/SquareMatrix.md\n */\ntemplate <class T, size_t N>\
    \ struct SquareMatrix {\n    array<array<T, N>, N> A;\n    SquareMatrix() = default;\n\
    \    size_t size() { return N; }\n    inline const array<T, N>& operator[](int\
    \ i) const { return A[i]; }\n    inline array<T, N>& operator[](int i) { return\
    \ A[i]; }\n    static SquareMatrix add_identity() { return SquareMatrix(); }\n\
    \    static SquareMatrix mul_identity() {\n        SquareMatrix res;\n       \
    \ for (size_t i = 0; i < N; i++) res[i][i] = 1;\n        return res;\n    }\n\
    \    SquareMatrix operator+(const SquareMatrix& B) const { return SquareMatrix(*this)\
    \ += B; }\n    SquareMatrix operator-(const SquareMatrix& B) const { return SquareMatrix(*this)\
    \ -= B; }\n    SquareMatrix operator*(const SquareMatrix& B) const { return SquareMatrix(*this)\
    \ *= B; }\n    SquareMatrix operator^(const long long& k) const { return SquareMatrix(*this)\
    \ ^= k; }\n    SquareMatrix& operator+=(const SquareMatrix& B) {\n        for\
    \ (size_t i = 0; i < N; i++) {\n            for (size_t j = 0; j < N; j++) {\n\
    \                (*this)[i][j] += B[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n    SquareMatrix& operator-=(const SquareMatrix& B) {\n\
    \        for (size_t i = 0; i < N; i++) {\n            for (size_t j = 0; j <\
    \ N; j++) {\n                (*this)[i][j] -= B[i][j];\n            }\n      \
    \  }\n        return *this;\n    }\n    SquareMatrix& operator*=(const SquareMatrix&\
    \ B) {\n        array<array<T, N>, N> C;\n        for (size_t i = 0; i < N; i++)\
    \ {\n            for (size_t j = 0; j < N; j++) {\n                for (size_t\
    \ k = 0; k < N; k++) {\n                    C[i][j] += (*this)[i][k] * B[k][j];\n\
    \                }\n            }\n        }\n        A.swap(C);\n        return\
    \ *this;\n    }\n    SquareMatrix& operator^=(long long k) {\n        SquareMatrix\
    \ res = SquareMatrix::mul_identity();\n        while (k > 0) {\n            if\
    \ (k & 1) res *= *this;\n            *this *= *this;\n            k >>= 1LL;\n\
    \        }\n        A.swap(res.A);\n        return *this;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: linearalgebra/SquareMatrix.hpp
  requiredBy: []
  timestamp: '2021-01-19 16:17:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1050.test.cpp
documentation_of: linearalgebra/SquareMatrix.hpp
layout: document
redirect_from:
- /library/linearalgebra/SquareMatrix.hpp
- /library/linearalgebra/SquareMatrix.hpp.html
title: Square Matrix
---
## 概要

## 計算量