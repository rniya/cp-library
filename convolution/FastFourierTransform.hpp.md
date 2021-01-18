---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1307.test.cpp
    title: test/yukicoder/1307.test.cpp
  - icon: ':x:'
    path: test/yukicoder/206.test.cpp
    title: test/yukicoder/206.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/convolution/FastFourierTransform.md
    document_title: Fast Fourier Transform
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/FastFourierTransform.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Fast Fourier Transform\n * @docs docs/convolution/FastFourierTransform.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nnamespace FastFourierTransform{\n\
    \    struct Complex{\n        double x,y;\n        Complex():x(0),y(0){}\n   \
    \     Complex(double x,double y):x(x),y(y){}\n        inline Complex operator+(const\
    \ Complex &c) const {\n            return Complex(x+c.x,y+c.y);\n        }\n \
    \       inline Complex operator-(const Complex &c) const {\n            return\
    \ Complex(x-c.x,y-c.y);\n        }\n        inline Complex operator*(const Complex\
    \ &c) const {\n            return Complex(x*c.x-y*c.y,x*c.y+y*c.x);\n        }\n\
    \        inline Complex conj() const {return Complex(x,-y);}\n    };\n    const\
    \ double PI=acosl(-1);\n    vector<Complex> roots={{0,0},{1,0}};\n    vector<int>\
    \ rev={0,1};\n    int base=1;\n    void ensure_base(int nbase){\n        if (nbase<=base)\
    \ return;\n        rev.resize(1<<nbase);\n        for (int i=0;i<(1<<nbase);++i){\n\
    \            rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));\n        }\n        roots.resize(1<<nbase);\n\
    \        for (;base<nbase;++base){\n            double angle=PI*2.0/(1<<(base+1));\n\
    \            for (int i=1<<(base-1);i<(1<<base);++i){\n                roots[i<<1]=roots[i];\n\
    \                double angle_i=angle*((i<<1|1)-(1<<base));\n                roots[i<<1|1]=Complex(cos(angle_i),sin(angle_i));\n\
    \            }\n        }\n    }\n    void fft(vector<Complex> &a,int n){\n  \
    \      int zeros=__builtin_ctz(n);\n        ensure_base(zeros);\n        int shift=base-zeros;\n\
    \        for (int i=0;i<n;++i){\n            if (i<(rev[i]>>shift)){\n       \
    \         swap(a[i],a[rev[i]>>shift]);\n            }\n        }\n        for\
    \ (int k=1;k<n;k<<=1){\n            for (int i=0;i<n;i+=(k<<1)){\n           \
    \     for (int j=0;j<k;++j){\n                    Complex z=a[i+j+k]*roots[j+k];\n\
    \                    a[i+j+k]=a[i+j]-z;\n                    a[i+j]=a[i+j]+z;\n\
    \                }\n            }\n        }\n    }\n    vector<long long> multiply(const\
    \ vector<int> &a,const vector<int> &b){\n        int need=a.size()+b.size()-1;\n\
    \        int nbase=1;\n        while((1<<nbase)<need) ++nbase;\n        ensure_base(nbase);\n\
    \        int sz=1<<nbase;\n        vector<Complex> C(sz);\n        for (int i=0;i<sz;++i){\n\
    \            int x=(i<a.size()?a[i]:0);\n            int y=(i<b.size()?b[i]:0);\n\
    \            C[i]=Complex(x,y);\n        }\n        fft(C,sz);\n        Complex\
    \ r(0,-0.25/(sz>>1)),s(0,1),t(0.5,0);\n        for (int i=0;i<=(sz>>1);++i){\n\
    \            int j=(sz-i)&(sz-1);\n            Complex z=(C[j]*C[j]-(C[i]*C[i]).conj())*r;\n\
    \            C[j]=(C[i]*C[i]-(C[j]*C[j]).conj())*r;\n            C[i]=z;\n   \
    \     }\n        for (int i=0;i<(sz>>1);++i){\n            Complex C0=(C[i]+C[i+(sz>>1)])*t;\n\
    \            Complex C1=(C[i]-C[i+(sz>>1)])*t*roots[(sz>>1)+i];\n            C[i]=C0+C1*s;\n\
    \        }\n        fft(C,sz>>1);\n        vector<long long> res(need);\n    \
    \    for (int i=0;i<need;++i){\n            res[i]=llround(i&1?C[i>>1].y:C[i>>1].x);\n\
    \        }\n        return res;\n    }\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: convolution/FastFourierTransform.hpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
  - test/yukicoder/206.test.cpp
  - test/yukicoder/1307.test.cpp
documentation_of: convolution/FastFourierTransform.hpp
layout: document
redirect_from:
- /library/convolution/FastFourierTransform.hpp
- /library/convolution/FastFourierTransform.hpp.html
title: Fast Fourier Transform
---
## 概要
2つの数列$a,b$の畳み込み, すなわち,
$$c_k=\sum_{i=0}^k a_ib_{k-i}$$
を計算する. バタフライ演算を利用した非再帰のものを実装している. 誤差に注意が必要だが, NTTよりもこちらの方が速いので, TLが厳しい場合であればこちらを使う方が無難.
## 計算量
$O(n\log n)$

## 問題例
[Codeforces Round #296 (Div. 1) D. Fuzzy Search](https://codeforces.com/contest/528/problem/D)
2つの文字列$S,T$について, 特に特定の1種類の文字に着目して2つの文字列をbit列に変換すると, それらを畳み込むことで一致しているかどうかを判定することができる.

## 参照
- [高速フーリエ変換](https://www.slideshare.net/chokudai/fft-49066791)
- [高速フーリエ変換 (FFT) - ゆるふわブログ](http://ysmr-ry.hatenablog.com/entry/2017/11/09/102008)
- [競プロのための高速フーリエ変換](https://www.creativ.xyz/fast-fourier-transform/)
- [Cooley-Tukeyのアルゴリズム - Mister雑記](https://misteer.hatenablog.com/entry/cooley-tukey)