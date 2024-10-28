---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <vector>\n#include \"FormalPowerSeries.hpp\"\n\ntemplate\
    \ <typename T> struct subproduct_tree {\n    using poly = FormalPowerSeries<T>;\n\
    \    int m;\n    std::vector<poly> prod;\n    subproduct_tree(const std::vector<T>&\
    \ x) : m(x.size()) {\n        int k = 1;\n        while (k < m) k <<= 1;\n   \
    \     prod.assign(k << 1, {1});\n        for (int i = 0; i < m; i++) prod[k +\
    \ i] = {-x[i], 1};\n        for (int i = k - 1; i > 0; i--) prod[i] = prod[i <<\
    \ 1] * prod[i << 1 | 1];\n    }\n\n    int size() const { return prod.size() >>\
    \ 1; }\n\n    poly mid_prod(const poly& a, const poly& b) const {}\n\n    std::vector<T>\
    \ multipoint_evaluation(poly f) const {\n        std::vector<poly> rem(size()\
    \ << 1);\n        rem[1] = f % prod[1];\n        for (int i = 2; i < size() +\
    \ m; i++) rem[i] = rem[i >> 1] % prod[i];\n        std::vector<T> res(m);\n  \
    \      for (int i = 0; i < m; i++) res[i] = (rem[size() + i].empty() ? 0 : rem[size()\
    \ + i][0]);\n        return res;\n    }\n};"
  dependsOn:
  - src/polynomial/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/polynomial/multipoint_evaluation.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/multipoint_evaluation.test.cpp
documentation_of: src/polynomial/multipoint_evaluation.hpp
layout: document
title: Multipoint Evaluation
---

## 入力

$N - 1$ 次多項式 $f(x)$ 及び数列 $x _ 0, \dots , x _ {M - 1}$．

## 出力

評価値 $f(x _ 0), \dots , f(x _ {M - 1})$．

## 計算量

時間計算量 $\mathrm{O}(M \log ^ 2 M + N \log N)$

## 概要

剰余の定理より $f(a) = f(x) \bmod (x - a)$ であるから $f(x _ 0) \bmod (x - x _ 0), f(x _ 1) \bmod (x - x _ 1), \dots , f(x _ {M - 1}) \bmod (x - x _ {M - 1})$ が求まれば良い．

ここで，次のような各ノードに多項式をもつ根付き 2 分木 (subproduct tree) を構築する．
まず，木は $M$ 個の葉ノードをもち，各ノードには $x - x _ 0, x - x _ 1, \dots , x - x _ {M - 1}$ が書かれている．
そして，葉以外のノードにはその 2 つの子ノードに書かれた多項式の積が書かれている．
subproduct tree は $\mathrm{O}(M \log ^2 M)$ 時間で構築可能である．

次に根の多項式を $f \bmod (x - x _ 0) (x - x _ 1) \dots (x - x _ {M - 1})$ に書き換える．
これは $\mathrm{O}((N + M) \log (N + M))$ 時間かかる．
また，多項式 $f, g, h$ に対して $(f \bmod g h) \bmod g = f \bmod g$ が成り立つことから，根から葉に逆方向に向かって $f$ をそのノードに書かれた多項式で割った余りを計算できる．
これは最初の構築と同様で $\mathrm{O}(M \log ^ 2 M)$ 時間で処理できる．

こうして最終的に葉ノードに書かれた値が求めたかった評価値である．

## TODO:
middle product を利用した高速化

## 出題例
- [AtCoder Beginner Contest 272 Ex - Flipping Coins 2](https://atcoder.jp/contests/abc272/tasks/abc272_h)
- [技術室奥プログラミングコンテスト#6 Day2 K - Ball in the Box 2](https://atcoder.jp/contests/tkppc6-2/tasks/tkppc6_2_k)
- [The 1st Universal Cup. Stage 16: Gomel E. Classical FFT Problem](https://qoj.ac/contest/1223/problem/6411?v=1)

## Links
- [Multipoint Evaluation の アルゴリズム – 37zigenのHP](https://37zigen.com/multipoint-evaluation/)
