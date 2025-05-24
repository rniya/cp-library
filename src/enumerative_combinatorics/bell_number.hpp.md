---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/binomial.hpp
    title: Binomial Coefficients
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bell_number.test.cpp
    title: test/yosupo/bell_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../math/binomial.hpp\"\n#include \"../polynomial/FormalPowerSeries.hpp\"\
    \n\ntemplate <typename T> std::vector<T> bell_number(int n) {\n    Binomial<T>\
    \ binom;\n    FormalPowerSeries<T> f(n + 1);\n    f[0] = 0;\n    for (int i =\
    \ 1; i <= n; i++) {\n        f[i] = binom.finv(i);\n    }\n    f = f.exp();\n\
    \    for (int i = 0; i <= n; i++) {\n        f[i] *= binom.fac(i);\n    }\n  \
    \  return f;\n}"
  dependsOn:
  - src/math/binomial.hpp
  - src/polynomial/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/enumerative_combinatorics/bell_number.hpp
  requiredBy: []
  timestamp: '2025-05-24 15:05:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bell_number.test.cpp
documentation_of: src/enumerative_combinatorics/bell_number.hpp
layout: document
title: Bell Number
---

## 入力

整数 $N$．

## 出力

$n$ 元集合を空でない部分集合に分割する方法の個数を $B _ n$（ベル数）とし，$B _ 0, \dots , B _ N$ を列挙．

## 計算量

時間計算量 $\mathrm{O}(N \log N)$

## 概要

$n$ 元集合 $\lbrace 1, \dots , n \rbrace$ を空でない部分集合に分割するに際し，要素 $1$ の属する集合のサイズを $i$ とすると，この集合の残り $i - 1$ 要素の選び方は $\binom{n - 1}{i - 1}$ 通りあり，残った $n - i$ 要素の分割方法の個数は $B _ {n - i}$ となるため，

$$
B _ n = \sum _ {i = 1} ^ n \binom{n - 1}{i - 1} B _ {n - i} = \sum _ {i = 0} ^ {n - 1} \binom{n - 1}{i} B _ i
$$

が成立する．

これを指数型母関数 $B(x) := \sum _ {n \ge 0} \frac{B _ n}{n!} x ^ n$ について変形すると，

$$
\begin{aligned}
    B _ n = \sum _ {i = 0} ^ {n - 1} \frac{(n - 1)!}{i! (n - 1 - i)!} B _ i
    &\implies n \frac{B _ n}{n!} = \sum _ {i = 0} ^ {n - 1} \frac{B _ i}{i!} \frac{1}{(n - 1 - i)!} \\
    & \implies \sum _ {n \ge 1} n \frac{B _ n}{n!} x ^ n = \sum _ {n \ge 1} x \sum _ {i = 0} ^ {n - 1} \frac{B _ i}{i!} x ^ i \frac{x ^ {n - 1 - i}}{(n - 1 - i)!} \\
    & \implies x B ^ \prime (x) = x B(x) e ^ x \\
    & \implies \frac{B ^ \prime(x)}{B(x)} = e ^ x
\end{aligned}
$$

を得る．
両辺を積分することで $c$ を定数として，

$$
\log B(x) = e ^ x + c
$$

となり，$B(0) = B _ 0 = 1$ より $c = -1$ である．

以上より，$B(x) = e ^ {e ^ x - 1}$ が成立する．
これは形式的冪級数の基本演算により $\mathrm{O}(N \log N)$ 時間で計算可能である．

## 出題例
- [AtCoder Beginner Contest 387 G - Prime Circuit](https://atcoder.jp/contests/abc387/tasks/abc387_g)
  - ほぼ同様の式変形を用いる．

## Links
- [[Tutorial] Generating Functions in Competitive Programming (Part 1) - Codeforces](https://codeforces.com/blog/entry/77468)