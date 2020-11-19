---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G.test.cpp
    title: test/aoj/DPL_5_G.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/combinatorics/BellNumber.md
    document_title: "\u30D9\u30EB\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/BellNumber.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u30D9\u30EB\u6570\n * @docs docs/combinatorics/BellNumber.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nT bell_number(int\
    \ n,int k){\n    if (n==0) return 1;\n    k=min(k,n);\n    Combination<T> COM(k);\n\
    \    vector<T> sum(k+1);\n    sum[0]=1;\n    for (int i=1;i<=k;++i){\n       \
    \ if (i&1) sum[i]=sum[i-1]-COM.finv(i);\n        else sum[i]=sum[i-1]+COM.finv(i);\n\
    \    }\n    T res=0;\n    for (int i=1;i<=k;++i){\n        res+=T(i).pow(n)*COM.finv(i)*sum[k-i];\n\
    \    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: combinatorics/BellNumber.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_G.test.cpp
documentation_of: combinatorics/BellNumber.hpp
layout: document
redirect_from:
- /library/combinatorics/BellNumber.hpp
- /library/combinatorics/BellNumber.hpp.html
title: "\u30D9\u30EB\u6570"
---
## 概要
ベル数$B\left(n,k\right)$は$n$個の区別できる玉を$k$個の区別できない箱に入れる組合せ数, すなわち整数$1$から$n$を$k$個以下のグループに分割する場合の数である. これは, スターリング数$S\left(n,k\right)$をもとに,
$$\begin{aligned}
B\left(n,k\right)&=\sum_{j=0}^k S\left(n,k\right)\\
&=\sum_{j=0}^k \dfrac{1}{j!} \sum_{i=0}^j \left(-1\right)^{j-i}\binom{j}{i}i^n\\
&=\sum_{j=0}^k \sum_{i=0}^j \dfrac{\left(-1\right)^{j-i}}{i!\left(j-i\right)!}i^n\\
&=\sum_{i=0}^k \sum_{j=i}^k \dfrac{\left(-1\right)^{j-i}}{i!\left(j-i\right)!}i^n\\
&=\sum_{i=0}^k \sum_{j=0}^{k-i} \dfrac{\left(-1\right)^j}{i!j!}i^n\\
&=\sum_{i=0}^k \dfrac{i^n}{i!} \sum_{j=0}^{k-1} \dfrac{\left(-1\right)^j}{j!}
\end{aligned}$$
と計算できる. $\sum_{j=0}^{k-1} \frac{\left(-1\right)^j}{j!}$は累積和のように前計算できる.

## 計算量
$O\left(\min\left(n,k\right)\log{n}\right)$

## 参照
[「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)