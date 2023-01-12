---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ base.hpp: line 7: unable to process #include in #if / #ifdef / #ifndef other\
    \ than include guards\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nvector<int> gray_code(int n) {\n\
    \    vector<int> res(1 << n);\n    for (int i = 0; i < (int)res.size(); i++) res[i]\
    \ = i ^ (i >> 1);\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: util/gray_code.hpp
  requiredBy: []
  timestamp: '2023-01-12 18:18:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/gray_code.hpp
layout: document
title: Gray Code
---

## 概要
Gray Code とは数値の符号化法の一つで, 前後に隣接する符号間のハミング距離が必ず 1 となるという特徴をもつ.

この特徴を生かして, 例えば bit dp や全探索の際に集合の探索順をこの Gray Code になぞらえることで, 更新の際の計算量を改善できることがある.

## 問題例
[Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine) F. Bingo](https://codeforces.com/contest/1530/problem/F)
包除原理により数え上げることを考える.1 が揃うような行集合及び対角線を固定すれば, 各列集合は独立であるから左から走査していくことで数え上げることができる.この際の計算量は決め打ちする集合が $2^{n+2}$ 個で, 各列で 1 が揃うとしたときの確率の計算に $O(n^2)$ かかるから, 結局 $O((n^2+2n)2^{n+2})$ となる.ここで, 集合の探索順を Gray Code にすれば, 集合が変更される際に各列の確率を $O(n)$ で更新することが可能になり, $O(n2^{n+3})$でこの問題が解くことができる.
