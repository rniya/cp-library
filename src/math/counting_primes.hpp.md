---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/counting_primes.test.cpp
    title: test/yosupo/counting_primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/counting_primes.hpp\"\n#include <cmath>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace internal {\n\nstd::pair<std::vector<long\
    \ long>, std::vector<long long>> pi_table(long long N) {\n    std::vector<long\
    \ long> ns{0};\n    for (long long i = N; i > 0; i = N / (N / i + 1)) ns.emplace_back(i);\n\
    \    auto f = ns;\n    for (auto& val : f) val--;\n    for (long long x = 2, sq\
    \ = sqrtl(N), len = ns.size(); x <= sq; x++) {\n        if (f[len - x] == f[len\
    \ - x + 1]) continue;\n        long long x2 = x * x, pi = f[len - x + 1];\n  \
    \      for (long long i = 1, n = ns[i]; i < len and n >= x2; n = ns[++i]) {\n\
    \            f[i] -= f[i * x <= sq ? i * x : len - n / x] - pi;\n        }\n \
    \   }\n    return {ns, f};\n}\n\n}  // namespace internal\n\nlong long counting_primes(long\
    \ long N) {\n    if (N < 2) return 0;\n    return internal::pi_table(N).second[1];\n\
    }\n"
  code: "#pragma once\n#include <cmath>\n#include <utility>\n#include <vector>\n\n\
    namespace internal {\n\nstd::pair<std::vector<long long>, std::vector<long long>>\
    \ pi_table(long long N) {\n    std::vector<long long> ns{0};\n    for (long long\
    \ i = N; i > 0; i = N / (N / i + 1)) ns.emplace_back(i);\n    auto f = ns;\n \
    \   for (auto& val : f) val--;\n    for (long long x = 2, sq = sqrtl(N), len =\
    \ ns.size(); x <= sq; x++) {\n        if (f[len - x] == f[len - x + 1]) continue;\n\
    \        long long x2 = x * x, pi = f[len - x + 1];\n        for (long long i\
    \ = 1, n = ns[i]; i < len and n >= x2; n = ns[++i]) {\n            f[i] -= f[i\
    \ * x <= sq ? i * x : len - n / x] - pi;\n        }\n    }\n    return {ns, f};\n\
    }\n\n}  // namespace internal\n\nlong long counting_primes(long long N) {\n  \
    \  if (N < 2) return 0;\n    return internal::pi_table(N).second[1];\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/counting_primes.hpp
  requiredBy: []
  timestamp: '2024-08-25 02:56:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/counting_primes.test.cpp
documentation_of: src/math/counting_primes.hpp
layout: document
title: Counting Primes
---

## 入力

整数 $N$．

## 出力

$N$ 以下の素数の個数．

## 計算量

- 時間計算量 $\mathrm{O} \left( \frac{N^{3 / 4}}{\log N} \right)$
- 空間計算量 $\mathrm{O}(\sqrt{N})$

## 概要

$\pi(n)$ を $n$ 以下の素数の個数とする．
求めたいのは $\pi(N)$ である．

$f(n, x)$ を $2$ 以上 $n$ 以下であって，$x$ 以下でふるいをかけた際に残る数の個数と定めると，

$$
\pi(N) = f\left( N, \left \lfloor \sqrt{N} \right \rfloor \right)
$$

である．
このとき，

$$
f(n, x) =
\begin{cases}
    f(n, x - 1) & (x \text{ is not prime} \lor n < x^2) \\
    f(n, x - 1) - \left( f\left( \left \lfloor \frac{n}{x} \right \rfloor, x - 1 \right) - \pi(x - 1) \right) & (\text{o.w.})
\end{cases}
$$

が成立する．
$\pi(N)$ を求めるにあたり必要となる $f(n, x)$ の値は $n = \left \lfloor \frac{N}{1} \right \rfloor, \left \lfloor \frac{N}{2} \right \rfloor, \dots , \left \lfloor \frac{N}{N} \right \rfloor$ 及び $x = 1, \dots , \left \lfloor \sqrt{N} \right \rfloor$ のみで，これを動的計画法により計算していく．

実装中の `internal::pi_table(N)` は $i$ 要素目 (1-indexed) が $\left \lfloor \frac{N}{i} \right \rfloor$ 及び $\pi(\frac{N}{i})$ に等しい配列を返している．