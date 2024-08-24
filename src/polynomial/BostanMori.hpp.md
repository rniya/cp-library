---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: compute Nth term of linearly recurrent sequence a_n = \sum_{i
      = 1}^d c_i a_{n - i}
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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../atcoder/convolution\"\n\ntemplate <typename T>\
    \ T BostanMori(std::vector<T> Q, std::vector<T> P, long long N) {\n    assert(Q[0]\
    \ == 1);\n    assert(P.size() < Q.size());\n    const int d = Q.size();\n    for\
    \ (; N; N >>= 1) {\n        auto Q_neg = Q;\n        for (int i = 1; i < int(Q.size());\
    \ i += 2) Q_neg[i] *= -1;\n        P = atcoder::convolution(P, Q_neg);\n     \
    \   Q = atcoder::convolution(Q, Q_neg);\n        for (int i = N & 1; i < int(P.size());\
    \ i += 2) P[i >> 1] = P[i];\n        for (int i = 0; i < int(Q.size()); i += 2)\
    \ Q[i >> 1] = Q[i];\n        P.resize(d - 1);\n        Q.resize(d);\n    }\n \
    \   return P[0];\n}\n\n/**\n * @brief compute Nth term of linearly recurrent sequence\
    \ a_n = \\sum_{i = 1}^d c_i a_{n - i}\n *\n * @tparam T F_p\n * @param a first\
    \ d elements of the sequence a_0, a_1, ... , a_{d - 1}\n * @param c coefficients\
    \ of the linear recurrence c_1, c_2, ... , c_d\n * @param N the number of term\
    \ you want to calculate\n * @return T Nth term of linearly recurrent sequence\n\
    \ */\ntemplate <typename T> T LinearRecurrence(std::vector<T> a, std::vector<T>\
    \ c, long long N) {\n    assert(a.size() >= c.size());\n    const int d = c.size();\n\
    \    std::vector<T> Q(d + 1);\n    Q[0] = 1;\n    for (int i = 0; i < d; i++)\
    \ Q[i + 1] = -c[i];\n    std::vector<T> P = atcoder::convolution(a, Q);\n    P.resize(d);\n\
    \    return BostanMori(Q, P, N);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/polynomial/BostanMori.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: src/polynomial/BostanMori.hpp
layout: document
title: Bostan-Mori Algorithm
---

## `BontanMori(Q, P, N)`

### 入力

$d$ 次多項式 $Q$ 及び高々 $d - 1$ 次の多項式 $P$，整数 $N$．

### 出力

$$
\lbrack x^N \rbrack \frac{P(x)}{Q(x)}.
$$

### 計算量

時間計算量 $\mathrm{O}(d \log d \log N)$

## `LinearRecurrence(a, c, N)`

### 入力

線型漸化式

$$
a _ i = \sum _ {j = 1} ^ d c _ j a _{i - j}
$$

を満たす数列 $a$ の初めの $d$ 項 $a _ 0, \dots , a _ {d - 1}$ 及び係数列 $c _ 1, \dots , c _ d$，整数 $N$．

### 出力

数列 $a$ の第 $N$ 項 $a _ N$ の値．

### 計算量

時間計算量 $\mathrm{O}(d \log d \log N)$

## 概要
アルゴリズムの詳細については Links にあるページがわかりやすい．
ここでは `LinearRecurrence(a, c, N)` から `BostanMori(Q, P, N)` への帰着について説明する．

$d + 1$ 項間漸化式

$$
a _ i = \sum _ {j = 1} ^ d c _ j a _ {i - j}
$$

について，その数列の母関数を

$$
G(x) = \sum _ {i = 0} ^ \infty a _ i x ^ i
$$

とし，また

$$
Q(x) = 1 - \sum _ {i = 1}^d c _ i x ^ i
$$

と定めるとき，$G(x) Q(x)$ は漸化式の定義より高々 $d - 1$ 次の多項式 $P(x)$ に一致する．
以上より，

$$
a _ N = \lbrack x ^ N \rbrack \frac{P(x)}{Q(x)}
$$

となり，これは $\mathrm{O}(d \log d \log N)$ で計算することが可能である．

## 出題例
- [競プロ典型 90 問 090 - Tenkei90's Last Problem](https://atcoder.jp/contests/typical90/tasks/typical90_cl)
- [AtCoder Beginner Contest 241 Ex - Card Deck Score](https://atcoder.jp/contests/abc241/tasks/abc241_h)
- [AtCoder Beginner Contest 300 Ex - Fibonacci: Revisited](https://atcoder.jp/contests/abc300/tasks/abc300_h)

## Links
- [線形漸化式を満たす数列の N 項目を計算するアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)
