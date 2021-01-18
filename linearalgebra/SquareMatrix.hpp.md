---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/linearalgebra/Squarematrix.md
    document_title: Square Matrix
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linearalgebra/SquareMatrix.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Square Matrix\n * @docs docs/linearalgebra/Squarematrix.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<class T,size_t N>\n\
    struct SquareMatrix{\n    array<array<T,N>,N> A;\n    SquareMatrix()=default;\n\
    \    size_t size() {return N;}\n    inline const array<T,N> &operator[](int i)\
    \ const {return A[i];}\n    inline array<T,N> &operator[](int i){return A[i];}\n\
    \    static SquareMatrix add_identity(){\n        return SquareMatrix();\n   \
    \ }\n    static SquareMatrix mul_identity(){\n        SquareMatrix res;\n    \
    \    for (size_t i=0;i<N;++i) res[i][i]=1;\n        return res;\n    }\n    SquareMatrix\
    \ operator+(const SquareMatrix &B) const {return SquareMatrix(*this)+=B;}\n  \
    \  SquareMatrix operator-(const SquareMatrix &B) const {return SquareMatrix(*this)-=B;}\n\
    \    SquareMatrix operator*(const SquareMatrix &B) const {return SquareMatrix(*this)*=B;}\n\
    \    SquareMatrix operator^(const long long &k) const {return SquareMatrix(*this)^=k;}\n\
    \    SquareMatrix &operator+=(const SquareMatrix &B){\n        for (size_t i=0;i<N;++i){\n\
    \            for (size_t j=0;j<N;++j){\n                (*this)[i][j]+=B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    SquareMatrix &operator-=(const\
    \ SquareMatrix &B){\n        for (size_t i=0;i<N;++i){\n            for (size_t\
    \ j=0;j<N;++j){\n                (*this)[i][j]-=B[i][j];\n            }\n    \
    \    }\n        return *this;\n    }\n    SquareMatrix &operator*=(const SquareMatrix\
    \ &B){\n        array<array<T,N>,N> C;\n        for (size_t i=0;i<N;++i){\n  \
    \          for (size_t j=0;j<N;++j){\n                for (size_t k=0;k<N;++k){\n\
    \                    C[i][j]+=(*this)[i][k]*B[k][j];\n                }\n    \
    \        }\n        }\n        A.swap(C);\n        return *this;\n    }\n    SquareMatrix\
    \ &operator^=(long long k){\n        SquareMatrix res=SquareMatrix::mul_identity();\n\
    \        while (k>0){\n            if (k&1) res*=*this;\n            *this*=*this;\
    \ k>>=1LL;\n        }\n        A.swap(res.A);\n        return *this;\n    }\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: linearalgebra/SquareMatrix.hpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1050.test.cpp
documentation_of: linearalgebra/SquareMatrix.hpp
layout: document
redirect_from:
- /library/linearalgebra/SquareMatrix.hpp
- /library/linearalgebra/SquareMatrix.hpp.html
title: Square Matrix
---
