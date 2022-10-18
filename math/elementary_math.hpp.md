---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_A.test.cpp
    title: test/aoj/NTL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/elementary_math.hpp\"\n#include <numeric>\n#include\
    \ <vector>\n\nnamespace elementary_math {\n\ntemplate <typename T> std::vector<T>\
    \ divisor(T n) {\n    std::vector<T> res;\n    for (T i = 1; i * i <= n; i++)\
    \ {\n        if (n % i == 0) {\n            res.emplace_back(i);\n           \
    \ if (i * i != n) res.emplace_back(n / i);\n        }\n    }\n    return res;\n\
    }\n\ntemplate <typename T> std::vector<std::pair<T, int>> prime_factor(T n) {\n\
    \    std::vector<std::pair<T, int>> res;\n    for (T p = 2; p * p <= n; p++) {\n\
    \        if (n % p == 0) {\n            res.emplace_back(p, 0);\n            while\
    \ (n % p == 0) {\n                res.back().second++;\n                n /= p;\n\
    \            }\n        }\n    }\n    if (n > 1) res.emplace_back(n, 1);\n   \
    \ return res;\n}\n\nstd::vector<int> osa_k(int n) {\n    std::vector<int> min_factor(n\
    \ + 1, 0);\n    for (int i = 2; i <= n; i++) {\n        if (min_factor[i]) continue;\n\
    \        for (int j = i; j <= n; j += i) {\n            if (!min_factor[j]) {\n\
    \                min_factor[j] = i;\n            }\n        }\n    }\n    return\
    \ min_factor;\n}\n\nstd::vector<int> prime_factor(const std::vector<int>& min_factor,\
    \ int n) {\n    std::vector<int> res;\n    while (n > 1) {\n        res.emplace_back(min_factor[n]);\n\
    \        n /= min_factor[n];\n    }\n    return res;\n}\n\nlong long modpow(long\
    \ long x, long long n, long long mod) {\n    assert(0 <= n && 1 <= mod && mod\
    \ < (1LL << 31));\n    if (mod == 1) return 0;\n    x %= mod;\n    long long res\
    \ = 1;\n    while (n > 0) {\n        if (n & 1) res = res * x % mod;\n       \
    \ x = x * x % mod;\n        n >>= 1;\n    }\n    return res;\n}\n\nlong long extgcd(long\
    \ long a, long long b, long long& x, long long& y) {\n    long long d = a;\n \
    \   if (b != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a / b) *\
    \ x;\n    } else\n        x = 1, y = 0;\n    return d;\n}\n\nlong long inv_mod(long\
    \ long a, long long mod) {\n    assert(1 <= mod);\n    long long x, y;\n    if\
    \ (extgcd(a, mod, x, y) != 1) return -1;\n    return (mod + x % mod) % mod;\n\
    }\n\ntemplate <typename T> T euler_phi(T n) {\n    auto pf = prime_factor(n);\n\
    \    T res = n;\n    for (const auto& p : pf) {\n        res /= p.first;\n   \
    \     res *= p.first - 1;\n    }\n    return res;\n}\n\nstd::vector<int> euler_phi_table(int\
    \ n) {\n    std::vector<int> res(n + 1, 0);\n    iota(res.begin(), res.end(),\
    \ 0);\n    for (int i = 2; i <= n; i++) {\n        if (res[i] != i) continue;\n\
    \        for (int j = i; j <= n; j += i) res[j] = res[j] / i * (i - 1);\n    }\n\
    \    return res;\n}\n\n// minimum i > 0 s.t. x^i \\equiv 1 \\pmod{m}\ntemplate\
    \ <typename T> T order(T x, T m) {\n    T n = euler_phi(m);\n    auto cand = divisor(n);\n\
    \    sort(cand.begin(), cand.end());\n    for (auto& i : cand) {\n        if (modpow(x,\
    \ i, m) == 1) {\n            return i;\n        }\n    }\n    return -1;\n}\n\n\
    }  // namespace elementary_math\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n\nnamespace elementary_math\
    \ {\n\ntemplate <typename T> std::vector<T> divisor(T n) {\n    std::vector<T>\
    \ res;\n    for (T i = 1; i * i <= n; i++) {\n        if (n % i == 0) {\n    \
    \        res.emplace_back(i);\n            if (i * i != n) res.emplace_back(n\
    \ / i);\n        }\n    }\n    return res;\n}\n\ntemplate <typename T> std::vector<std::pair<T,\
    \ int>> prime_factor(T n) {\n    std::vector<std::pair<T, int>> res;\n    for\
    \ (T p = 2; p * p <= n; p++) {\n        if (n % p == 0) {\n            res.emplace_back(p,\
    \ 0);\n            while (n % p == 0) {\n                res.back().second++;\n\
    \                n /= p;\n            }\n        }\n    }\n    if (n > 1) res.emplace_back(n,\
    \ 1);\n    return res;\n}\n\nstd::vector<int> osa_k(int n) {\n    std::vector<int>\
    \ min_factor(n + 1, 0);\n    for (int i = 2; i <= n; i++) {\n        if (min_factor[i])\
    \ continue;\n        for (int j = i; j <= n; j += i) {\n            if (!min_factor[j])\
    \ {\n                min_factor[j] = i;\n            }\n        }\n    }\n   \
    \ return min_factor;\n}\n\nstd::vector<int> prime_factor(const std::vector<int>&\
    \ min_factor, int n) {\n    std::vector<int> res;\n    while (n > 1) {\n     \
    \   res.emplace_back(min_factor[n]);\n        n /= min_factor[n];\n    }\n   \
    \ return res;\n}\n\nlong long modpow(long long x, long long n, long long mod)\
    \ {\n    assert(0 <= n && 1 <= mod && mod < (1LL << 31));\n    if (mod == 1) return\
    \ 0;\n    x %= mod;\n    long long res = 1;\n    while (n > 0) {\n        if (n\
    \ & 1) res = res * x % mod;\n        x = x * x % mod;\n        n >>= 1;\n    }\n\
    \    return res;\n}\n\nlong long extgcd(long long a, long long b, long long& x,\
    \ long long& y) {\n    long long d = a;\n    if (b != 0) {\n        d = extgcd(b,\
    \ a % b, y, x);\n        y -= (a / b) * x;\n    } else\n        x = 1, y = 0;\n\
    \    return d;\n}\n\nlong long inv_mod(long long a, long long mod) {\n    assert(1\
    \ <= mod);\n    long long x, y;\n    if (extgcd(a, mod, x, y) != 1) return -1;\n\
    \    return (mod + x % mod) % mod;\n}\n\ntemplate <typename T> T euler_phi(T n)\
    \ {\n    auto pf = prime_factor(n);\n    T res = n;\n    for (const auto& p :\
    \ pf) {\n        res /= p.first;\n        res *= p.first - 1;\n    }\n    return\
    \ res;\n}\n\nstd::vector<int> euler_phi_table(int n) {\n    std::vector<int> res(n\
    \ + 1, 0);\n    iota(res.begin(), res.end(), 0);\n    for (int i = 2; i <= n;\
    \ i++) {\n        if (res[i] != i) continue;\n        for (int j = i; j <= n;\
    \ j += i) res[j] = res[j] / i * (i - 1);\n    }\n    return res;\n}\n\n// minimum\
    \ i > 0 s.t. x^i \\equiv 1 \\pmod{m}\ntemplate <typename T> T order(T x, T m)\
    \ {\n    T n = euler_phi(m);\n    auto cand = divisor(n);\n    sort(cand.begin(),\
    \ cand.end());\n    for (auto& i : cand) {\n        if (modpow(x, i, m) == 1)\
    \ {\n            return i;\n        }\n    }\n    return -1;\n}\n\n}  // namespace\
    \ elementary_math\n"
  dependsOn: []
  isVerificationFile: false
  path: math/elementary_math.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:27:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_A.test.cpp
  - test/aoj/NTL_1_E.test.cpp
  - test/aoj/NTL_1_D.test.cpp
  - test/aoj/NTL_1_B.test.cpp
