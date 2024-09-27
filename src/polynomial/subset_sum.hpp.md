---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <vector>\n#include \"FormalPowerSeries.hpp\"\n\ntemplate\
    \ <typename T> std::vector<T> subset_sum(const std::vector<int>& s, int m) {\n\
    \    std::vector<int> cnt(m + 1, 0);\n    for (const int& x : s) {\n        assert(x\
    \ >= 0);\n        if (x <= m) cnt[x]++;\n    }\n    FormalPowerSeries<T> res(m\
    \ + 1);\n    std::vector<T> inv(m + 1);\n    inv[0] = T(0);\n    if (m > 0) inv[1]\
    \ = T(1);\n    auto mod = T::mod();\n    for (int i = 2; i <= m; i++) inv[i] =\
    \ -inv[mod % i] * (mod / i);\n    for (int i = 1; i <= m; i++) {\n        if (cnt[i]\
    \ == 0) continue;\n        for (int j = 1; i * j <= m; j++) {\n            if\
    \ (j & 1)\n                res[i * j] += inv[j] * cnt[i];\n            else\n\
    \                res[i * j] -= inv[j] * cnt[i];\n        }\n    }\n    res = res.exp(m\
    \ + 1);\n    T p = T(2).pow(cnt[0]);\n    for (auto& val : res) val *= p;\n  \
    \  return res;\n}\n"
  dependsOn:
  - src/polynomial/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/polynomial/subset_sum.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sharp_p_subset_sum.test.cpp
documentation_of: src/polynomial/subset_sum.hpp
layout: document
title: $\#_p$ Subset Sum
---

## 入力

$N$ 個の非負整数 $s _ 0, \dots , s _ {N - 1}$ 及び正整数 $m$．

## 出力

$t = 1, \dots , m$ について $\sum _ {i \in I} s _ i = t$ となる $I \subseteq \lbrace 0, 1, \dots , N - 1 \rbrace$ の個数．

## 計算量

時間計算量 $\mathrm{O}(N + M \log M)$

## 概要

$s _ i = 0$ については答えを $2$ 倍すれば良いから以降は $s _ i \geq 1$ とする．
$t$ に対する答えは

$$
[x ^ t] \prod _ {i = 0} ^ {N - 1} (1 + x ^ {s _ i}) = \exp \left( \sum _ {i = 0} ^ {N - 1} \log (1 + x ^ {s _ i}) \right)
$$

に等しい．

ここで，

$$
\log (1 + x) = x - \frac{x ^ 2}{2} + \frac{x ^ 3}{3} - \cdots = \sum _ {i \geq 1} \frac{(-1) ^ {i - 1}}{i} x ^ i
$$

であるから $s _ i = k$ なる $i \in \lbrace 0, 1, \dots , N - 1 \rbrace$ の個数を $c _ k\ (k \in \lbrack 1, m \rbrack)$ とすると，

$$
\sum _ {i = 0} ^ {N - 1} \log (1 + x ^ {s _ i}) = \sum _ {k = 1} ^ m c_k \sum _ {k i \leq m} \frac{(-1) ^ {i - 1}}{i} x^{k i}
$$

で，これは $\mathrm{O}(M \log M)$ 時間で計算可能である．


## Links
