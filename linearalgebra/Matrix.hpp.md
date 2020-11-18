---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ once\n\n#include \"../base.hpp\"\n\ntemplate<class K>\nstruct Matrix{\n    vector<vector<K>>\
    \ dat;\n    Matrix(size_t r,size_t c):dat(r,vector<K>(c,K())){}\n    Matrix(size_t\
    \ n):dat(n,vector<K>(n,K())){}\n    Matrix(vector<vector<K>> dat):dat(dat){}\n\
    \    size_t size() const{return dat.size();}\n    vector<K> &operator[](int i){return\
    \ dat[i];}\n    const vector<K> &operator[](int i) const{return dat[i];}\n   \
    \ static Matrix I(size_t n){\n        Matrix res(n);\n        for (int i=0;i<n;++i)\
    \ res[i][i]=K(1);\n        return res;\n    }\n    Matrix &operator+=(const Matrix\
    \ &B){\n        for (int i=0;i<dat.size();++i)\n            for (int j=0;j<dat[0].size();++j)\n\
    \                (*this)[i][j]+=B[i][j];\n        return (*this);\n    }\n   \
    \ Matrix operator+(const Matrix &B) const{\n        return Matrix(*this)+=B;\n\
    \    }\n    Matrix &operator-=(const Matrix &B){\n        for (int i=0;i<dat.size();++i)\n\
    \            for (int j=0;j<dat[0].size();++j)\n                (*this)[i][j]-=B[i][j];\n\
    \        return (*this);\n    }\n    Matrix operator-(const Matrix &B) const{\n\
    \        return Matrix(*this)-=B;\n    }\n    Matrix &operator*=(const Matrix\
    \ &B){\n        vector<vector<K>> res(dat.size(),vector<K>(B[0].size(),K()));\n\
    \        for (int i=0;i<dat.size();++i)\n            for (int j=0;j<B[0].size();++j)\n\
    \                for (int k=0;k<B.size();++k)\n                    res[i][j]+=(*this)[i][k]*B[k][j];\n\
    \        dat.swap(res);\n        return (*this);\n    }\n    Matrix operator*(const\
    \ Matrix &B) const{\n        return Matrix(*this)*=B;\n    }\n    Matrix &operator^=(long\
    \ long k){\n        Matrix res=Matrix::I(size());\n        while(k){\n       \
    \     if (k&1LL) res*=*this;\n            *this*=*this; k>>=1LL;\n        }\n\
    \        dat.swap(res.dat);\n        return (*this);\n    }\n    Matrix operator^(long\
    \ long k) const{\n        return Matrix(*this)^=k;\n    }\n    static Matrix Gauss_Jordan(const\
    \ Matrix &A,const Matrix &B){\n        int n=A.size(),l=B[0].size();\n       \
    \ Matrix C(n,n+l);\n        for (int i=0;i<n;++i){\n            for (int j=0;j<n;++j)\n\
    \                C[i][j]=A[i][j];\n            for (int j=0;j<l;++j)\n       \
    \         C[i][j+n]=B[i][j];\n        }\n        for (int i=0;i<n;++i){\n    \
    \        int p=i;\n            for (int j=i;j<n;++j){\n                if (abs(C[p][i])<abs(C[j][i]))\
    \ p=j;\n            }\n            swap(C[i],C[p]);\n            if (abs(C[i][i])<1e-9)\
    \ return Matrix(0,0);\n            for (int j=i+1;j<n+l;++j) C[i][j]/=C[i][i];\n\
    \            for (int j=0;j<n;++j){\n                if (i!=j) for (int k=i+1;k<n+l;++k){\n\
    \                    C[j][k]-=C[j][i]*C[i][k];\n                }\n          \
    \  }\n        }\n        Matrix res(n,l);\n        for (int i=0;i<n;++i)\n   \
    \         for (int j=0;j<n;++j)\n                res[i][j]=C[i][j+n];\n      \
    \  return res;\n    }\n    Matrix inv() const{\n        Matrix res=I(size());\n\
    \        return Gauss_Jordan(*this,res);\n    }\n    K determinant() const{\n\
    \        Matrix A(dat);\n        K res(1);\n        int n=size();\n        for\
    \ (int i=0;i<n;++i){\n            int p=i;\n            for (int j=i;j<n;++j){\n\
    \                if (abs(A[p][i])<abs(A[j][i])) p=j;\n            }\n        \
    \    if (i!=p) swap(A[i],A[p]),res=-res;\n            if (abs(A[i][i])<1e-9) return\
    \ K(0);\n            res*=A[i][i];\n            for (int j=i+1;j<n;++j) A[i][j]/=A[i][i];\n\
    \            for (int j=i+1;j<n;++j)\n                for (int k=i+1;k<n;++k)\n\
    \                    A[j][k]-=A[j][i]*A[i][k];\n        }\n        return res;\n\
    \    }\n    //sum_{k=0}^{n-1} x^k\n    static K geometric_sum(K x,long long n){\n\
    \        Matrix A(2);\n        A[0][0]=x; A[0][1]=0;\n        A[1][0]=1; A[1][1]=1;\n\
    \        return (A^n)[1][0];\n    }\n    //sum_{k=0}^{n-1} A^k\n    Matrix powsum(long\
    \ long k) const{\n        int n=size();\n        Matrix B(n<<1),res(n);\n    \
    \    for (int i=0;i<n;++i){\n            for (int j=0;j<n;++j)\n             \
    \   B[i][j]=dat[i][j];\n            B[i+n][i]=B[i+n][i+n]=K(1);\n        }\n \
    \       B^=k;\n        for (int i=0;i<n;++i)\n            for (int j=0;j<n;++j)\n\
    \                res[i][j]=B[i+n][j];\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: linearalgebra/Matrix.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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