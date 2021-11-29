---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/polynomial/StirlingSecond.md
    document_title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"FormalPowerSeries.hpp\"\
    \n\n/**\n * @brief \u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\n *\
    \ @docs docs/polynomial/StirlingSecond.md\n */\ntemplate <typename T> FormalPowerSeries<T>\
    \ StirlingSecond(int n) {\n    FormalPowerSeries<T> a(n + 1), b(n + 1);\n    T\
    \ prod = 1;\n    for (int i = 0; i <= n; i++) {\n        T inv = T(1) / prod;\n\
    \        a[i] = T(i).pow(n) * inv;\n        b[i] = T(1) * inv;\n        if (i\
    \ & 1) b[i] *= -1;\n        prod *= i + 1;\n    }\n    return (a * b).pre(n +\
    \ 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/StirlingSecond.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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