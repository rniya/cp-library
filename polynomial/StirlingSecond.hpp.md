---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/polynomial/StirlingSecond.md
    document_title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ polynomial/StirlingSecond.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\n\
    \ * @docs docs/polynomial/StirlingSecond.md\n */\n\n#pragma once\n\n#include \"\
    ../base.hpp\"\n#include \"../polynomial/FormalPowerSeries.hpp\"\n\ntemplate<typename\
    \ T>\nFormalPowerSeries<T> StirlingSecond(int n){\n    FormalPowerSeries<T> a(n+1),b(n+1);\n\
    \    T prod=1;\n    for (int i=0;i<=n;++i){\n        T inv=T(1)/prod;\n      \
    \  a[i]=T(i).pow(n)*inv;\n        b[i]=T(1)*inv;\n        if (i&1) b[i]*=-1;\n\
    \        prod*=i+1;\n    }\n    return (a*b).pre(n+1);\n}"
  dependsOn:
  - base.hpp
  - polynomial/FormalPowerSeries.hpp
  isVerificationFile: false
  path: polynomial/StirlingSecond.hpp
  requiredBy: []
  timestamp: '2020-11-19 22:07:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
documentation_of: polynomial/StirlingSecond.hpp
layout: document
redirect_from:
- /library/polynomial/StirlingSecond.hpp
- /library/polynomial/StirlingSecond.hpp.html
title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
---
## 概要
$n$について, 第2種スターリング数$S\left(n,k\right)\left(0\leq k \leq n\right)$を列挙する.
$$S\left(n,k\right)=\sum_{i=0}^k \dfrac{i^n}{i!}\cdot\dfrac{\left(-1\right)^{k-i}}{\left(k-i\right)!}$$
なので,
$$a_i=\dfrac{i^n}{i!},\ b_i=\dfrac{\left(-1\right)^i}{i!}$$
とすれば,
$$S\left(n,k\right)=\sum_{i=0}^k a_ib_{k-i}$$
であり, これはそのまま数列$\left\{a_i\right\}$と$\left\{b_i\right\}$の畳み込みにより計算可能である.

## 計算量
$O\left(n\log{n}\right)$

## 参照
[FFT (NTT) 関連 - memo](https://min-25.hatenablog.com/entry/2015/04/07/160154)