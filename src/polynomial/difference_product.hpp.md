---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2513.test.cpp
    title: test/yukicoder/2513.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"FormalPowerSeries.hpp\"\n\ntemplate <typename T>\
    \ T difference_product(const std::vector<int>& x) {\n    int n = x.size(), k =\
    \ 1;\n    while (k < n) k <<= 1;\n    std::vector<FormalPowerSeries<T>> prod(k\
    \ << 1, {1});\n    for (int i = 0; i < n; i++) prod[k + i] = {-x[i], 1};\n   \
    \ for (int i = k - 1; i > 0; i--) prod[i] = prod[i << 1] * prod[i << 1 | 1];\n\
    \    std::vector<FormalPowerSeries<T>> rem(k << 1);\n    rem[0] = {1};\n    for\
    \ (int i = 1; i < k + n; i++) {\n        rem[i] = rem[i >> 1];\n        if (~i\
    \ & 1) rem[i] *= prod[i | 1];\n        rem[i] %= prod[i];\n    }\n    T res =\
    \ 1;\n    for (int i = 0; i < n; i++) res *= (rem[k + i].empty() ? 0 : rem[k +\
    \ i][0]);\n    return res;\n}"
  dependsOn:
  - src/polynomial/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/polynomial/difference_product.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2513.test.cpp
documentation_of: src/polynomial/difference_product.hpp
layout: document
title: Difference Product (Vandermonde's Determinant)
---

## 入力

長さ $N$ の数列 $x _ 0, \dots , x _ {N - 1}$．

## 出力

差積の値．
すなわち，

$$
\prod _ {0 \le i \lt j \le n} (x _ j - x _ i).
$$

## 計算量

時間計算量 $\mathrm{O}(N \log ^ 2 N)$

## 出題例
- [yukicoder No.2513 Power Eraser](https://yukicoder.me/problems/no/2513)

## Links
- [差積の $2$ 乗？](https://x.com/maspy_stars/status/1715375727460401307?s=20)