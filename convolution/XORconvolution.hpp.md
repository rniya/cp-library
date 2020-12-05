---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1240.test.cpp
    title: test/yukicoder/1240.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/XORconvolution.md
    document_title: "\u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/XORconvolution.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F\n * @docs docs/convolution/XORconvolution.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvoid\
    \ fwt(vector<T> &f){\n    int n=f.size();\n    for (int i=1;i<n;i<<=1){\n    \
    \    for (int j=0;j<n;++j){\n            if (!(j&i)){\n                T x=f[j],y=f[j|i];\n\
    \                f[j]=x+y; f[j|i]=x-y;\n            }\n        }\n    }\n}\n\n\
    template<typename T>\nvoid ifwt(vector<T> &f){\n    int n=f.size();\n    for (int\
    \ i=1;i<n;i<<=1){\n        for (int j=0;j<n;++j){\n            if (!(j&i)){\n\
    \                T x=f[j],y=f[j|i];\n                f[j]=(x+y)/2; f[j|i]=(x-y)/2;\n\
    \            }\n        }\n    }\n}\n\ntemplate<typename T>\nvector<T> XOR_convolution(vector<T>\
    \ A,vector<T> B){\n    int n=A.size();\n    assert(__builtin_popcount(n)==1);\n\
    \    assert(A.size()==B.size());\n    fwt(A); fwt(B);\n    for (int i=0;i<n;++i)\
    \ A[i]*=B[i];\n    ifwt(A);\n    return A;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: convolution/XORconvolution.hpp
  requiredBy: []
  timestamp: '2020-12-02 22:02:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1240.test.cpp
documentation_of: convolution/XORconvolution.hpp
layout: document
redirect_from:
- /library/convolution/XORconvolution.hpp
- /library/convolution/XORconvolution.hpp.html
title: "\u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F"
---
## 概要
添字XORでの畳み込みを行う. すなわち,
$$c_k=\sum_{i\oplus j=k}a_ib_j$$
を計算する.

列$a,b$に対して離散Hadamard変換を施した後に掛け合わせて, 逆Hadamard変換することで求めたい列$c$が得られる. この際, 列$a,b$の長さは$2$の冪乗である必要がある. また$\mathbb{F}_p$上での逆Hadamard変換では$2$で割る操作がネックになることもあるので, 定数倍改善が必要な場合は適宜$2$の逆元を掛けるように書き換える必要がある.

## 計算量
$|a|=2^n$として, $O(n2^n)$

## 参照
[色々な畳み込み - kazuma8128’s blog](https://kazuma8128.hatenablog.com/entry/2018/05/31/144519)