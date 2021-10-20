---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/binomial.hpp
    title: binomial
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G.test.cpp
    title: test/aoj/DPL_5_G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/combinatorics/BellNumber.md
    document_title: "\u30D9\u30EB\u6570"
    links: []
  bundledCode: "#line 1 \"combinatorics/BellNumber.hpp\"\n#include <vector>\n#line\
    \ 2 \"combinatorics/binomial.hpp\"\n#include <cassert>\n#line 4 \"combinatorics/binomial.hpp\"\
    \n\ntemplate <typename T> struct Binomial {\n    Binomial(int MAX = 0) : n(1),\
    \ facs(1, T(1)), finvs(1, T(1)), invs(1, T(1)) {\n        while (n <= MAX) extend();\n\
    \    }\n\n    T fac(int i) {\n        assert(i >= 0);\n        while (n <= i)\
    \ extend();\n        return facs[i];\n    }\n\n    T finv(int i) {\n        assert(i\
    \ >= 0);\n        while (n <= i) extend();\n        return finvs[i];\n    }\n\n\
    \    T inv(int i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n\
    \        return invs[i];\n    }\n\n    T P(int n, int r) {\n        if (n < 0\
    \ || n < r || r < 0) return T(0);\n        return fac(n) * finv(n - r);\n    }\n\
    \n    T C(int n, int r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n\
    \        return fac(n) * finv(n - r) * finv(r);\n    }\n\n    T H(int n, int r)\
    \ {\n        if (n < 0 || r < 0) return T(0);\n        return r == 0 ? 1 : C(n\
    \ + r - 1, r);\n    }\n\n    T C_naive(int n, int r) {\n        if (n < 0 || n\
    \ < r || r < 0) return T(0);\n        T res = 1;\n        r = std::min(r, n -\
    \ r);\n        for (int i = 1; i <= r; i++) res *= inv(i) * (n--);\n        return\
    \ res;\n    }\n\nprivate:\n    int n;\n    std::vector<T> facs, finvs, invs;\n\
    \n    inline void extend() {\n        int m = n << 1;\n        facs.resize(m);\n\
    \        finvs.resize(m);\n        invs.resize(m);\n        for (int i = n; i\
    \ < m; i++) facs[i] = facs[i - 1] * i;\n        finvs[m - 1] = T(1) / facs[m -\
    \ 1];\n        invs[m - 1] = finvs[m - 1] * facs[m - 2];\n        for (int i =\
    \ m - 2; i >= n; i--) {\n            finvs[i] = finvs[i + 1] * (i + 1);\n    \
    \        invs[i] = finvs[i] * facs[i - 1];\n        }\n        n = m;\n    }\n\
    };\n\n/**\n * @brief binomial\n * @docs docs/combinatorics/binomial.md\n */\n\
    #line 3 \"combinatorics/BellNumber.hpp\"\n\n/**\n * @brief \u30D9\u30EB\u6570\n\
    \ * @docs docs/combinatorics/BellNumber.md\n */\ntemplate <typename T> T bell_number(int\
    \ n, int k) {\n    if (n == 0) return 1;\n    k = std::min(k, n);\n    Binomial<T>\
    \ BINOM(k);\n    std::vector<T> sum(k + 1);\n    sum[0] = 1;\n    for (int i =\
    \ 1; i <= k; i++) {\n        if (i & 1)\n            sum[i] = sum[i - 1] - BINOM.finv(i);\n\
    \        else\n            sum[i] = sum[i - 1] + BINOM.finv(i);\n    }\n    T\
    \ res = 0;\n    for (int i = 1; i <= k; i++) {\n        res += T(i).pow(n) * BINOM.finv(i)\
    \ * sum[k - i];\n    }\n    return res;\n}\n"
  code: "#include <vector>\n#include \"binomial.hpp\"\n\n/**\n * @brief \u30D9\u30EB\
    \u6570\n * @docs docs/combinatorics/BellNumber.md\n */\ntemplate <typename T>\
    \ T bell_number(int n, int k) {\n    if (n == 0) return 1;\n    k = std::min(k,\
    \ n);\n    Binomial<T> BINOM(k);\n    std::vector<T> sum(k + 1);\n    sum[0] =\
    \ 1;\n    for (int i = 1; i <= k; i++) {\n        if (i & 1)\n            sum[i]\
    \ = sum[i - 1] - BINOM.finv(i);\n        else\n            sum[i] = sum[i - 1]\
    \ + BINOM.finv(i);\n    }\n    T res = 0;\n    for (int i = 1; i <= k; i++) {\n\
    \        res += T(i).pow(n) * BINOM.finv(i) * sum[k - i];\n    }\n    return res;\n\
    }"
  dependsOn:
  - combinatorics/binomial.hpp
  isVerificationFile: false
  path: combinatorics/BellNumber.hpp
  requiredBy: []
  timestamp: '2021-09-26 16:55:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_G.test.cpp
documentation_of: combinatorics/BellNumber.hpp
layout: document
redirect_from:
- /library/combinatorics/BellNumber.hpp
- /library/combinatorics/BellNumber.hpp.html
title: "\u30D9\u30EB\u6570"
---
## 概要
ベル数$B\left(n,k\right)$は$n$個の区別できる玉を$k$個の区別できない箱に入れる組合せ数, すなわち整数$1$から$n$を$k$個以下のグループに分割する場合の数である. これは, スターリング数$S\left(n,k\right)$をもとに,
$$ \begin{aligned}
    B\left(n,k\right)&=\sum_{j=0}^k S\left(n,k\right)\\
    &=\sum_{j=0}^k \frac{1}{j!} \sum_{i=0}^j \left(-1\right)^{j-i}\binom{j}{i}i^n\\
    &=\sum_{j=0}^k \sum_{i=0}^j \frac{\left(-1\right)^{j-i}}{i!\left(j-i\right)!}i^n\\
    &=\sum_{i=0}^k \sum_{j=i}^k \frac{\left(-1\right)^{j-i}}{i!\left(j-i\right)!}i^n\\
    &=\sum_{i=0}^k \sum_{j=0}^{k-i} \frac{\left(-1\right)^j}{i!j!}i^n\\
    &=\sum_{i=0}^k \frac{i^n}{i!} \sum_{j=0}^{k-1} \frac{\left(-1\right)^j}{j!}
\end{aligned} $$
と計算できる. $\sum_{j=0}^{k-1} \frac{\left(-1\right)^j}{j!}$は累積和のように前計算できる.

## 計算量
$O\left(\min\left(n,k\right)\log{n}\right)$

## 参照
[「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)