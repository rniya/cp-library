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
    \ invs[i];\n    }\n\n    T P(int n, int r) {\n        if (n < r or r < 0) return\
    \ 0;\n        return fac(n) * finv(n - r);\n    }\n\n    T C(int n, int r) {\n\
    \        if (n < r or r < 0) return 0;\n        return fac(n) * finv(n - r) *\
    \ finv(r);\n    }\n\n    T H(int n, int r) {\n        if (n < 0 or r < 0) return\
    \ 0;\n        return r == 0 ? 1 : C(n + r - 1, r);\n    }\n\n    T negative_binom(int\
    \ n, int k) { return H(k, n); }\n\n    T C_naive(int n, int r) {\n        if (n\
    \ < r or r < 0) return 0;\n        T res = 1;\n        r = std::min(r, n - r);\n\
    \        for (int i = 1; i <= r; i++) res *= inv(i) * (n--);\n        return res;\n\
    \    }\n\n    T catalan(int n) {\n        if (n < 0) return 0;\n        return\
    \ fac(2 * n) * finv(n + 1) * finv(n);\n    }\n\n    T catalan_pow(int n, int k)\
    \ {\n        if (n < 0 or k < 0) return 0;\n        if (k == 0) return n == 0\
    \ ? 1 : 0;\n        return inv(n + k) * k * C(2 * n + k - 1, n);\n    }\n\n  \
    \  T calatan1(int n, int m) { return C(n + m, m) - C(n + m, m - 1); }\n\n    T\
    \ catalan2(int n, int m, int k) { return n - m <= -k ? 0 : C(n + m, m) - C(n +\
    \ m, m - k); }\n\n    T narayana(int n, int k) {\n        if (n < k or k <= 0)\
    \ return 0;\n        return C(n, k) * C(n, k - 1) * inv(n);\n    }\n\n    T grid_sum(int\
    \ x, int y) {\n        if (x < 0 or y < 0) return 0;\n        return C(x + y +\
    \ 2, x + 1) - 1;\n    }\n\n    T grid_sum2(int xl, int xr, int yl, int yr) {\n\
    \        if (xl >= xr or yl >= yr) return 0;\n        xl--, xr--, yl--, yr--;\n\
    \        return grid_sum(xr, yr) - grid_sum(xl, yr) - grid_sum(xr, yl) + grid_sum(xl,\
    \ yl);\n    }\n\n  private:\n    int n;\n    std::vector<T> facs, finvs, invs;\n\
    \n    inline void extend(int m = -1) {\n        if (m == -1) m = n * 2;\n    \
    \    m = std::min(m, T::mod());\n        if (n >= m) return;\n        facs.resize(m);\n\
    \        finvs.resize(m);\n        invs.resize(m);\n        for (int i = n; i\
    \ < m; i++) facs[i] = facs[i - 1] * i;\n        finvs[m - 1] = T(1) / facs[m -\
    \ 1];\n        invs[m - 1] = finvs[m - 1] * facs[m - 2];\n        for (int i =\
    \ m - 2; i >= n; i--) {\n            finvs[i] = finvs[i + 1] * (i + 1);\n    \
    \        invs[i] = finvs[i] * facs[i - 1];\n        }\n        n = m;\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T> struct Binomial {\n    Binomial(int MAX = 0) : n(1), facs(1,\
    \ T(1)), finvs(1, T(1)), invs(1, T(1)) {\n        assert(T::mod() != 0);\n   \
    \     if (MAX > 0) extend(MAX + 1);\n    }\n\n    T fac(int i) {\n        assert(i\
    \ >= 0);\n        while (n <= i) extend();\n        return facs[i];\n    }\n\n\
    \    T finv(int i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n\
    \        return finvs[i];\n    }\n\n    T inv(int i) {\n        assert(i >= 0);\n\
    \        while (n <= i) extend();\n        return invs[i];\n    }\n\n    T P(int\
    \ n, int r) {\n        if (n < r or r < 0) return 0;\n        return fac(n) *\
    \ finv(n - r);\n    }\n\n    T C(int n, int r) {\n        if (n < r or r < 0)\
    \ return 0;\n        return fac(n) * finv(n - r) * finv(r);\n    }\n\n    T H(int\
    \ n, int r) {\n        if (n < 0 or r < 0) return 0;\n        return r == 0 ?\
    \ 1 : C(n + r - 1, r);\n    }\n\n    T negative_binom(int n, int k) { return H(k,\
    \ n); }\n\n    T C_naive(int n, int r) {\n        if (n < r or r < 0) return 0;\n\
    \        T res = 1;\n        r = std::min(r, n - r);\n        for (int i = 1;\
    \ i <= r; i++) res *= inv(i) * (n--);\n        return res;\n    }\n\n    T catalan(int\
    \ n) {\n        if (n < 0) return 0;\n        return fac(2 * n) * finv(n + 1)\
    \ * finv(n);\n    }\n\n    T catalan_pow(int n, int k) {\n        if (n < 0 or\
    \ k < 0) return 0;\n        if (k == 0) return n == 0 ? 1 : 0;\n        return\
    \ inv(n + k) * k * C(2 * n + k - 1, n);\n    }\n\n    T calatan1(int n, int m)\
    \ { return C(n + m, m) - C(n + m, m - 1); }\n\n    T catalan2(int n, int m, int\
    \ k) { return n - m <= -k ? 0 : C(n + m, m) - C(n + m, m - k); }\n\n    T narayana(int\
    \ n, int k) {\n        if (n < k or k <= 0) return 0;\n        return C(n, k)\
    \ * C(n, k - 1) * inv(n);\n    }\n\n    T grid_sum(int x, int y) {\n        if\
    \ (x < 0 or y < 0) return 0;\n        return C(x + y + 2, x + 1) - 1;\n    }\n\
    \n    T grid_sum2(int xl, int xr, int yl, int yr) {\n        if (xl >= xr or yl\
    \ >= yr) return 0;\n        xl--, xr--, yl--, yr--;\n        return grid_sum(xr,\
    \ yr) - grid_sum(xl, yr) - grid_sum(xr, yl) + grid_sum(xl, yl);\n    }\n\n  private:\n\
    \    int n;\n    std::vector<T> facs, finvs, invs;\n\n    inline void extend(int\
    \ m = -1) {\n        if (m == -1) m = n * 2;\n        m = std::min(m, T::mod());\n\
    \        if (n >= m) return;\n        facs.resize(m);\n        finvs.resize(m);\n\
    \        invs.resize(m);\n        for (int i = n; i < m; i++) facs[i] = facs[i\
    \ - 1] * i;\n        finvs[m - 1] = T(1) / facs[m - 1];\n        invs[m - 1] =\
    \ finvs[m - 1] * facs[m - 2];\n        for (int i = m - 2; i >= n; i--) {\n  \
    \          finvs[i] = finvs[i + 1] * (i + 1);\n            invs[i] = finvs[i]\
    \ * facs[i - 1];\n        }\n        n = m;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/binomial.hpp
  requiredBy:
  - src/math/number_of_increasing_sequences_between_two_sequences.hpp
  - src/polynomial/lagrange_interpolation.hpp
  timestamp: '2024-10-28 15:43:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
  - test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/yukicoder/665.test.cpp
documentation_of: src/math/binomial.hpp
layout: document
title: Binomial Coefficients
---

## 概要
$\mathbb{Z}/p\mathbb{Z}$ における二項係数を扱うライブラリ．
$n$ の上限等を指定する必要はなく，不十分な場合に適宜上限を $2$ 倍にしていくことで効率的に計算する．
上限 $n$，クエリ数 $q$ の際の時間計算量は $\mathrm{O}(q + n + \log n\log p)$、空間計算量は $\mathrm{O}(n)$ となる．

下記の時間計算量については構築にかかる時間計算量は含んでいない．

| メンバ関数             | 効果                                                                                                                       | 時間計算量                   |
| ---------------------- | -------------------------------------------------------------------------------------------------------------------------- | ---------------------------- |
| `fac(i)`               | $i!$ を返す．                                                                                                              | $\mathrm{O}(1)$              |
| `finv(i)`              | $\frac{1}{i!}$ を返す．                                                                                                    | $\mathrm{O}(1)$              |
| `inv(i)`               | $\frac{1}{i}$ を返す．                                                                                                     | $\mathrm{O}(1)$              |
| `P(n, r)`              | ${}_n\mathrm{P}_r = \frac{n!}{r!}$ を返す．                                                                                | $\mathrm{O}(1)$              |
| `C(n, r)`              | ${}_n \mathrm{C}_r = \binom{n}{r} = \frac{n!}{(n - r)!r!}$ を返す．                                                        | $\mathrm{O}(1)$              |
| `H(n, r)`              | ${}_n \mathrm{H}_r = \binom{n + r - 1}{r}$，すなわち $n$ 種類のものから重複を許して $r$ 個取り出す組み合わせの総数を返す． | $\mathrm{O}(1)$              |
| `negative_binom(n, k)` | $\lbrack x ^ n \rbrack \frac{1}{(1 - x) ^ k}$ を返す。                                                                     | $\mathrm{O}(1)$              |
| `C_naive(n, r)`        | $\binom{n}{r}$ を愚直に計算する．                                                                                          | $\mathrm{O}(\min(r, n - r))$ |
| `catalan(n)`           | $n$ 番目の Catalan 数を返す。                                                                                              | $\mathrm{O}(1)$              |
| `catalan1(n, m)`       | $+1$ が $n$ 個、$-1$ が $m$ 個からなる数列であって、累積和がどれも $0$ 以上であるよなものの個数を返す。                    | $\mathrm{O}(1)$              |
| `catalan2(n, m, k)`    | $+1$ が n 個、$-1$ が $m$ 個からなる数列であって、累積和がどれも $- k$ より大きいようなものの個数を返す。                  | $\mathrm{O}(1)$              |

| `catalan_pow(n, k)`         | Catalan 数の母関数を $C(x)$ として、$\lbrack x ^ n \rbrack C ^ k (x)$ を返す。                                                     | $\mathrm{O}(1)$              |
| `narayana(n, k)`            | Narayana 数 $N(n, k)$ を返す。これは長さ $2 n$ の括弧列であって、連続部分列として `()` を丁度 $k$ 個含むようなものの個数に等しい。 | $\mathrm{O}(1)$              |
| `grid_sum(x, y)`            | $\sum _ {i = 0} ^ x \sum _ {j = 0} ^ y \binom{i + j}{i}$ を返す。                                                                  | $\mathrm{O}(1)$              |
| `grid_sum2(xl, xr, yl, yr)` | $\sum _ {i = x _ l} ^ {x _ r - 1} \sum _ {j = y _ l} ^ {y _ r - 1} \binom{i + j}{i}$ を返す。                                      | $\mathrm{O}(1)$              |
