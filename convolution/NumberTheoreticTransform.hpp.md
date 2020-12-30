---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/ArbitaryModConvolution.hpp
    title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1068.test.cpp
    title: test/yukicoder/1068.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1302.test.cpp
    title: test/yukicoder/1302.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/931.test.cpp
    title: test/yukicoder/931.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/NumberTheoreticTransform.md
    document_title: Number Theoretic Transform
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/NumberTheoreticTransform.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Number Theoretic Transform\n * @docs docs/convolution/NumberTheoreticTransform.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n#include \"../modulo/modint.hpp\"\
    \n\ntemplate<int mod>\nstruct NumberTheoreticTransform{\n    using Mint=modint<mod>;\n\
    \    vector<Mint> roots;\n    vector<int> rev;\n    int base,max_base;\n    Mint\
    \ root;\n    NumberTheoreticTransform():base(1),rev{0,1},roots{Mint(0),Mint(1)}{\n\
    \        int tmp=mod-1;\n        for (max_base=0;tmp%2==0;++max_base) tmp>>=1;\n\
    \        root=2;\n        while (root.pow((mod-1)>>1)==1) ++root;\n        root=root.pow((mod-1)>>max_base);\n\
    \    }\n    void ensure_base(int nbase){\n        if (nbase<=base) return;\n \
    \       rev.resize(1<<nbase);\n        for (int i=0;i<(1<<nbase);++i){\n     \
    \       rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));\n        }\n        roots.resize(1<<nbase);\n\
    \        for (;base<nbase;++base){\n            Mint z=root.pow(1<<(max_base-1-base));\n\
    \            for (int i=1<<(base-1);i<(1<<base);++i){\n                roots[i<<1]=roots[i];\n\
    \                roots[i<<1|1]=roots[i]*z;\n            }\n        }\n    }\n\
    \    void ntt(vector<Mint> &a){\n        const int n=a.size();\n        int zeros=__builtin_ctz(n);\n\
    \        ensure_base(zeros);\n        int shift=base-zeros;\n        for (int\
    \ i=0;i<n;++i){\n            if (i<(rev[i]>>shift)){\n                swap(a[i],a[rev[i]>>shift]);\n\
    \            }\n        }\n        for (int k=1;k<n;k<<=1){\n            for (int\
    \ i=0;i<n;i+=(k<<1)){\n                for (int j=0;j<k;++j){\n              \
    \      Mint z=a[i+j+k]*roots[j+k];\n                    a[i+j+k]=a[i+j]-z;\n \
    \                   a[i+j]=a[i+j]+z;\n                }\n            }\n     \
    \   }\n    }\n    vector<Mint> multiply(vector<Mint> a,vector<Mint> b){\n    \
    \    int need=a.size()+b.size()-1;\n        int nbase=1;\n        while ((1<<nbase)<need)\
    \ ++nbase;\n        ensure_base(nbase);\n        int sz=1<<nbase;\n        a.resize(sz,Mint(0));\
    \ b.resize(sz,Mint(0));\n        ntt(a); ntt(b);\n        Mint inv_sz=1/Mint(sz);\n\
    \        for (int i=0;i<sz;++i) a[i]*=b[i]*inv_sz;\n        reverse(a.begin()+1,a.end());\n\
    \        ntt(a);\n        a.resize(need);\n        return a;\n    }\n    vector<int>\
    \ multiply(vector<int> a,vector<int> b){\n        vector<Mint> A(a.size()),B(b.size());\n\
    \        for (int i=0;i<a.size();++i) A[i]=Mint(a[i]);\n        for (int i=0;i<b.size();++i)\
    \ B[i]=Mint(b[i]);\n        vector<Mint> C=multiply(A,B);\n        vector<int>\
    \ res(C.size());\n        for (int i=0;i<C.size();++i) res[i]=C[i].v;\n      \
    \  return res;\n    }\n};"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  isVerificationFile: false
  path: convolution/NumberTheoreticTransform.hpp
  requiredBy:
  - convolution/ArbitaryModConvolution.hpp
  timestamp: '2020-11-19 21:51:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yukicoder/1302.test.cpp
  - test/yukicoder/931.test.cpp
  - test/yukicoder/1068.test.cpp
  - test/yukicoder/3046.test.cpp
documentation_of: convolution/NumberTheoreticTransform.hpp
layout: document
redirect_from:
- /library/convolution/NumberTheoreticTransform.hpp
- /library/convolution/NumberTheoreticTransform.hpp.html
title: Number Theoretic Transform
---
## 概要
剰余環$\mathbb{Z}/p\mathbb{Z}$上でFFTを行う. このとき, $p$としてはNTT-friendlyな素数($998244353,1012924417,924844033$など)である必要がある.

## 問題例
[AGC047 C Product Modulo](https://atcoder.jp/contests/agc047/tasks/agc047_c)
一般に素数$P$について, 添字の剰余環$\mathbb{Z}/P\mathbb{Z}$における積での畳み込み, すなわち,
$$c_k=\sum_{i\times j\bmod P=k}a_ib_j$$
が計算できる. 具体的には, $P$の原子根$r$が取れて, $\mathbb{Z}/P\mathbb{Z}$の乗法群と$\mathbb{Z}/(P-1)\mathbb{Z}$が同型であることから, 各添字を$r$を底とした離散対数に変換して, その上でNTTを施した後に解を復元すれば良い. [これ](https://yukicoder.me/problems/no/931)が類題.

## 計算量
$O(n\log n)$