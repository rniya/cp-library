---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/subset_convolution.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace internal {\n\ntemplate <typename T,\
    \ int LIM> std::vector<std::array<T, LIM + 1>> ranked_zeta(const std::vector<T>&\
    \ a) {\n    int n = a.size(), len = __builtin_ctz(n);\n    assert((n & (n - 1))\
    \ == 0);\n    std::vector<std::array<T, LIM + 1>> res(n);\n    for (int i = 0;\
    \ i < n; i++) res[i][__builtin_popcount(i)] = a[i];\n    for (int step = 1; step\
    \ < n; step <<= 1) {\n        for (int start = 0; start < n; start += 2 * step)\
    \ {\n            for (int i = start; i < start + step; i++) {\n              \
    \  for (int j = 0; j <= len; j++) {\n                    res[i | step][j] += res[i][j];\n\
    \                }\n            }\n        }\n    }\n    return res;\n}\n\ntemplate\
    \ <typename T, int LIM> std::vector<T> ranked_mobius(std::vector<std::array<T,\
    \ LIM + 1>>& ranked) {\n    int n = ranked.size(), len = __builtin_ctz(n);\n \
    \   assert((n & (n - 1)) == 0);\n    for (int step = 1; step < n; step <<= 1)\
    \ {\n        for (int start = 0; start < n; start += 2 * step) {\n           \
    \ for (int i = start; i < start + step; i++) {\n                for (int j = 0;\
    \ j <= len; j++) {\n                    ranked[i | step][j] -= ranked[i][j];\n\
    \                }\n            }\n        }\n    }\n    std::vector<T> res(n);\n\
    \    for (int i = 0; i < n; i++) res[i] = ranked[i][__builtin_popcount(i)];\n\
    \    return res;\n}\n\n}  // namespace internal\n\ntemplate <typename T, int LIM\
    \ = 20>\nstd::vector<T> subset_convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    auto ra = internal::ranked_zeta<T, LIM>(a);\n    auto rb = internal::ranked_zeta<T,\
    \ LIM>(b);\n    int n = ra.size(), len = __builtin_ctz(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        auto &f = ra[i], &g = rb[i];\n        for (int j = len;\
    \ j >= 0; j--) {\n            T sum = 0;\n            for (int k = 0; k <= j;\
    \ k++) sum += f[k] * g[j - k];\n            f[j] = sum;\n        }\n    }\n  \
    \  return internal::ranked_mobius<T, LIM>(ra);\n}\n"
  code: "#include <array>\n#include <cassert>\n#include <vector>\n\nnamespace internal\
    \ {\n\ntemplate <typename T, int LIM> std::vector<std::array<T, LIM + 1>> ranked_zeta(const\
    \ std::vector<T>& a) {\n    int n = a.size(), len = __builtin_ctz(n);\n    assert((n\
    \ & (n - 1)) == 0);\n    std::vector<std::array<T, LIM + 1>> res(n);\n    for\
    \ (int i = 0; i < n; i++) res[i][__builtin_popcount(i)] = a[i];\n    for (int\
    \ step = 1; step < n; step <<= 1) {\n        for (int start = 0; start < n; start\
    \ += 2 * step) {\n            for (int i = start; i < start + step; i++) {\n \
    \               for (int j = 0; j <= len; j++) {\n                    res[i |\
    \ step][j] += res[i][j];\n                }\n            }\n        }\n    }\n\
    \    return res;\n}\n\ntemplate <typename T, int LIM> std::vector<T> ranked_mobius(std::vector<std::array<T,\
    \ LIM + 1>>& ranked) {\n    int n = ranked.size(), len = __builtin_ctz(n);\n \
    \   assert((n & (n - 1)) == 0);\n    for (int step = 1; step < n; step <<= 1)\
    \ {\n        for (int start = 0; start < n; start += 2 * step) {\n           \
    \ for (int i = start; i < start + step; i++) {\n                for (int j = 0;\
    \ j <= len; j++) {\n                    ranked[i | step][j] -= ranked[i][j];\n\
    \                }\n            }\n        }\n    }\n    std::vector<T> res(n);\n\
    \    for (int i = 0; i < n; i++) res[i] = ranked[i][__builtin_popcount(i)];\n\
    \    return res;\n}\n\n}  // namespace internal\n\ntemplate <typename T, int LIM\
    \ = 20>\nstd::vector<T> subset_convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    auto ra = internal::ranked_zeta<T, LIM>(a);\n    auto rb = internal::ranked_zeta<T,\
    \ LIM>(b);\n    int n = ra.size(), len = __builtin_ctz(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        auto &f = ra[i], &g = rb[i];\n        for (int j = len;\
    \ j >= 0; j--) {\n            T sum = 0;\n            for (int k = 0; k <= j;\
    \ k++) sum += f[k] * g[j - k];\n            f[j] = sum;\n        }\n    }\n  \
    \  return internal::ranked_mobius<T, LIM>(ra);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/subset_convolution.hpp
  requiredBy: []
  timestamp: '2023-10-09 17:44:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/subset_convolution.test.cpp
documentation_of: src/math/subset_convolution.hpp
layout: document
title: Subset Convolution
---

## 概要

$[n] \coloneqq \{0, 1, \dots , n - 1\}$ 、及び $\mathbb{K}$ を環とする。
集合関数 $f \colon 2^{[n]} \to \mathbb{K},\ g \colon 2^{[n]} \to \mathbb{K}$ の subset convolution $f \ast g$ を以下で定義する：
$$
(f \ast g) \colon S \in 2^{[n]} \to \sum_{T \subseteq S} f(T) g(S \setminus T) \in \mathbb{K}
$$

subset convolution はランク付き zeta / mobius 変換を経由して $\mathrm{O}(n^2 2^n)$ 時間で計算することができる。


## Links
- [Xmas Contest 2020 H: Hierarchical Phylogeny 解説 - hos.lyric's blog](https://hos-lyric.hatenablog.com/entry/2021/01/14/201231)
- [Subset Convolutionのアルゴリズム – 37zigenのHP](https://37zigen.com/subset-convolution/)
- [Optimal Algorithm on Polynomial Composite Set Power Series - Codeforces](https://codeforces.com/blog/entry/92183)
- [集合冪級数 (Set Power Series) のダブリングまとめ - suisen のブログ](https://suisen-kyopro.hatenablog.com/entry/2023/04/07/041318)
- [集合べき級数解説 \| maspyのHP](https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0)

## 問題例
