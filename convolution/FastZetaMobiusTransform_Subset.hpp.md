---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1289.test.cpp
    title: test/yukicoder/1289.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/FastZetaMobiusTransform.md
    document_title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\
      \u63DB(\u4E0B\u4F4D\u96C6\u5408)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/FastZetaMobiusTransform_Subset.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\n * @brief \u9AD8\u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\
    \u5909\u63DB(\u4E0B\u4F4D\u96C6\u5408)\n * @docs docs/convolution/FastZetaMobiusTransform.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvoid\
    \ FastZetaTransform(int n,vector<T> &f){\n    for (int i=0;i<n;++i){\n       \
    \ for (int j=0;j<(1<<n);++j){\n            if ((j>>i)&1){\n                f[j]+=f[j^(1<<i)];\n\
    \            }\n        }\n    }\n}\n\ntemplate<typename T>\nvoid FastMobiusTransform(int\
    \ n,vector<T> &f){\n    for (int i=0;i<n;++i){\n        for (int j=0;j<(1<<n);++j){\n\
    \            if ((j>>i)&1){\n                f[j]-=f[j^(1<<i)];\n            }\n\
    \        }\n    }\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: convolution/FastZetaMobiusTransform_Subset.hpp
  requiredBy: []
  timestamp: '2020-12-05 18:17:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1289.test.cpp
documentation_of: convolution/FastZetaMobiusTransform_Subset.hpp
layout: document
redirect_from:
- /library/convolution/FastZetaMobiusTransform_Subset.hpp
- /library/convolution/FastZetaMobiusTransform_Subset.hpp.html
title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\u63DB(\u4E0B\
  \u4F4D\u96C6\u5408)"
---
## 概要
- 高速ゼータ変換(上位集合)：集合$S$を部分集合に含むような集合$T$についての$f(T)$の総和, すなわち,
$$g(S)=\sum_{T\supseteq S} f(T)$$
を計算する.
- 高速ゼータ変換(下位集合)：集合$S$の部分集合$T$についての$f(T)$の総和, すなわち,
$$g(S)=\sum_{T\subseteq S} f(T)$$
を計算する.
- 高速メビウス変換(上位集合)：高速ゼータ変換(上位集合)の逆変換, すなわち,
$$f(S)=\sum_{T\supseteq S} (-1)^{|T|-|S|}g(T)$$
を計算する.
- 高速メビウス変換(下位集合)：高速ゼータ変換(上位集合)の逆変換, すなわち,
$$f(S)=\sum_{T\subseteq S} (-1)^{|S|-|T|}g(T)$$
を計算する.

また高速ゼータ変換は演算を$+$に限定せずとも環上で動く([参考](http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#qef794e9), 未整備)

## 計算量
どれも$O(n2^n)$

## 参照
- [高速ゼータ変換について - Qiita](https://qiita.com/Euglenese/items/260f9ddf513f772d7e42)
- [高速ゼータ・メビウス変換 - Mister雑記](https://misteer.hatenablog.com/entry/zeta-moebius)
