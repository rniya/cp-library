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
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/linearalgebra/Matrix.md
    document_title: Matrix
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linearalgebra/Matrix.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Matrix\n * @docs docs/linearalgebra/Matrix.md\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n\ntemplate<class T>\nstruct Matrix{\n    vector<vector<T>>\
    \ A;\n    Matrix(size_t n,size_t m):A(n,vector<T>(m,0)){}\n    Matrix(size_t n):A(n,vector<T>(n,0)){}\n\
    \    size_t height() const {return A.size();}\n    size_t width() const {return\
    \ A[0].size();}\n    inline const vector<T> &operator[](int i) const {return A[i];}\n\
    \    inline vector<T> &operator[](int i){return A[i];}\n    static Matrix I(size_t\
    \ n){\n        Matrix res(n);\n        for (int i=0;i<n;++i) res[i][i]=1;\n  \
    \      return res;\n    }\n    Matrix operator+(const Matrix &B) const {return\
    \ Matrix(*this)+=B;}\n    Matrix operator-(const Matrix &B) const {return Matrix(*this)-=B;}\n\
    \    Matrix operator*(const Matrix &B) const {return Matrix(*this)*=B;}\n    Matrix\
    \ operator^(const long long k) const {return Matrix(*this)^=k;}\n    Matrix &operator+=(const\
    \ Matrix &B){\n        size_t n=height(),m=width();\n        assert(n==B.height()&&m==B.width());\n\
    \        for (int i=0;i<n;++i){\n            for (int j=0;j<m;++j){\n        \
    \        (*this)[i][j]+=B[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n    Matrix &operator-=(const Matrix &B){\n        size_t n=height(),m=width();\n\
    \        assert(n==B.height()&&m==B.width());\n        for (int i=0;i<n;++i){\n\
    \            for (int j=0;j<m;++j){\n                (*this)[i][j]-=B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix &operator*=(const\
    \ Matrix &B){\n        size_t n=height(),m=B.width(),l=width();\n        assert(l==B.height());\n\
    \        vector<vector<T>> C(n,vector<T>(m,0));\n        for (int i=0;i<n;++i){\n\
    \            for (int j=0;j<m;++j){\n                for (int k=0;k<l;++k){\n\
    \                    C[i][j]+=(*this)[i][k]*B[k][j];\n                }\n    \
    \        }\n        }\n        A.swap(C);\n        return *this;\n    }\n    Matrix\
    \ &operator^=(long long k){\n        Matrix res=Matrix::I(height());\n       \
    \ while (k>0){\n            if (k&1) res*=*this;\n            *this*=*this; k>>=1LL;\n\
    \        }\n        A.swap(res.A);\n        return *this;\n    }\n    T determinant(){\n\
    \        Matrix B(*this);\n        T res=1;\n        for (int i=0;i<width();++i){\n\
    \            int pivot=-1;\n            for (int j=i;j<height();++j){\n      \
    \          if (B[j][i]!=0){\n                    pivot=j;\n                }\n\
    \            }\n            if (pivot<0) return 0;\n            if (pivot!=i){\n\
    \                res*=-1;\n                swap(B[i],B[pivot]);\n            }\n\
    \            res*=B[i][i];\n            T v=T(1)/B[i][i];\n            for (int\
    \ j=0;j<width();++j) B[i][j]*=v;\n            for (int j=i+1;j<height();++j){\n\
    \                T w=B[j][i];\n                for (int k=0;k<width();++k){\n\
    \                    B[j][k]-=B[i][k]*w;\n                }\n            }\n \
    \       }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: linearalgebra/Matrix.hpp
  requiredBy: []
  timestamp: '2020-12-01 01:23:29+09:00'
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