documentation_of: math/elementary_math.hpp
layout: document
title: elementary math
---

## 概要
基本的な数学関数の集合．

| 関数                          | 効果                                                                                                                    | 時間計算量           |
| ----------------------------- | ----------------------------------------------------------------------------------------------------------------------- | -------------------- |
| `divisor(n)`                  | $n$ の約数を列挙する．                                                                                                  | $O(\sqrt{n})$        |
| `prime_factor(n)`             | $n$ の素因数を列挙する．                                                                                                | $O(\sqrt{n})$        |
| `osa_k(n)`                    | $n$ 以下の各数 $i$ について，その最小素因数を記録した配列を返す．                                                       | $O(n \log \log n)$   |
| `prime_factor(min_factor, n)` | `osa_k` で構築された最小素因数の配列 `min_factor` をもとに $n$ の素因数を列挙する．                                     | $O(\log n)$          |
| `modpow(x, n, mod)`           | $x^n \pmod{mod}$ を計算する．                                                                                           | $O(\log n)$          |
| `extgcd(a, b, x, y)`          | $x, y$ を参照渡しすることで $ax + by = d$ を満たす $x, y$ に変更し，$a$ と $b$ の最大公約数 $d$ を返す．                | $O(\log \max(a,b))$  |
| `inv_mod(a, mod)`             | $\mathbb{Z}/mod\mathbb{Z}$ における $a$ の逆元を返す．$a$ と $mod$ が互いに素でなく逆元が存在しない場合は `-1` を返す． | $O(\log mod)$        |
| `euler_phi(n)`                | Euler's totient function $\varphi(n)$ を返す．ここで，$\varphi(n)$ は $n$ 以下の $n$ と互いに素な自然数の個数である．   | $O(\sqrt{n})$        |
| `euler_phi_table(n)`          | $n$ 以下の各数 $i$ について，$\varphi(i)$ を記録した配列を返す．                                                        | $O(n \log \log n)$   |
| `order(x, m)`                 | $x^i \equiv 1 \pmod{m}$ を満たす最小の正整数 $i$ を返す．存在しない場合は `-1` を返す．                                 | $O(\sqrt{m}\log{m})$ |
