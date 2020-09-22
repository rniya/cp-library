---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/linearalgebra/Squarematrix.md
    document_title: Square Matrix
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linearalgebra/SquareMatrix.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Square Matrix\n * @docs docs/linearalgebra/Squarematrix.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<class K,size_t N>\n\
    struct SquareMatrix{\n    array<array<K,N>,N> dat;\n    SquareMatrix(){\n    \
    \    for (size_t i=0;i<N;++i)\n            for (size_t j=0;j<N;++j)\n        \
    \        dat[i][j]=K();\n    }\n    size_t size() const{return N;}\n    array<K,N>\
    \ &operator[](size_t i){return dat[i];}\n    const array<K,N> &operator[](size_t\
    \ i) const{return dat[i];}\n    static SquareMatrix I(){\n        SquareMatrix\
    \ res;\n        for (size_t i=0;i<N;++i) res[i][i]=K(1);\n        return res;\n\
    \    }\n    SquareMatrix &operator+=(const SquareMatrix &B){\n        for (size_t\
    \ i=0;i<N;++i)\n            for (size_t j=0;j<N;++j)\n                (*this)[i][j]+=B[i][j];\n\
    \        return (*this);\n    }\n    SquareMatrix operator+(const SquareMatrix\
    \ &B) const{\n        return SquareMatrix(*this)+=B;\n    }\n    SquareMatrix\
    \ &operator-=(const SquareMatrix &B){\n        for (size_t i=0;i<N;++i)\n    \
    \        for (size_t j=0;j<N;++j)\n                (*this)[i][j]-=B[i][j];\n \
    \       return (*this);\n    }\n    SquareMatrix operator-(const SquareMatrix\
    \ &B) const{\n        return SquareMatrix(*this)-=B;\n    }\n    SquareMatrix\
    \ &operator*=(const SquareMatrix &B){\n        SquareMatrix res;\n        for\
    \ (size_t i=0;i<N;++i)\n            for (size_t j=0;j<N;++j)\n               \
    \ for (size_t k=0;k<N;++k)\n                    res[i][j]+=(*this)[i][k]*B[k][j];\n\
    \        dat.swap(res.dat);\n        return (*this);\n    }\n    SquareMatrix\
    \ operator*(const SquareMatrix &B) const{\n        return SquareMatrix(*this)*=B;\n\
    \    }\n    SquareMatrix &operator^=(long long k){\n        SquareMatrix res=I();\n\
    \        while(k){\n            if (k&1LL) res*=*this;\n            *this*=*this;\
    \ k>>=1LL;\n        }\n        dat.swap(res.dat);\n        return (*this);\n \
    \   }\n    SquareMatrix operator^(long long k) const{\n        return SquareMatrix(*this)^=k;\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: linearalgebra/SquareMatrix.hpp
  requiredBy: []
  timestamp: '2020-09-11 16:00:32+09:00'
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
