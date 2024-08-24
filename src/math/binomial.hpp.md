---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/number_of_increasing_sequences_between_two_sequences.hpp
    title: Number of Increasing Sequences Between Two Sequences
  - icon: ':heavy_check_mark:'
    path: src/polynomial/lagrange_interpolation.hpp
    title: Lagrange Interpolation
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/binomial_coefficient_prime_mod.test.cpp
    title: test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
    title: test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/binomial.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <typename T> struct Binomial {\n  \
    \  Binomial(int MAX = 0) : n(1), facs(1, T(1)), finvs(1, T(1)), invs(1, T(1))\
    \ {\n        assert(T::mod() != 0);\n        if (MAX > 0) extend(MAX + 1);\n \
    \   }\n\n    T fac(int i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n\
    \        return facs[i];\n    }\n\n    T finv(int i) {\n        assert(i >= 0);\n\
    \        while (n <= i) extend();\n        return finvs[i];\n    }\n\n    T inv(int\
    \ i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n        return\
    \ invs[i];\n    }\n\n    T P(int n, int r) {\n        if (n < 0 || n < r || r\
    \ < 0) return T(0);\n        return fac(n) * finv(n - r);\n    }\n\n    T C(int\
    \ n, int r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n        return\
    \ fac(n) * finv(n - r) * finv(r);\n    }\n\n    T H(int n, int r) {\n        if\
    \ (n < 0 || r < 0) return T(0);\n        return r == 0 ? 1 : C(n + r - 1, r);\n\
    \    }\n\n    T C_naive(int n, int r) {\n        if (n < 0 || n < r || r < 0)\
    \ return T(0);\n        T res = 1;\n        r = std::min(r, n - r);\n        for\
    \ (int i = 1; i <= r; i++) res *= inv(i) * (n--);\n        return res;\n    }\n\
    \n  private:\n    int n;\n    std::vector<T> facs, finvs, invs;\n\n    inline\
    \ void extend(int m = -1) {\n        if (m == -1) m = n * 2;\n        m = std::min(m,\
    \ T::mod());\n        if (n >= m) return;\n        facs.resize(m);\n        finvs.resize(m);\n\
    \        invs.resize(m);\n        for (int i = n; i < m; i++) facs[i] = facs[i\
    \ - 1] * i;\n        finvs[m - 1] = T(1) / facs[m - 1];\n        invs[m - 1] =\
    \ finvs[m - 1] * facs[m - 2];\n        for (int i = m - 2; i >= n; i--) {\n  \
    \          finvs[i] = finvs[i + 1] * (i + 1);\n            invs[i] = finvs[i]\
    \ * facs[i - 1];\n        }\n        n = m;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T> struct Binomial {\n    Binomial(int MAX = 0) : n(1), facs(1,\
    \ T(1)), finvs(1, T(1)), invs(1, T(1)) {\n        assert(T::mod() != 0);\n   \
    \     if (MAX > 0) extend(MAX + 1);\n    }\n\n    T fac(int i) {\n        assert(i\
    \ >= 0);\n        while (n <= i) extend();\n        return facs[i];\n    }\n\n\
    \    T finv(int i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n\
    \        return finvs[i];\n    }\n\n    T inv(int i) {\n        assert(i >= 0);\n\
    \        while (n <= i) extend();\n        return invs[i];\n    }\n\n    T P(int\
    \ n, int r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n        return\
    \ fac(n) * finv(n - r);\n    }\n\n    T C(int n, int r) {\n        if (n < 0 ||\
    \ n < r || r < 0) return T(0);\n        return fac(n) * finv(n - r) * finv(r);\n\
    \    }\n\n    T H(int n, int r) {\n        if (n < 0 || r < 0) return T(0);\n\
    \        return r == 0 ? 1 : C(n + r - 1, r);\n    }\n\n    T C_naive(int n, int\
    \ r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n        T res = 1;\n\
    \        r = std::min(r, n - r);\n        for (int i = 1; i <= r; i++) res *=\
    \ inv(i) * (n--);\n        return res;\n    }\n\n  private:\n    int n;\n    std::vector<T>\
    \ facs, finvs, invs;\n\n    inline void extend(int m = -1) {\n        if (m ==\
    \ -1) m = n * 2;\n        m = std::min(m, T::mod());\n        if (n >= m) return;\n\
    \        facs.resize(m);\n        finvs.resize(m);\n        invs.resize(m);\n\
    \        for (int i = n; i < m; i++) facs[i] = facs[i - 1] * i;\n        finvs[m\
    \ - 1] = T(1) / facs[m - 1];\n        invs[m - 1] = finvs[m - 1] * facs[m - 2];\n\
    \        for (int i = m - 2; i >= n; i--) {\n            finvs[i] = finvs[i +\
    \ 1] * (i + 1);\n            invs[i] = finvs[i] * facs[i - 1];\n        }\n  \
    \      n = m;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/binomial.hpp
  requiredBy:
  - src/polynomial/lagrange_interpolation.hpp
  - src/math/number_of_increasing_sequences_between_two_sequences.hpp
  timestamp: '2024-05-25 01:38:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/665.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
documentation_of: src/math/binomial.hpp
layout: document
title: Binomial Coefficients
---

## 概要
$\mathbb{Z}/p\mathbb{Z}$ における二項係数を扱うライブラリ．
$n$ の上限等を指定する必要はなく，不十分な場合に適宜上限を $2$ 倍にしていくことで効率的に計算する．
上限 $n$，クエリ数 $q$ の際の時間計算量は $O(q + n + \log n\log p)$ となる．

下記の時間計算量については構築にかかる時間計算量は含んでいない．

| メンバ関数      | 効果                                                                                                                           | 時間計算量          |
| --------------- | ------------------------------------------------------------------------------------------------------------------------------ | ------------------- |
| `fac(i)`        | $i!$ を返す．                                                                                                                  | $O(1)$              |
| `finv(i)`       | $\frac{1}{i!}$ を返す．                                                                                                        | $O(1)$              |
| `inv(i)`        | $\frac{1}{i}$ を返す．                                                                                                         | $O(1)$              |
| `P(n, r)`       | ${}_n\mathrm{P}_r = \frac{n!}{r!}$ を返す．                                                                                    | $O(1)$              |
| `C(n, r)`       | ${}_n \mathrm{C}_r = \binom{n}{r} = \frac{n!}{(n - r)!r!}$ を返す．                                                            | $O(1)$              |
| `H(n, r)`       | ${}_n \mathrm{H}_r = \binom{n + r - 1}{r}$，すなわち $n$ 種類のものから重複を許して $r$ 個取り出す組み合わせの総数を計算する． | $O(1)$              |
| `C_naive(n, r)` | $\binom{n}{r}$ を愚直に計算する．                                                                                              | $O(\min(r, n - r))$ |
