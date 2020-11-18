---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_J.test.cpp
    title: test/aoj/DPL_5_J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_L.test.cpp
    title: test/aoj/DPL_5_L.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/combinatorics/PartitionTable.md
    document_title: "\u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/PartitionTable.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief \u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB\n * @docs docs/combinatorics/PartitionTable.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<vector<T>>\
    \ partition_table(int n,int k){\n    vector<vector<T>> dp(n+1,vector<T>(k+1));\n\
    \    dp[0][0]=1;\n    for (int i=0;i<=n;++i){\n        for (int j=1;j<=k;++j){\n\
    \            dp[i][j]=dp[i][j-1]+(i-j>=0?dp[i-j][j]:0);\n        }\n    }\n  \
    \  return dp;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: combinatorics/PartitionTable.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_L.test.cpp
  - test/aoj/DPL_5_J.test.cpp
documentation_of: combinatorics/PartitionTable.hpp
layout: document
redirect_from:
- /library/combinatorics/PartitionTable.hpp
- /library/combinatorics/PartitionTable.hpp.html
title: "\u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB"
---
## 概要
分割数$P\left(n,k\right)$は$n$の個の区別できない玉を$k$個の区別できない箱に入れる組合せ数, すなわち整数$n$をちょうど$k$個の非負整数の和で表す場合の数を与える. これは,
1. 分割が$0$を含むとき, 組合せ数は$P\left(n,k-1\right)$に帰着される.
2. 分割が$0$を含まないとき, $k$個の整数が全て$0$以上なので, それらから$1$ずつ除けば組合せ数は$P\left(n-k,k\right)$に帰着される.

から,
$$P\left(n,k\right)=P\left(n,k-1\right)+P\left(n-k,k\right)$$
によって計算できる.

## 計算量
$O\left(nk\right)$

## 参照
[「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)