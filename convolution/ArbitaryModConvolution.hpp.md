---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/convolution/ArbitaryModConvolution.md
    document_title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F\
      )"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/ArbitaryModConvolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\
    \u307F)\n * @docs docs/convolution/ArbitaryModConvolution.md\n */\n\n#pragma once\n\
    \n#include \"../base.hpp\"\n#include \"../modulo/modint.hpp\"\n#include \"../convolution/NumberTheoreticTransform.hpp\"\
    \n\ntemplate<typename M>\nvector<M> ArbitaryModConvolution(const vector<M> &a,const\
    \ vector<M> &b){\n    int n=a.size(),m=b.size();\n    static constexpr int mod0=167772161,mod1=469762049,mod2=754974721;\n\
    \    using mint0=modint<mod0>;\n    using mint1=modint<mod1>;\n    using mint2=modint<mod2>;\n\
    \    NumberTheoreticTransform<mod0> ntt0;\n    NumberTheoreticTransform<mod1>\
    \ ntt1;\n    NumberTheoreticTransform<mod2> ntt2;\n    vector<mint0> a0(n),b0(m);\n\
    \    vector<mint1> a1(n),b1(m);\n    vector<mint2> a2(n),b2(m);\n    for (int\
    \ i=0;i<n;++i) a0[i]=a[i].v,a1[i]=a[i].v,a2[i]=a[i].v;\n    for (int i=0;i<m;++i)\
    \ b0[i]=b[i].v,b1[i]=b[i].v,b2[i]=b[i].v;\n    auto c0=ntt0.multiply(a0,b0);\n\
    \    auto c1=ntt1.multiply(a1,b1);\n    auto c2=ntt2.multiply(a2,b2);\n    static\
    \ const mint1 inv0=(mint1)1/mod0;\n    static const mint2 inv1=(mint2)1/mod1,inv0inv1=inv1/mod0;\n\
    \    static const M m0=mod0,m0m1=m0*mod1;\n    vector<M> res(n+m-1);\n    for\
    \ (int i=0;i<n+m-1;++i){\n        int v0=c0[i].v;\n        int v1=(inv0*(c1[i]-v0)).v;\n\
    \        int v2=(inv0inv1*(c2[i]-v0)-inv1*v1).v;\n        res[i]=v0+m0*v1+m0m1*v2;\n\
    \    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - convolution/NumberTheoreticTransform.hpp
  isVerificationFile: false
  path: convolution/ArbitaryModConvolution.hpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yukicoder/3046.test.cpp
documentation_of: convolution/ArbitaryModConvolution.hpp
layout: document
redirect_from:
- /library/convolution/ArbitaryModConvolution.hpp
- /library/convolution/ArbitaryModConvolution.hpp.html
title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
---
## 概要
$1000000007$などのNTT-frinedlyでないような$\bmod$に対する畳み込みを行う.

NTT-frinedlyな3つの素数$167772161,469762049,754974721$についてそれぞれ畳み込み, 元の$\bmod$での余りをChinese Remainder Theoremによって復元する.

長さ$n$の2つの列を畳み込んだときの要素の最大値は$n\times\left(2^{31}-1\right)$であり, これが3つの素数の積よりも小さくなる必要があるため, おおよそ$n<2^{22}$である必要があるが困ることはほぼない.

## 計算量
$O(n\log n)$

## 参照
[任意modでの畳み込み演算をO(n log(n))で - math314のブログ](https://math314.hateblo.jp/entry/2015/05/07/014908)