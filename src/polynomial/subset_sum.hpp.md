---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: "Formal Power Series\uFF08\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\uFF09"
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution:\
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
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sharp_p_subset_sum.test.cpp
documentation_of: src/polynomial/subset_sum.hpp
layout: document
title: $\#_p$ Subset Sum
---

## 概要
$n$ 個の正整数 $s_0, \dots , s_{n - 1}$ と正整数 $m$ が与えられるとき，$t = 1, \dots , m$ について $\sum_{i \in I} s_i = t$ なる $I \subseteq \{0, 1, \dots , n - 1\}$ の個数を $O(n + m \log m)$ で求める．

$s_i = 0$ については答えを $2$ 倍すれば良いから以降は $s_i \geq 1$ とする．
$t$ に対する答えは

$$
[x^t] \prod_{i = 0}^{n - 1} (1 + x^{s_i}) = \exp\left(\sum_{i = 0}^{n - 1} \log (1 + x^{s_i}) \right)
$$

に等しい．

ここで，

$$
\log (1 + x) = x - \frac{x^2}{2} + \frac{x^3}{3} - \cdots = \sum_{i \geq 1} \frac{(-1)^{i - 1}}{i} x^i
$$

であるから $s_i = k$ なる $i \in \{0, 1, \dots , n - 1\}$ の個数を $c_k\ (k \in [1, m])$ とすると，

$$
\sum_{i = 0}^{n - 1} \log (1 + x^{s_i}) = \sum_{k = 1}^m c_k \sum_{k i \leq m} \frac{(-1)^{i - 1}}{i} x^{k i}
$$

で，これは $O(m \log m)$ で計算可能である．


## Links
